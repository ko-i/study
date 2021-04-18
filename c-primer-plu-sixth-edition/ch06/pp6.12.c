// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	int epoch;
	double flag = -1.0;

	printf("Please import the epochs(-1 or 0 to quit):\n");
	scanf("%d", &epoch);

	while(epoch >= 1)
	{
		double result1 = 0;
		double result2 = 0;

		for(int i = 1; i <= epoch; i++)
		{
			result1 += 1.0 / i;
			result2 += -flag / i;
			flag = -flag;
		}

		printf("result1: %lf, result2: %lf\n", result1, result2);
		printf("Please import the epochs(-1 or 0 to quit):\n");
		scanf("%d", &epoch);
	}
	printf("Done\n");

	return 0;
}