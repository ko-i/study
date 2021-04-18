// 2020-11-09 created by Akson
// Code11.6 getsputs.c

#include <stdio.h>

#define STLEN 10

int main(void)
{
	char words[STLEN];

	puts("Enter a string, please.");
	gets(words);
	printf("Your string twice:\n");
	printf("%s\n", words);
	puts(words);

	return 0;
}