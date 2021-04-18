// 2020-12-22 created by Akson
// pe16.7

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMSIZE 10000

void gernerate_random(int* array, int n);
void check_random(int* array, int n);

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int num_array[NUMSIZE];

	gernerate_random(num_array, NUMSIZE);

	check_random(num_array, NUMSIZE);



	return 0;
}

void gernerate_random(int* array, int n)
{
	printf("\nStart gernerate...\n");
	for(int i = 0; i < NUMSIZE; i++)
	{
		array[i] = rand();
	}

	printf("Gernerate Done!\n\n");
}

void check_random(int* array, int n)
{
	printf("\nStart Check:\n");
	for(int i = 2; i <= 10; i++)
	{
		int count[10] = {0};
		for(int j = 0; j < NUMSIZE; j++)
		{
			count[array[j] % i]++;
		}

		printf("For check %d to %d:\n", 0, i - 1);
		for(int k = 0; k < i; k++)
		{
			printf("number %d: %d\n", k, count[k]);
		}

		printf("\n");
	}

	printf("Check Done!\n");
}