#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

char CloudPic[10][30];
char CloudPic2[10][30];

char MountainPic[10][110];

//����
char WallPic[100][100];

//������
char endpoint[100][100];

//��
char enemyPic[100][100];

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


//������ �׸��� �Լ�
void DrawCloud(int CloudX, int CloudY, char string[10][30])
{
   
    strcpy(CloudPic[0], "  @@@@@@@@@\n");
    strcpy(CloudPic[1], " @@@@    @@@\n");
    strcpy(CloudPic[2], "@@@@ ���� @@@@\n");
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

//2��° ������ �׸��� �Լ�
void DrawCloud2(int CloudX, int CloudY, char string[10][30])
{

    strcpy(CloudPic2[0], "  @@@@@@@@@\n");
    strcpy(CloudPic2[1], " @@@@    @@@\n");
    strcpy(CloudPic2[2], "@@@@ ���� @@@@\n");
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



//�ٴڱ׸���
void BottomDraw()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    char string[] = "�����������������������������������������������������������������������������������";
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

//�߰� ����ũ Ǯ �׸���
void DrawGrass(int grassX, int grassY)
{
    char string[] = "��";

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

//�عٴ� Ʈ���� �׸��� �Լ�
void DrawBottomTrap(int bottomTX, int bottomTY)
{
    char string[] = "��";

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



//���ͼ��� ����ϴ� �Լ�
void DrawMeter(int score,int bullet1, int bullet2)
{
    

    char string[100];
    sprintf(string, "����ģ �Ÿ� : %dM   ���� : %d    �ӽŰ� : %d ", score,bullet1,bullet2);

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





// ������ ����
void EndPoint(int endPointX, int endPointY, char string[100][100])
{
    

    strcpy(endpoint[0], "            ��\n");
    strcpy(endpoint[1], "        �ʢʢʢʢ�\n");
    strcpy(endpoint[2], "    �ʢʢʢʢʢʢʢʢ�\n");
    strcpy(endpoint[3], "  �ʢʡ�������ʢ�\n");
    strcpy(endpoint[4], "  �ʢʡ�ʢʢʢʢʡ�ʢ�\n");
    strcpy(endpoint[5], "  �ʢʡ�ʡ���ʡ�ʢ�\n");
    strcpy(endpoint[6], "  �ʢʡ�ʡ���ʡ�ʢ�\n");
    strcpy(endpoint[7], "  �ʢʡ�ʢȡ��ʡ�ʢ�\n");
    strcpy(endpoint[8], "  �ʢʡ�ʡ���ʡ�ʢ�\n");
    strcpy(endpoint[9], "�ʢʢʡ�ʢʢʢʢʡ�ʢʢ�\n");

 
  

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



// 1�� �� ����
void DrawFristEnemy(int enemyX, int enemyY, char string[100][100])
{
    strcpy(enemyPic[0], "  ��");
    strcpy(enemyPic[1], "����ʢʢ�");
    strcpy(enemyPic[2], "  ��");
    

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

// 2�� �� ����
void DrawSecondEnemy(int enemyX, int enemyY, char string[100][100],int enemyHP)
{
    char aa[50];
    sprintf(aa, "      ��  %d", enemyHP);

    strcpy(enemyPic2[0], aa);
    strcpy(enemyPic2[1], "��������");
    strcpy(enemyPic2[2], "��  ����  ��");
    strcpy(enemyPic2[3], "��  ����  ��");
    strcpy(enemyPic2[4], "    ����");
    strcpy(enemyPic2[5], "    ��  ��");
    strcpy(enemyPic2[6], "    ��  ��");


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

// 3�� �� ����
void DrawThirdEnemy(int enemyX, int enemyY, char string[100][100], int enemyHP)
{
    char aa[50];
    sprintf(aa, "          ��  HP : %d", enemyHP);

    strcpy(enemyPic3[0], aa);
    strcpy(enemyPic3[1], "�����  ��  �����");
    strcpy(enemyPic3[2], "  ����������");
    strcpy(enemyPic3[3], "    ��������");
    strcpy(enemyPic3[4], "��      ����      ��");
    strcpy(enemyPic3[4], "������������");
    strcpy(enemyPic3[4], "        ���� ");
    strcpy(enemyPic3[5], "������������");
    strcpy(enemyPic3[6], "        ����");
    strcpy(enemyPic3[7], "       ��   ��");
    strcpy(enemyPic3[8], "     ��� ���");


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

// ���� ����
void DrawSkill(int skillX, int skillY, char string[100][100])
{
    strcpy(skillPic[0], "     �ɢ�");
    strcpy(skillPic[1], "     �ɢɢ�");
    strcpy(skillPic[2], "�ᢺ �ɢɢɢ�");
    strcpy(skillPic[3], "     �ɢɢ�");
    strcpy(skillPic[4], "     �ɢ�");



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

// ��� �ӽŰ� ����
void DrawSkill2(int skillX, int skillY, char string[100][100])
{
    strcpy(skillPic[0], "     ");
    strcpy(skillPic[1], "��   ");
    strcpy(skillPic[2], "�ᢺ ��������������������");
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

//�������� �׸�
void Stage1(int stageX, int stageY,char string [100][100],int score)
{
   
    if (score < 210) {

    strcpy(stagePic1[0], "  ��� ����    ��       ���� �����   ��");
    strcpy(stagePic1[1], "��       ��     ���    ��       ��       ���");
    strcpy(stagePic1[2], "����   ��    ��  ��   ��  ��� �����   �� ");
    strcpy(stagePic1[3], "    ��   ��   �����  ��    �� ��         ��");
    strcpy(stagePic1[4], "���     ��  ��      ��  ����  ����� ����");
    }

    if (score >= 210 && score< 500) {

        strcpy(stagePic1[0], "  ��� ����    ��       ���� �����  ����");
        strcpy(stagePic1[1], "��       ��     ���    ��       ��       ��   ��");
        strcpy(stagePic1[2], "����   ��    ��  ��   ��  ��� �����     �� ");
        strcpy(stagePic1[3], "    ��   ��   �����  ��    �� ��         ��");
        strcpy(stagePic1[4], "���     ��  ��      ��  ����  ����� �����");
    }


    if (score >375) {

        strcpy(stagePic1[0], "  ��� ����    ��       ���� �����  ����");
        strcpy(stagePic1[1], "��       ��     ���    ��       ��            ��");
        strcpy(stagePic1[2], "����   ��    ��  ��   ��  ��� �����  ���� ");
        strcpy(stagePic1[3], "    ��   ��   �����  ��    �� ��            ��");
        strcpy(stagePic1[4], "���     ��  ��      ��  ����  �����  ����");
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



