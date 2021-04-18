// 2020-12-07 created by Akson
// pe5.3

#include <stdio.h>

unsigned int reverse_bits(unsigned int value);

int main(int argc, char const *argv[])
{
	unsigned int num;
	printf("Enter a number and I will reverse bits in it.\n");
	printf("Number(q to quit): \n");

	while(scanf("%u", &num) == 1)
	{
		printf("The number %u after reverse is %u\n", num, reverse_bits(num));

		printf("Another number(q to quit): \n");
	}

	printf("Bye!\n");

	return 0;
}

unsigned int reverse_bits(unsigned int value)
{
	int bits_num = 8 * sizeof(unsigned int);

	for(int i = 0; i < bits_num / 2; i++)
	{
		// find the bit number in two position
		int bit_1, bit_2;
		bit_1 = (value >> i) % 2;
		bit_2 = (value >> (bits_num - i)) % 2;

		// change them
		unsigned int temp = 1;
		temp <<= i;

		if(bit_2 == 1)
		{
			value ^= temp;
		}
		else
		{
			value &= (~temp);
		}

		temp = 1;
		temp <<= (bits_num - i - 1);
		if(bit_1 == 1)
		{
			value ^= temp;
		}
		else
		{
			value &= (~temp);
		}
	}

	return value;
}