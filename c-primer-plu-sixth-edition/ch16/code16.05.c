// 2020-11-14 created by Akson
// Code16.5 variadic.c

#include <stdio.h>
#include <math.h>

#define PR(X, ...) printf("Message " #X ": "__VA_ARGS__);

int main(void)
{
	double x = 48;
	double y;

	y = sqrt(x);

	PR(1, "x = %g\n", x);
	PR(2, "x = %.2f, y = %.4f\n", x, y);

	return 0;
}