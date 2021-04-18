// 2020-12-05 created by Akson
// code5.2 count_1b.c

#include <stdio.h>

// 这个函数返回参数值中值为一的个数
int count_one_bits(unsigned int value);

int main(int argc, char const *argv[])
{
	printf("Enter a number and I will count the 1 numbers in its bit expression.\n");
	printf("Number enter(q to quit): ");

	unsigned int value;
	while(scanf("%u", &value) == 1)
	{
		printf("The one's number in %d(bit expression) is %d\n", value, count_one_bits(value));

		// eat '\n'
		while(getchar() != '\n')
		{
			continue;
		}
		
		printf("Next number enter(q to quit): ");
	}

	printf("Bye!\n");

	return 0;
}

int count_one_bits(unsigned int value)
{
	int ones;

	// 当这个值还有一些值为1时...
	for(ones = 0; value != 0; value >>= 1)
	{
		// 如果最低位的值为一，计数增一
		if(value % 2 == 1)
		{
			ones += 1;
		}
	}

	return ones;
}