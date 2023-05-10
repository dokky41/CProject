#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#pragma region 자기 참조 구조체
	// 자기 자신을 가리키는 포인터가
	// 구조체의 멤버로 들어가 있는 구조체입니다.

	
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

#pragma endregion

int main()
{
#pragma region 자기 참조 구조체

	//Node node1 = { 100,NULL };
	//Node node2 = { 200,NULL };
	//Node node3 = { 300,NULL };

	//printf("node1의 data 값 : %d\n", node1.data);
	//printf("node2의 data 값 : %d\n", node2.data);
	//printf("node3의 data 값 : %d\n", node3.data);

	//node1.next = &node2;
	//node2.next = &node3;
	//node3.next = NULL;

	//node1.next->data = 999;
	//printf("node1의 data 값 : %d\n", node1.data);
	//printf("node2의 data 값 : %d\n", node2.data);


	//Node* currentPtr = &node1;

	//while (currentPtr != NULL)
	//{
	//	//1. currentPtr로 값 출력
	//	printf("%d\n", currentPtr->data);


	//	//2. currentPtr 주소값 변경
	//	currentPtr=currentPtr->next;
	//	

	//}
#pragma endregion

#pragma region 삼항 연산자

	//int data = 0;

	//     // (조건)  ? (참) : (거짓)
	//data = 10 == 10 ? 100 : 445;

	//printf("data의 값 : %d\n",data);



#pragma endregion

	char string[10];

	//scanf("%s", string);
	scanf("%[^\n]s", string);

	printf("string의 값 : %s", string);



    return 0;
}