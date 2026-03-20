#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "magic_ball.h"
#include "cmd_console_tools.h"
#include <string.h>
using namespace std;

void kuangjia(int arr[13][13], int hang, int lie, int fan, int countt, int *fenshu)
{
    bool markers[13][13] = { 0 }; 
    biaoji(arr, hang, lie, fan, markers);

    if (fan == 4 || fan == 5)
    {
        cout << endl;
        cout << "按回车键显示图形..." << endl;
        while (1)
        {
            char ch = _getch();
            if (ch == 13)                      
                break;      
        }
    }
    if (countt == 0)
        cct_cls();
        
    bool mar = false;
    if (fan == 4||fan==6)
    {
        cct_setconsoleborder(40, hang + 6, 120, 9000);
        cct_setfontsize("新宋体", 36); 
        cct_gotoxy(0, 0);
        if(fan==4)
            cout << "屏幕:" << hang + 6 << "行40列" << endl;
        if (fan == 6)
            fan6(arr,  markers, hang, lie,  fan,&mar,countt);
        wukuang(arr, hang, lie, fan,markers);
    }
    if (fan == 5)
    {
        cct_setconsoleborder(40, 2*hang + 5, 120, 9000);
        cct_setfontsize("新宋体", 32); 
        cct_gotoxy(0, 0);       
        cout << "屏幕:" << 2 * hang + 5 << "行40列" << endl;
        wukuang(arr, hang, lie, fan,markers);
    }
    if (fan == 7||fan==8||fan==9)
    {
        int count = 0;
        if(countt==0)
            cct_setconsoleborder(40, 2 * hang + 5, 120, 9000);
        while (1)
        {
            mar = false;           
            cct_setfontsize("新宋体", 32); 
            cct_gotoxy(0, 0);
            bool markers[13][13] = { 0 }; 
            biaoji(arr, hang, lie, fan, markers);
            fan6(arr, markers, hang, lie, fan, &mar,countt);          
            if (count == 0 && countt == 0)
                wukuang(arr, hang, lie, fan, markers);         
            else            
                o_no(arr, markers, hang, lie, fan);     
            fan7(arr, markers, hang, lie, fan, &mar, countt,fenshu);
            if (mar == false)
                break;
            count++;        
        }       
    }
}

void wukuang(int arr[13][13], int hang, int lie, int fan,bool markers[13][13])
{
    char a1[] = "╔";
    char a2[] = "╗";
    char a3[] = "╚";
    char a4[] = "╝";
    char b1[] = "═";
    char b2[] = "║";
    char c1[] = "╦";
    char c2[] = "╩";
    char c3[] = "╠";
    char c4[] = "╣";
    char c5[] = "╬";

    if (fan == 4||fan==6)
    {
        for (int i = 0; i < hang + 2; i++)
        {
            for (int j = 0; j < lie + 2; j++)
            {
                cct_setcolor(15, 0);
                if (i == 0)
                {
                    if (j == 0)
                        cout << a1;                    
                    else if (j == lie + 1)
                        cout << a2 << endl;                               
                    else
                        cout << b1;
                }
                else if (i == hang + 1)
                {
                    if (j == 0)
                        cout << a3;                    
                    else if (j == lie + 1)
                        cout << a4;                             
                    else
                        cout << b1;
                }
                else
                {
                    if (j == 0)
                        cout << b2;
                    else if (j == lie + 1)
                        cout << b2 << endl;
                    else
                    {
                        cct_setcolor(0, 7);
                        cout << "  ";
                        cct_setcolor(15, 0);
                    }
                }
                if (fan == 4)
                    Sleep(1);
                cct_setcolor(0, 7);
            }
        }
        qiu(arr, hang, lie, fan,markers);
    }
    if (fan == 5||fan==7||fan==8||fan==9)
    {
        kuang(hang, lie, fan, a1, a2, a3, a4, b1, b2, c1, c2, c3, c4, c5);
        qiu(arr, hang, lie, fan,markers);
    }
        
}

