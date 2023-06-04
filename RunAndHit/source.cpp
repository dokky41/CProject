#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "StartHeader.h"
#include "MainGame.h"
#include "MainSound.h"


int main()
{
	//πË∞Ê¿Ωæ«
	//playingBgm();
	system("mode con cols=164 lines=43 | title 2km");
	CursorView();
	StartMenu();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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