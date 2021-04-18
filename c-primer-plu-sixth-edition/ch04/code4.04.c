// 2020-11-05 created by Akson
// Code4.4 pizza.c

#include <stdio.h>

#define PI 3.14159

int main()
{
	float area, circum, radius;

	printf("What is the radius of your pizze?\n");
	scanf("%f", &radius);

	area = PI * radius * radius;
	circum = 2.0 * PI * radius;

	printf("Your basic pizza parameters are as follows:\n");
	printf("circumference = %.2f, area = %.2f\n", circum, area);

	return 0;
}