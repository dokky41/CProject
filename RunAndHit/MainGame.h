#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define MONSTER_BOTTOM_Y 28

#define ME_BOTTOM_X 70
#define ME_BOTTOM_Y 32

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

// ����
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>

// HANDLE �ε����� �����ؼ� ���۸� ��ü��Ű�� ����
int screenIndex = 0;

// ������ ũ��
int width = 100;
int height = 60;

// ���� ����
HANDLE Screen[2]; // [0] front buffer
// [1] back buffer

// ���۸� �ʱ�ȭ�ϴ� �Լ�
void ScreenInit()
{
    CONSOLE_CURSOR_INFO cursor;

    // ������ ���� ������, ���� ������
    COORD size = { width, height };

    // Left, Top, Right, Bottom
    SMALL_RECT rect = { 0, 0, width - 1, height - 1 };

    // ȭ�� 2���� �����մϴ�.
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

    // Ŀ���� Ȱ��ȭ ����
    // false : ����
    // true : ��
    cursor.bVisible = 0;

    SetConsoleCursorInfo(Screen[0], &cursor);
    SetConsoleCursorInfo(Screen[1], &cursor);
}


// ���۸� ��ü�ϴ� �Լ�
void ScreenFlipping()
{
    // ���۴� �ϳ��� Ȱ��ȭ��ų �� �ֽ��ϴ�.
    SetConsoleActiveScreenBuffer(Screen[screenIndex]);

    screenIndex = !screenIndex;
}

// ��ü�� ���۸� �����ִ� �Լ�
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

// ���۸� �����ϴ� �Լ�
void ScreenRelease()
{
    CloseHandle(Screen[0]);
    CloseHandle(Screen[1]);
}



// Ŀ���� ��ġ�� x,y �� �̵��ϴ� �Լ�
void GotoXY2(int x, int y)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// Ŀ���� ��ġ�� x,y �� �̵��ϴ� �Լ�
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void BottomDraw()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    char  string[] = "�����������������������������������������������������������������������������������";
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

char MonsterPic[11][23];

//������ �׸��� �Լ�
void DrawMonster(int monsterX, char string[11][23])
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
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
    strcpy(MonsterPic[11], "    $    $\n");
    strcpy(MonsterPic[12], "    $$   $$\n");
    

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

//�ù��� �׸��� �Լ�
void DrawMe(int MeX,int MeY, char string[5][10])
{

    strcpy(MePic[0], " ��\n");
    strcpy(MePic[1], "\n");
     strcpy(MePic[2], " ��\n");
    strcpy(MePic[3], "�Ǧ��� \n");
     strcpy(MePic[4], " /��");

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




void GameStart2()
{
    CursorView(); //Ŀ�� ������ ���ֱ�
    //PlaySound(TEXT("Sound.wav"), NULL, SND_ASYNC);
   
    bool isJumping = false;
    bool isBottom = true;
    const int gravity = 3; // ���� ����

    int monsterY = MONSTER_BOTTOM_Y; //���� Y��
    int meX = ME_BOTTOM_X; //�� X��
    int meY = ME_BOTTOM_Y; //�� X��
    char key = 0;

     while(true)
     {
           
             
             if (GetAsyncKeyState(VK_LEFT))
             {
                 if (meX > 0) {
                     Sleep(10);
                     meX--;
                 }
             }
             if (GetAsyncKeyState(VK_RIGHT))
             {
                 if (meX < 159) {
                 Sleep(10);
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

         


         // 1. ���� �ʱ�ȭ
         ScreenInit();

         BottomDraw(); //�ٴ� �׸���
         
  
         DrawMonster(monsterY+1, MonsterPic);  //�����׸���
         DrawMe(meX,meY,MePic);  //�� �׸���
     
         // 2. ���� ��ü 
         ScreenFlipping();
         // 3. ��ü�� ������ ������ ����
         ScreenClear();

     }

     // ������ ����Ǿ��� �� ���۸� �����մϴ�.
     ScreenRelease();
    


   

};