void kuang(int hang, int lie, int fan, char a1[], char a2[], char a3[], char a4[], char b1[], char b2[], char c1[], char c2[], char c3[], char c4[], char c5[])
{
    for (int i = 0; i < 2*hang + 1; i++)
    {
        for (int j = 0; j < 2*lie + 1; j++)
        {
            cct_setcolor(15, 0);
            if (i == 0)
            {
                if (j == 0)
                    cout << a1;                    
                else if (j == 2 * lie)
                    cout << a2 << endl;
                else if (j == 2 || j == 4 || j == 6 || j == 8 || j == 10 || j == 12 || j == 14 || j == 16)
                    cout << c1;
                else
                    cout << b1;
            }
            else if (i == 2*hang)
            {
                if (j == 0)
                    cout << a3;                    
                else if (j == 2 * lie)
                    cout << a4;     
                else if (j == 2 || j == 4 || j == 6 || j == 8 || j == 10 || j == 12 || j == 14 || j == 16)
                    cout << c2;
                else
                    cout << b1;
            }
            else if(i==1|| i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15 || i == 17 )
            {
                if (j==0||j == 2 || j == 4 || j == 6 || j == 8 || j == 10 || j == 12 || j == 14 || j == 16||j==18)
                    cout << b2;
                else                                    
                    cout << "  ";                  
                if (j == 2 * lie)
                    cout << endl;
            }
            else
            {
                if (j == 0)
                    cout << c3;                    
                else if (j == 2 * lie)
                    cout << c4;
                else if(j == 2 || j == 4 || j == 6 || j == 8 || j == 10 || j == 12 || j == 14 || j == 16)
                    cout << c5;
                else
                    cout << b1;
                if (j == 2 * lie)
                    cout << endl;
            }
            if(fan==5)
                Sleep(1);
            cct_setcolor(0, 7);
        }
    }
}

void qiu(int arr[13][13], int hang, int lie, int fan, bool markers[13][13])
{
    char a[] = "〇";
    char b[] = "●";
    char c[] = "◎";
    
    
    for (int i = 0; i < hang ; i++)
    {
        if (fan == 4||fan==6)
        {
            cct_gotoxy(2, 2 + i);
            for (int j = 0; j < lie; j++)
            {
                cct_setcolor(arr[i + 2][j + 2]+5, 0);
                if (markers[i + 2][j + 2] == true&&fan==6)
                    cout << b;
                else
                    cout << a;
                if(fan==4)
                    Sleep(1);
            }
        }
        if (fan == 5||fan==7||fan==8||fan==9)
        {           
            for (int j = 0; j < lie; j++)
            {
                cct_gotoxy(2+4*j, 2 + 2 * i);
                cct_setcolor(arr[i + 2][j + 2]+5, 0);
                if (markers[i + 2][j + 2] == true && (fan == 7||fan==8 || fan == 9))
                    cout << b;
                else
                    cout << a;
                if (fan == 5)
                    Sleep(1);
            }
        }
        cout << endl;
    }
    cct_setcolor(0, 7);
}

void fan6(int arr[13][13],bool markers[13 ][13],int hang, int lie, int fan,bool *mar,  int countt)
{
    
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < lie; j++)
        {
            if (markers[i + 2][j + 2] == true)
                *mar = true;
        }
    }
    if (*mar == false)
    {
        if(fan==6)
            cout << "屏幕:" << hang + 6 << "行40列(未找到初始可消除项)" << endl;
        if(fan==7)
            cout << "屏幕:" << 2 * hang + 5 << "行40列(未找到初始可消除项)" << endl;
        if (fan == 8)
            cout << "屏幕:" << 2 * hang + 5 << "行40列(当前分数：0 右键退出)" << endl;
        if (fan == 9&&countt==0)
            cout << "屏幕:" << 2 * hang + 5 << "行40列(当前分数：0 右键退出)" << endl;
    }
        
    else
    {
        if (fan == 6)
            cout << "屏幕:" << hang + 6 << "行40列" << endl;
        if (fan == 7||fan==8 || fan == 9)
            cout << "屏幕:" << 2 * hang + 5 << "行40列" << endl;
    }
}

