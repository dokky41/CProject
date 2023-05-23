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
	//��ǥ
	int x, y;
	const char* shape;

}Player;


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
		case LEFT: if (ptrPlayer->x <= 0) return; ptrPlayer->x -= 2;
			break;
		case RIGHT: if (ptrPlayer->x >= 28) return; ptrPlayer->x += 2;
			break;

		}

	}


}


int main()
{
	//ȭ��ũ������
	system("mode con cols=30 lines=25");
	int count = 0;

#pragma region �����ϱ� 
	// 1. x�����θ� �̵�
	// 2. �ܼ� ũ�� (���� : 30 ���� : 60)
	// 3. x<0 �۾����ٸ� -�� �̵����ϵ���
	// 4. Enemy�� x���� �������� �����ǵ��� �ϸ�, y���� �Ʒ��� ���������� ����
	// �˰� �÷��̾ �浹�ߴٸ� ���� ����
	srand(time(NULL));
	Player player = { 8,15,"��" };
	Player enemy = { 0,0,"��" };
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

		//�÷��̾�
		Keyboard(&player);
		GotoXY(player.x, player.y);
		printf("%s", player.shape);

		if (enemy.x == player.x && enemy.y == player.y)
		{
			break;
		}


		system("cls");
	}


	printf("�й�\n");
	printf("���� ���� : %d", count);

#pragma endregion






	return 0;
}
