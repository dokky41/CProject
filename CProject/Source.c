#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80


// ��ǥ �̵� �Լ�
void GotoXY(int x, int y)
{
    //��ǥ ������ �����ϴ� ����ü 
    COORD position = { x,y };
    
    //��ǥ ������ ����
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);


}


int main()
{   
#pragma region ��ǥ �̵� �Լ�
   
    //char key = 0;

    //int x = 0;
    //int y = 0;

    //
    //// ĳ���� ����
   

    //while (1)
    //{
    //    GotoXY(x, y);
    //    printf("��");

    //    if (_kbhit())
    //    {
    //        key = _getch();

    //        if (key == -32)
    //        {
    //             key = _getch();
    //        }

    //        
    //            switch (key)
    //            {

    //            case UP: if(y>0) y--;
    //                break;
    //            case LEFT: if(x>0) x--;
    //                break;
    //            case RIGHT: x++;
    //                break;
    //            case DOWN:  y++;
    //                break;

    //            }

    //            system("cls");

    //        

    //        
    //    }



    //}





#pragma endregion



#pragma region ���ڿ� ���� �Լ�(strlen)
    // ���ڿ��� ũ�⸦ ��ȯ�ϴ� �Լ��Դϴ�.

    // ���� �������� �ִ� NULL ���ڸ� �������� �ʰ� ���ڿ� ũ�⸦ ���
   //char* string = "Visual";
   //
   //int size = strlen(string);
   //
   //printf("size�� �� : %d", size);


#pragma endregion

#pragma region ȸ�� (Level ���� �յڷ� �Ȱ��� �ܾ�)

   /* char* data = "11021";
    int flag = 1, i = 0 , j = strlen(data)-1;

    while (1)
    {
        if (flag == 0)
        {
            printf("ȸ���� �ƴմϴ�.");
            break;
        }
        if (i == j)
        {
            break;
        }
        if (data[i] != data[j])
        {
            flag = 0;
        }

        i++; j--;
    }
        
    if (flag == 1)
    {
        printf("ȸ���� �½��ϴ�.");
    }*/

#pragma endregion

#pragma region ȸ�� ����

    /*
        int flag = 1;

        for(int i=0; i<strlen(data)/2; i++)
        {
           
           if(data[i] != data[strlen(data)-1 - i])
           {
                flag = 0;
                break;
           }

        }
    
        if(flag == 1)
        {
            printf("ȸ��\n");
        }else{
            printf("ȸ���� �ƴմϴ�."\n);
        }
        
    */

      

#pragma endregion




    return 0;
}
