// 2020-11-08 created by Akson
// Code10.3 some_data.c

#include <stdio.h>

#define SIZE 4

int main(void)
{
	int some_data[SIZE] = {1492, 1066};
	int i;

	printf("%2s%14s\n", "i", "some_data[i]");
	for(i = 0; i < SIZE; i++)
	{
		printf("%2d%14d\n", i, some_data[i]);
	}

	return 0;
}