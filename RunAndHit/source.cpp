#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "StartHeader.h"
#include "MainGame.h"


int main()
{
	system("mode con cols=164 lines=43 | title pickPocket");
	CursorView();
	StartMenu();

		while (1) 
		{

			if (GetAsyncKeyState(VK_RETURN))
			{
				PlaySound(TEXT("coin.wav"), NULL, SND_ASYNC); 
				Sleep(1000);
				system("cls");
				GameStart2();

			}
			
		


			
		};
	


	return 0;
}