#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <windows.h>

// 음악
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>

#define ENTER 43
#define ESC 110
#define MAX 1000

void tleDraw() {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("##################################################################################################################################################################\n");
	for (int i = 0; i < 40; i++) 
	{ 
		printf("##                                                                                                                                                              ##\n"); 
                                                                                                                                                          
	}
	printf("##################################################################################################################################################################\n");

}

void gotoxy(int x, int y) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}



void menuDraw() 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	gotoxy(40, 10);
	printf("          ZZ           Z                                   BZ                 EZ");
	gotoxy(40, 11);
	printf("                       Z                                   jZ                 ZZ");
	gotoxy(40, 12);
	printf("9ZZZZZZ   ZZ   ZZZZZ5  Z   ZZz ZZZZZZZ    ZZZZZD   wZZZZZ  WZ   ZZW  ZZZZZE  ZZZZ5");
	gotoxy(40, 13);
	printf("WZy   ZZ  ZZ  ZZ   yZ  Z ,Z5   BZ,   ZZ  ZZ    ZZ  ZW   ZZ WZ BZ    ZE    ZZ  Z8");
	gotoxy(40, 14);
	printf("WZ     Z  ZZ ,Z        ZZZZ    BZ     Z  Z     EZ 8Z       wZZZZ   ,ZZZZZZZZ  ZZ");
	gotoxy(40, 15);
	printf("WZ     Z  ZZ ,Z     Z, Z  ZZ   BZ     Z  Z     ZZ zZ     Z wZ  ZZ   Z         ZZ");
	gotoxy(40, 16);
	printf("WZZ  WZZ  ZZ  ZZ   ZZ  Z   ZZ  DZZ  WZZ  ZZw  ZZy  ZZ   ZZ yZ   ZZ  ZZ5  wZZ  ZZ");
	gotoxy(40, 17);
	printf("WZ ZZZ    ZZ   wZZZB   Z    ZZ DZ ZZZ,    ,ZZZ8     DZZZW  yZ    ZZ   ZZZZj    ZZz");
	gotoxy(40, 18);
	printf("jZ                             BZ");
	gotoxy(40, 19);
	printf("8Z                             ZZ");
	

	gotoxy(72 - 2, 30);
	printf(" 게 임 시 작 (ENTER)");

	gotoxy(72, 32);
	printf("  종 료 (ESC)");
	

}

// 커서없애기
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = 0; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void StartMenu()
{
	//PlaySound(TEXT("Sound.wav"), NULL, SND_ASYNC | SND_LOOP); // 반복 재생

	// 효과음은 헤더파일로 만들어어야함 검색창에 C++ FMOD

	char key = 0;

	tleDraw();
	menuDraw();
	CursorView();
	
	while (1)
	{
		if (_kbhit())
		{
			key = _getch();

			if (key == -32)
			{
				key = _getch();
			}

			switch (key)
			{
			case ENTER:  printf("ENTER\n");
				break;
			case ESC:  printf("ESC\n");
				break;
			}

		}
	};


}