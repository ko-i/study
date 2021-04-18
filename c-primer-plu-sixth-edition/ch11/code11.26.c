// 2020-11-10 created by Akson
// Code11.26 copy2.c

#include <stdio.h>
#include <string.h>

#define WORDS "beast"
#define SIZE 40

int main(void)
{
	const char * orig = WORDS;
	char copy[SIZE] = "Be the best that you can be.";
	char * ps;

	puts(orig);
	puts(copy);

	ps = strcpy(copy + 7, orig);
	puts(copy);
	puts(ps);

	return 0;
}