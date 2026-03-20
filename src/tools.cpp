#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "magic_ball.h"
#include "cmd_console_tools.h"
#include <string.h>
using namespace std;


void shuru(int* hang, int* lie)
{
    while (true)
    {
        cout << "请输入行数(5-9):" << endl;
        cin >> *hang;
        cin.clear();
        cin.ignore(65535, '\n');
        if (cin.fail() || *hang > 9 || *hang < 5)
        {
            continue;
        }
        break;
    }

    while (true)
    {
        cout << "请输入列数(5-9):" << endl;
        cin >> *lie;
        cin.clear();
        cin.ignore(65535, '\n');
        if (cin.fail() || *lie > 9 || *lie < 5)
        {
            continue;
        }
        break;
    }

}


void end()
{
    cout << endl;
    int x, y;
    cct_getxy(x, y);
    const int xx = x, yy = y;
    cct_gotoxy(xx, yy);
    cout << "本小题结束，请输入End继续...";
    while (1)
    {
        char input[100];
        int i = 0;
        do
        {
            input[i] = cin.get(); // 读取一个字符
        }while (input[i++] != '\n' && i < 99); 
        input[i] = '\0'; // 替换换行符为字符串终止符

        if ((input[0] == 'e'||input[0]=='E') && (input[1] == 'n' ||input[1]=='N') && (input[2] == 'd'||input[2]=='D'))
            break;  // 如果输入为end，则结束循环
        else
        {          
            cout << "输入错误，请重新输入";

            cct_gotoxy(0, yy);
            cout << "本小题结束，请输入End继续...                                                                          ";
            cct_gotoxy(0, yy);
            cout << "本小题结束，请输入End继续...";
        }
    }
    cct_cls();   
}