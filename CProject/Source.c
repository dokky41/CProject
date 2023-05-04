#include <stdio.h>
#include <math.h>

struct Player
{
    int x, y;
    int hp;
    float attack;
};

struct Enemy
{
    int x, y;
};


int main()
{
#pragma region 구조체 포인터

     //struct Player player;
     //
     //struct Player * ptrPlayer = NULL;
     //
     //ptrPlayer = &player;
     //
     //(*ptrPlayer).hp = 100;
     //(*ptrPlayer).attack = 12.5f;
     //
     //printf("%d\n", (*ptrPlayer).hp);
     //printf("%f\n", (*ptrPlayer).attack);
     //
     //ptrPlayer->hp = 250;
     //ptrPlayer->attack = 22.75f;
     //
     //printf("%d\n", (*ptrPlayer).hp);
     //printf("%f\n", (*ptrPlayer).attack);
   


#pragma endregion

#pragma region 두 점 사이의 거리

    // 제곱근 (sqrt)
    //printf("루트 49 : %lf\n", sqrt(49));

    // 거듭제곱 (pow)
    //printf("2의 3승 : %lf\n", pow(2,3));

   //struct Player player;
   //struct Enemy  enemy;
   //
   //player.x = 0;
   //player.y = 0;
   //
   //enemy.x = 5;
   //enemy.y = 7;
   //
   //float distance =
   //    sqrt(pow((enemy.x - player.x), 2) + pow((enemy.y - player.y), 2));
   //
   //if (distance >= 5)
   //{
   //    printf("위험한 상태가 아닙니다.");
   //}
   //
   //printf("캐릭터와 몬스터의 거리 : %f\n", distance);


#pragma endregion

#pragma region 실수를 저장하는 방법

    // 부동 소수점
    // 소수점의 위치를 고정하지 않고 소수점의 위치를
    // 나타내는 방법입니다.

    // 고정 소수점
    // 소수점의 위치를 고정하여 소수점의 위치를 나타내는 방법입니다.


    // 12.375

    // float 4(Byte)
    //float fData = 1.3f;
    //printf("fData의 값 : %.15f\n", fData);

    //// double 8(Byte)
    //double dData = 1.3f;
    //printf("dData의 값 : %.20lf\n", dData);

    //if (fData == 1.3)
    //{
    //    printf("fData의 값과 1.3f의 값이 같다.");
    //}
    //else 
    //{
    //    printf("fData의 값과 1.3의 값이 같지 않다.");
    //}


#pragma endregion




    return 0;
}