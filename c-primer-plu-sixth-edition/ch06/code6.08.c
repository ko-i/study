// 2020-11-06 created by Akson
// Code6.8 trouble.c

#include <stdio.h>

int main(void)
{
	long num;
	long sum = 0L;
	int status;

	printf("Please enter an integer to be summed (q to quit): ");
	status = scanf("%ld", &num);
	while(status = 1) // status == 1
	{
		sum = sum +num;

		printf("Please enter an integer to be summed (q to quit): ");
		status = scanf("%ld", &num);
	}

	printf("Those integers sum to %ld.\n", sum);

	return 0;
}