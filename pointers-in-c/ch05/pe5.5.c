// 2020-12-07 created by Akson
// pe5.5

#include <stdio.h>

int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit);

int main(int argc, char const *argv[])
{
	int original_value = 0xffff;
	int value_to_store = 0x123;
	unsigned starting_bit = 13;
	unsigned ending_bit = 9;

	printf("0x%x after change is 0x%x\n", original_value, store_bit_field(original_value, value_to_store, starting_bit, ending_bit));

	printf("Done!\n");

	return 0;
}

int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit)
{
	// create mask
	unsigned int mask = 0;
	unsigned int one_bit = 1;
	for(int i = starting_bit; i >= ending_bit; i--)
	{
		mask |= (one_bit << i);
	}

	original_value &= (~mask);
	value_to_store <<= ending_bit;

	value_to_store &= mask;

	return original_value | value_to_store;
}