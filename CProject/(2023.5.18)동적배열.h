#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define SIZER 50

int main()
{

#pragma region 동적 배열

    // HEAP이라는 메모리 공간을 이용하여
    // 배열의 크기를 컴파일 단계가 아닌 실행 시간에 
    // 가변적으로 바꿀 수 있는 배열입니다.

   /* int size = 10;

    scanf_s("%d", &size);

    int* arrayPtr = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        arrayPtr[i] = size * i;
    }

    for (int i = 0; i < size; i++)
    {
        printf("arrayPtr[%d]의 값 : %d\n",i, arrayPtr[i]);

    }

    free(arrayPtr); */


#pragma endregion


#pragma region fflush() 함수

    /*char a,b,c;

    scanf("%c",&a);
    fflush(stdin);

    scanf("%c",&b);
    fflush(stdin);

    scanf("%c",&c);
    fflush(stdin);




    printf("a변수의 값 : %c\n",a);
    printf("b변수의 값 : %c\n",b);
    printf("c변수의 값 : %c\n",c);*/


#pragma endregion


#pragma region 문자열 뒤집기

    //char string[10] = { 0, };

    //scanf("%s", string);  // &안붙여도됨


    //for(int i=0; i<= strlen(string); i++)
    //{
    //    printf("%c", string[strlen(string) - i]);
    //}


#pragma endregion


#pragma region 문자열 뒤집기 답

    /*
        char string[100]={0,};

        scanf_s("%s",string,SIZE);

        for(int i = strlen(string) -1; i>= 0; i--)
        {
            printf("%c",string[i]);

        }

    */

#pragma endregion




    return 0;
}

