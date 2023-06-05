#pragma once

#include<stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>

// Ŀ�����ֱ�

void CursorView2()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = 0; //Ŀ�� Visible TRUE(����) FALSE(����)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

char overPic[11][100];

//(v2.0) �浹 ������ ���ӿ��� �׷���
void DrawGameOver(const int score, char string[11][100],char message[])
{
   
    char string2[100];
    sprintf(string2, "�޼��� : %s   ����ģ �Ÿ� : %dm ", message,score);

    CursorView();

    strcpy(overPic[0], "===============================");
    strcpy(overPic[1], "===============================");
    strcpy(overPic[2], "======  G A M E O V E R  ======");
    strcpy(overPic[3], "===============================");
    strcpy(overPic[4], "===============================");
    strcpy(overPic[5], "");
    strcpy(overPic[6],  string2);
    strcpy(overPic[7], "");
    strcpy(overPic[8], "���� : ESC");
    strcpy(overPic[9], "");
    strcpy(overPic[10], "����� : ENTER");

    for (int i = 0; i < 11; i++)
    {
        COORD cursorPosition = { 70, 17 + i };
        DWORD dw;
        SetConsoleCursorPosition(Screen[screenIndex], cursorPosition);

        WriteFile
        (
            Screen[screenIndex],
            string[i],
            strlen(string[i]),
            &dw,
            NULL
        );
    }
   


}



char clearPic[10][100];

void DrawGameClear(const int score, char string[10][100], char message[])
{
    
    CursorView2();
    char string2[100];
    sprintf(string2, "�޼��� : %s", message);

    int x = 70;
    int y = 17;

    strcpy(clearPic[0], "===============================");
    strcpy(clearPic[1], "===============================");
    strcpy(clearPic[2], "====== G A M E C L E A R ======");
    strcpy(clearPic[3], "===============================");
    strcpy(clearPic[4], "===============================");
    strcpy(clearPic[5], "");
    strcpy(clearPic[6], string2);
    strcpy(clearPic[7], "");
    strcpy(clearPic[8], "���� : ESC");
    strcpy(clearPic[9], "");
    strcpy(clearPic[10], "����� : ENTER");

    for (int i = 0; i < 11; i++)
    {
        COORD cursorPosition = { x, y + i };
        DWORD dw;
        SetConsoleCursorPosition(Screen[screenIndex], cursorPosition);

        WriteFile
        (
            Screen[screenIndex],
            string[i],
            strlen(string[i]),
            &dw,
            NULL
        );
    }


}



