// 2020-11-09 created by Akson
// Code11.15 put2.c

#include <stdio.h>

int put2(const char * string)
{
	int count = 0;
	while(*string)
	{
		putchar(*string++);
		count++;
	}

	putchar('\n');

	return count;
}