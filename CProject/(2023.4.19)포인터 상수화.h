#pragma once

#include <stdio.h> // �⺻ ����� ��� ����

void main()
{

#pragma region ��� ���� ������

	// ������ ������ ����� �����Ͽ�, ������ ������ 
	// ����Ű�� �ִ� �ּҿ� �����ϴ� ���� ������ �� ������
	// �����ϴ� ���ȭ�Դϴ�.


	/*int data = 100;

	int * ptr = &data;

	*ptr = 300;*/
	// �� ���´� ���氡���� ����

	//int data = 100;
	//int data1 = 20;

	//const int * ptr = &data;

	//printf("ptr ������ �� : %p \n", ptr);
	////*ptr = 300; (������ ���� �������� ���ȭ�� �Ǿ��� ������)
	////            ERROR�� �߻���ŵ�ϴ�.

	//ptr = &data1;
	//printf("ptr ������ �� : %p \n", ptr);


#pragma endregion

#pragma region ������ ���

	// ����� ������ �������̹Ƿ�, �ش� ������ ���� ������ �� ������
	// �ٸ� ������ �ּ� ���� ����ų �� �ֽ��ϴ�.

	//int value1 = 30;
	//int value2 = 60;

	//int* const ptr1 = &value1;

	//printf("value1�� ���� %d \n", value1);

	//*ptr1 = 99999;  //�������� ����
	////ptr1 = &value2; (���ο� �ּҰ� ����)

	//printf("value1�� ���� %d \n", value1);


#pragma endregion

#pragma region sizeof(�ڷ���)

	/*float health = 66.5f;
	short * pointer= NULL;

	printf("char�� ũ�� : %d \n", sizeof(char));
	printf("short�� ũ�� : %d \n", sizeof(short));
	printf("int�� ũ�� : %d \n", sizeof(int));
	printf("long�� ũ�� : %d \n", sizeof(long));

	printf("float�� ũ�� : %d \n", sizeof(health));
	printf("double�� ũ�� : %d \n", sizeof(double));
	printf("long double�� ũ�� : %d \n", sizeof(long double));

	printf("pointer�� ũ�� : %d \n", sizeof(pointer));*/

#pragma endregion

#pragma region ������

	// 2 * 1 = 2
	// ~
	// 2 * 9 = 18

	// 9 * 9 = 81

	/*for (int i = 2; i < 10; i++) {

		for (int j = 1; j < 10; j++) {

			printf("%d * %d = %d  ", i, j, i * j);

		}
		printf("\n");

	}*/




#pragma endregion

#pragma region Scanf(�Է� �Լ�)

	// ǥ�� �Է� �Լ���, ���� ������ �����͸�
	// �پ��� ���Ŀ� ���߾� �Է����ִ� �Լ��Դϴ�.

	// scanf <- SDL �˻� ������ ���ϰ� ����ϰ� �Ǹ�
	//          ������ �����߻�

	// scanf_s("�Է��� ������ ����", &����(������ �ּҰ�))

	//int count = 0;

	//printf("count ������ ���� �Է����ּ���.");
	//scanf_s("%d", &count); //�ȿ� ���������� �ȵ�

	//// ǥ�� �Է� �Լ��� �Է��� ������ ������ ����
	//// �۾����� �Ѿ �� �����ϴ�.
	//printf("count ������ �� : %d", count);

	// �� ���
	// ����) ���� �Է��� ���� ���� ���� �������� �������ּ���
	// ex) 3 �Է�
	// ��
	// �١�
	// �١١�

	/*int x = 0;

	scanf_s("%d", &x);

	for (int i = 1; i <= x; i++) {

		for (int j = 1; j <= i; j++) {
			printf("��");
		}

		printf("\n");
	}*/



#pragma endregion




}

