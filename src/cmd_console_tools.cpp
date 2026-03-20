/* * 终端伪图形界面工具库实现文件
 * 针对 MagicBall 项目基于 Windows API 完整还原
 */

#include "../include/cmd_console_tools.h"
#include <windows.h>
#include <iostream>

using namespace std;

// 获取标准输出句柄的内部辅助函数
static HANDLE GetOutHandle() {
    return GetStdHandle(STD_OUTPUT_HANDLE);
}

// 获取标准输入句柄的内部辅助函数
static HANDLE GetInHandle() {
    return GetStdHandle(STD_INPUT_HANDLE);
}

void cct_cls() {
    // 使用 Windows API 实现无闪烁的高效清屏
    HANDLE hConsole = GetOutHandle();
    COORD coordScreen = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // 用空格填充整个屏幕缓冲区
    FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten);
    // 恢复默认文本属性
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    // 将光标移回左上角
    SetConsoleCursorPosition(hConsole, coordScreen);
}

void cct_gotoxy(int x, int y) {
    COORD pos;
    pos.X = (short)x;
    pos.Y = (short)y;
    SetConsoleCursorPosition(GetOutHandle(), pos);
}

void cct_getxy(int &x, int &y) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetOutHandle(), &csbi)) {
        x = csbi.dwCursorPosition.X;
        y = csbi.dwCursorPosition.Y;
    } else {
        x = 0;
        y = 0;
    }
}

void cct_setcolor(int textcolor, int bgcolor) {
    // Windows API 中颜色属性是 8 位：高 4 位为背景色，低 4 位为前景色
    WORD colorAttribute = (WORD)((bgcolor << 4) | textcolor);
    SetConsoleTextAttribute(GetOutHandle(), colorAttribute);
}

void cct_setconsoleborder(int width, int height, int bufferWidth, int bufferHeight) {
    HANDLE hConsole = GetOutHandle();
    
    // 设置缓冲区大小
    COORD bufferSize = { (short)bufferWidth, (short)bufferHeight };
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // 设置窗口可视区域大小 (注意：坐标是从 0 开始的，所以要减 1)
    SMALL_RECT windowSize = { 0, 0, (short)(width - 1), (short)(height - 1) };
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

void cct_setfontsize(const char* fontName, int size) {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;           // 宽度设为0，系统会自动根据高度按比例适配
    cfi.dwFontSize.Y = (short)size; // 设置字体高度
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;

    // 将 const char* 的多字节字符串转换为 Windows API 需要的宽字符 (wchar_t)
    MultiByteToWideChar(CP_ACP, 0, fontName, -1, cfi.FaceName, LF_FACESIZE);

    SetCurrentConsoleFontEx(GetOutHandle(), FALSE, &cfi);
}

void cct_enable_mouse() {
    HANDLE hStdin = GetInHandle();
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    
    // 启用鼠标输入
    mode |= ENABLE_MOUSE_INPUT;
    // 启用扩展标志，以便后续能够禁用快速编辑
    mode |= ENABLE_EXTENDED_FLAGS; 
    
    // 根据实验报告要求，必须去除快速编辑模式和插入模式，
    // 否则用鼠标点击控制台时会自动变成选中文字，导致游戏卡死
    mode &= ~ENABLE_QUICK_EDIT_MODE; 
    mode &= ~ENABLE_INSERT_MODE;

    SetConsoleMode(hStdin, mode);
}

int cct_read_keyboard_and_mouse(int &x, int &y, int &maction, int &keycode1, int &keycode2) {
    HANDLE hStdin = GetInHandle();
    INPUT_RECORD inRec;
    DWORD numRead;

    while (true) {
        // 阻塞读取控制台输入事件
        ReadConsoleInput(hStdin, &inRec, 1, &numRead);

        // 如果是鼠标事件
        if (inRec.EventType == MOUSE_EVENT) {
            x = inRec.Event.MouseEvent.dwMousePosition.X;
            y = inRec.Event.MouseEvent.dwMousePosition.Y;

            // 判断具体的鼠标动作
            if (inRec.Event.MouseEvent.dwEventFlags == 0) { 
                // 按键状态发生变化 (按下)
                if (inRec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
                    maction = MOUSE_LEFT_BUTTON_CLICK;
                    return CCT_MOUSE_EVENT;
                }
                else if (inRec.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) {
                    maction = MOUSE_RIGHT_BUTTON_CLICK;
                    return CCT_MOUSE_EVENT;
                }
            } 
            else if (inRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK) {
                // 左键双击
                if (inRec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
                    maction = MOUSE_LEFT_BUTTON_DOUBLE_CLICK;
                    return CCT_MOUSE_EVENT;
                }
            }
        }
        // 如果是键盘事件
        else if (inRec.EventType == KEY_EVENT) {
            if (inRec.Event.KeyEvent.bKeyDown) { // 仅响应按键按下，忽略弹起
                keycode1 = inRec.Event.KeyEvent.wVirtualKeyCode;
                keycode2 = inRec.Event.KeyEvent.uChar.AsciiChar;
                return CCT_KEYBOARD_EVENT;
            }
        }
    }
    return 0; // 理论上不会走到这里
}