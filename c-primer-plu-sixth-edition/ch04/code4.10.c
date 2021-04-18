// 2020-11-05 created by Akson
// Code4.10 stringf.c

#include <stdio.h>

#define BLURB "Authentic imitation"

int main(void)
{
	printf("[%2s]\n", BLURB);
	printf("[%24s]\n", BLURB);
	printf("[%24.5s]\n", BLURB);
	printf("[%-24.52s]\n", BLURB);

	return 0;
}