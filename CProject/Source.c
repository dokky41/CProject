#include <stdio.h> 

#pragma region �Լ�

	// �ϳ��� Ư���� ������ �۾��� �����ϱ� ����
	// ���������� ����� �ڵ��� ����

// void : ���� ��ȯ���� �ʴ� �ڷ���
void Attack() 
{
	for (int i = 0; i < 5; i++)
	{
		printf("���� \n");
	}
}

// ��ȯ�� : �Լ��� ����Ǿ��� �� ���� ��ȯ���ִ� ����
int Function() 
{
	return 100;
}

// �Լ��� ��� �ڷ����� ��ȯ�ϴ� ���� ���°�
// ��ġ���� ������ ���ϴ� ���� ���� �� ����
int ProcessInt()
{
	return 67.5f;
}

// �Լ��� ���� �̸��� �Լ��� �ߺ����� ������ �� ����

#pragma endregion

#pragma region �Ű� ����

// �Լ��� ���ǿ��� ���޹��� �μ��� �Լ� ���η� �����ϱ�
// ���� ����ϴ� �����Դϴ�.

void Calculator(int x)
{
	printf("�Ű� ���� x�� �� : %d \n", x);

}

int Add(int x, int y)
{
	return x + y;
}





#pragma endregion

// ���� ���� ���� ( �Լ� )
void swap(int a, int b)
{
	int temp = 0;

	printf("Swap �� -> a = %d, b = %d \n", a, b);

	temp = a;
	a = b;
	b = temp;

	printf("Swap �� -> a = %d, b = %d \n", a, b);
}

// ������ ���� ���� (�Լ�)
void SwapReference(int * x, int * y) {

	int temp=0;

	temp = * x;
	* x = * y;
	* y = temp;

}


void main()
{

#pragma region �Լ��� ȣ��(�Ű�����(X))

	// �Լ��� ȣ��
	//Attack();
	//Attack();

	/*printf("Function()�� �� : %d \n",Function());
	printf("ProcessInt()�� �� : %d \n", ProcessInt());*/


#pragma endregion


#pragma region �Լ��� ȣ��(�Ű�����(O))

	// �μ���?
	// �Լ��� ȣ��� �� �Ű������� ������ ���޵Ǵ� ��
	// Calculator(100);

	// �μ��� ���ʿ������� �Ű� ������ ���޵˴ϴ�.
	// printf("Add() �Լ��� �� : %d \n", Add(10,20));





#pragma endregion

#pragma region ���� ���� ���� & ������ ���� ����

	//int a = 100;
	//int b = 200;
	//int temp = 0;

	//// ����) a ������ b ������ ���� �ٲ��ּ���.

	//temp = a;
	//a = b;
	//b = temp;

	//printf("a = %d, b = %d \n", a, b);
	
	int a = 100;
	int b = 200;

	// call by value
	swap(a, b);
	printf("a: %d,  b: %d \n", a, b);

	// call by reference
	// �Լ��� ȣ���� �� ������ �ּҸ� �μ��� �����ϰ� �Ǹ�
	// ������ ������ �ּҰ� �����Ǿ� �μ��� ������ ���� 
	// �Լ� ������ �Ͼ ���꿡 ���� ������ �޽��ϴ�.

	SwapReference(&a, &b);
	printf("a: %d,  b: %d \n", a, b);


#pragma endregion


}

