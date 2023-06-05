#pragma once

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define MONSTER_BOTTOM_Y 28

#define ME_BOTTOM_X 70
#define ME_BOTTOM_Y 32


char MonsterPic[30][100];
char MePic[5][10];


//괴물을 그리는 함수
void DrawMonster(int monsterX, char string[30][100])
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

    static bool legFlag = true;

    strcpy(MonsterPic[0], "         ■■■■■\n");
    strcpy(MonsterPic[1], "         ■  ■  ■\n");

    strcpy(MonsterPic[8], "           ■■■    \n");

    if (legFlag)

    {
        Sleep(10);
    strcpy(MonsterPic[2], "         ■■■■■    \n");
    strcpy(MonsterPic[3], "         ■■  ■■   ■\n");
    strcpy(MonsterPic[4], "           ■■■     ■  \n");
    strcpy(MonsterPic[5], "    ■■■■■■■■■■\n");
    strcpy(MonsterPic[6], "    ■     ■■■       \n");
    strcpy(MonsterPic[7], "    ■     ■■■        \n");
    strcpy(MonsterPic[9], "           ■  \n");
    strcpy(MonsterPic[10], "         ■    \n");
    strcpy(MonsterPic[11], "        ■        \n");
    strcpy(MonsterPic[12], "       ■    \n");
        legFlag = false;
    }
    else
    {
        Sleep(10);
     strcpy(MonsterPic[2], "         ■■■■■\n");
     strcpy(MonsterPic[3], "         ■■  ■■\n");
     strcpy(MonsterPic[4], "           ■■■\n");
     strcpy(MonsterPic[5], "    ■■■■■■■■■■\n");
     strcpy(MonsterPic[6], "           ■■■     \n");
     strcpy(MonsterPic[7], "           ■■■      \n");
     strcpy(MonsterPic[9], "               ■    \n");
     strcpy(MonsterPic[10],"                ■    \n");
     strcpy(MonsterPic[11],"                 ■    \n");
     strcpy(MonsterPic[12],"                  ■    \n");
        legFlag = true;
    }


    for (int i = 0; i < 13; i++)
    {

        COORD cursorPosition = { 0, monsterX + i };
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


//시민을 그리는 함수
void DrawMe(int MeX, int MeY, char string[5][10])
{

    static bool legFlag = true;

    strcpy(MePic[0], " ▼\n");
    strcpy(MePic[1], "");
    strcpy(MePic[2], " ●\n");

    if (legFlag)
    {
        Sleep(10);
        strcpy(MePic[3], " ╋┘ \n");
        strcpy(MePic[4], " /");
        legFlag = false;
    }
    else
    {
        Sleep(10);
        strcpy(MePic[3], "┎╋ \n");
        strcpy(MePic[4], "  ＼");
        legFlag = true;
    }


    for (int i = 0; i < 5; i++)
    {
        COORD cursorPosition = { MeX, MeY + i + 5 };
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


