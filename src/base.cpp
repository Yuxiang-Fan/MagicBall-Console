#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "magic_ball.h"
#include "cmd_console_tools.h"
#include <string.h>
using namespace std;

void suiji(int hang, int lie, int fan, int arr[13][13])
{
    srand((unsigned int)(time(0)));

    for (int i = 0; i < hang; i++)
    {
        for (int j = 0; j < lie; j++)
        {
            arr[i + 2][j + 2] = 1 + rand() % 9;
        }
    }
    if (fan == 1 || fan == 2 || fan == 3 || fan == 4 || fan == 5)
    {
        cout << endl;
        cout << "初始数组:" << endl;
        dayin(arr, hang, lie);
    }

    if (fan == 1 || fan == 2 || fan == 3)
    {
        cout << endl;
        cout << "按回车键进行寻找初始可消除项的操作..." << endl;
        while (1)
        {
            char ch = _getch();
            if (ch == 13)
                break;
        }
    }
}

void shuzuban(int hang, int lie, int fan)
{
    int arr[13][13] = { 0 };
    suiji(hang,  lie,  fan, arr);
    
    if (fan == 1)
        chushi(hang, lie, fan, arr);
    if (fan == 2 || fan == 3)
    {
        while (1)
        {
            bool o = chushi(hang, lie, fan, arr);
            if (o == false)
                break;
        }       
    }
    if (fan == 3)
    {
        fan3(arr,  hang, lie, fan);
    }
    if (fan == 4|| fan == 5 || fan==6||fan == 7 || fan == 8 || fan == 9 )
    {
        int fenshu = 0;
        int countt = 0;
        kuangjia(arr, hang, lie, fan, countt, &fenshu);
    }
}

bool chushi(int hang, int lie, int fan,int arr[13][13])
{
    bool what = truema(arr, hang, lie);
    if (what == true)
    {
        if (fan == 2||fan==3)
            cout << endl;
        cout << "初始可消除项（不同色标识）：" << endl;
        bool markers[13][13] = { 0 }; 
        biaoji(arr, hang, lie, fan, markers);
        if (fan == 2||fan==3)
            fan2(arr, markers, hang, lie, fan);
        return 1;
    }
    else
    {
        if (fan == 2||fan==3)
            cout << endl;
        cout << "初始已无可消除项" << endl; 
        return 0;
    }
}

void dayin(int arr[13][13], int hang,int lie)
{
    cout << "  |  ";
    for (int i = 0; i < lie; i++)
        cout << i + 1 << "  ";
    cout << endl;

    cout << "--+-";
    for (int i = 0; i < lie; i++)
        cout << "---";
    cout << endl;

    char zimu[9] = { '\0' };
    for (int i = 0; i < hang; i++)
    {
        zimu[i] = 'A' + i;
    }

    for (int i = 0; i < hang; i++)
    {
        cout << zimu[i] << " |  ";
        for (int j = 0; j < lie; j++)
        {
            cout << arr[i + 2][j + 2] << "  ";
            if (j == lie - 1)
            {
                cout << endl;
            }
        }
    }
}

bool truema(int arr[13][13],int hang,int lie)
{
    
    for (int i = 0; i < hang ; i++)
        for (int j = 0; j < lie ; j++)
        {
            int count = 1;
            while (arr[i+2][j+2] == arr[i+2 + count][j+2])
                count++;
            if (count >= 3)
                return true;            
        }

    for (int i = 0; i < hang ; i++)
        for (int j = 0; j < lie ; j++)
        {
            int count = 1;
            while (arr[i + 2][j + 2] == arr[i + 2 ][j + 2 + count])
                count++;
            if (count >= 3)
                return true;
        }
    return false;
}

void biaoji(int arr[13][13], int hang, int lie,int fan,bool markers[13][13])
{
    
    for (int i = 0; i < hang ; i++)
        for (int j = 0; j < lie ; j++)
        {
            int count = 1;
            while (arr[i + 2][j + 2] == arr[i + 2 + count][j + 2])
                count++;
            if (count >= 3)
                for (int k = 0; k < count; k++) 
                {
                    markers[i+2+k][j +2] = true; 
                }
        }

    for (int i = 0; i < hang ; i++)
        for (int j = 0; j < lie ; j++)
        {
            int count = 1;
            while (arr[i + 2][j + 2] == arr[i + 2][j + 2 + count])
                count++;
            if (count >= 3)
                for (int k = 0; k < count; k++)
                {
                    markers[i+2][j + 2+k] = true; 
                }
        }
    if(fan==1||fan==2||fan==3)
        yanse(arr, markers, hang, lie, fan);
}

