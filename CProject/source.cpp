#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define LEFT 75
#define RIGHT 77

#define height 30
#define width 60

typedef struct Player
{
	//��ǥ
	int x, y;
	const char* shape;

}Player;

typedef struct Enemy
{
	//��ǥ
	int x, y;
	const char* shape;

}Enemy;

// ��ǥ �̵� �Լ�
void GotoXY(int x, int y)
{
	//��ǥ ������ �����ϴ� ����ü 
	COORD position = { x,y };

	//��ǥ ������ ����
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
		case LEFT: if (ptrPlayer->x <= 0) return;  ptrPlayer->x -= 2;
			break;
		case RIGHT:if (ptrPlayer->x >= 28) return;  ptrPlayer->x += 2;
			break;

		}

	}


}

int RandomX()
{
	srand(time(NULL));

	int random = rand() % 31;

	if (random % 2 == 1)
	{
		random += 1;
	}

	return random;
}

int main()
{
	system("mode con cols=30 lines=25");


#pragma region �����ϱ� 
	// 1. x�����θ� �̵�
	// 2. �ܼ� ũ�� (���� : 30 ���� : 60)
	// 3. x<0 �۾����ٸ� -�� �̵����ϵ���
	// 4. Enemy�� x���� �������� �����ǵ��� �ϸ�, y���� �Ʒ��� ���������� ����
	// �˰� �÷��̾ �浹�ߴٸ� ���� ����
	Player player = { 16,23,"��" };
	Enemy enemy = { RandomX(),0,"��" };

	while (1)
	{
		Keyboard(&player);

		GotoXY(enemy.x, enemy.y++);
		printf("%s", enemy.shape);

		if (enemy.y >= 24)
		{
			enemy.y = 0;
			enemy.x = RandomX();
		}

		if (player.x == enemy.x && player.y == enemy.y)
		{
			printf("�й�");
			break;
		}

		GotoXY(player.x, player.y);
		printf("%s", player.shape);

		Sleep(100);
		system("cls");

	}



#pragma endregion






	return 0;
}
