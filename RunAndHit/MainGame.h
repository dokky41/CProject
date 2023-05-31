#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include "TrapHeader.h"
#include "EnemyPlayer.h"

#define MONSTER_BOTTOM_Y 28

#define ME_BOTTOM_X 70
#define ME_BOTTOM_Y 32

#define BottomTrapX 140
#define BottomTrapY 43

#define CLOUD_BOTTOM_Y 10
#define CLOUD_BOTTOM_X 155
#define CLOUD_BOTTOM_Y2 3
#define CLOUD_BOTTOM_X2 155

// 음악
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>



char CloudPic[10][30];
char CloudPic2[10][30];
char MonsterPic[13][23];
char MePic[5][10];
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

//미터수 출력함수




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
   
    int bottomTX = BottomTrapX;
    int bottomTY = BottomTrapY;

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

             bottomTX -= 1;
             if (BottomTrapX <= 0)
             {
                 bottomTX = BottomTrapX;
             }

         // 1. 버퍼 초기화
         ScreenInit();

         //BottomDraw(); //바닥 그리기
         
         DrawMonster(monsterY+1, MonsterPic);  //괴물그리기
         DrawMe(meX,meY,MePic);  //나 그리기
         DrawCloud(cloudX, cloudY, CloudPic); //구름 그리기
         DrawCloud2(cloudX2, cloudY2, CloudPic2); //구름2 그리기
        
         DrawBottomTrap(bottomTX, bottomTY); //바닥 장애물 그리기


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
