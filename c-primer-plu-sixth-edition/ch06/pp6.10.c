// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	int start, end;

	printf("Enter lower and upper integer limits: ");
	scanf("%d %d", &start, &end);

	while(start < end)
	{
		int sum = 0;
		for(int i = start; i <= end; i++)
		{
			sum += i * i;
		}
		printf("The sums of the squares from %d to %d is %d\n", start, end, sum);
		printf("Enter next set of limits: ");
		scanf("%d %d", &start, &end);
	}

	printf("Done\n");

	return 0;
}