#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int StringLength(const char * string)
{
	int count = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		count++;
	}

	return count;
}

int main()
{

	// ���ڿ� ���� �Լ� (strlen)
	int value = StringLength("IPhone");
	//printf("value�� �� : %d\n", value);

	// ���ڿ� ���� �Լ� (strcpy) 


	// ���ڿ� ���� �Լ� (strcat) ex) strcat(content1,content2)  content1�� ������ �Ѿ�� ����
	char content1[20] = { "Hello" };
	char content2[10] = { "Update" };

	strcat(content1, content2);
	//printf("%s\n", content1);



	return 0;
}
