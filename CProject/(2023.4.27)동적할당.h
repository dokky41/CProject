#pragma once

#include <stdio.h> 
#include <malloc.h>

void main()
{

#pragma region 동적 할당
	// 프로그램을 실행 중에 필요한 만큼
	// 메모리를 할당하는 작업입니다.

	// 동적 할당은 실행 시간에 가변적으로 메모리의
	// 크기를 변경시킬 수 있으며, 동적으로 메모리의
	// 크기를 할당할 때 바이트 단위로 지정합니다.
	//int * ptr = (int *)malloc(sizeof(int)); 

	//// 메모리 동적 할당할 때 주소를 범용 포인터로 반환하기
	//// 때문에 자료형을 반환한 다음 메모리에 할당해야 합니다.
	//*ptr = 1000;

	//printf("동적 할당한 메모리 안에 있는 값: %d\n", *ptr);

	//// 메모리 해제
	//free(ptr);
	// 스택 영역의 ptr은 그대로지만
	// 힙 영역의 주소값이 사라지게 됨

	// free(ptr); 이미 해제된 메모리를 해제하면 Error





#pragma endregion

#pragma region ASCII 코드
	// 영문 알파벳을 사용하는 대표적인 문자 인코딩입니다.

	//char alphabet = 65;

	//printf("ASCII 코드 정수 값 : %d\n", alphabet);
	//printf("ASCII 코드 문자 값 : %c\n", alphabet);

	//// 문제) 알파벳 a ~ z까지 출력해주세요

	//for (char i = 'a'; i <= 'z'; i++)
	//{
	//	printf("%c ", i);
	//}






#pragma endregion

#pragma region 허상 포인터
	// 이미 해제된 메모리 영역을 가리키는 포인터입니다.

	//int* intPtr = malloc(sizeof(int)); //4byte 메모리공간할당

	//*intPtr = 300;
	//printf("intPtr이 가리키는 값 : %d \n", *intPtr);

	//free(intPtr);
	//printf("해제된 intPtr이 가리키는 값 : %d \n", *intPtr);

	//intPtr = NULL;

	// *intPtr = 100; Error





#pragma endregion

#pragma region 이중 포인터

	int a = 100;
	int* aPtr = &a;	   //단일포인터
	int** daPtr = &aPtr; //이중포인터

	//printf("**dptr의 값 : %p \n", *daPtr);  //주소값
	//printf("**dptr의 값 : %d \n", **daPtr); //값


	int b = 200;
	int* bPtr = &b;
	int** dbPtr = &bPtr;

	int num = 0;
	// 문제) aPtr과 bPtr을 이용해서 값을 스왑해주세요
	num = *aPtr;
	*aPtr = *bPtr;
	*bPtr = num;

	printf("a : %d b : %d \n", *aPtr, *bPtr);

	// 문제)이중 포인터를 이용해서 값을 스왑
	num = 0;

	num = **daPtr;
	**daPtr = **dbPtr;
	**dbPtr = num;

	printf("a : %d b : %d \n", **daPtr, **dbPtr);
#pragma endregion



}

