// 2020-11-05 created by Akson

#include <stdio.h>

int main(void)
{
	double cup_number;
	printf("Please input your cups number:");
	scanf("%lf", &cup_number);
	printf("So you have:\n");
	printf("%.2lf pintos or\n", cup_number / 2.0);
	printf("%.2lf cups or\n", cup_number);
	printf("%.2lf ans or\n", cup_number * 8.0);
	printf("%.2lf big spoons or\n", cup_number * 16.0);
	printf("%.2lf tea spoons\n", cup_number * 48.0);
	
	return 0;
}