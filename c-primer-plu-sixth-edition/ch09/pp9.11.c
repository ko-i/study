// 2020-11-08 created by Akson

#include <stdio.h>
int Fab(int n);

int main(void)
{
	int n;
	printf("Enter a number(q to quit)\n");
	while(scanf("%d", &n) == 1)
	{
		printf("%d\n", Fab(n));
		printf("Enter a number(q to quit)\n");
	}

	return 0;
}

int Fab(int n)
{
	int last2 = 1;
	int last1 = 1;
	int now;
	if(n == 0)
	{
		return 1;
	}
	if(n == 1)
	{
		return 1;
	}

	while(--n)
	{
		now = last1 + last2;
		last2 = last1;
		last1 = now;
	}

	return now;
}