void fan7(int arr[13][13], bool markers[13][13], int hang, int lie, int fan, bool *mar, int countt,int *fenshu)
{
    
    if (*mar == true)
    {
        if (fan == 7)
        {
            cct_gotoxy(0, 2 * hang + 2);
            cout << "按回车键进行消除及下落除0操作...";
            while (1)
            {
                char ch = _getch();
                if (ch == 13)
                    break;
            }
        }   
        *fenshu+=xialuo_2(arr, markers, hang, lie, fan,*fenshu, countt);

        if (fan == 7)
        {
            cct_gotoxy(0, 2 * hang + 2);
            cout << "按回车键进行新值填充...          ";
            while (1)
            {
                char ch = _getch();
                if (ch == 13)
                    break;
            }
        }
        tianchong_2(arr, markers, hang, lie, fan);
    }
    
    if (*mar == false)
    {
        if (fan == 7)
        {
            cct_gotoxy(0, 2 * hang + 2);
            cout << "按回车键显示消除提示...          ";
            while (1)
            {
                char ch = _getch();
                if (ch == 13)
                    break;
            }
        }
        xiaochu_tishi(arr, hang, lie, fan,countt,fenshu);
    }
    if (fan == 7)
    {
        cct_gotoxy(0, 2 * hang + 2);
        cout << "                                   ";
    }
}

int xialuo_2(int arr[13][13], bool markers[13][13], int hang, int lie, int fan,int fenshu,int countt)
{
    int t = 0;
    xinqiu(arr, markers, hang, lie, fan);
    for (int i = 0; i <= hang; i++)
    {
        for (int j = 0; j <= lie; j++)
        {
            if (markers[i + 2][j + 2] == true)
            {
                arr[i + 2][j + 2] = 0; 
                if(countt!=0)
                    t++;
            }
        }
    }

    xialuo_qiu(arr, markers, hang, lie, fan);
    return t;
}

void tianchong_2(int arr[13][13], bool markers[13][13], int hang, int lie, int fan)
{
    char a[] = "〇";
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < lie; j++)
        {
            if (markers[i + 2][j + 2] == true)
            {
                arr[i + 2][j + 2] = 1 + rand() % 9;
                cct_setcolor(arr[i + 2][j + 2] + 5, 0);
                cct_gotoxy(2 + 4 * j, 2 + 2 * i);
                cout << a;
                cct_setcolor(0, 7);
                Sleep(200);
            }
        }
    }

}

void xinqiu(int arr[13][13], bool markers[13][13], int hang, int lie, int fan)
{
    char a[] = "〇";
    char d[] = "¤";
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < lie; j++)
        {
            if (markers[i + 2][j + 2] == true)
            {
                for (int m = 0; m < 5; m++)
                {                   
                    cct_setcolor(arr[i + 2][j + 2] + 5, 0);
                    cct_gotoxy(2 + 4 * j, 2 + 2 * i);
                    cout << d;
                    Sleep(50);
                    cct_gotoxy(2 + 4 * j, 2 + 2 * i);
                    cout << a;
                    Sleep(50);
                }
                cct_gotoxy(2 + 4 * j, 2 + 2 * i);
                cct_setcolor(15, 15);
                cout << "  ";
                cct_setcolor(0, 7);
            }
        }
    }
}

void xialuo_qiu(int arr[13][13], bool markers[13][13], int hang, int lie, int fan)
{
    char a[] = "〇";
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j <lie; j++)
        {
            if (markers[i + 2][j + 2] == true)
            {
                for (int m = i; m > 0; m--)
                {
                    if (arr[m + 2][j + 2] < arr[m + 2 - 1][j + 2])
                    {
                        int t = arr[m + 2][j + 2];
                        arr[m + 2][j + 2] = arr[m + 2 - 1][j + 2];
                        arr[m + 2 - 1][j + 2] = t;
                        markers[m + 2][j + 2] = false;
                        markers[m + 2 - 1][j + 2] = true;
                        cct_gotoxy(2 + 4 * j, 2 + 2 * m);       
                        cct_setcolor(arr[m+2][j + 2] + 5, 0);            
                        cout << a;
                        cct_gotoxy(2 + 4 * j,  2 * m);
                        cct_setcolor(15, 15);
                        cout << "  ";
                        cct_setcolor(0, 7);
                        Sleep(150);
                    }
                }
            }
        }
    }
}

