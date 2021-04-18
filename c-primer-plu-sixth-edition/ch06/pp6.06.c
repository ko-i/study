// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	int start;
	int end;
	printf("Please input start and end: \n");
	scanf("%d %d", &start, &end);

	printf("number square   cube\n");
	for(int i = start; i <= end; i++)
	{
		printf("%6d %6d %6d\n", i, i * i, i * i * i);
	}

	return 0;
}