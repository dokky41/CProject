#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "LoadManager.h"

#define UP 72
#define DOWN 80

// 좌표 이동 함수
void GotoXY(int x, int y)
{
	//좌표 정보를 저장하는 구조체 
	COORD position = { x,y };

	//좌표 정보를 설정
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

}

typedef struct Select
{
	int x, y;
	const char* shape;

}Select;


void Keyboard(Select * selectPtr)
{
	char key = 0;

	if (_kbhit())
	{
		key = _getch();

		if (key == -32)
		{
			key = _getch();
		}

		switch (key)
		{
		case UP: selectPtr->y -= 5;
			break;
		case DOWN: selectPtr->y += 5;
			break;

		}

	
	}


}

//타이핑 효과
void Typing(unsigned int speed, const char * content)
{
	int i = 0;

	while (content[i] != '\0')
	{
		printf("%c", content[i++]);
		fflush(stdout); //버퍼 비우기
		Sleep(speed);
	}

}



int main()
{
	
	//ReadTextFile("Resources/DB.txt");
	//Typing(100, "Hello~");
	
	int stage = 0;

	Select select = { 15,29,"☞" };

	while (1)
	{

		Keyboard(&select);

		switch (stage)
		{
			case 0 : ReadTextFile("Resources/DB.txt");
				break;
			case 1 : ReadTextFile("Resources/DB.txt");
				break;
		}
		
		GotoXY(select.x,select.y);
		printf("%s", select.shape);
		system("cls");
	}



	return 0;
}
