// 2020-12-13 created by Akson
// try3

#include <stdio.h>
#include <time.h>

#define SIZE 500000

int main(void)
{
	int x[SIZE];
	int y[SIZE];
	int *p1, *p2;
	int i;

	clock_t start, end;

	start = clock();
	for(i = 0, p1 = x, p2 = y; i < SIZE; i++)
	{
		*p1++ = *p2++;
	}
	end = clock();

	double duration =(double)(end-start) / CLOCKS_PER_SEC;
    printf("%.12lf\n",duration);

	return 0;
}