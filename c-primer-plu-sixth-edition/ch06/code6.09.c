// 2020-11-06 created by Akson
// Code6.9 boolean.c

#include <stdio.h>

int main(void)
{
	long num;
	long sum = 0L;
	bool input_is_good;

	printf("Please enter an integer to be summed (q to quit): ");
	input_is_good = scanf("%ld", &num);
	while(input_is_good)
	{
		sum = sum +num;

		printf("Please enter an integer to be summed (q to quit): ");
		input_is_good = scanf("%ld", &num);
	}

	printf("Those integers sum to %ld.\n", sum);

	return 0;
}