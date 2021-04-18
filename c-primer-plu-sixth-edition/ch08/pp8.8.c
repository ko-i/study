// 2020-11-08 created by Akson

#include <stdio.h>
#include <ctype.h>

char load_operation(void);
float load_number(void);
char get_first(void);

void add(void);
void subtract(void);
void multiply(void);
void divide(void);

int main(void)
{
	printf("Enter the operation of your choice:\n");
	printf("a. add         s. subtract\n");
	printf("m. multiply    d. divide\n");
	printf("q. quit\n");

	char op = load_operation();
	while(op != 'q')
	{
		switch(op)
		{
			case 'a': add(); break;
			case 's': subtract(); break;
			case 'm': multiply(); break;
			case 'd': divide(); break;
		}

		printf("Enter the operation of your choice:\n");
		printf("a. add         s. subtract\n");
		printf("m. multiply    d. divide\n");
		printf("q. quit\n");

		op = load_operation();
	}

	printf("Bye.\n");

	return 0;
}

char load_operation(void)
{
	int ch;

	ch = get_first();
	while(ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
	{
		printf("Please respond with a, s, m, d or q.\n");
		ch = get_first();
	}

	return ch;
}

char get_first(void)
{
	int ch;

	while(isspace(ch = getchar()))
	{
		continue;
	}

	while(getchar() != '\n')
	{
		continue;
	}

	return ch;
}

float load_number(void)
{
	float input;
	char ch;

	while(scanf("%f", &input) != 1)
	{
		while((ch = getchar()) != '\n')
		{
			putchar(ch);
		}
		printf(" is not an integer.\n");
		printf("Please enter an integer value, such as 2.5, -1.78E8, or 3: ");
	}

	while(getchar() != '\n')
	{
		continue;
	}

	return input;
}

void add(void)
{
	printf("Enter first number: ");
	float num1 = load_number();
	printf("Enter second number: ");
	float num2 = load_number();

	printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
}

void subtract(void)
{
	printf("Enter first number: ");
	float num1 = load_number();
	printf("Enter second number: ");
	float num2 = load_number();

	printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
}

void multiply(void)
{
	printf("Enter first number: ");
	float num1 = load_number();
	printf("Enter second number: ");
	float num2 = load_number();

	printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
}

void divide(void)
{
	printf("Enter first number: ");
	float num1 = load_number();
	printf("Enter second number: ");
	float num2 = load_number();
	while(num2 == 0.0)
	{
		printf("0 can not be a divider, try another: \n");
		num2 = load_number();
	}

	printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
}
