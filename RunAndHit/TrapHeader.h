#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define BottomTrapX 163
#define BottomTrapY 43

#define CLOUD_BOTTOM_Y 10
#define CLOUD_BOTTOM_X 155
#define CLOUD_BOTTOM_Y2 3
#define CLOUD_BOTTOM_X2 155

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

//2��° ������ �׸��� �Լ�
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


//�عٴ� Ʈ���� �׸��� �Լ�
void DrawBottomTrap(int bottomTX, int bottomTY)
{
    BottomDraw();
    
    char string[] = "��";

    COORD cursorPosition = { bottomTX - 20, bottomTY - 10 };
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

