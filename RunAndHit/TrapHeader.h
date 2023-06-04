#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

char CloudPic[10][30];
char CloudPic2[10][30];

char MountainPic[10][110];

//윗벽
char WallPic[100][100];

//도착지
char endpoint[100][100];

//적
char enemyPic[100][100];

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


//구름을 그리는 함수
void DrawCloud(int CloudX, int CloudY, char string[10][30])
{
   
    strcpy(CloudPic[0], "  @@@@@@@@@\n");
    strcpy(CloudPic[1], " @@@@    @@@\n");
    strcpy(CloudPic[2], "@@@@ 구름 @@@@\n");
    strcpy(CloudPic[3], " @@@@    @@@\n");
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

//2번째 구름을 그리는 함수
void DrawCloud2(int CloudX, int CloudY, char string[10][30])
{

    strcpy(CloudPic2[0], "  @@@@@@@@@\n");
    strcpy(CloudPic2[1], " @@@@    @@@\n");
    strcpy(CloudPic2[2], "@@@@ 구름 @@@@\n");
    strcpy(CloudPic2[3], " @@@@    @@@\n");
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



//바닥그리기
void BottomDraw()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    char string[] = "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
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

//중간 페이크 풀 그리기
void DrawGrass(int grassX, int grassY)
{
    char string[] = "∥";

    COORD cursorPosition = { grassX , grassY - 2 };
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

//밑바닥 트랩을 그리는 함수
void DrawBottomTrap(int bottomTX, int bottomTY)
{
    char string[] = "▲";

    COORD cursorPosition = { bottomTX , bottomTY-2};
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



//미터수를 계산하는 함수
void DrawMeter(int score,int bullet1, int bullet2)
{
    

    char string[100];
    sprintf(string, "도망친 거리 : %dM   샷건 : %d    머신건 : %d ", score,bullet1,bullet2);

    COORD cursorPosition = {5,0};
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





// 도착지 생성
void EndPoint(int endPointX, int endPointY, char string[100][100])
{
    

    strcpy(endpoint[0], "            ▧\n");
    strcpy(endpoint[1], "        ▧▧▧▧▧\n");
    strcpy(endpoint[2], "    ▧▧▧▧▧▧▧▧▧\n");
    strcpy(endpoint[3], "  ▧▧■■■■■■■▧▧\n");
    strcpy(endpoint[4], "  ▧▧■▧▧▧▧▧■▧▧\n");
    strcpy(endpoint[5], "  ▧▧■▧■■■▧■▧▧\n");
    strcpy(endpoint[6], "  ▧▧■▧■■■▧■▧▧\n");
    strcpy(endpoint[7], "  ▧▧■▧▥■■▧■▧▧\n");
    strcpy(endpoint[8], "  ▧▧■▧■■■▧■▧▧\n");
    strcpy(endpoint[9], "▧▧▧■▧▧▧▧▧■▧▧▧\n");

 
  

    for (int i = 0; i < 10; i++) {

        COORD cursorPosition = { endPointX,endPointY + i };
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



// 1번 적 생성
void DrawFristEnemy(int enemyX, int enemyY, char string[100][100])
{
    strcpy(enemyPic[0], "  ▧");
    strcpy(enemyPic[1], "＠■▧▧▧");
    strcpy(enemyPic[2], "  ▧");
    

    for (int i = 0; i < 3; i++) {

        COORD cursorPosition = { enemyX,enemyY + i };
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

char enemyPic2[100][100];

// 2번 적 생성
void DrawSecondEnemy(int enemyX, int enemyY, char string[100][100],int enemyHP)
{
    char aa[50];
    sprintf(aa, "      ●  %d", enemyHP);

    strcpy(enemyPic2[0], aa);
    strcpy(enemyPic2[1], "■■■■■■■");
    strcpy(enemyPic2[2], "■  ■■■  ■");
    strcpy(enemyPic2[3], "■  ■■■  ■");
    strcpy(enemyPic2[4], "    ■■■");
    strcpy(enemyPic2[5], "    ■  ■");
    strcpy(enemyPic2[6], "    ■  ■");


    for (int i = 0; i < 7; i++) {

        COORD cursorPosition = { enemyX,enemyY + i };
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

char enemyPic3[100][100];

// 3번 적 생성
void DrawThirdEnemy(int enemyX, int enemyY, char string[100][100], int enemyHP)
{
    char aa[50];
    sprintf(aa, "          ●  HP : %d", enemyHP);

    strcpy(enemyPic3[0], aa);
    strcpy(enemyPic3[1], "■■■■  ■  ■■■■");
    strcpy(enemyPic3[2], "  ■■■■■■■■■");
    strcpy(enemyPic3[3], "    ■■■■■■■");
    strcpy(enemyPic3[4], "■      ■■■      ■");
    strcpy(enemyPic3[4], "■■■■■■■■■■■");
    strcpy(enemyPic3[4], "        ■■■ ");
    strcpy(enemyPic3[5], "■■■■■■■■■■■");
    strcpy(enemyPic3[6], "        ■■■");
    strcpy(enemyPic3[7], "       ■   ■");
    strcpy(enemyPic3[8], "     ■■ ■■");


    for (int i = 0; i < 9; i++) {

        COORD cursorPosition = { enemyX,enemyY + i };
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




char skillPic[100][100];

// 샷건 쓰기
void DrawSkill(int skillX, int skillY, char string[100][100])
{
    strcpy(skillPic[0], "     ▨▨");
    strcpy(skillPic[1], "     ▨▨▨");
    strcpy(skillPic[2], "■▶ ▨▨▨▨");
    strcpy(skillPic[3], "     ▨▨▨");
    strcpy(skillPic[4], "     ▨▨");



    for (int i = 0; i < 5; i++) {

        COORD cursorPosition = { skillX,skillY + i };
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

// 헤비 머신건 쓰기
void DrawSkill2(int skillX, int skillY, char string[100][100])
{
    strcpy(skillPic[0], "     ");
    strcpy(skillPic[1], "◐   ");
    strcpy(skillPic[2], "■▶ ＝＝＝＝＝＝＝＝＝＝");
    strcpy(skillPic[3], "     ");
    strcpy(skillPic[4], "     ");



    for (int i = 0; i < 5; i++) {

        COORD cursorPosition = { skillX,skillY + i };
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

char stagePic1[100][100];

//스테이지 그림
void Stage1(int stageX, int stageY,char string [100][100],int score)
{
   
    if (score < 210) {

    strcpy(stagePic1[0], "  □□ □□□    □       □□□ □□□□   □");
    strcpy(stagePic1[1], "□       □     □□    □       □       □□");
    strcpy(stagePic1[2], "□□□   □    □  □   □  □□ □□□□   □ ");
    strcpy(stagePic1[3], "    □   □   □□□□  □    □ □         □");
    strcpy(stagePic1[4], "□□     □  □      □  □□□  □□□□ □□□");
    }

    if (score >= 210 && score< 500) {

        strcpy(stagePic1[0], "  □□ □□□    □       □□□ □□□□  □□□");
        strcpy(stagePic1[1], "□       □     □□    □       □       □   □");
        strcpy(stagePic1[2], "□□□   □    □  □   □  □□ □□□□     □ ");
        strcpy(stagePic1[3], "    □   □   □□□□  □    □ □         □");
        strcpy(stagePic1[4], "□□     □  □      □  □□□  □□□□ □□□□");
    }


    if (score >375) {

        strcpy(stagePic1[0], "  □□ □□□    □       □□□ □□□□  □□□");
        strcpy(stagePic1[1], "□       □     □□    □       □            □");
        strcpy(stagePic1[2], "□□□   □    □  □   □  □□ □□□□  □□□ ");
        strcpy(stagePic1[3], "    □   □   □□□□  □    □ □            □");
        strcpy(stagePic1[4], "□□     □  □      □  □□□  □□□□  □□□");
    }


    for (int i = 0; i < 5; i++) {

        COORD cursorPosition = { stageX,stageY +i};
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



