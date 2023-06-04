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

// ����
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>
#include "endHeader.h"

void GameStart2()
{
    CursorView(); //Ŀ�� ������ ���ֱ�
    //PlaySound(TEXT("Sound.wav"), NULL, SND_ASYNC);
    int cloudX = CLOUD_BOTTOM_X;
    int cloudY = CLOUD_BOTTOM_Y;

    int cloudX2 = CLOUD_BOTTOM_X2;
    int cloudY2 = CLOUD_BOTTOM_Y2; 
    
    int grassX = BottomTrapX;
   
    // ���� ������ �ʿ��� ����
    int endNum = 0;

    bool isJumping = false;
    bool isBottom = true;
    const int gravity = 10; // ���� ����

    int monsterY = MONSTER_BOTTOM_Y; //���� Y��
    int meX = ME_BOTTOM_X; //�� X��
    int meY = ME_BOTTOM_Y; //�� X��
   
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
    
    //�������� ����
    int sort = SORT;

    int ENDX = ENDPOINTX;

    int score = 0;
    clock_t start, curr; //���� ��ȭ �ʱ�ȭ
    start = clock();        //���۽ð� �ʱ�ȭ

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
        //����
        if (GetAsyncKeyState(VK_UP) & 0x0001)
        {
            PlaySound(TEXT("marioJump.wav"), NULL, SND_ASYNC);
            if (meY > 27) {
                meX += 2;
                isJumping = true;
                isBottom = false;
            }
        }
        //�������̶�� Y�� ����, ������ �������� Y�� ����.
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


        //Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
        if (meY >= ME_BOTTOM_Y)
        {
            meY = ME_BOTTOM_Y;
            isBottom = true;
        }

        //������ ������ ������ ������ ���� ��Ȳ.
        if (meY <= 70)
        {
            isJumping = false;
        }

        //������ �������� (x����) �������ϰ�
           //������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
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

        //�ٴ���ֹ� �浹�� ����
        if ((bottomTX-2 <= meX && meX <= bottomTX +1) )
        {

            if (bottomTY-2 < meY + 10 && meY+10 < bottomTY+2) {
                score = 0;
                //1.���� �ʱ�ȭ
                ScreenInit();
                PlaySound(TEXT("despair.wav"), NULL, SND_ASYNC);
                while (1) {
                    DrawGameOver(score*4, overPic,"�Ѿ����� ���");
                    // 2. ���� ��ü 
                    ScreenFlipping();
                    // 3. ��ü�� ������ ������ ����
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

        //������ �浹 �� ����
        if (meX < 19)
        {
            PlaySound(TEXT("despair.wav"), NULL, SND_ASYNC);
            //1.���� �ʱ�ȭ
            ScreenInit();

            while (1) {
                DrawGameOver(score*4, overPic, "�������� ���Ĵ���");
                // 2. ���� ��ü 
                ScreenFlipping();
                // 3. ��ü�� ������ ������ ����
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



        // 1. ���� �ʱ�ȭ
        ScreenInit();


        BottomDraw(); //�ٴ� �׸���


        DrawMonster(monsterY + 1, MonsterPic);  //�����׸���
        DrawMe(meX, meY, MePic);  //�� �׸���

        DrawCloud(cloudX, cloudY, CloudPic); //���� �׸���

        DrawCloud2(cloudX2, cloudY2, CloudPic2); //����2 �׸���

        //DrawMountain(mountainX, mountainY, MountainPic);//�� �׸���

        DrawBottomTrap(bottomTX, bottomTY); //�ٴ� ��ֹ� �׸���

        DrawGrass(grassX, bottomTY);

        score++;    //���ھ� UP

        DrawMeter(score * 4,bullet1,bullet2);//���ͼ� �׸���


        //��1 �����Ű��
        if ((200 > score && score > 50) && score % 50 == 0)
        {
            DrawFristEnemy(enemyX, enemyY, enemyPic); //�� �׸���
            enemyX -= 3;

            if (enemyX < 18)
            {
                enemyX = ENEMYX;
            }

        }

        //��1�� �浹�� ����
        if (score < 500)
        {
            if (enemyX - 1 <= meX && meX <= enemyX + 12)
            {
                //1.���� �ʱ�ȭ
                ScreenInit();
                PlaySound(TEXT("despair.wav"), NULL, SND_ASYNC);

                while (1) {
                    DrawGameOver(score * 4, overPic,"���౫���� �浹 ���");
                    // 2. ���� ��ü 
                    ScreenFlipping();
                    // 3. ��ü�� ������ ������ ����
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

            //��1 �����Ű��
            if (200 > score && score > 50)
            {
                DrawFristEnemy(enemyX, enemyY, enemyPic); //�� �׸���
                enemyX -= 3;

                if (enemyX < 18)
                {
                    enemyX = ENEMYX;
                }

            }

            //��1�� �浹�� ����
            if (enemyX - 1 <= meX && meX <= enemyX + 12)
            {
                //1.���� �ʱ�ȭ
                ScreenInit();
                PlaySound(TEXT("despair.wav"), NULL, SND_ASYNC);

                while (1) {
                    DrawGameOver(score * 4, overPic, "���౫���� �浹 ���");
                    // 2. ���� ��ü 
                    ScreenFlipping();
                    // 3. ��ü�� ������ ������ ����
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


            //��2 �����Ű��
            if (375 > score && score > 210)
            {
                DrawSecondEnemy(enemyX2, enemyY2, enemyPic2, enemyHP2); //�� �׸���
                enemyX2 -= 2;

                if (enemyX2 < 18)
                {
                    enemyX2 = ENEMYX2;
                }

            }

            //��2�� �浹�� ����
            if (enemyX2 - 1 <= meX && meX <= enemyX2 + 16)
            {
                //1.���� �ʱ�ȭ
                ScreenInit();
                PlaySound(TEXT("despair.wav"), NULL, SND_ASYNC);

                while (1) {
                    DrawGameOver(score * 4, overPic, "���α��� �浹 ���");
                    // 2. ���� ��ü 
                    ScreenFlipping();
                    // 3. ��ü�� ������ ������ ����
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
            //��3 �����Ű��
            if (500 > score && score > 375 && enemyCount3 == 1)
            {
                DrawThirdEnemy(enemyX3, enemyY3, enemyPic3, enemyHP3); //�� �׸���
                enemyX3 -= 1;

                if (enemyX3 < 18)
                {
                    enemyX3 = ENEMYX2;
                }

            }

            //��3�� �浹�� ����
            if (enemyX3 - 1 <= meX && meX <= enemyX3 + 16 && enemyCount3 == 1)
            {
                //1.���� �ʱ�ȭ
                ScreenInit();
                PlaySound(TEXT("despair.wav"), NULL, SND_ASYNC);

                while (1) {
                    DrawGameOver(score * 4, overPic,"�������� ���");
                    // 2. ���� ��ü 
                    ScreenFlipping();
                    // 3. ��ü�� ������ ������ ����
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

    
        //���� ��� �� 
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
        
        //���� ��� �� 
        if (GetAsyncKeyState(0x52))
        {
            PlaySound(TEXT("reload.wav"), NULL, SND_ASYNC);
            bullet1 = BULLET1;
        }

         //�ӽŰ� ��� �� 
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
     

  

         // 2km�̻� ������ ������ ����
         if (score > 500)
         {
             EndPoint(ENDX, ENDPOINTY, endpoint);

             if (ENDX > ENDPOINTX -4) {

                 
                 ENDX--;
                 
             }

             if (ENDPOINTX-1 < meX && meX < ENDPOINTX+10)
             {

                 PlaySound(TEXT("doorSound.wav"), NULL, SND_ASYNC);

                 //1.���� �ʱ�ȭ
                 ScreenInit();

                 while (1) {
                     DrawGameClear(score*4, clearPic,"Ŭ����");
                     // 2. ���� ��ü 
                     ScreenFlipping();
                     // 3. ��ü�� ������ ������ ����
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



         //�������� 1 �˸�â
         Stage1(60, 18, stagePic1, score);

         // 2. ���� ��ü 
         ScreenFlipping();
         // 3. ��ü�� ������ ������ ����
         ScreenClear();


         
         


         }
         


     }
    

  
