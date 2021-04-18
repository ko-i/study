// 2020-11-06 created by Akson

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

	int input;
	while(1)
	{
		printf("*****************************************************************\n");
		printf("Enter the number corresponding to the desired pay rate or action:\n");
		printf("1) $8.75/hr                    2) $9.33/hr\n");
		printf("3) $10.00/hr                   4) $11.20/hr\n");
		printf("5) quit\n");
		printf("*****************************************************************\n");

		scanf("%d", &input);

		if(input >= 1 && input <= 5)
		{
			break;
		}
		else
		{
			printf("Please enter a valid input!\n");
		}
	}

	if(input != 5)
	{
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