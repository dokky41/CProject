#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define LEFT 75
#define RIGHT 77

#define height 30
#define width 60

typedef struct Player
{
	//좌표
	int x, y;
	const char* shape;

}Player;


// 좌표 이동 함수
void GotoXY(int x, int y)
{
	//좌표 정보를 저장하는 구조체 
	COORD position = { x,y };

	//좌표 정보를 설정
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

}

void Keyboard(Player* ptrPlayer)
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
		case LEFT: if (ptrPlayer->x <= 0) return; ptrPlayer->x -= 2;
			break;
		case RIGHT: if (ptrPlayer->x >= 28) return; ptrPlayer->x += 2;
			break;

		}

	}


}


int main()
{
	//화면크기지정
	system("mode con cols=30 lines=25");
	int count = 0;

#pragma region 똥피하기 
	// 1. x축으로만 이동
	// 2. 콘솔 크기 (가로 : 30 세로 : 60)
	// 3. x<0 작아졌다면 -로 이동못하도록
	// 4. Enemy의 x축은 랜덤으로 설정되도록 하며, y축이 아래로 내려오도록 설정
	// 똥과 플레이어가 충돌했다면 게임 오버
	srand(time(NULL));
	Player player = { 8,15,"★" };
	Player enemy = { 0,0,"＠" };
	enemy.x = rand() % 31;

	while (1)
	{

		if (enemy.y != 16)
		{
			GotoXY(enemy.x, enemy.y++);
			printf("%s", enemy.shape);

		}
		else {
			enemy.x = rand() % 31;
			enemy.y = 0;
			GotoXY(enemy.x, enemy.y++);
			printf("%s", enemy.shape);
			count++;
		}

		//플레이어
		Keyboard(&player);
		GotoXY(player.x, player.y);
		printf("%s", player.shape);

		if (enemy.x == player.x && enemy.y == player.y)
		{
			break;
		}


		system("cls");
	}


	printf("패배\n");
	printf("피한 갯수 : %d", count);

#pragma endregion






	return 0;
}
