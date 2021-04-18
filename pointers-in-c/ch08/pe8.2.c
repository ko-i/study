// 2020-12-13 created by Akson
// pe8.2

#include <stdio.h>

float single_tax(float income);

int main(int argc, char const *argv[])
{
	printf("Enter your salary and I will calcu the tat you should pay.\n");
	printf("Salary enter(q to quit): ");

	float salary;
	while(scanf("%f", &salary) == 1 && salary >= 0)
	{
		printf("You should pay %f\n", single_tax(salary));

		printf("Next salary enter(q to quit): ");
		while(getchar() != '\n')
		{
			continue;
		}
	}

	printf("Bye!\n");

	return 0;
}

float single_tax(float income)
{
	if(income <= 0.0)
	{
		return 0.0;
	}

	if(income <= 23350.0)
	{
		return income * 0.15;
	}

	if(income <= 56550.0)
	{
		return 3502.2 + (income - 23350.0) * 0.28;
	}

	if(income <= 117950.0)
	{
		return 12798.5 + (income - 56550.0) * 0.31;
	}

	if(income <= 256500.0)
	{
		return 31832.5 + (income - 117950.0) * 0.36;
	}

	return 81710.5 + (income - 256500.0) * 0.396;
}