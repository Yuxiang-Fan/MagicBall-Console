/* * 终端伪图形界面工具库头文件
 * 根据 MagicBall 项目中对于控制台的光标、颜色、鼠标事件、字体设置等调用逆向还原。
 */
#pragma once
#ifndef CMD_CONSOLE_TOOLS_H
#define CMD_CONSOLE_TOOLS_H

// --- 颜色宏定义 (基于 Windows 控制台标准颜色码 0-15) ---
#define COLOR_BLACK     0
#define COLOR_BLUE      1
#define COLOR_GREEN     2
#define COLOR_CYAN      3
#define COLOR_RED       4
#define COLOR_MAGENTA   5
#define COLOR_YELLOW    6
#define COLOR_WHITE     7
#define COLOR_HGRAY     8
#define COLOR_HBLUE     9   // 亮蓝色 (代码中使用的常量)
#define COLOR_HGREEN    10
#define COLOR_HCYAN     11
#define COLOR_HRED      12
#define COLOR_HMAGENTA  13
#define COLOR_HYELLOW   14  // 亮黄色 (代码中使用的常量)
#define COLOR_HWHITE    15

// --- 事件类型宏定义 ---
#define CCT_MOUSE_EVENT    1
#define CCT_KEYBOARD_EVENT 2

// --- 鼠标动作宏定义 ---
#define MOUSE_LEFT_BUTTON_CLICK    1
#define MOUSE_RIGHT_BUTTON_CLICK   2
#define MOUSE_LEFT_BUTTON_DOUBLE_CLICK 3

// --- 控制台基础操作 ---

// 清空当前控制台屏幕的内容 [cite: 509]
void cct_cls();

// 将光标移动到指定的列 (x) 和行 (y) [cite: 425]
void cct_gotoxy(int x, int y);

// 获取当前光标位置，通过引用修改传入的 x 和 y 变量 [cite: 552]
void cct_getxy(int &x, int &y);

// 设置控制台的前景色 (textcolor) 和背景色 (bgcolor)。
// 默认参数用于恢复控制台初始状态 (例如 7 为白字，0 为黑底) 
void cct_setcolor(int textcolor = 7, int bgcolor = 0);

// 设置控制台窗口可视大小及缓冲区大小 (单位为字符)
void cct_setconsoleborder(int width, int height, int bufferWidth, int bufferHeight);

// 设置控制台的字体类型 (如 "新宋体") 和字号大小
void cct_setfontsize(const char* fontName, int size);

// --- 键鼠交互操作 ---

// 启用鼠标事件捕获机制 [cite: 587]
void cct_enable_mouse();

// 读取键盘或鼠标的交互事件 
// 返回值: 代表事件类型的整型 (如 CCT_MOUSE_EVENT)
// x, y: 引用传递，返回触发事件时鼠标所在的列和行
// maction: 引用传递，返回鼠标动作 (如 MOUSE_LEFT_BUTTON_CLICK) [cite: 582]
// keycode1, keycode2: 引用传递，记录键盘输入的键码
int cct_read_keyboard_and_mouse(int &x, int &y, int &maction, int &keycode1, int &keycode2);

#endif // CMD_CONSOLE_TOOLS_H