void xiaochu_tishi(int arr[13][13], int hang, int lie, int fan, int countt, int *q)
{
    char a[] = "〇";
    char c[] = "◎";
    bool tishi[13][13] = { 0 }; 
    sisan(arr, tishi, hang, lie, fan);
    er(arr, tishi, hang, lie, fan);
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < lie; j++)
        {
            if (tishi[i+2][j+2] == true)
            {
                cct_gotoxy(2 + 4 * j, 2 + 2 * i);
                cct_setcolor(arr[i + 2][j + 2] + 5, 0);
                cout << c;
                cct_setcolor(0, 7);
            }
        }
    }
    if(fan==8||fan==9)
        if(countt==0)
            fan8(arr, tishi, hang, lie, fan,countt,q);
}

void o_no(int arr[13][13],bool markers[13][13], int hang, int lie, int fan)
{
    char b[] = "●";
    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < lie; j++)
        {
            if (markers[i + 2][j + 2] == true)
            {
                cct_gotoxy(2 + 4 * j, 2 + 2 * i);
                cct_setcolor(arr[i + 2][j + 2] + 5, 0);
                cout << b;
                cct_setcolor(0, 7);
            }
        }
    }
}

void fan8(int arr[13][13], bool tishi[13][13], int hang, int lie, int fan, int countt, int *fenshu)
{
    countt++;
    char oo = 'A';
    int X = 0, Y = 0;
    int ret, maction;
    int keycode1, keycode2;
    int loop = 1;
    cct_enable_mouse();
    bool xuan_ = false;
    bool biaojier[13][13] = { 0 };

    while (loop)
    {
        for (int i = 0; i < hang; i++)
            for (int j = 0; j < lie; j++)
                tishi[2 + i][2 + j] = false;
        sisan(arr, tishi, hang, lie, fan);
        er(arr, tishi, hang, lie, fan);

        bool tuichu=chaa(arr, tishi, biaojier, hang, lie, fan, fenshu);
        if (tuichu == false)
            break;

        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        if (ret == CCT_MOUSE_EVENT)
        {
            bool feifa = false;
            cct_gotoxy(0, 2 + 2 * hang);
            cout << "[当前光标] ";
            if (Y > 2 * hang)       
                cout << "位置非法";
            else if (Y == 0 || Y % 2 == 1)
                cout << "位置非法";                          
            else if(X>4*lie-1||X==0)
                cout << "位置非法";
            else if(X%4==0||X%4==1)
                cout << "位置非法";
            else
            {
                cout << char(oo - 1 + Y / 2) << "行" << (X + 2) / 4 << "列  ";
                feifa = true;
            }
            switch (maction)
            {
                case MOUSE_LEFT_BUTTON_CLICK:
                    if (feifa == true)
                    {
                        if (tishi[1 + Y / 2][1 + (X + 2) / 4] == true)
                        {
                            cct_gotoxy(0, 2 + 2 * hang);
                            cout <<"当前选择"<< char(oo - 1 + Y / 2) << "行" << (X + 2) / 4 << "列  ";
                            if(fan==9)
                                Sleep(150);
                            else
                                Sleep(1000);
                            if (fan == 9 && biaojier[1 + Y / 2][1 + (X + 2) / 4] == false && biaojier[1 + 1 + Y / 2][1 + (X + 2) / 4] == false && biaojier[1 - 1 + Y / 2][1 + (X + 2) / 4] == false && biaojier[1 + Y / 2][1 + 1 + (X + 2) / 4] == false && biaojier[1 + Y / 2][1 - 1 + (X + 2) / 4] == false)
                                biao_all_false(arr, tishi, biaojier, hang, lie, fan, X, Y, &xuan_);
                            else if (fan == 9 && biaojier[1 + Y / 2][1 + (X + 2) / 4] == true)                    
                                biao_zishen(arr, tishi, biaojier, hang, lie, fan, X, Y, &xuan_);
                            else if (fan == 9 && (biaojier[1 + 1 + Y / 2][1 + (X + 2) / 4] == true || biaojier[1 - 1 + Y / 2][1 + (X + 2) / 4] == true || biaojier[1 + Y / 2][1 + 1 + (X + 2) / 4] == true || biaojier[1 + Y / 2][1 - 1 + (X + 2) / 4] == true))                                                     
                                biao_panduan(arr, tishi, biaojier, hang, lie, fan, X, Y, &xuan_,countt,fenshu);
                            else if(fan==8)
                                xuan_ = true;
                            break;
                        }
                        else
                        {
                            cct_gotoxy(0, 2 + 2 * hang);
                            cout << "不能选择" << char(oo - 1 + Y / 2) << "行" << (X + 2) / 4 << "列  ";
                            Sleep(200);
                            break;
                        }
                    }
                case MOUSE_RIGHT_BUTTON_CLICK:
                    if (feifa == true)                     
                        xuan_ = true;
                    break;              
            }
            if (xuan_ == true)
            {
                cct_gotoxy(0, 2 + 2 * hang);
                cout << "                                  " ;
                break;
            }           
        }
    }
}

