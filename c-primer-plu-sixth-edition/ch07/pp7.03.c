// 2020-11-07 created by Akson

#include <stdio.h>

int main(void)
{
	int num;

	int even_sum = 0;
	int even_num = 0;
	int odd_sum = 0;
	int odd_num = 0;

	printf("Please enter an integer, 0 to quit: ");
	while(scanf("%d", &num))
	{
		if(num == 0)
		{
			break;
		}
		else if(num % 2 == 0)
		{
			even_sum += num;
			even_num++;
		}
		else
		{
			odd_sum += num;
			odd_num++;
		}
		printf("Please enter an integer, 0 to quit: ");
	}

	printf("Even number sum = %d, average = %.2f\n", even_num == 0? 0 : even_sum, even_num == 0? 0.0 : float(even_sum) / float(even_num));
	printf("Odd number sum = %d, average = %.2f\n", odd_num == 0? 0 : odd_sum, odd_num == 0? 0.0 : float(odd_sum) / float(odd_num));

	return 0;
}