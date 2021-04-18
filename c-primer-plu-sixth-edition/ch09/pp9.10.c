// 2020-11-08 created by Akson

#include <stdio.h>

void to_base_n(unsigned long number, int n);

int main(void)
{
	unsigned long number;
	int n;
	printf("Enter two integers (q to quit):\n");
	while(scanf("%lu %d", &number, &n) == 2)
	{
		printf("%d equivalent: ", n);
		to_base_n(number, n);
		putchar('\n');
		printf("Enter two integers (q to quit):\n");
	}

	printf("Bye.\n");

	return 0;
}

void to_base_n(unsigned long number, int n)
{
	int r;

	r = number % n;

	if(number >= n)
	{
		to_base_n(number / n, n);
	}

	putchar(r + 48);

	return;
}