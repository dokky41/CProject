#include <stdio.h> 


int main()
{

	//return 0; �� ��� �ؿ� �ڵ�� ����ȵ�
#pragma region ������ �迭

	// [8byte] [8byte] [8byte]
	/*const char * string[3];*/


	// 0��° Index [First�� �����ּ�]
	
	//string[0] = "First";
	//string[1] = "Second";
	//string[2] = "Third";

	//for (int i = 0; i < 3; i++)
	//{
	//	printf("string[%d]�� �� : %s\n", i, string[i]);
	//}

	
	//int�� ������ �迭

	//int a = 10;
	//int b = 20;
	//int c = 30;

	//int* ptr1 = &a;
	//int* ptr2 = &b;
	//int* ptr3 = &c;

	//int* arrayPtr[] = { ptr1,ptr2,ptr3 };
	////arrayPtr[0] = ptr1; //arrayPtr[1] = ptr2; //arrayPtr[2] = ptr3;

	//for (int i = 0; i < 3; i++)
	//{
	//	printf("arrayPtr[%d]�� �� : %d\n", i, *arrayPtr[i]);
	//}





#pragma endregion


#pragma region unsigned(��ȣ���� �ڷ���)
	// ��ȣ�� ���� �ڷ������� ��ȣ ��Ʈ�� ����
	// �ڷḦ ������ �� �ִ� ������ ������ 2���
	// �þ�� �ڷ����Դϴ�.

	// ��ȣ
	// [1]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]
	// - 128
	//char data = 128; // - 128 ~ 127

	//// ��ȣ
	//// [1]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]
	//// 128   64   32  16    8    4    2    1
	//unsigned char uData = 128;
	//
	//// signed �ڷ����� ������ ����ȯ�� ����� ��
	//// �þ�� �޸� ���� 1(��ȣ��Ʈ)�� ä�����ϴ�.

	//// [] [] [] []
	//// [1] [1] [1] [10000000] �ִ밪 - 1111111 ��ŭ���� ��°��� ����
	//printf("data�� �� : %d\n", data);
	//printf("data�� �� : %u\n", data);

	//// %u : unsigned int �� ���� ǥ���ϴ� ���� �������Դϴ�.

	//// �� �� ��ȣ�� ���� ǥ���̹Ƿ� ������ ����ȯ�� ����� ��
	//// �þ�� �޸� ���� 0���� ä�����ϴ�.
	//printf("uData�� �� : %d\n", uData);
	//printf("uData�� �� : %u\n", uData); 

	// [11111111]
	// 1 byte (char) uData
	 
	// [0] [0] [0] [11111111]
	// 4 byte




#pragma endregion


#pragma region �����
	// �� ���� ������ ���� ����
	// ex) int x, y;
	// x�� y������ �Է��� ���� �����ϰ�
	// x�� y�� ����� ����� ã���ּ���

	int x = 0, y = 0;

	printf("�Է��ϼ��� : ");
	scanf_s("%d", &x);
	scanf_s("%d", &y);

	for (int i = 1; i <= x && i <= y; i++)
	{
		if (x % i == 0 && y % i == 0)
		{
			printf("����� : %d ", i);
		}
		
	}


#pragma endregion





	return 0;
}

