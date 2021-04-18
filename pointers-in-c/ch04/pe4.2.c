// 2020-12-05 created by Akson
// pe4.2.c

#include <stdio.h>

int is_prime(int num);

int main(int argc, char const *argv[])
{
	int start_num = 1;
	int end_num = 100;

	printf("These is the prime between %d and %d:\n", start_num, end_num);

	for(int i = start_num; i <= end_num; i++)
	{
		if(!is_prime(i))
		{
			printf("%d ", i);
		}
	}

	printf("\nBye!\n");

	return 0;
}

int is_prime(int num)
{
	for(int i = 2; i <= num / 2; i++)
	{
		if(num % i == 0)
		{
			return 1;
		}
	}

	return 0;
}