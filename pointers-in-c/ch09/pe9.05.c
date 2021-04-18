// 2020-12-14 created by Akson
// pe9.5

#include <stdio.h>

void my_strncat(char* dest, char* src, int dest_len);

int main(int argc, char const *argv[])
{
	// some test 

	return 0;
}

void my_strncat(char* dest, char* src, int dest_len)
{
	int count = 0;
	char* result = dest;

	while(*dest != '\0')
	{
		dest++;
		count++;
	}

	while(*src != '\0' && count < dest_len)
	{
		*dest = *src;
		dest++;
		src++;
		count++;
	}

	if(count == dest_len)
	{
		*dest = '\0';
	}
	else
	{
		dest++;
		*dest = '\0';
	}

	return result;
}