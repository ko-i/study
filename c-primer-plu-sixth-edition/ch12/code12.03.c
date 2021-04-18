// 2020-11-10 created by Akson
// Code12.2 loc_stat.c

#include <stdio.h>

void trystat(void);

int main(void)
{
	int count;

	for(count = 1; count <= 3; count++)
	{
		printf("Here comes iteration %d:\n", count);
		trystat();
	}

	return 0;
}

void trystat(void)
{
	int fade = 1;
	static int stay = 1;

	printf("fade = %d and stay = %d\n", fade++, stay++);
}