void fan9(int arr[13][13], bool tishi[13][13], bool biaojier[13][13], int hang, int lie, int fan, int x, int y, int *fenshu)
{
    cct_gotoxy(0, 0);
    cout << "屏幕:" << 2 * hang + 5 << "行40列(当前分数：" << *fenshu << " 右键退出)" << endl;
}

void biao_zishen(int arr[13][13], bool tishi[13][13], bool biaojier[13][13], int hang, int lie, int fan, int x, int y, bool* xuan_)
{
    char c[] = "◎";
    cct_setcolor(arr[1 + y / 2][1 + (x + 2) / 4] + 5, 0);
    cct_gotoxy(2 + 4 * ((x + 2) / 4 - 1), 2 + 2 * (y / 2 - 1));
    cout << c;
    cct_setcolor(0, 7);
    biaojier[1 + y / 2][1 + (x + 2) / 4] = false;
}

void biao_panduan(int arr[13][13], bool tishi[13][13], bool biaojier[13][13], int hang, int lie, int fan, int x, int y, bool* xuan_, int countt, int *fenshu)
{
    char c[] = "◎";
    biaojier[1 + y / 2][1 + (x + 2) / 4] = true;
    int arr_choice[13][13] = { 0 };
    for (int i = 0; i < hang; i++)
        for (int j = 0; j < lie; j++)
            arr_choice[2 + i][2 + j] = arr[2 + i][2 + j];
    int n;
    char m, oo = 'A';
    if (biaojier[1 + 1 + y / 2][1 + (x + 2) / 4] == true)
    {
        m = oo - 1 + y / 2+1;
        n = (x + 2) / 4;
        int p = arr_choice[1 + 1 + y / 2][1 + (x + 2) / 4];
        arr_choice[1 + 1 + y / 2][1 + (x + 2) / 4] = arr_choice[1 + y / 2][1 + (x + 2) / 4];
        arr_choice[1 + y / 2][1 + (x + 2) / 4] = p;
    }
    if (biaojier[1 - 1 + y / 2][1 + (x + 2) / 4] == true)
    {
        m = oo - 1 + y / 2 -1;
        n = (x + 2) / 4;
        int p = arr_choice[1 - 1 + y / 2][1 + (x + 2) / 4];
        arr_choice[1 - 1 + y / 2][1 + (x + 2) / 4] = arr_choice[1 + y / 2][1 + (x + 2) / 4];
        arr_choice[1 + y / 2][1 + (x + 2) / 4] = p;
    }
    if (biaojier[1  + y / 2][1 +1+ (x + 2) / 4] == true)
    {
        m = oo - 1 + y / 2 ;
        n = 1+(x + 2) / 4;
        int p = arr_choice[1 + y / 2][1 + 1+(x + 2) / 4];
        arr_choice[1  + y / 2][1 +1+ (x + 2) / 4] = arr_choice[1 + y / 2][1 + (x + 2) / 4];
        arr_choice[1 + y / 2][1 + (x + 2) / 4] = p;
    }
    if (biaojier[1 + y / 2][1 -1+ (x + 2) / 4] == true)
    {
        m = oo - 1 + y / 2 ;
        n = (x + 2) / 4-1;
        int p = arr_choice[1  + y / 2][1 -1+ (x + 2) / 4];
        arr_choice[1 + y / 2][1 -1+ (x + 2) / 4] = arr_choice[1 + y / 2][1 + (x + 2) / 4];
        arr_choice[1 + y / 2][1 + (x + 2) / 4] = p;
    }
    bool mar_choice = false;
    bool markers_choice[13][13] = { 0 }; 
    biaoji(arr_choice, hang, lie, fan, markers_choice);
    for (int i = 0; i < hang; i++)   
        for (int j = 0; j < lie; j++)       
            if (markers_choice[i + 2][j + 2] == true)
                mar_choice = true;
    if (mar_choice == true)
    {       
        for (int i = 0; i < hang; i++)
            for (int j = 0; j < lie; j++)
                if (arr_choice[i + 2][j + 2] != arr[i + 2][j + 2])
                    arr[i + 2][j + 2] = arr_choice[i + 2][j + 2];

        huan(arr, markers_choice, tishi, biaojier, hang, lie, fan, x, y,m,n,countt,fenshu);
        fan9(arr, tishi, biaojier, hang, lie, fan, x, y, fenshu);
    }
    else
    {
        cct_gotoxy(0, 2 + 2 * hang);
        cout << "不能交换"<<char(m)<<"行"<<n<<"列 <=> "<< char(oo - 1 + y / 2)<<"行"<< (x + 2) / 4<<"列";
        Sleep(1500);
        cct_gotoxy(0, 2 + 2 * hang);
        cout << "                                                        ";
    }
    for (int i = 0; i < hang; i++)
        for (int j = 0; j < lie; j++)                                  
            if (biaojier[2 + i][2 + j] == true)
            {
                if (mar_choice == false)
                {
                    cct_gotoxy(2 + 4 * j, 2 + 2 * i);
                    cct_setcolor(arr[i + 2][j + 2] + 5, 0);
                    cout << c;
                    cct_setcolor(0, 7);
                }
                biaojier[2 + i][2 + j] = false;
            }
}

