#pragma once

#include <stdio.h> 
#include <malloc.h>

void main()
{

#pragma region ���� �Ҵ�
	// ���α׷��� ���� �߿� �ʿ��� ��ŭ
	// �޸𸮸� �Ҵ��ϴ� �۾��Դϴ�.

	// ���� �Ҵ��� ���� �ð��� ���������� �޸���
	// ũ�⸦ �����ų �� ������, �������� �޸���
	// ũ�⸦ �Ҵ��� �� ����Ʈ ������ �����մϴ�.
	//int * ptr = (int *)malloc(sizeof(int)); 

	//// �޸� ���� �Ҵ��� �� �ּҸ� ���� �����ͷ� ��ȯ�ϱ�
	//// ������ �ڷ����� ��ȯ�� ���� �޸𸮿� �Ҵ��ؾ� �մϴ�.
	//*ptr = 1000;

	//printf("���� �Ҵ��� �޸� �ȿ� �ִ� ��: %d\n", *ptr);

	//// �޸� ����
	//free(ptr);
	// ���� ������ ptr�� �״������
	// �� ������ �ּҰ��� ������� ��

	// free(ptr); �̹� ������ �޸𸮸� �����ϸ� Error





#pragma endregion

#pragma region ASCII �ڵ�
	// ���� ���ĺ��� ����ϴ� ��ǥ���� ���� ���ڵ��Դϴ�.

	//char alphabet = 65;

	//printf("ASCII �ڵ� ���� �� : %d\n", alphabet);
	//printf("ASCII �ڵ� ���� �� : %c\n", alphabet);

	//// ����) ���ĺ� a ~ z���� ������ּ���

	//for (char i = 'a'; i <= 'z'; i++)
	//{
	//	printf("%c ", i);
	//}






#pragma endregion

#pragma region ��� ������
	// �̹� ������ �޸� ������ ����Ű�� �������Դϴ�.

	//int* intPtr = malloc(sizeof(int)); //4byte �޸𸮰����Ҵ�

	//*intPtr = 300;
	//printf("intPtr�� ����Ű�� �� : %d \n", *intPtr);

	//free(intPtr);
	//printf("������ intPtr�� ����Ű�� �� : %d \n", *intPtr);

	//intPtr = NULL;

	// *intPtr = 100; Error





#pragma endregion

#pragma region ���� ������

	int a = 100;
	int* aPtr = &a;	   //����������
	int** daPtr = &aPtr; //����������

	//printf("**dptr�� �� : %p \n", *daPtr);  //�ּҰ�
	//printf("**dptr�� �� : %d \n", **daPtr); //��


	int b = 200;
	int* bPtr = &b;
	int** dbPtr = &bPtr;

	int num = 0;
	// ����) aPtr�� bPtr�� �̿��ؼ� ���� �������ּ���
	num = *aPtr;
	*aPtr = *bPtr;
	*bPtr = num;

	printf("a : %d b : %d \n", *aPtr, *bPtr);

	// ����)���� �����͸� �̿��ؼ� ���� ����
	num = 0;

	num = **daPtr;
	**daPtr = **dbPtr;
	**dbPtr = num;

	printf("a : %d b : %d \n", **daPtr, **dbPtr);
#pragma endregion



}

