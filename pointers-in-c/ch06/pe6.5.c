// 2020-12-08 created by Akson
// pe6.5

#include <stdio.h>
#include <limits.h>

#define MAXSIZE 1000

unsigned int clear_bit(unsigned int nums, int bit_index);
int get_bit(unsigned int nums, int bit_index);
int is_prime(int num);

int main(int argc, char const *argv[])
{
	unsigned int nums[MAXSIZE];
	int int_bits = sizeof(int) * 8;  // 在本机上int有32位

	// initial nums;
	for(int i = 0; i < MAXSIZE; i++)
	{
		nums[i] = UINT_MAX;
	}

	// 还是省略偶数，所以第一个数字是3，第index个数字对应2 * index + 1。
	// 其对应是否为素数的的判定位置在(index - 1) / int_bits)个元素中的第(index - 1) % int_bits)位
	// 例如第1个数字应该在nums[0]的第0位（0~31位)
	// 第32个数字应该在nums[1]的第0位

	// 开始埃氏筛法
	for(int i = 1; i < MAXSIZE * int_bits; i++)
	{
		if(get_bit(nums[(i - 1) / int_bits], (i - 1) % int_bits) == 0)
		{
			continue;
		}

		if(!is_prime(2 * i + 1))
		{
			nums[(i - 1) / int_bits] = clear_bit(nums[(i - 1) / int_bits], (i - 1) % int_bits);
		}

		for(int j = i + 1; j < MAXSIZE * int_bits; j++)
		{
			if(get_bit(nums[(j - 1) / int_bits], (j - 1) % int_bits) != 0 && ((2 * j + 1) % (2 * i + 1) == 0))
			{
				nums[(j - 1) / int_bits] = clear_bit(nums[(j - 1) / int_bits], (j - 1) % int_bits);
			}
		}
	}

	// 检测
	for(int i = 1; i < MAXSIZE * int_bits; i++)
	{
		if(get_bit(nums[(i - 1) / int_bits], (i - 1) % int_bits) != 0)
		{
			printf("%d ", 2 * i + 1);
		}
	}

	printf("Done!\n");

	return 0;
}

unsigned int clear_bit(unsigned int nums, int bit_index)
{
	unsigned int mask = 1;
	
	mask <<= bit_index;
	nums &= (~mask);

	return nums;
}

int get_bit(unsigned int nums, int bit_index)
{
	unsigned int mask = 1;
	mask <<= bit_index;
	nums &= mask;

	if(nums == 0)
	{
		return 0;
	}

	return 1;
}

int is_prime(int num)
{
	for(int i = 2; i <= num / 2 + 1; i++)
	{
		if(num % i == 0)
		{
			return 0;
		}
	}

	return 1;
}