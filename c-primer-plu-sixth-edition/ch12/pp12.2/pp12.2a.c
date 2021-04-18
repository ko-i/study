// 2020-11-11 created by Akson

#include <stdio.h>

static int mode = 0;
static double distance = 0.0;
static double fuel = 0.0;

void set_mode(int num)
{
	if(num > 1)
	{
		printf("Invalid mode specified. Mode %d(%s) used.\n", mode, mode ? "US" : "metric");;
	}
	else
	{
		mode = num;
	}
}

void get_info(void)
{
	if(mode == 0)
	{
		printf("Enter distance traveled in kilometers: ");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in liters: ");
		scanf("%lf", &fuel);
	}
	else
	{
		printf("Enter distance traveled in miles: ");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in gallon: ");
		scanf("%lf", &fuel);
	}
}

void show_info(void)
{
	if(mode == 0)
	{
		printf("Fuel consumption is %.2lf liters per 100km.\n", fuel / distance * 100.0);
		distance = 0.0;
		fuel = 0.0;
	}
	else
	{
		printf("Fuel consumption is %.2lf miles per gallon.\n", distance / fuel);
		distance = 0.0;
		fuel = 0.0;
	}
}