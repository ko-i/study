// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	double nums[8];
	double result[8];

	printf("Please enter 8 numbers:\n");
	for(int i = 0; i < 8; i++)
	{
		scanf("%lf", &nums[i]);
		if(i == 0)
		{
			result[i] = nums[i];
			continue;
		}
		result[i] = nums[i] + result[i - 1];
	}

	for(int i = 0; i <8; i++)
	{
		printf("%10.2lf ", nums[i]);
	}
	printf("\n");
	for(int i = 0; i <8; i++)
	{
		printf("%10.2lf ", result[i]);
	}
	printf("\n");

	return 0;
}