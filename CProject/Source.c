#include <stdio.h> 


int main()
{

	//return 0; 이 경우 밑에 코드는 실행안됨
#pragma region 포인터 배열

	// [8byte] [8byte] [8byte]
	/*const char * string[3];*/


	// 0번째 Index [First의 시작주소]
	
	//string[0] = "First";
	//string[1] = "Second";
	//string[2] = "Third";

	//for (int i = 0; i < 3; i++)
	//{
	//	printf("string[%d]의 값 : %s\n", i, string[i]);
	//}

	
	//int형 포인터 배열

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
	//	printf("arrayPtr[%d]의 값 : %d\n", i, *arrayPtr[i]);
	//}





#pragma endregion


#pragma region unsigned(부호없는 자료형)
	// 부호가 없는 자료형으로 부호 비트가 없고
	// 자료를 저장할 수 있는 데이터 영역이 2배로
	// 늘어나는 자료형입니다.

	// 부호
	// [1]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]
	// - 128
	//char data = 128; // - 128 ~ 127

	//// 부호
	//// [1]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]
	//// 128   64   32  16    8    4    2    1
	//unsigned char uData = 128;
	//
	//// signed 자료형은 묵시적 형변환이 진행될 때
	//// 늘어나는 메모리 값은 1(부호비트)로 채워집니다.

	//// [] [] [] []
	//// [1] [1] [1] [10000000] 최대값 - 1111111 만큼빼면 출력값이 나옴
	//printf("data의 값 : %d\n", data);
	//printf("data의 값 : %u\n", data);

	//// %u : unsigned int 형 값을 표현하는 서식 지정자입니다.

	//// 둘 다 부호가 없는 표현이므로 묵시적 형변환이 진행될 때
	//// 늘어나는 메모리 값은 0으로 채워집니다.
	//printf("uData의 값 : %d\n", uData);
	//printf("uData의 값 : %u\n", uData); 

	// [11111111]
	// 1 byte (char) uData
	 
	// [0] [0] [0] [11111111]
	// 4 byte




#pragma endregion


#pragma region 공약수
	// 두 개의 정수형 변수 선언
	// ex) int x, y;
	// x와 y변수에 입력한 값을 저장하고
	// x와 y의 공통된 약수를 찾아주세요

	int x = 0, y = 0;

	printf("입력하세요 : ");
	scanf_s("%d", &x);
	scanf_s("%d", &y);

	for (int i = 1; i <= x && i <= y; i++)
	{
		if (x % i == 0 && y % i == 0)
		{
			printf("공약수 : %d ", i);
		}
		
	}


#pragma endregion





	return 0;
}

