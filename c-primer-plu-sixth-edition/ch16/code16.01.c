// 2020-11-14 created by Akson
// Code16.1 preproc.c

#include <stdio.h>

#define TWO 2    /* 可以使用注释 */
#define OW "Consistency is the last refuge of the unimagina\
tive. - Oscar Wilde"

#define FOUR TWO*TWO
#define PX printf("X is %d.\n", x)
#define FMT "X is %d.\n"

int main(void)
{
	int x = TWO;

	PX;
	x = FOUR;
	printf(FMT, x);;
	printf("%s\n", OW);
	printf("TWO: OW\n");;

	return 0;
}