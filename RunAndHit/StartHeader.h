#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <windows.h>

// ����
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>


void tleDraw() {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("�����������������������������������������������������������������������������������");
	for (int i = 0; i < 40; i++) 
	{ 
		printf("��                                                                                                                                                                ��"); 
                                                                                                                                                          
	}
	printf("�����������������������������������������������������������������������������������");
	

}

void gotoxy(int x, int y) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void gotoxy2(int x, int y) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}



void menuDraw() 
{
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
	

	gotoxy2(72 - 2, 30);
	printf(" �� �� �� �� (ENTER)");

	gotoxy2(72, 32);
	printf("  �� �� (ESC)");
	

}

// Ŀ�����ֱ�
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = 0; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void KeyGuide()
{
	

	for (int i = 22; i <= 33; i++)
	{
		
		gotoxy2(115, i);
		printf("��                          ��");
	}

	gotoxy2(115, 22);
	printf("���������������");


	gotoxy2(122 - 2, 24);
	printf(" ��");

	gotoxy2(120 - 2, 25);
	printf(" ���墺    ����Ű");


	gotoxy2(120 - 2, 28);
	printf(" ������ ���  ( CTRL )");
	
	gotoxy2(120 - 2, 31);
	printf(" ���ع� ��ġ ( SPACE )");

	gotoxy2(115, 33);
	printf("���������������");

	

}


void StartMenu()
{
	//PlaySound(TEXT("Sound.wav"), NULL, SND_ASYNC | SND_LOOP); // �ݺ� ���

	// ȿ������ ������Ϸ� ��������� �˻�â�� C++ FMOD
	

	char key = 0;

	tleDraw();
	menuDraw();
	CursorView();
	KeyGuide();




}