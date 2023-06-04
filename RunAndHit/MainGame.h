#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include "TrapHeader.h"
#include "EnemyPlayer.h"
#include <math.h>

#define RIGHT 77
#define MONSTER_BOTTOM_Y 28

#define ME_BOTTOM_X 70
#define ME_BOTTOM_Y 32

#define BottomTrapX 160
#define BottomTrapY 43

#define ENEMYX 170
#define ENEMYY 36

#define ENEMYX2 170
#define ENEMYY2 34
#define ENEMYHP2 5

#define ENEMYX3 144
#define ENEMYY3 32
#define ENEMYHP3 41

#define ENDPOINTX 135
#define ENDPOINTY 32

#define SORT 1;

#define CLOUD_BOTTOM_Y 10
#define CLOUD_BOTTOM_X 155
#define CLOUD_BOTTOM_Y2 3
#define CLOUD_BOTTOM_X2 155


#define BULLET1 7
#define BULLET2 40

// 음악
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>
#include "endHeader.h"

void GameStart2()
{
    CursorView(); //커서 깜박이 없애기
    //PlaySound(TEXT("Sound.wav"), NULL, SND_ASYNC);
    int cloudX = CLOUD_BOTTOM_X;
    int cloudY = CLOUD_BOTTOM_Y;

    int cloudX2 = CLOUD_BOTTOM_X2;
    int cloudY2 = CLOUD_BOTTOM_Y2; 
    
    int grassX = BottomTrapX;
   
    // 게임 끝내기 필요한 숫자
    int endNum = 0;

    bool isJumping = false;
    bool isBottom = true;
    const int gravity = 10; // 점프 높이

    int monsterY = MONSTER_BOTTOM_Y; //도둑 Y축
    int meX = ME_BOTTOM_X; //내 X축
    int meY = ME_BOTTOM_Y; //내 X축
   
    int bottomTX = BottomTrapX;
    int bottomTY = BottomTrapY;
    
    int enemyX = ENEMYX;
    int enemyY = ENEMYY;
    
    int enemyX2 = ENEMYX2;
    int enemyY2 = ENEMYY2;
    int enemyHP2 = ENEMYHP2;

    int enemyX3 = ENEMYX3;
    int enemyY3 = ENEMYY3;
    int enemyHP3 = ENEMYHP3;
    int enemyCount3 = 1;

    int bullet1 = BULLET1;
    int bullet2 = BULLET2;
    
    //스테이지 종류
    int sort = SORT;

    int ENDX = ENDPOINTX;

    int score = 0;
    clock_t start, curr; //점수 변화 초기화
    start = clock();        //시작시간 초기화

    curr = clock();


    while (true)
    {

        if (endNum == 1)
        {
            ScreenRelease();
            break;
        }


        if (meX > 15 && !GetAsyncKeyState(VK_RIGHT)) {
            meX -= 3;
        }

        if (GetAsyncKeyState(VK_RIGHT))
        {
            if (meX < 159) {

                meX = meX + 1;
            }
        }
        //점프
        if (GetAsyncKeyState(VK_UP) & 0x0001)
        {
            PlaySound(TEXT("marioJump.wav"), NULL, SND_ASYNC);
            if (meY > 27) {
                meX += 2;
                isJumping = true;
                isBottom = false;
            }
        }
        //점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
        if (isJumping)
        {
            meY -= gravity;
            Sleep(40);
        }
        else
        {
            Sleep(40);
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


        bottomTX -= 4;
        if (bottomTX <= 0)
        {
            bottomTX = BottomTrapX;
        }

        grassX -= 2;
        if (grassX <= 0)
        {
            grassX = BottomTrapX;
        }

        //바닥장애물 충돌시 죽음
        if ((bottomTX-2 <= meX && meX <= bottomTX +1) )
        {

            if (bottomTY-2 < meY + 10 && meY+10 < bottomTY+2) {
                score = 0;
                //1.버퍼 초기화
                ScreenInit();
                PlaySound(TEXT("despair.wav"), NULL, SND_ASYNC);
                while (1) {
                    DrawGameOver(score*4, overPic,"넘어져서 사망");
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

        //괴물과 충돌 시 죽음
        if (meX < 19)
        {
            PlaySound(TEXT("despair.wav"), NULL, SND_ASYNC);
            //1.버퍼 초기화
            ScreenInit();

            while (1) {
                DrawGameOver(score*4, overPic, "괴물에게 포식당함");
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



        // 1. 버퍼 초기화
        ScreenInit();


        BottomDraw(); //바닥 그리기


        DrawMonster(monsterY + 1, MonsterPic);  //괴물그리기
        DrawMe(meX, meY, MePic);  //나 그리기

        DrawCloud(cloudX, cloudY, CloudPic); //구름 그리기

        DrawCloud2(cloudX2, cloudY2, CloudPic2); //구름2 그리기

        //DrawMountain(mountainX, mountainY, MountainPic);//산 그리기

        DrawBottomTrap(bottomTX, bottomTY); //바닥 장애물 그리기

        DrawGrass(grassX, bottomTY);

        score++;    //스코어 UP

        DrawMeter(score * 4,bullet1,bullet2);//미터수 그리기


        //적1 등장시키기
        if ((200 > score && score > 50) && score % 50 == 0)
        {
            DrawFristEnemy(enemyX, enemyY, enemyPic); //적 그리기
            enemyX -= 3;

            if (enemyX < 18)
            {
                enemyX = ENEMYX;
            }

        }

        //적1과 충돌시 죽음
        if (score < 500)
        {
            if (enemyX - 1 <= meX && meX <= enemyX + 12)
            {
                //1.버퍼 초기화
                ScreenInit();
                PlaySound(TEXT("despair.wav"), NULL, SND_ASYNC);

                while (1) {
                    DrawGameOver(score * 4, overPic,"비행괴물과 충돌 사망");
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

            //적1 등장시키기
            if (200 > score && score > 50)
            {
                DrawFristEnemy(enemyX, enemyY, enemyPic); //적 그리기
                enemyX -= 3;

                if (enemyX < 18)
                {
                    enemyX = ENEMYX;
                }

            }

            //적1과 충돌시 죽음
            if (enemyX - 1 <= meX && meX <= enemyX + 12)
            {
                //1.버퍼 초기화
                ScreenInit();
                PlaySound(TEXT("despair.wav"), NULL, SND_ASYNC);

                while (1) {
                    DrawGameOver(score * 4, overPic, "비행괴물과 충돌 사망");
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


            //적2 등장시키기
            if (375 > score && score > 210)
            {
                DrawSecondEnemy(enemyX2, enemyY2, enemyPic2, enemyHP2); //적 그리기
                enemyX2 -= 2;

                if (enemyX2 < 18)
                {
                    enemyX2 = ENEMYX2;
                }

            }

            //적2과 충돌시 죽음
            if (enemyX2 - 1 <= meX && meX <= enemyX2 + 16)
            {
                //1.버퍼 초기화
                ScreenInit();
                PlaySound(TEXT("despair.wav"), NULL, SND_ASYNC);

                while (1) {
                    DrawGameOver(score * 4, overPic, "거인괴물 충돌 사망");
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
            //적3 등장시키기
            if (500 > score && score > 375 && enemyCount3 == 1)
            {
                DrawThirdEnemy(enemyX3, enemyY3, enemyPic3, enemyHP3); //적 그리기
                enemyX3 -= 1;

                if (enemyX3 < 18)
                {
                    enemyX3 = ENEMYX2;
                }

            }

            //적3과 충돌시 죽음
            if (enemyX3 - 1 <= meX && meX <= enemyX3 + 16 && enemyCount3 == 1)
            {
                //1.버퍼 초기화
                ScreenInit();
                PlaySound(TEXT("despair.wav"), NULL, SND_ASYNC);

                while (1) {
                    DrawGameOver(score * 4, overPic,"보스에게 사망");
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

    
        //샷건 사용 시 
        if ((GetAsyncKeyState(VK_CONTROL) & 0x0001) && bullet1 >= 1)
        {
            PlaySound(TEXT("skillSound.wav"), NULL, SND_ASYNC);
            DrawSkill(meX + 8, meY + 4, skillPic);
            bullet1--;

            if (enemyX - 2 < meX + 8 && meX + 8 < enemyX + 10)
            {
                enemyX = ENEMYX;
            }

            if (enemyX2 - 2 < meX + 12 && meX + 12 < enemyX2 + 10)
            {
                enemyHP2--;
            }

            if (enemyHP2 == 0)
            {
                enemyX2 = ENEMYX2;
                enemyHP2 = ENEMYHP2;
            }

            if (enemyX3 - 2 < meX + 12 && meX + 12 < enemyX3 + 10)
            {
                enemyHP3--;
            }

            if (enemyHP3 == 0)
            {
                enemyX3 = ENEMYX3;
                enemyHP3 = ENEMYHP3;
                enemyCount3 = 0;
            }
        }
        else if ((GetAsyncKeyState(VK_CONTROL) & 0x0001) && bullet1 == 0)
        {
            PlaySound(TEXT("skillSound.wav"), NULL, SND_ASYNC);
        }
        
        //장전 사용 시 
        if (GetAsyncKeyState(0x52))
        {
            PlaySound(TEXT("reload.wav"), NULL, SND_ASYNC);
            bullet1 = BULLET1;
        }

         //머신건 사용 시 
         if (GetAsyncKeyState(VK_SPACE) && bullet2 >= 1)
         {
             PlaySound(TEXT("machinegun.wav"), NULL, SND_ASYNC);
             DrawSkill2(meX + 8, meY + 4, skillPic);
             bullet2--;

             if (enemyX - 22 < meX + 8 && meX + 8 < enemyX + 10)
             {
                 enemyX = ENEMYX;
             }

             if (enemyX2 - 22 < meX + 12 && meX + 12 < enemyX2 + 10)
             {
                 enemyHP2--;
             }

             if (enemyHP2 == 0)
             {
                 enemyX2 = ENEMYX2;
                 enemyHP2 = ENEMYHP2;
             }

             if (enemyX3 - 22 < meX + 12 && meX + 12 < enemyX3 + 10)
             {
                 enemyHP3--;
             }

             if (enemyHP3 == 0)
             {
                 enemyX3 = ENEMYX3;
                 enemyHP3 = ENEMYHP3;
                 enemyCount3 = 0;
             }
         }
     

  

         // 2km이상 갔을때 도착지 생성
         if (score > 500)
         {
             EndPoint(ENDX, ENDPOINTY, endpoint);

             if (ENDX > ENDPOINTX -4) {

                 
                 ENDX--;
                 
             }

             if (ENDPOINTX-1 < meX && meX < ENDPOINTX+10)
             {

                 PlaySound(TEXT("doorSound.wav"), NULL, SND_ASYNC);

                 //1.버퍼 초기화
                 ScreenInit();

                 while (1) {
                     DrawGameClear(score*4, clearPic,"클리어");
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



         //스테이지 1 알림창
         Stage1(60, 18, stagePic1, score);

         // 2. 버퍼 교체 
         ScreenFlipping();
         // 3. 교체된 버퍼의 내용을 삭제
         ScreenClear();


         
         


         }
         


     }
    

  
