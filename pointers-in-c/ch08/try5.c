// 2020-12-13 created by Akson
// try5

#include <stdio.h>
#include <time.h>

#define SIZE 500000

int main(void)
{
	int x[SIZE];
	int y[SIZE];
	register int *p1, *p2;
    register int i;

	clock_t start, end;

	start = clock();
	for(p1 = x, p2 = y; p1 < &x[SIZE];)
	{
		*p1++ = *p2++;
	}
	end = clock();

	double duration =(double)(end-start) / CLOCKS_PER_SEC;
    printf("%.12lf\n",duration);

	return 0;
}