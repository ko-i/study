// 2020-12-28 created by Akson
// pc9.3

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int zero_int = 0;
	float zero_float = 0.0;

	char bit_map[33];
	bit_map[32] = '\0';
	int count = 32;
	while(count > 0)
	{
		bit_map[count - 1] = (unsigned int)zero_int & (unsigned)1 ? '1' : '0';
		count--;
		zero_int >>= 1;
	}

	printf("int 0's bit: %s\n", bit_map);

	count = 32;
	while(count > 0)
	{
		bit_map[count - 1] = (unsigned int)zero_float & (unsigned)1 ? '1' : '0';
		count--;
		zero_float = (unsigned int)zero_float >> 1;
	}

	printf("float 0.0's bit: %s\n", bit_map);

	return 0;
}