// 2020-11-10 created by Akson
// Code11.31 repeat.c

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int count;

	printf("The command line has %d arguments:\n", argc - 1);
	for(count = 1; count < argc; count++)
	{
		printf("%d: %s\n", count, argv[count]);
	}

	printf("\n");

	return 0;
}