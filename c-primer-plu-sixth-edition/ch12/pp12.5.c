// 2020-11-11 created by Akson

#include <stdio.h>

#define SIZE 100

static int next = 0;

int my_rand();

int main(void)
{
	int rend_int[SIZE];
	printf("Please enter a rand seed: ");
	scanf("%d", &next);
	for(int i = 0; i < SIZE; i++)
	{
		rend_int[i] = my_rand();
	}

	// sort
	for(int i = 0; i < SIZE - 1; i++)
	{
		for(int j = i + 1; j < SIZE; j++)
		{
			if(rend_int[i] < rend_int[j])
			{
				int temp = rend_int[i];
				rend_int[i] = rend_int[j];
				rend_int[j] = temp;
			}
		}
	}

	printf("This is the randonm numbers:\n");
	for(int i = 0; i < SIZE; i++)
	{
		printf("%d ", rend_int[i]);
		if(i % 10 == 9)
		{
			printf("\n");
		}
	}

	printf("Done!\n");

	return 0;
}

int my_rand(void)
{
	next = next * 1103515245 + 12345;

	return (unsigned int)(next / 65535) % 10;
}