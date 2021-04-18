// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	int count, sum;

	sum = 0;
	printf("Please enter the days: ");
	scanf("%d", &count);

	while(count > 0)
	{
		sum = sum + count * count;
		count--;
	}

	printf("sum = %d\n", sum);

	return 0;
}