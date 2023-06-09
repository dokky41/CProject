#pragma once

#include <stdio.h> 
#include "SoundManager.h"

#pragma region 재귀 함수
// 어떤 함수에서 자신을 다시 호출하여
// 작업을 수행하는 함수입니다.

void Recursion(int x)
{
	if (x == 1)
	{
		// 재귀 함수는 함수를 계속 호출하기 때문에
		// 스택 영역에 메모리가 계속 쌓이게 되므로
		// 스택 오버플로우가 발생합니다.

		return;
	}

	printf("Recursion() 함수 호출 \n");

	Recursion(x - 1);

}


#pragma endregion

#pragma region 팩토리얼

//    

int Factorial(int x)
{
	// 특정한 조건이 되었을 때 return 

	if (x == 1)
	{
		return 1;
	}
	// 특정한 조건이 아니라면 재귀 함수 실행
	else
	{
		return x * Factorial(x - 1);
	}
}

#pragma endregion

#pragma region 인라인 함수
// 함수를 호출하는 대신 함수가 호출되는 위치마다
// 함수의 코드를 복사하여 전달하는 방식의 함수입니다.

inline void Function()
{
	// 인라인 함수는 함수를 호출하는 과정이 없으므로
	// 처리 속도가 빠르지만, 인라인 함수를 많이 사용하면
	// 함수의 코드가 복사되기 때문에 실행 파일의 
	// 크기가 커짐
	printf("Function() 호출 \n");
	// 보통 1,2줄 정도의 짧은 코드에 많이 활용
}

#pragma endregion


void main()
{
	// 재귀함수
	// Recursion(3);

	// 팩토리얼 (n!)
	// printf("팩토리얼 값 : %d \n ", Factorial(3));

	// 인라인 함수
	// Function(); 
	// printf("Function() 호출") 이렇게 처리해줌
	// 즉 그냥 코드 자체를 복사해서 넣어줌

#pragma region 반복문(do~while)

	// 조건과 상관없이 한번의 작업을 수행한 다음
	// 조건에 따라 명령문을 실행하는 반복문입니다.

	//int count = 3;

	//do 
	//{
	//	printf("로그인 시도\n");
	//	count--;
	//} 
	//while (count > 0);

#pragma endregion

	//Sound();



}

