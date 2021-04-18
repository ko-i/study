// 2020-11-15 created by Akson

#include <stdio.h>
#include <time.h>

int main(void)
{
	double epoch;
	printf("Please enter a time in second, and i will count number in it.\n");
	while(scanf("%lf", &epoch) == 1)
	{
		double start = (double)clock();
		double end = (double)clock();
		double dis = (double)(end - start) / CLOCKS_PER_SEC;
		int count = 0;
		while(dis < epoch)
		{
			printf("Count: %d\n", count);
			count++;
			end = (double)clock();
			dis = (double)(end - start) / CLOCKS_PER_SEC;
		}

		printf("Please enter a time in second, and i will count number in it.\n");
	}

	printf("Bye!\n");

	return 0;
}