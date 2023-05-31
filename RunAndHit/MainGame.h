#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
//#include "TrapHeader.h"

#define MONSTER_BOTTOM_Y 28


#define ME_BOTTOM_X 70
#define ME_BOTTOM_Y 32

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

// 음악
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>


// HANDLE 인덱스에 접근해서 버퍼를 교체시키는 변수
int screenIndex = 0;

// 버퍼의 크기
int width = 100;
int height = 60;

// 버퍼 생성
HANDLE Screen[2]; // [0] front buffer
// [1] back buffer


// 버퍼를 초기화하는 함수
void ScreenInit()
{
    CONSOLE_CURSOR_INFO cursor;

    // 버퍼의 가로 사이즈, 세로 사이즈
    COORD size = { width, height };

    // Left, Top, Right, Bottom
    SMALL_RECT rect = { 0, 0, width - 1, height - 1 };

    // 화면 2개를 생성합니다.
    // front buffer
    Screen[0] = CreateConsoleScreenBuffer
    (
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );

    SetConsoleScreenBufferSize(Screen[0], size);

    SetConsoleWindowInfo(Screen[0], TRUE, &rect);

    // back buffer
    Screen[1] = CreateConsoleScreenBuffer
    (
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );

    SetConsoleScreenBufferSize(Screen[1], size);

    SetConsoleWindowInfo(Screen[1], TRUE, &rect);

    // 커서의 활성화 여부
    // false : 거짓
    // true : 참
    cursor.bVisible = 0;

    SetConsoleCursorInfo(Screen[0], &cursor);
    SetConsoleCursorInfo(Screen[1], &cursor);
}


// 버퍼를 교체하는 함수
void ScreenFlipping()
{
    // 버퍼는 하나만 활성화시킬 수 있습니다.
    SetConsoleActiveScreenBuffer(Screen[screenIndex]);

    screenIndex = !screenIndex;
}

// 교체된 버퍼를 지워주는 함수
void ScreenClear()
{
    COORD coord = { 0,0 };

    DWORD dw;

    FillConsoleOutputCharacter
    (
        Screen[screenIndex],
        ' ',
        width * height,
        coord,
        &dw
    );
}

// 버퍼를 해제하는 함수
void ScreenRelease()
{
    CloseHandle(Screen[0]);
    CloseHandle(Screen[1]);
}



void BottomDraw()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    char  string[] = "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
    COORD cursorPosition = { 0, 42 };
    
    DWORD dw;

    SetConsoleCursorPosition(Screen[screenIndex], cursorPosition);

    WriteFile
    (
        Screen[screenIndex],
        string,
        strlen(string),
        &dw,
        NULL
    );


}

char MonsterPic[13][23];

