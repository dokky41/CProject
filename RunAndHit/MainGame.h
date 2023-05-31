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

// ����
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>



char CloudPic[10][30];
char CloudPic2[10][30];
char MonsterPic[13][23];
char MePic[5][10];
char overPic[10][30];



//(v2.0) �浹 ������ ���ӿ��� �׷���
void DrawGameOver(const int score, char string[10][30])
{
    CursorView();

    int x = 70;
    int y = 17;

    strcpy(overPic[0], "===========================");
    strcpy(overPic[1], "======G A M E O V E R======");
    strcpy(overPic[2], "===========================");
    strcpy(overPic[3], "");
    strcpy(overPic[4], "����� : ENTER");

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

//���ͼ� ����Լ�




void GameStart2()
{
    CursorView(); //Ŀ�� ������ ���ֱ�
    //PlaySound(TEXT("Sound.wav"), NULL, SND_ASYNC);
    int cloudX = CLOUD_BOTTOM_X;
    int cloudY = CLOUD_BOTTOM_Y;

    int cloudX2 = CLOUD_BOTTOM_X2;
    int cloudY2 = CLOUD_BOTTOM_Y2;

    // ���� ������ �ʿ��� ����
    int endNum = 0;

    bool isJumping = false;
    bool isBottom = true;
    const int gravity = 3; // ���� ����

    int monsterY = MONSTER_BOTTOM_Y; //���� Y��
    int meX = ME_BOTTOM_X; //�� X��
    int meY = ME_BOTTOM_Y; //�� X��
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
             //����
             if (GetAsyncKeyState(VK_UP))
             {
                 if (meY > 30) {
                    
                     isJumping = true;
                     isBottom = false;
                 }
             }
             //�������̶�� Y�� ����, ������ �������� Y�� ����.
             if (isJumping)
             {
                 meY -= gravity;
             }
             else
             {
                 Sleep(10);
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

             bottomTX -= 1;
             if (BottomTrapX <= 0)
             {
                 bottomTX = BottomTrapX;
             }

         // 1. ���� �ʱ�ȭ
         ScreenInit();

         //BottomDraw(); //�ٴ� �׸���
         
         DrawMonster(monsterY+1, MonsterPic);  //�����׸���
         DrawMe(meX,meY,MePic);  //�� �׸���
         DrawCloud(cloudX, cloudY, CloudPic); //���� �׸���
         DrawCloud2(cloudX2, cloudY2, CloudPic2); //����2 �׸���
        
         DrawBottomTrap(bottomTX, bottomTY); //�ٴ� ��ֹ� �׸���


         // 2. ���� ��ü 
         ScreenFlipping();
         // 3. ��ü�� ������ ������ ����
         ScreenClear();



         //���� ����
         if (GetAsyncKeyState(VK_DOWN)) {
             //1.���� �ʱ�ȭ
             ScreenInit();

             while (1) {
                 DrawGameOver(15, overPic);
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
    

     
    

};
