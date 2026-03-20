#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "magic_ball.h"
#include "cmd_console_tools.h"
#include <string.h>
using namespace std;

int main()
{	
	int hang=0, lie=0;
	while (1)
	{
		int fan = menu();//拿到返回值
	
		if (fan == 0)
		{
			cct_gotoxy(0, 20);
		    return 0;
		}
		cct_cls();
		
		if (fan == 1 || fan == 2 || fan == 3 || fan == 4 || fan==5||fan == 6 || fan == 7 || fan == 8 || fan == 9)
		{
			shuru(&hang, &lie);
		}
		if (fan == 1 || fan == 2 || fan == 3)
		{
			shuzuban(hang, lie, fan);
		}
		if (fan == 4 || fan == 5 || fan == 6||fan == 7 || fan == 8 || fan == 9)
		{
			shuzuban(hang, lie, fan);
		}
		

		end();
		/*cout << endl;
		cout << "按回车键继续";
		while (1)
		{
			char ch = _getch();
			if (ch == 13)
			{
				cct_cls();
				break;
			}
		}
		*/
	}


	return 0;



}