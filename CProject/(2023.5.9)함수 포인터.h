#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void Function()
{
    printf("Function() �Լ�\n");
}

void DataList()
{
    printf("DataList() �Լ�\n");
}

int Damage(int x)
{
    return x;
}

// ��ǰ ���� (�������� / ��������) <- A ������
// ���� ���� (�������� / ��������) <- B ������
// ���� ���� (�������� / ��������) <- C ������

// �� ����   <- A ������
// ���� ���� <- B ������
// ��� ���� <- C ������


void Sort(void (*fPtr)()) // ��������, ��������
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

#pragma region �Լ� ������
    // �Լ��� �ּڰ��� �����ϰ� ����ų �� �ִ�
    // �����Դϴ�.

    // �Լ��� �̸��� �Լ��� �ּҸ� �ǹ��մϴ�.
    //printf("Function()�� �ּڰ� : %p\n", Function);

    //// �Լ� ������ ����
    //void(*fPtr) ();
    //fPtr = Function;
    //fPtr();

    //int(*intfptr) (int);
    //intfptr = Damage;
    //printf("intfptr���� %d\n", intfptr(10));

    //fPtr = DataList;
    //fPtr();


    //Sort(Function);

    // �Լ� �����ʹ� �Լ��� ��ȯ���� �Ű������� Ÿ����
    // ��ġ�ؾ� �ϹǷ�, �Լ� �����͸� ����Ͽ�
    // �������� �޸𸮸� �Ҵ��� �� �����ϴ�.
     
    // fPtr = Damage;  
    // printf("fPtr�� �� : %d\n", fPtr(5));

    


#pragma endregion

#pragma region typedef
    /*UINT count = 100;
    unsigned int value = 10000;
    
    printf("count�� �� : %d\n",count);

    Player1 player1;
    player1.x = 10;
    player1.y = 20;*/

 
    
    // �迭�� �ּ� <-
    // [][][][][][][][][][] <- [A][l].....[r] 
    // ù ��° �Ű����� : ����޴� ���� �迭
    // �� ��° �Ű����� : �����ϴ� ���� �迭
    /*strcpy(player1.name,"Alistar");

    printf("player1.name�� �� : %s\n", player1.name);
    printf("player1.x�� �� : %d\n", player1.x);
    printf("player1�� �޸� ũ�� : %u\n", sizeof(player1));*/


#pragma endregion






    return 0;
}