void huan(int arr[13][13], bool markers_choice[13][13], bool tishi[13][13], bool biaojier[13][13], int hang, int lie, int fan, int x, int y,char m,int n, int countt, int *fenshu)
{
    char a[] = "〇";
    char c[] = "◎";
    char oo = 'A';

    for(int i=0;i<hang;i++)
        for (int j = 0; j < lie; j++)
        {
            if (tishi[i + 2][j + 2] == true)
            {
                cct_gotoxy(2 + 4 * j, 2 + 2 * i);
                cct_setcolor(arr[i + 2][j + 2] + 5, 0);
                cout << a;
                cct_setcolor(0, 7);
            }
        }
    bool mar_meiyong = true;   
    kuangjia(arr, hang, lie, fan ,countt,fenshu);
}

void biao_all_false(int arr[13][13], bool tishi[13][13], bool biaojier[13][13], int hang, int lie, int fan, int x, int y, bool* xuan_)
{
    char c[] = "◎";
    for (int i = 0; i < hang; i++)
        for (int j = 0; j < lie; j++)
        {
            if (biaojier[2 + i][2 + j] == true)
            {
                cct_gotoxy(2 + 4 * j, 2 + 2 * i);
                cct_setcolor(arr[i + 2][j + 2] + 5, 0);
                cout << c;
                cct_setcolor(0, 7);
                biaojier[2 + i][2 + j] = false;
            }
        }
    cct_setcolor(arr[1 + y / 2][1 + (x + 2) / 4] + 5, 15);
    cct_gotoxy(2 + 4 * ((x + 2) / 4 - 1), 2 + 2 * (y / 2 - 1));
    cout << c;
    cct_setcolor(0, 7);

    biaojier[1 + y / 2][1 + (x + 2) / 4] = true;
}

bool chaa(int arr[13][13], bool tishi[13][13], bool biaojier[13][13], int hang, int lie, int fan, int* fenshu)
{
    bool youma = false;
    for (int i = 0; i < hang; i++)
        for (int j = 0; j < lie; j++)
            if (tishi[2 + i][2 + j] == true)
                youma = true;

    if (youma == false)
    {
        cct_gotoxy(0, 0);
        cout << "无可消除项，游戏结束! 最终分数：" << *fenshu << ")       ";       
        cct_gotoxy(0, 2 * hang + 1);
    }
    return youma;
}