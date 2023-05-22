#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <windows.h>


#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

#define WIDTH 11
#define HEIGHT 11



typedef struct Player
{
	// 좌표값
	int x, y;
	// 캐릭터 모양
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

// 미로 맵 데이터
char maze[WIDTH][HEIGHT];

// 미로 맵 생성
void CreateMaze()
{
	// 0 : 빈 공간 (" ")
	// 1 : 벽 (ㅁ)
	// 2 : 탈출구 (◎)

	strcpy(maze[0], "00111111111");
	strcpy(maze[1], "10001111111");
	strcpy(maze[2], "11100000001");
	strcpy(maze[3], "11101111101");
	strcpy(maze[4], "11101111101");
	strcpy(maze[5], "11000000011");
	strcpy(maze[6], "11011111011");
	strcpy(maze[7], "10010000011");
	strcpy(maze[8], "11001111111");
    strcpy(maze[9], "11100000002");
   strcpy(maze[10], "11111111111");


}

// 0 : 빈 공간 (" ")
// 1 : 벽 (ㅁ)
// 2 : 탈출구 (◎)

void Renderer()
{
	// Hint 2중 for문 사용
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (maze[i][j] == '0')
			{
				printf("  ");
			}
			else if (maze[i][j] == '1')
			{
				printf("■");
			}
			else if (maze[i][j] == '2')
			{
				printf("◎");
			}

		}
		printf("\n");
	}


}

void Keyboard(char map[WIDTH][HEIGHT], Player * ptrPlayer)
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
		case UP: if (maze[ptrPlayer->y-1][ptrPlayer->x / 2] != '1') ptrPlayer->y--;
			break;
		case LEFT:if (maze[ptrPlayer->y][ptrPlayer->x / 2 - 1] != '1') ptrPlayer->x -= 2;
			break;
		case RIGHT:if (maze[ptrPlayer->y][ptrPlayer->x / 2 + 1] != '1') ptrPlayer->x += 2;
			break;
		case DOWN:if (maze[ptrPlayer->y+1][ptrPlayer->x / 2] != '1') ptrPlayer->y++;
			break;

		}

	}


}



int main()
{

#pragma region 미로 찾기

	Player player = {0, 0,"★"};
	
	CreateMaze();
	
	while (1)
	{
		Renderer();

		Keyboard(maze, &player);

		GotoXY(player.x, player.y);
		printf("%s", player.shape);

		Sleep(100);
		system("cls");
	}



	


#pragma endregion





	return 0;
}
