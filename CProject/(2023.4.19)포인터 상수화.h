#pragma once

#include <stdio.h> // 기본 입출력 헤더 파일

void main()
{

#pragma region 상수 지시 포인터

	// 포인터 변수를 상수로 선언하여, 포인터 변수가 
	// 가리키고 있는 주소에 존재하는 값을 변경할 수 없도록
	// 설정하는 상수화입니다.


	/*int data = 100;

	int * ptr = &data;

	*ptr = 300;*/
	// 위 상태는 변경가능한 상태

	//int data = 100;
	//int data1 = 20;

	//const int * ptr = &data;

	//printf("ptr 변수의 값 : %p \n", ptr);
	////*ptr = 300; (포인터 변수 역참조는 상수화가 되었기 때문에)
	////            ERROR를 발생시킵니다.

	//ptr = &data1;
	//printf("ptr 변수의 값 : %p \n", ptr);


#pragma endregion

#pragma region 포인터 상수

	// 상수로 선언한 포인터이므로, 해당 변수의 값을 변경할 수 없지만
	// 다른 변수의 주소 값을 가리킬 수 있습니다.

	//int value1 = 30;
	//int value2 = 60;

	//int* const ptr1 = &value1;

	//printf("value1의 값은 %d \n", value1);

	//*ptr1 = 99999;  //역참조는 가능
	////ptr1 = &value2; (새로운 주소값 에러)

	//printf("value1의 값은 %d \n", value1);


#pragma endregion

#pragma region sizeof(자료형)

	/*float health = 66.5f;
	short * pointer= NULL;

	printf("char의 크기 : %d \n", sizeof(char));
	printf("short의 크기 : %d \n", sizeof(short));
	printf("int의 크기 : %d \n", sizeof(int));
	printf("long의 크기 : %d \n", sizeof(long));

	printf("float의 크기 : %d \n", sizeof(health));
	printf("double의 크기 : %d \n", sizeof(double));
	printf("long double의 크기 : %d \n", sizeof(long double));

	printf("pointer의 크기 : %d \n", sizeof(pointer));*/

#pragma endregion

#pragma region 구구단

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

#pragma region Scanf(입력 함수)

	// 표준 입력 함수로, 여러 종류의 데이터를
	// 다양한 서식에 맞추어 입력해주는 함수입니다.

	// scanf <- SDL 검사 해제를 안하고 사용하게 되면
	//          컴파일 에러발생

	// scanf_s("입력할 변수의 서식", &변수(변수의 주소값))

	//int count = 0;

	//printf("count 변수의 값을 입력해주세요.");
	//scanf_s("%d", &count); //안에 문장적으면 안됨

	//// 표준 입력 함수는 입력을 수행할 때까지 다음
	//// 작업으로 넘어갈 수 없습니다.
	//printf("count 변수의 값 : %d", count);

	// 별 찍기
	// 문제) 내가 입력한 값에 따라 별이 찍히도록 구현해주세요
	// ex) 3 입력
	// ☆
	// ☆☆
	// ☆☆☆

	/*int x = 0;

	scanf_s("%d", &x);

	for (int i = 1; i <= x; i++) {

		for (int j = 1; j <= i; j++) {
			printf("☆");
		}

		printf("\n");
	}*/



#pragma endregion




}

