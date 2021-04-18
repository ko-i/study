// 2020-12-14 created by Akson
// pe9.4

#include <stdio.h>

char* my_strcat(char* des, char* src, int size);

int main(int argc, char const *argv[])
{
	// some test
	return 0;
}

char* my_strcat(char* des, char* src, int size)
{
	int count = 0;
	char* result = des;

	while(*des != '\0')
	{
		des++;
		count++;
	}

	while(*src != '\0' && count < size)
	{
		*des = *src;
		des++;
		src++;
		count++;
	}

	if(count == size)
	{
		*des = '\0';
	}
	else
	{
		des++;
		*des = '\0';
	}

	return result;
}