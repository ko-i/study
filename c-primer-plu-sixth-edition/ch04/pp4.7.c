// 2020-11-05 created by Akson

#include <stdio.h>
#include <float.h>

int main(void)
{
	float flo = 1.0 / 3.0;
	double dou = 1.0 / 3.0;

	printf("float: %.3f, %.6f, %.12f\n", flo, flo, flo);
	printf("FLT_DIG: %d\n", FLT_DIG);
	printf("doubl: %.3f, %.6f, %.12f\n", dou, dou, dou);
	printf("DBL_DIG: %d\n", DBL_DIG);

	return 0;
}