// 2020-11-06 created by Akson
// Code6.14 zeno.c

#include <stdio.h>

int main(void)
{
	int i_ct;
	double time, power_of_2;
	int limit;

	printf("Enter the number of terms you want: ");
	scanf("%d", &limit);

	for(time = 0, power_of_2 = 1, i_ct = 1; i_ct <= limit; i_ct++, power_of_2 *= 2.0)
	{
		time += 1.0 / power_of_2;
		printf("time = %f when terms = %d.\n", time, i_ct);
	}

	return 0;
}