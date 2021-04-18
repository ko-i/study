// 2020-11-09 created by Akson
// Code10.8 pnt_add.c

#include <stdio.h>

#define SIZE 4

int main(void)
{
	short datas[SIZE];
	short * pti;
	short index;
	double bills[SIZE];
	double *ptf;
	pti = datas;
	ptf = bills;

	printf("%23s %15s\n", "short", "double");
	for(index = 0; index < SIZE; index++)
	{
		printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
	}

	return 0;
}