#include <stdio.h>
#include <stdlib.h>   // rand(),srand()
#include <time.h>

int main()
{   

#pragma region rand() �Լ�
     // 0 ~ 32767 ������ ���� ���� �����ϴ�
     // �Լ��Դϴ�. 
    
     // time : 1970�� 1�� 1�� 0�� (UTC)���� ������� 
     // �帥 �ð��� ��ȯ�մϴ�.

     // �ð� ���� : (��)
     

     // ������ ���� 5�� ������ּ���.
    /*srand(time(NULL));
     int value = 0;*/

     // ������ ���� �� �ڸ����� ���� �� �ֵ��� ����� �ּ���.
    /* for (int i = 0; i < 5; i++)
     {
         value = rand() % 10 + 1;

         printf("value�� �� : %d\n", value);

     }*/



#pragma endregion

#pragma region UP-DOWN ���� �� ���
    /* srand(time(NULL)); 
     int num = 0;
     num = rand() % 50+1;

     int myNum = 0;
     int life = 5;

     for (int i = 0; i < 5; i++)
     {

         printf("���� �Է��ϼ��� : ");
         scanf_s("%d", &myNum);

         if (myNum < num)
         {
             printf("up\n");
             life--;
             printf("���� ������ : %d\n\n", life);
         }
         if (myNum > num)
         {
             printf("down\n");
             life--;
             printf("���� ������ : %d\n\n", life);
         }
         if (myNum == num)
         {
             printf("%d �����Դϴ�!\n", myNum);
             break;
         }

         if (life == 0)
         {
             printf("�й��ϼ̽��ϴ�!\n");
             printf("������ %d�Դϴ�.\n", num);
             break;
         }


     }*/





#pragma endregion

#pragma region UP-DOWN ���� ����
    //srand(time(NULL));
    //int life = 5;
    //int answer = 0;
    //int computer = 0;

    //computer = rand() % 50 + 1;

    //while (life) // <- ���� ������Ʈ 
    //{
    //    printf("\n���� ��� : %d",life); 
    //    printf("��ǻ�Ͱ� ������ �ִ� ���� : ");
    //    scanf_s("%d",&answer);

    //    if (answer == computer)
    //    {
    //        printf("\n���ӿ��� �¸��Ͽ����ϴ�.");
    //        break;
    //    }
    //    else if (answer < computer)
    //    {
    //        printf("��ǻ�Ͱ� ������ �ִ� ������ �۽��ϴ�.\n");
    //        life--;
    //    } 
    //    else if (answer > computer)
    //    {
    //        printf("��ǻ�Ͱ� ������ �ִ� ������ Ů�ϴ�.\n");
    //        life--;
    //    }

    //}

    //if (life == 0)
    //{
    //    printf("���ӿ��� �й��Ͽ����ϴ�.");
    //}

#pragma endregion

#pragma region ������ �°�
    // char �ڷ����� short �ڷ����� ������
    // �̷���� �� CPU�� ó���ϱ⿡ ���� ������
    // ũ���� ���� �ڷ��� int�� �ڵ� ����ȯ�ϴ� �����Դϴ�.

    char data1 = 5;
    short data2 = 10;

    printf("data1�� data2�� ������ ũ�� : %u byte\n", sizeof(data1 + data2));
     


#pragma endregion







    return 0;
}
