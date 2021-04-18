// 2020-12-13 created by Akson
// try1

#include <stdio.h>
#include <time.h>

#define SIZE 500000

int main(void)
{
	int x[SIZE];
	int y[SIZE];
	int i;

	clock_t start, end;

	start = clock();
	for(i = 0; i < SIZE; i++)
	{
		x[i] = y[i];
	}
	end = clock();

	double duration =(double)(end-start) / CLOCKS_PER_SEC;
    printf("%.12lf\n",duration);

	return 0;
}