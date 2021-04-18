// 2020-11-15 created by Akson

#include <stdio.h>
#include <math.h>

int main(void)
{
	double A;
	double r;

	double x;
	double y;

	printf("Please enter a length and an angle. I will caculate the x and y for them.\n");
	printf("Enter length: ");
	while(scanf("%lf", &A) == 1)
	{
		printf("Enter angle: ");
		scanf("%lf", &r);

		x = r * cos(A);
		y = r * sin(A);

		printf("The dot's at (%.2lf, %.2lf)\n", x, y);

		printf("Enter length: ");
	}

	printf("Bye!\n");

	return 0;
}