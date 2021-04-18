// 2020-11-07 created by Akson

#include <stdio.h>

int main(void)
{
	char last_ch = '#';
	char curr_ch = '#';
	int ei_cnt = 0;

	printf("Please enter a sentence and i will count the 'ei' numbers in it! # to end.\n");
	while((curr_ch = getchar()) != '#')
	{
		if(last_ch == 'e' && curr_ch == 'i')
		{
			ei_cnt++;
		}
		last_ch = curr_ch;
	}

	printf("The number of 'ei' appearance is %d.\n", ei_cnt);

	return 0;

}