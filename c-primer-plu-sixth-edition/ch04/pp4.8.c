// 2020-11-05 created by Akson

#include <stdio.h>

int main(void)
{
	float mile;
	float km;
	float galon;
	float liter;

	printf("Please input your miles and galons.\n");
	scanf("%f %f", &mile, &galon);
	printf("You consum %.1f galon per mile.\n", galon / mile);
	printf("Or %.1f liter per 100 km.\n", galon * 3.785 / (mile * 1.609 / 100.0));

	return 0;
}