void yanse(int arr[13][13], bool markers[13][13], int hang, int lie,int fan)
{
    cout << "  |  ";
    for (int i = 0; i < lie; i++)
        cout << i + 1 << "  ";
    cout << endl;

    cout << "--+-";
    for (int i = 0; i < lie; i++)
        cout << "---";
    cout << endl;

    char zimu[9] = { '\0' };
    for (int i = 0; i < hang; i++)
    {
        zimu[i] = 'A' + i;
    }

    for (int i = 0; i < hang; i++)
    {
        cout << zimu[i] << " |  ";
        for (int j = 0; j < lie; j++)
        {
            if (markers[i + 2][j + 2] == true)
            {
                if (arr[i + 2][j + 2] == 0)
                {
                    cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
                    cout << arr[i + 2][j + 2];
                }
                else
                {
                    cct_setcolor(COLOR_HYELLOW, COLOR_HBLUE);
                    cout << arr[i + 2][j + 2];
                }               
                cct_setcolor(0, 7);
            }
            else
                cout << arr[i + 2][j + 2];
            
            cout << "  ";
            if (j == lie - 1)
            {
                cout << endl;
            }
        }
    }
    
}

void fan2(int arr[13][13], bool markers[13][13], int hang, int lie, int fan)
{
    cout << endl;
    cout << "按回车键进行数组下落除0操作..."<< endl;   
    while (1)
    {
        char ch = _getch();
        if (ch == 13)
            break;
    }
    cout << "下落除0后的数组(不同色标识)：" << endl;
    xialuo(arr, markers, hang, lie, fan);

    cout << endl;
    cout << "按回车键进行新值填充..." << endl;
    while (1)
    {
        char ch = _getch();
        if (ch == 13)
            break;
    }
    cout << "新值填充后的数组(不同色标识)：" << endl;
    tianchong(arr, markers, hang, lie, fan);

}

void xialuo(int arr[13][13], bool markers[13][13], int hang, int lie, int fan)
{
    for (int i = 1; i <= hang; i++)
    {
        for (int j = 1; j <= lie; j++)
        {
            if (markers[i+1][j+1] == true)
            {
                arr[i+1][j+1] = 0;
            }
        }
    }

    for (int i = 1; i <= hang; i++)
    {
        for (int j = 1; j <= lie; j++)
        {
            if (markers[i+1][j+1] == true)
            {               
                for (int m = i; m > 1; m--)
                {
                    if (arr[m+1][j+1] < arr[m+1 - 1][j+1])
                    {
                        int t = arr[m+1][j+1];
                        arr[m+1][j+1] = arr[m+1-1][j+1];
                        arr[m+1-1][j+1] = t;
                        markers[m+1][j+1] = false;
                        markers[m+1-1][j+1] = true;
                    }
                }
            }
        }
    }
    if(fan==1||fan==2||fan==3)
        yanse(arr, markers, hang, lie, fan);
}

void tianchong(int arr[13][13], bool markers[13][13], int hang, int lie, int fan)
{
    for (int i = 1; i <= hang; i++)
    {
        for (int j = 1; j <= lie; j++)
        {
            if (markers[i+1][j+1] == true)
            {
                arr[i+1][j+1] = 1 + rand() % 9;
            }
        }
    }
    yanse(arr, markers, hang, lie, fan);
}

void fan3(int arr[13][13], int hang, int lie, int fan)
{
    cout << endl;
    cout << "可选择的消除提示（不同色标识）：" << endl;
    bool tishi[13][13]= { 0 }; 
    sisan(arr, tishi, hang, lie, fan);
    er(arr, tishi, hang, lie, fan);

    yanse(arr,tishi, hang, lie, fan);
}

void sisan(int arr[13][13], bool tishi[13][13], int hang, int lie, int fan)
{
    for (int i = 1; i <= hang; i++) 
    {
        for (int j = 1; j <= lie; j++) 
        {
            
            int up = arr[i+1 - 1][j+1]; 
            int down = arr[i+1 + 1][j+1]; 
            int left = arr[i+1][j+1 - 1]; 
            int right = arr[i+1][j+1 + 1]; 
            
            if ( down ==left  && down == right)
            {
                tishi[i+1][j+1] = true;
                tishi[i+1 + 1][j+1] = true;
            }
            else if (up == left && up == right)
            {
                tishi[i+1][j+1] = true;
                tishi[i+1 - 1][j+1] = true;
            }
            else if (right == up && down == right)
            {
                tishi[i+1][j+1] = true;
                tishi[i+1][j +1+ 1] = true;
            }
            else if (down == left && up == left)
            {
                tishi[i+1][j+1] = true;
                tishi[i+1][j+1 - 1] = true;
            }

            if (down == left && up == left && right == left)
            {
                tishi[i+1][j+1] = true;
                tishi[i+1][j+1 + 1] = true;
                tishi[i+1][j+1 - 1] = true;
                tishi[i+1 + 1][j+1] = true;
                tishi[i+1 - 1][j+1] = true;
            }
        }
    }
}

