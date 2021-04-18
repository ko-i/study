// 2020-12-11 created by Akson
// pe7.2

#include <stdio.h>

int gcd(int m, int n);
int gcd_iter(int m, int n);

int main(int argc, char const *argv[])
{
	// test
	int m, n;
	printf("Enter two positive numbers and I will calcu gcd of them.\n");
	printf("Two positive numbers(q to quit): ");

	while(scanf("%d %d", &m, &n) == 2)
	{
		printf("The gcd of %d and %d is: %d\n", m, n, gcd(m, n));
		printf("And the result of iter mathod: %d\n", gcd_iter(m, n));

		printf("Next two positive numbers(q to quit): ");
	}

	printf("Bye!\n");

	return 0;
}

int gcd(int m, int n)
{
	if(m <= 0 || n <= 0)
	{
		return 0;
	}

	if(m % n == 0)
	{
		return n;
	}

	return gcd(n, m % n);
}

int gcd_iter(int m, int n)
{
	if(m <= 0 || n <= 0)
	{
		return 0;
	}

	int r;
	while(m % n != 0)
	{
		r = m % n;
		m = n;
		n = r;
	}

	return n;
}