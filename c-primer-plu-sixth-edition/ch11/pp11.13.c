// 2020-11-10 created by Akson

#include <stdio.h>

int main(int argc, char const *argv[])
{
	for(int i = argc - 1; i >= 1; i--)
	{
		printf("%s ", argv[i]);
	}
	printf("\n");

	return 0;
}