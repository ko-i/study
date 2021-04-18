// 2020-11-09 created by Akson
// Code11.3 addresses.c

#include <stdio.h>

#define MSG "I'm special"

int main(void)
{
	char ar[] = MSG;
	const char *pt = MSG;

	printf("address of \"I'm special\": %p\n", "I'm special");
	printf("              address ar: %p\n", ar);
	printf("              address pt: %p\n", pt);
	printf("          address of MSG: %p\n", MSG);
	printf("address of \"I'm special\": %p\n", "I'm special");

	return 0;

}