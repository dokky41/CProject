#include <stdio.h> // 기본 입출력 헤더 파일

void main()
{

#pragma region 오버플로우
	// 특정한 자료형이 표현할 수 있는 최대값의 범위
	// 넘어서 연산을 수행하는 과정입니다.
	
	// char 1 Byte(-128 ~ +127)
	/*char data = 128;
	printf("data의 값 : %d \n", data);*/

	// int <- 21억 
	// -21억 (21억이 넘어가서 -로 바뀌는 이유는 오버플로우 때문)




#pragma endregion

#pragma region 언더플로우

	// 특정한 자료형이 표현할 수 있는 최솟값의 
	// 범위를 넘어서 연산을 수행하는 과정입니다.

	/*char value = -128;
	printf("value의 값 : %d \n", value);*/




#pragma endregion

#pragma region 관계연산자

	// 두 개의 피연산자의 값을 비교하여 
	// 그 결과를 0 또는 1이라는 값으로 나타내는 연산자

	//int A = 5;
	//int B = 10 ;
	//
	//// A "<" B : B가 A보다 클 때 (참 1 거짓 0)
	//printf(" A < B : %d \n", A < B);

	//// A ">" B : B가 A보다 작을 때
	//printf(" A > B : %d \n", A > B);
	//

	//// A "<=" B : B가 A보다 크거나 같을 때
	//printf(" A <= B : %d \n", A <= B);

	//// A ">=" B : B가 A보다 작거나 같을 때
	//printf(" A >= B : %d \n", A >= B);

	//// A "==" B : A와 B가 같을 때
	//printf(" A == B : %d \n", A == B);

	//// A "!=" B : A와 B가 같지 않을 때
	//printf(" A != B : %d \n", A != B);






#pragma endregion

#pragma region 조건문(if ~ else if ~ else)
	// if 문 : 어떤 특정한 조건을 비교하여 조건이 
	//		   맞다면 실행되는 명령문입니다.

	// 만약에~ (조건)
	//if (15 == 15)
	//{
	//	// 조건이 "참" 이라면 {} 내부에 있는 내용을 실행합니다.
	//	printf("15는 15와 같다. \n");
	//}

	//else if 문 : if문의 조건이 틀릴 때 else if 문의 조건이 
	// 맞다면 실행되는 명령문

	//if (5 > 1)
	//{
	//	printf("if의 조건");
	//}
	//else if (5 == 5) 
	//{
	//	printf("else if의 조건");
	//}
	//else if (10 == 10) 
	//{
	//	// else if() 여러 개 선언할 수 있습니다.
	//	printf("else if의 조건");
	//}

	// else 문 : if문과 else if문의 조건이 다 틀리면 실행되는 명령문입니다.

	//if ('A' == 'B')
	//{
	//	printf("if 문");
	//}
	//else if ('C' == 'D') 
	//{
	//	printf("else if 문");
	//}
	//else
	//{
	//	printf("else 문");
	//}




#pragma endregion

#pragma region 논리 연산자
	//// && (AND)  조건이 모두 성립할때만 출력됨
	//if ('A' == 'A' && 'A' == 'A')
	//{
	//	printf("AND의 조건이 성립합니다. \n");
	//}
	//
	//// || (OR)
	//if ('A' == 'A' || 'A' == 'B')
	//{
	//	printf("OR의 조건이 성립합니다. \n");
	//}

	//// !  (NOT)
	//if (!'A')
	//{
	//	printf("NOT의 조건이 성립합니다. \n");
	//}


#pragma endregion


#pragma region 사분면



	//문제 사분면

	int x = 0;
	int y = 0;

	if (x > 0 && y > 0) {
		printf("제 1 사분면");
	}
	else if (x < 0 && y > 0) {
		printf("제 2 사분면");
	}
	else if (x < 0 && y < 0) {
		printf("제 3 사분면");
	}
	else if (x > 0 && y < 0) {
		printf("제 4 사분면");
	}
	else if (x != 0 && y == 0) {
		printf("x 절편");
	}
	else if (x == 0 && y != 0) {
		printf("y 절편");
	}
	else if (x == 0 && y == 0) {
		printf(" 원점 ");
	}



#pragma endregion




}

