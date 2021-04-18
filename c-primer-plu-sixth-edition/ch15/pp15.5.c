// 2020-11-14 created by Akson

#include <stdio.h>

unsigned int rotate_l(unsigned int num, int rotate_num);

int main(void)
{
	unsigned int num;
	int rotate_num;
	unsigned int result;

	printf("Enter a number: ");
	while(scanf("%u", &num) == 1)
	{
		printf("Enter a rotate number: ");
		scanf("%d", &rotate_num);

		result = rotate_l(num, rotate_num);

		printf("The number %u rotate left %d digit is %u\n", num, rotate_num, result);
		printf("Enter a number: ");
	}

	printf("Bye.\n");

	return 0;
}

unsigned int rotate_l(unsigned int num, int rotate_num)
{
	int digit_len = sizeof(unsigned int) * 8;
	
	unsigned int temp = num;
	num >>= (digit_len - (rotate_num % digit_len));
	temp <<= (rotate_num % digit_len);

	num = num | temp;

	return num;
}