//괴물을 그리는 함수
void DrawMonster(int monsterX, char string[13][23])
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

    static bool legFlag = true;

    strcpy(MonsterPic[0], "        $$$$$$$\n");
    strcpy(MonsterPic[1], "       $$ $$$ $$\n");
    strcpy(MonsterPic[2], "       $$$$$$$$$\n");
    strcpy(MonsterPic[3], "       $$$    $$\n");
    strcpy(MonsterPic[4], "       $$$$$$$$$\n");
    strcpy(MonsterPic[5], "      $$$$$$$$$$$$$$$\n");
    strcpy(MonsterPic[6], "     $$$$$$$$$$\n");
    strcpy(MonsterPic[7], "    $$$$$$$$$$$$$$$$$\n");
    strcpy(MonsterPic[8], "    $$$$$$$$\n");
    strcpy(MonsterPic[9], "    $$$$$$$$\n");
    strcpy(MonsterPic[10], "    $$$$$$\n");
   
    if (legFlag)
    {
        Sleep(10);
        strcpy(MonsterPic[11], "    $    $$$\n");
        strcpy(MonsterPic[12], "    $$     \n");
        legFlag = false;
    }
    else
    {
        Sleep(10);
        strcpy(MonsterPic[11], "    $$$  $\n");
        strcpy(MonsterPic[12], "         $$\n");
        legFlag = true;
    }


    for(int i=0; i<13; i++)
    {
        
        COORD cursorPosition = { 0, monsterX+i };
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

char MePic[5][10];

//시민을 그리는 함수
void DrawMe(int MeX,int MeY, char string[5][10])
{
    static bool legFlag = true;

    strcpy(MePic[0], " ▼\n");
    strcpy(MePic[1], "\n");
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
        COORD cursorPosition = { MeX, MeY + i + 5};
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

#define CLOUD_BOTTOM_Y 10
#define CLOUD_BOTTOM_X 155


char CloudPic[10][30];

//구름을 그리는 함수
void DrawCloud(int CloudX, int CloudY, char string[10][30])
{

    strcpy(CloudPic[0], "  @@@@@@@@@\n");
    strcpy(CloudPic[1], " @@@@@@@@@@@\n");
    strcpy(CloudPic[2], "@@@@@@@@@@@@@\n");
    strcpy(CloudPic[3], " @@@@@@@@@@@\n");
    strcpy(CloudPic[4], "  @@@@@@@@@");

    for (int i = 0; i < 5; i++)
    {
        COORD cursorPosition = { CloudX, CloudY + i };
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

#define CLOUD_BOTTOM_Y2 3

#define CLOUD_BOTTOM_X2 155


char CloudPic2[10][30];
//구름을 그리는 함수
void DrawCloud2(int CloudX, int CloudY, char string[10][30])
{

    strcpy(CloudPic2[0], "  @@@@@@@@@\n");
    strcpy(CloudPic2[1], " @@@@@@@@@@@\n");
    strcpy(CloudPic2[2], "@@@@@@@@@@@@@\n");
    strcpy(CloudPic2[3], " @@@@@@@@@@@\n");
    strcpy(CloudPic2[4], "  @@@@@@@@@");

    for (int i = 0; i < 5; i++)
    {
        COORD cursorPosition = { CloudX, CloudY + i };
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

char overPic[10][30];

//(v2.0) 충돌 했을때 게임오버 그려줌
void DrawGameOver(const int score, char string[10][30])
{
    CursorView();

    int x = 70;
    int y = 17;

    strcpy(overPic[0], "===========================");
    strcpy(overPic[1], "======G A M E O V E R======");
    strcpy(overPic[2], "===========================");
    strcpy(overPic[3], "");
    strcpy(overPic[4], "재시작 : ENTER");

    for (int i = 0; i < 5; i++)
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



void GameStart2()
{
    CursorView(); //커서 깜박이 없애기
    //PlaySound(TEXT("Sound.wav"), NULL, SND_ASYNC);
    int cloudX = CLOUD_BOTTOM_X;
    int cloudY = CLOUD_BOTTOM_Y;

    int cloudX2 = CLOUD_BOTTOM_X2;
    int cloudY2 = CLOUD_BOTTOM_Y2;

    // 게임 끝내기 필요한 숫자
    int endNum = 0;

    bool isJumping = false;
    bool isBottom = true;
    const int gravity = 3; // 점프 높이

    int monsterY = MONSTER_BOTTOM_Y; //도둑 Y축
    int meX = ME_BOTTOM_X; //내 X축
    int meY = ME_BOTTOM_Y; //내 X축
    char key = 0;



     while(true)
     {

            if (endNum == 1)
            {
                ScreenRelease();
                break;
            }


             if (meX > 15 && !GetAsyncKeyState(VK_RIGHT)) {
                 meX -= 1;
             }
   
             if (GetAsyncKeyState(VK_RIGHT))
             {
                 if (meX < 159) {
                 Sleep(5);
                 meX++;
                 }
             }
             //점프
             if (GetAsyncKeyState(VK_UP))
             {
                 if (meY > 30) {
                    
                     isJumping = true;
                     isBottom = false;
                 }
             }
             //점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
             if (isJumping)
             {
                 meY -= gravity;
             }
             else
             {
                 Sleep(10);
                 meY += gravity;
             }


             //Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
             if (meY >= ME_BOTTOM_Y)
             {
                 meY = ME_BOTTOM_Y;
                 isBottom = true;
             }

             //점프의 맨위를 찍으면 점프가 끝난 상황.
             if (meY <= 70)
             {
                 isJumping = false;
             }

             //구름이 왼쪽으로 (x음수) 가도록하고
                //구름의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
             cloudX -= 3;
             if (cloudX <= 0)
             {
                 cloudX = CLOUD_BOTTOM_X;
             }

             cloudX2 -= 4;
             if (cloudX2 <= 0)
             {
                 cloudX2 = CLOUD_BOTTOM_X2;
             }

         // 1. 버퍼 초기화
         ScreenInit();

         BottomDraw(); //바닥 그리기
         
  
         DrawMonster(monsterY+1, MonsterPic);  //괴물그리기
         DrawMe(meX,meY,MePic);  //나 그리기
         DrawCloud(cloudX, cloudY, CloudPic);
         DrawCloud2(cloudX2, cloudY2, CloudPic2);
 

         // 2. 버퍼 교체 
         ScreenFlipping();
         // 3. 교체된 버퍼의 내용을 삭제
         ScreenClear();

         //게임 종료
         if (GetAsyncKeyState(VK_DOWN)) {
             //1.버퍼 초기화
             ScreenInit();

             while (1) {
                 DrawGameOver(15, overPic);
                 // 2. 버퍼 교체 
                 ScreenFlipping();
                 // 3. 교체된 버퍼의 내용을 삭제
                 ScreenClear();

                 if (GetAsyncKeyState(VK_RETURN)) {
                     GameStart2();
                     break;
                 }
                 else if (GetAsyncKeyState(VK_ESCAPE)) {
                     endNum = 1;
                     break; 
                   
                 }

             }


         }
         


     }
    

     
    

};
