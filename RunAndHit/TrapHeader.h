#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define TREE_BOTTOM_Y 30
#define TREE_BOTTOM_X 45

char TreePic[10][10];

//나무를 그리는 함수
void DrawTree(int TreeX, int TreeY, char string[10][10])
{

    strcpy(TreePic[0], "$$$$$$\n");
    strcpy(TreePic[1], "  $$\n");
    strcpy(TreePic[2], "  $$\n");
    strcpy(TreePic[3], "  $$\n");
    strcpy(TreePic[4], "  $$");

    for (int i = 0; i < 5; i++)
    {
        COORD cursorPosition = { TreeX, TreeY + i };
        DWORD dw;
        SetConsoleCursorPosition(Screen[screenIndex], cursorPosition);

        WriteFile
        (
            Screen[screenIndex],
            string[i],
            strlen(string[i]),
            &dw,
            NULL
        );
    }

}


void Trap()
{

   

    DrawTree(treeX,treeY, TreePic);        //draw Tree


}