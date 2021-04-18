// 2020-12-05 created by Akson
// pe4.1.c

#include <stdio.h>

double my_sqrt(double num);

int main(int argc, char const *argv[])
{
	printf("Enter a number and I will calcu its sqrt.\n");
	printf("Number enter(EOF to quit): ");

	double number;
	while(scanf("%lf", &number) == 1)
	{
		printf("sqrt(%.2lf) is %.2lf\n", number, my_sqrt(number));

		printf("Any number else?(EOF to quit): ");

		// eat the '\n'
		while(getchar() != '\n')
		{
			continue;
		}
	}

	printf("Bye!\n");
	return 0;
}

double my_sqrt(double num)
{
	double a1 = 1.0;
	double a2 = 1.0;

	do
	{
		a1 = a2;
		a2 = (a1 + num / a1) / 2.0;
		
		printf("%.2lf ", a2);
	} while(a1 != a2);

	printf("\n");
	return a1;
}