// 2020-11-11 created by Akson

#include <stdio.h>

void get_info(int mode)
{
	double distance = 0.0;
	double fuel = 0.0;

	if(mode == 0)
	{
		printf("Enter distance traveled in kilometers: ");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in liters: ");
		scanf("%lf", &fuel);
		printf("Fuel consumption is %.2lf liters per 100km.\n", fuel / distance * 100.0);
	}
	else
	{
		printf("Enter distance traveled in miles: ");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in gallon: ");
		scanf("%lf", &fuel);
		printf("Fuel consumption is %.2lf miles per gallon.\n", distance / fuel);
	}
}