// 2020-11-08 created by Akson

#include <stdio.h>

#define NORMALTIME 40.0
#define EXTRATIMERATE 1.5
#define TAXRATE1 0.15
#define TAXRATE2 0.2
#define TAXRATE3 0.25
#define INCOME1 300
#define INCOME2 450

int main(void)
{
	float work_hours;
	float income;
	float income_per_hour = 10.0;
	float tax;

	char input;
	while(1)
	{
		printf("*****************************************************************\n");
		printf("Enter the number corresponding to the desired pay rate or action:\n");
		printf("a) $8.75/hr                    b) $9.33/hr\n");
		printf("c) $10.00/hr                   d) $11.20/hr\n");
		printf("q) quit\n");
		printf("*****************************************************************\n");

		scanf("%c", &input);

		if(input >= 'a' && input <= 'd' || input == 'q')
		{
			break;
		}
		else
		{
			printf("Please enter a valid input!\n");
		}
	}

	if(input != 'q')
	{
		switch(input)
		{
			case 'a': income_per_hour = 8.75; break;
			case 'b': income_per_hour = 9.33; break;
			case 'c': income_per_hour = 10.00; break;
			case 'd': income_per_hour = 11.20; break;
		}
		printf("Please input your work hours: ");
		scanf("%f", &work_hours);

		if(work_hours > NORMALTIME)
		{
			work_hours = NORMALTIME + (work_hours - NORMALTIME) * EXTRATIMERATE;
		} 

		income = income_per_hour * work_hours;

		if(income <= INCOME1)
		{
			tax = income * TAXRATE1;
		}
		else if (income <= INCOME2)
		{
			tax = INCOME1 * TAXRATE1 + (income - INCOME1) * TAXRATE2;
		}
		else
		{
			tax = INCOME1 * TAXRATE1 + (INCOME2 - INCOME1) * TAXRATE2 + (income - INCOME2) * TAXRATE3;
		}

		printf("The income of you is: $%.2f\n", income);
		printf("The tax you should pay is: $%.2f\n", tax);
		printf("The money you earn last is: $%.2f\n", income - tax);
	}

	return 0;
}