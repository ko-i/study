// 2020-12-05 created by Akson
// pe4.3.c

#include <stdio.h>

#define EQUILATERAL_TRIANGLE 3
#define ISOSCELES_TRIANGLE 2
#define SCALENE_TRIANGLE 1
#define NOT_A_TRIANGLE 0

int judge_triangle(double e1, double e2, double e3);

int main(int argc, char const *argv[])
{
	printf("Enter three edge length and I will judge what triangle it is.\n");
	printf("Three edge length(q to quit): ");

	double e1, e2, e3;
	while(scanf("%lf %lf %lf", &e1, &e2, &e3) == 3)
	{
		switch(judge_triangle(e1, e2, e3))
		{
			case EQUILATERAL_TRIANGLE: printf("This is a equilateral triangle.\n"); break;
			case ISOSCELES_TRIANGLE: printf("This is a isosceles triangle.\n"); break;
			case SCALENE_TRIANGLE: printf("This is a scalene triangle.\n"); break;
			default: printf("This is not a triangle.\n");
		}

		printf("Edge length(q to quit): ");
	}

	printf("Bye!\n");

	return 0;
}

int judge_triangle(double e1, double e2, double e3)
{
	if(e1 + e2 <= e3 || e1 + e3 <= e2 || e2 + e3 <= e1)
	{
		return NOT_A_TRIANGLE;
	}

	if(e1 == e2 || e2 == e3 || e1 == e3)
	{
		if(e1 == e2 && e2 == e3)
		{
			return EQUILATERAL_TRIANGLE;
		}

		return ISOSCELES_TRIANGLE;
	}

	return SCALENE_TRIANGLE;
}