// 2020-11-10 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	double num1;
	int num2;
	double result;

	num1 = atof(argv[1]);
	num2 = atoi(argv[2]);

	printf("%.2lf\n", pow(num1, num2));

	return 0;
}