// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	int nums[8];
	int i;

	for(i = 0; i < 8; i++)
	{
		if(i == 0)
		{
			nums[i] = 2;
			continue;
		}
		nums[i] = 2 * nums[i - 1];
	}

	i = 0;
	do
	{
		printf("%d ", nums[i]);
		i++;
	} while(i < 8);

	printf("\n");

	return 0;
}