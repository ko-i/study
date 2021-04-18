// 2020-12-11 created by Akson
// pe7.6

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 200

void written_amount(unsigned int amount, char* buffer);

int main(int argc, char const *argv[])
{
	// test
	char buffer[MAXSIZE];
	buffer[0] = '\0';
	unsigned int amount = 16312;

	written_amount(amount, buffer);
	printf("\n%s\n", buffer);

	return 0;
}

void written_amount(unsigned int amount, char* buffer)
{
	char** digit_name = (char**)malloc(9 * sizeof(char*));
	digit_name[0] = "ONE";
	digit_name[1] = "TWO";
	digit_name[2] = "THREE";
	digit_name[3] = "FOUR";
	digit_name[4] = "FIVE";
	digit_name[5] = "SIX";
	digit_name[6] = "SEVEN";
	digit_name[7] = "EIGHT";
	digit_name[8] = "NINE";

	char** digit_count_name = (char**)malloc(4 * sizeof(char*));
	digit_count_name[0] = "TY";
	digit_count_name[1] = "HUNDRED";
	digit_count_name[2] = "THOUSAND";
	digit_count_name[3] = "TY";

	int digit_count = 0;
	int digits[MAXSIZE];
	int amount_copy = amount;
	while(amount_copy != 0)
	{
		digits[digit_count] = amount_copy % 10;
		digit_count++;
		amount_copy /= 10;
	}

	amount_copy = amount;
	while(amount_copy != 0)
	{
		if((amount_copy % 10) - 1 >= 0)
		{
			strcat(buffer, digit_name[digits[digit_count - 1] - 1]);
			strcat(buffer, " ");
			printf("%s ", digit_name[digits[digit_count - 1] - 1]);
		}

		if(digit_count - 2 >= 0)
		{
			strcat(buffer, digit_count_name[digit_count - 2]);
			strcat(buffer, " ");
			printf("%s ", digit_count_name[digit_count - 2]);
		}

		amount_copy /= 10;
		digit_count--;
	}

	free(digit_name);
	free(digit_count_name);
}