void er(int arr[13][13], bool tishi[13][13], int hang, int lie, int fan)
{
    
    for (int i = 2; i <= hang+1; i++) 
    {
        for (int j = 2; j <= lie+1; j++)
        {
            int center = arr[i][j]; 
            int up = arr[i - 1][j]; 
            int upup = arr[i - 2][j]; 
            int down = arr[i + 1][j]; 
            int downdown = arr[i + 2][j]; 
            int left = arr[i][j - 1]; 
            int leftleft = arr[i][j - 2]; 
            int right = arr[i][j + 1]; 
            int rightright = arr[i][j + 2]; 

            uptwo(tishi, i, j, fan, center, up, upup, down, downdown, left, leftleft, right, rightright);
            downtwo(tishi, i, j, fan, center, up, upup, down, downdown, left, leftleft, right, rightright);
            lefttwo(tishi, i, j, fan, center, up, upup, down, downdown, left, leftleft, right, rightright);
            righttwo(tishi, i, j, fan, center, up, upup, down, downdown, left, leftleft, right, rightright);           
        }
    }
    
}

void uptwo( bool tishi[13][13], int i, int j, int fan, int center, int up, int upup, int down, int downdown, int left, int leftleft, int right, int rightright)
{
    if (up == upup&&up!=0)
    {
        if (up == down)
        {
            tishi[i][j] = true;
            tishi[i + 1][j] = true;
            if (down == downdown)
                tishi[i - 1][j] = true;
        }
        if (up == left)
        {
            tishi[i][j] = true;
            tishi[i][j - 1] = true;
            if (left == leftleft)
                tishi[i - 1][j] = true;
        }
        if (up == right)
        {
            tishi[i][j] = true;
            tishi[i][j + 1] = true;
            if (right == rightright)
                tishi[i - 1][j] = true;
        }
    }
}

void downtwo(bool tishi[13][13], int i, int j, int fan, int center, int up, int upup, int down, int downdown, int left, int leftleft, int right, int rightright)
{
    if (down == downdown && down != 0)
    {
        if (up == down)
        {
            tishi[i][j] = true;
            tishi[i - 1][j] = true;
            if (up == upup)
                tishi[i + 1][j] = true;
        }
        if (down == left)
        {
            tishi[i][j] = true;
            tishi[i][j - 1] = true;
            if (left == leftleft)
                tishi[i + 1][j] = true;
        }
        if (down == right)
        {
            tishi[i][j] = true;
            tishi[i][j + 1] = true;
            if (right == rightright)
                tishi[i + 1][j] = true;
        }
    }
}

void lefttwo(bool tishi[13][13], int i, int j, int fan, int center, int up, int upup, int down, int downdown, int left, int leftleft, int right, int rightright)
{
    if (left == leftleft && left != 0)
    {
        if (left == right)
        {
            tishi[i][j] = true;
            tishi[i][j+1] = true;
            if (right == rightright)
                tishi[i][j-1] = true;
        }
        if (up == left)
        {
            tishi[i][j] = true;
            tishi[i-1][j] = true;
            if (up == upup)
                tishi[i][j - 1] = true;
        }
        if (left == down)
        {
            tishi[i][j] = true;
            tishi[i+1][j] = true;
            if (down == downdown)
                tishi[i][j - 1] = true;
        }
    }
}

void righttwo(bool tishi[13][13], int i, int j, int fan, int center, int up, int upup, int down, int downdown, int left, int leftleft, int right, int rightright)
{
    if (right == rightright && right != 0)
    {
        if (left == right)
        {
            tishi[i][j] = true;
            tishi[i][j - 1] = true;
            if (left == leftleft)
                tishi[i][j + 1] = true;
        }
        if (right ==up)
        {
            tishi[i][j] = true;
            tishi[i - 1][j] = true;
            if (up == upup)
                tishi[i][j + 1] = true;
        }
        if (right == down)
        {
            tishi[i][j] = true;
            tishi[i + 1][j] = true;
            if (down == downdown)
                tishi[i][j + 1] = true;
        }
    }
}