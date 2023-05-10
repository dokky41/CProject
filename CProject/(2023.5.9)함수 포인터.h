#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void Function()
{
    printf("Function() 함수\n");
}

void DataList()
{
    printf("DataList() 함수\n");
}

int Damage(int x)
{
    return x;
}

// 거품 정렬 (오름차순 / 내림차순) <- A 개발자
// 선택 정렬 (오름차순 / 내림차순) <- B 개발자
// 삽입 정렬 (오름차순 / 내림차순) <- C 개발자

// 퀵 정렬   <- A 개발자
// 병합 정렬 <- B 개발자
// 계수 정렬 <- C 개발자


void Sort(void (*fPtr)()) // 오름차순, 내림차순
{
    fPtr();
}

#pragma region typedef
    
typedef unsigned int UINT;

typedef struct Player
{
    int x; 
    int y;
    char name[10];

}Player1;

#pragma endregion



int main()
{

#pragma region 함수 포인터
    // 함수의 주솟값을 저장하고 가리킬 수 있는
    // 변수입니다.

    // 함수의 이름은 함수의 주소를 의미합니다.
    //printf("Function()의 주솟값 : %p\n", Function);

    //// 함수 포인터 선언
    //void(*fPtr) ();
    //fPtr = Function;
    //fPtr();

    //int(*intfptr) (int);
    //intfptr = Damage;
    //printf("intfptr값은 %d\n", intfptr(10));

    //fPtr = DataList;
    //fPtr();


    //Sort(Function);

    // 함수 포인터는 함수의 반환형과 매개변수의 타입이
    // 일치해야 하므로, 함수 포인터를 사용하여
    // 동적으로 메모리를 할당할 수 없습니다.
     
    // fPtr = Damage;  
    // printf("fPtr의 값 : %d\n", fPtr(5));

    


#pragma endregion

#pragma region typedef
    /*UINT count = 100;
    unsigned int value = 10000;
    
    printf("count의 값 : %d\n",count);

    Player1 player1;
    player1.x = 10;
    player1.y = 20;*/

 
    
    // 배열의 주소 <-
    // [][][][][][][][][][] <- [A][l].....[r] 
    // 첫 번째 매개변수 : 복사받는 문자 배열
    // 두 번째 매개변수 : 복사하는 문자 배열
    /*strcpy(player1.name,"Alistar");

    printf("player1.name의 값 : %s\n", player1.name);
    printf("player1.x의 값 : %d\n", player1.x);
    printf("player1의 메모리 크기 : %u\n", sizeof(player1));*/


#pragma endregion






    return 0;
}