// 2020-11-11 created by Akson

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

static int next = 0;

int my_rand();

int main(void)
{
	int my_rend_int_count[SIZE] = {0};
	int machine_rend_int_count[SIZE] = {0};

	printf("Please enter a rand seed: ");
	scanf("%d", &next);
	srand(next);
	for(int i = 0; i < 1000; i++)
	{
		my_rend_int_count[my_rand() % SIZE]++;
		machine_rend_int_count[rand() % SIZE]++;
	}

	printf("This is the randonm numbers count of my:\n");
	for(int i = 0; i < SIZE; i++)
	{
		printf("%d: %d\n", i + 1, my_rend_int_count[i]);
	}

	printf("This is the randonm numbers count of machine:\n");
	for(int i = 0; i < SIZE; i++)
	{
		printf("%d: %d\n", i + 1, machine_rend_int_count[i]);
	}

	printf("Done!\n");

	return 0;
}

int my_rand(void)
{
	next = next * 1103515245 + 12345;
	int result = next / 65535;
	if(result < 0)
	{
		result = -result;
	}
	return result;
}