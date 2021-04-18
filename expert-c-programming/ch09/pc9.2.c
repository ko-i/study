// 2020-12-28 created by Akson
// pc9.2

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int apricot[2][3][5];

	int (*r)[5] = apricot[0];
	int *t = apricot[0][0];

	printf("r = %p\n", r);
	printf("t = %p\n", t);

	printf("r++ = %p\n", ++r);
	printf("t++ = %p\n", ++t);

	return 0;
}