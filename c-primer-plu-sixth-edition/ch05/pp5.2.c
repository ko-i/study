// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	int num;
	printf("Please enter a number:\n");
	scanf("%d", &num);

	for(int i = 0; i <= 10; i++)
	{
		printf("%d ", num++);
	}

	printf("\n");
	printf("Done!\n");

	return 0;
}