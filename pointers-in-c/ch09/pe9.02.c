// 2020-12-14 created by Akson
// pe9.2

#include <stdio.h>

unsigned int my_strlen(char* str, int size);

int main(int argc, char const *argv[])
{
	// some test

	return 0;
}

unsigned int my_strlen(char* str, int size)
{
	unsigned int len = 0;
	while(*str != '\0' && len < size)
	{
		len++;
		str++;
	}

	return len;
}