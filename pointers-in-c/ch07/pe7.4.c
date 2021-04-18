// 2020-12-11 created by Akson
// pe7.4

#include <stdio.h>

int max_list(int nums[]);

int main(int argc, char const *argv[])
{
	// test
	int nums[10] = {1, 3, 4, 5, 6, 2, 3, 4, 12, -1};

	printf("The max num is: %d\n", max_list(nums));

	printf("Bye!\n");
	return 0;
}

int max_list(int nums[])
{
	int max = nums[0];

	for(int i = 1; nums[i] >=0; i++)
	{
		if(max < nums[i])
		{
			max = nums[i];
		}
	}

	return max;
}
