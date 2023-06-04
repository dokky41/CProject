#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <windows.h>

// 음악
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>


void tleDraw() {

	
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	for (int i = 0; i < 40; i++) 
	{ 
		printf("■                                                                                                                                                                ■"); 
                                                                                                                                                          
	}
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	

}

void gotoxy(int x, int y) {

	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void gotoxy2(int x, int y) {

	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}



void menuDraw() 
{
	gotoxy(50, 10); 
	printf(" ■■■■■■         ■      ■      ■              ■  ");
	gotoxy(50, 11);
	printf("■          ■        ■    ■        ■■          ■■  ");
	gotoxy(50, 12);
	printf("          ■          ■  ■          ■ ■        ■ ■  ");
	gotoxy(50, 13);
	printf("        ■            ■ ■           ■  ■      ■  ■  ");
	gotoxy(50, 14);
	printf("      ■              ■■            ■   ■    ■   ■  ");
	gotoxy(50, 15);
	printf("     ■               ■  ■          ■    ■  ■    ■  ");
	gotoxy(50, 16);
	printf("   ■                 ■    ■        ■     ■■     ■  ");
	gotoxy(50, 17);
	printf("  ■                  ■      ■      ■      ■      ■  ");
	gotoxy(50, 18);
	printf("■■■■■■■■      ■        ■    ■      ■      ■   ");
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

	gotoxy2(72 - 2, 30);
	printf(" 게 임 시 작 (ENTER)");

	gotoxy2(72, 32);
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

void KeyGuide()
{
	

	for (int i = 22; i <= 33; i++)
	{
		
		gotoxy2(115, i);
		printf("■                          ■");
	}

	gotoxy2(115, 22);
	printf("■■■■■■■■■■■■■■");


	gotoxy2(122 - 2, 24);
	printf(" ▲");

	gotoxy2(120 - 2, 25);
	printf(" ◀▼▶    방향키");


	gotoxy2(120 - 2, 27);
	printf(" 샷건 사용  ( CTRL )");
	
	gotoxy2(120 - 2, 29);
	printf(" 샷건 재장전 ( R )");
	
	gotoxy2(120 - 2, 31);
	printf(" 머신건 교체 ( SPACE )");

	gotoxy2(115, 33);
	printf("■■■■■■■■■■■■■■");

	

}


void StartMenu()
{
	PlaySound(TEXT("mainbgm.wav"), NULL, SND_ASYNC | SND_LOOP); // 반복 재생

	// 효과음은 헤더파일로 만들어어야함 검색창에 C++ FMOD
	

	char key = 0;
	CursorView();


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	tleDraw();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	menuDraw();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	KeyGuide();





}