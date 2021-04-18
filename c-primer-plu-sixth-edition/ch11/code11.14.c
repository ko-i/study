// 2020-11-09 created by Akson
// Code11.14 put1()

#include <stdio.h>

void put1(const char * string)
{
	while(*string != '\0')
	{
		putchar(*string++);
	}
}