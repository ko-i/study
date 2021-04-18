// 2020-12-11 created by Akson
// p7.10.c

#include <stdio.h>

static long long count = 0;

long long Fibonacci(int n);

int main(int argc, char const *argv[])
{
	for(int i = 1; i < 51; i++)
	{
		count = 0;
		long long result = Fibonacci(i);
		printf("Fibonacci(%d) = %lld, call Fibo count: %lld\n", i, result, count);
	}

	printf("Bye!\n");

	return 0;
}

long long Fibonacci(int n)
{
	count++;
	if(n == 0 || n == 1)
	{
		return 1;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}