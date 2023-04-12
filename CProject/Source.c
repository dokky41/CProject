#include <stdio.h>

void main() // <- void main 하나만 존재해야 합니다.
{
#pragma region 변수

	// 데이터를 저장할 수 있는 메모리 공간을 생성하는 것 입니다.

	// 자료형이란? 
	// 데이터를 저장하기 위한 데이터의 형태를 정해주는 것입니다.

	// 자료형 변수의 이름
	// ;(세미콜론) : 한 문장의 끝을 알려주는 기호입니다!
	
	// char alphabet = 'A'; // <- 디버깅 화살표가 여기 있다면 (디버깅 실행 대기)
	// int data = 100;
	// float pi = 3.14f; 

#pragma endregion

	//변수의 이름 규칙
	/* 
	 1. 예약어를 사용할 수 없습니다.
	 ex) int int = 100 (X);

	 2. 숫자를 변수의 이름으로 사용할 수 있으나
	    첫번째 단어로 사용할 수 없습니다.
	 ex) int 1hp = 100 (X);

	 3. 변수의 이름은 대소문자를 구분합니다.
	 ex) int attack=26; int ATTACK=16; <- 서로 다른 메모리공간을 가지고 있음 

	 4. 변수의 이름에 공백이 포함될 수 없습니다.
	 ex) int count Down = 3; (인식 불가능)

	 5. 변수의 이름으로 특수 기호는 "$", "_" 만 가능합니다.
	 ex) int count_Down = 5; int mo$ney=999;
	*/ 

#pragma region 변수의 초기화
// 최초로 변수에 값을 저장해주는 과정입니다. 
	int exp = 100; //변수의 선언
	//가비지값이 100으로 덮어씌워짐
	exp = 999;
#pragma endregion


#pragma region 상수
// 프로그램이 실행되는 동안 더 이상 값을 변경할 수 없는 
// 메모리 공간입니다.
   
	//심볼릭 상수 //리터럴 값
	//const float pi = 3.141592;
	// L-value 와 R-Value
	

   //pi = 6.4571; 상수로 선언되었기 때문에 값을 변경할 수 없습니다.

      


#pragma endregion

#pragma region 산술 연산자

	int result = (10 - 2) * 3;

	// 1. num1 변수 = B 변수 + C 변수
	// 2. num2 변수 = E 변수 - F (심볼릭)상수
	// 3. num3 변수 = 리터럴 상수 * B 변수
	// 4. num4 변수 = 리터럴 상수 / F (심볼릭)상수
	// 5. num5 변수 = 리터럴 상수 + 리터럴 상수

	int num1, num2, num3, num4, num5;
	int B=1, C=2, E=3;
	const int F=4;

	num1 = B + C;
	num2 = E - F;
	num3 = 10 * B;
	num4 = 8 / F;
	num5 = 1 + 2;
	


#pragma endregion








}

