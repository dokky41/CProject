#pragma once

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80


// 좌표 이동 함수
void GotoXY(int x, int y)
{
    //좌표 정보를 저장하는 구조체 
    COORD position = { x,y };

    //좌표 정보를 설정
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);


}


int main()
{
#pragma region 좌표 이동 함수

    //char key = 0;

    //int x = 0;
    //int y = 0;

    //
    //// 캐릭터 설정


    //while (1)
    //{
    //    GotoXY(x, y);
    //    printf("★");

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



#pragma region 문자열 길이 함수(strlen)
    // 문자열의 크기를 반환하는 함수입니다.

    // 가장 마지막에 있는 NULL 문자를 포함하지 않고 문자열 크기를 계산
   //char* string = "Visual";
   //
   //int size = strlen(string);
   //
   //printf("size의 값 : %d", size);


#pragma endregion

#pragma region 회문 (Level 같이 앞뒤로 똑같은 단어)

   /* char* data = "11021";
    int flag = 1, i = 0 , j = strlen(data)-1;

    while (1)
    {
        if (flag == 0)
        {
            printf("회문이 아닙니다.");
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
        printf("회문이 맞습니다.");
    }*/

#pragma endregion

#pragma region 회문 정답

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
            printf("회문\n");
        }else{
            printf("회문이 아닙니다."\n);
        }

    */



#pragma endregion




    return 0;
}
