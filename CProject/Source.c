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
#pragma region ����ü ������

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

#pragma region �� �� ������ �Ÿ�

    // ������ (sqrt)
    //printf("��Ʈ 49 : %lf\n", sqrt(49));

    // �ŵ����� (pow)
    //printf("2�� 3�� : %lf\n", pow(2,3));

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
   //    printf("������ ���°� �ƴմϴ�.");
   //}
   //
   //printf("ĳ���Ϳ� ������ �Ÿ� : %f\n", distance);


#pragma endregion

#pragma region �Ǽ��� �����ϴ� ���

    // �ε� �Ҽ���
    // �Ҽ����� ��ġ�� �������� �ʰ� �Ҽ����� ��ġ��
    // ��Ÿ���� ����Դϴ�.

    // ���� �Ҽ���
    // �Ҽ����� ��ġ�� �����Ͽ� �Ҽ����� ��ġ�� ��Ÿ���� ����Դϴ�.


    // 12.375

    // float 4(Byte)
    //float fData = 1.3f;
    //printf("fData�� �� : %.15f\n", fData);

    //// double 8(Byte)
    //double dData = 1.3f;
    //printf("dData�� �� : %.20lf\n", dData);

    //if (fData == 1.3)
    //{
    //    printf("fData�� ���� 1.3f�� ���� ����.");
    //}
    //else 
    //{
    //    printf("fData�� ���� 1.3�� ���� ���� �ʴ�.");
    //}


#pragma endregion




    return 0;
}