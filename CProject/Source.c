#include <stdio.h> 

#pragma region ����ü
	// ���� ���� ������ �ϳ��� �������� ����ȭ��
	// ���� �ϳ��� ��ü�� �����ϴ� ���Դϴ�.

struct Player //12byte�� ����? 
{
	char grade;
	int attack;
	float health;

	// ����ü�� �����ϱ� ���� ����ü�� �޸� ������ 
	// �������� �����Ƿ�, ����ü ���ο� �ִ� �����͸�
	// �ʱ�ȭ�� �� �����ϴ�.
};

struct Model
{
	int weight; // 4byte
	short mesh; // 2byte
	// Padding     2byte
	double size; // 8byte

	// ����ü�� ũ���� ��� ��� ������ ������ ����
	// �޸��� ũ�Ⱑ �ٸ��� ������ �� ������,
	// ����ü ũ�⸦ �����ϴ� ���´� �⺻ �ڷ������θ�
	// �����˴ϴ�

};


#pragma endregion


void main()
{

#pragma region  ����ü 


	struct Player player; //���ÿ� �Ҵ��

	/*player.attack = 10;
	player.grade = 'A';
	player.health = 91.25f;

	printf("player.attack�� �� : %d \n", player.attack);
	printf("player.grade�� �� : %c \n", player.grade);
	printf("player.health�� �� : %f \n", player.health);*/

	// ����ü �ʱ�ȭ
	// ����ü�� �ʱ�ȭ ����Ʈ�� �ʱ�ȭ�� �� ����ü�� �����
	// ������ ������ �������ּž� �մϴ�.

	//                          char int float
	/*struct Player newPlayer = { 'B',15,66.85f };

	printf("newPlayer.grade�� �� : %c \n", newPlayer.grade);
	printf("newPlayer.attack�� �� : %d \n", newPlayer.attack);
	printf("newPlayer.health�� �� : %f \n", newPlayer.health);*/

#pragma endregion

#pragma region ����Ʈ �е�
	// ��� ������ �޸𸮿��� CPU�� ���� �� �� ���� 
	// ���� �� �ֵ���, �����Ϸ��� ���������� ��Ͽ�
	// ���߾� ����Ʈ�� �е� ���ִ� �۾��Դϴ�.

	//struct Player otherPlayer;
	//// ����ü�� ũ��� ����ü�� �����ϴ� ��� �߿� 
	//// ũ�Ⱑ ���� ū �ڷ����� ����� �ǵ��� �����մϴ�.
	//printf("Player�� ũ�� : %d \n", sizeof(otherPlayer));


	//struct Model model;
	//printf("model�� ũ�� : %d \n", sizeof(model));
	


#pragma endregion

#pragma region �Ҽ�
	// 1���� ū �ڿ��� �� 1�� �ڱ� �ڽŸ��� �����
	// ������ ����.
	/*int count = 0;
	int number = 0;

	printf("�� �Է� : ");
	scanf_s("%d", &number);

	for (int i = 2; i <= number; i++)
	{
		if (number %i == 0)
		{
			count++;
		}

	}

	if (count == 1)
	{
		printf("�Ҽ��Դϴ�.");
	}
	else {
		printf("�Ҽ��� �ƴմϴ�");
	}*/






#pragma endregion


}

