#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <windows.h>

// ����
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>


void tleDraw() {

	
	printf("�����������������������������������������������������������������������������������");
	for (int i = 0; i < 40; i++) 
	{ 
		printf("��                                                                                                                                                                ��"); 
                                                                                                                                                          
	}
	printf("�����������������������������������������������������������������������������������");
	

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
	printf(" �������         ��      ��      ��              ��  ");
	gotoxy(50, 11);
	printf("��          ��        ��    ��        ���          ���  ");
	gotoxy(50, 12);
	printf("          ��          ��  ��          �� ��        �� ��  ");
	gotoxy(50, 13);
	printf("        ��            �� ��           ��  ��      ��  ��  ");
	gotoxy(50, 14);
	printf("      ��              ���            ��   ��    ��   ��  ");
	gotoxy(50, 15);
	printf("     ��               ��  ��          ��    ��  ��    ��  ");
	gotoxy(50, 16);
	printf("   ��                 ��    ��        ��     ���     ��  ");
	gotoxy(50, 17);
	printf("  ��                  ��      ��      ��      ��      ��  ");
	gotoxy(50, 18);
	printf("���������      ��        ��    ��      ��      ��   ");
	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

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


	gotoxy2(120 - 2, 27);
	printf(" ���� ���  ( CTRL )");
	
	gotoxy2(120 - 2, 29);
	printf(" ���� ������ ( R )");
	
	gotoxy2(120 - 2, 31);
	printf(" �ӽŰ� ��ü ( SPACE )");

	gotoxy2(115, 33);
	printf("���������������");

	

}


void StartMenu()
{
	PlaySound(TEXT("mainbgm.wav"), NULL, SND_ASYNC | SND_LOOP); // �ݺ� ���

	// ȿ������ ������Ϸ� ��������� �˻�â�� C++ FMOD
	

	char key = 0;
	CursorView();


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	tleDraw();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	menuDraw();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	KeyGuide();





}