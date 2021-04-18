// 2020-12-07 created by Akson
// pe5.5

#include <stdio.h>

#define MAXSIZE 32

void set_bit(char bit_array[], unsigned int bit_number);
void clear_bit(char bit_array[], unsigned int bit_number);
void assign_bit(char bit_array[], unsigned int bit_number, int value);
int test_bit(char bit_array[], unsigned int bit_number);

int main(int argc, char const *argv[])
{
	// initial the bits array
	char bits[MAXSIZE + 1];
	for(int i = 0; i < MAXSIZE; i++)
	{
		bits[i] = '0';
	}
	bits[MAXSIZE] = '\0';

	printf("This is a number in bit present (32 digits):\n");
	printf("%s\n", bits);

	printf("Here are the operation you can make on it.\n");
	printf("s) set_bit  c) clear_bit  a) assign_bit  t) test_bit  q) quit\n");
	printf("Operation: ");
	int choice;
	while((choice = getchar()) && choice != 'q')
	{
		while(getchar() != '\n')
		{
			continue;
		}

		switch(choice)
		{
			unsigned int bit_index; 
			case 's':
				printf("Enter the bit index(1 to %d) you want to set 1: ", MAXSIZE);
				while(scanf("%u", &bit_index) != 1 && (bit_index < 1 || bit_index > MAXSIZE))
				{
					while(getchar() != '\n');
					printf("Invalid number! Please enter a number between 1 and %d: ", MAXSIZE);
				}

				while(getchar() != '\n');
				set_bit(bits, bit_index);
				break;

			case 'c':
				printf("Enter the bit index(1 to %d) you want to clear(set to 0): ", MAXSIZE);
				while(scanf("%u", &bit_index) != 1 && (bit_index < 1 || bit_index > MAXSIZE))
				{
					while(getchar() != '\n');
					printf("Invalid number! Please enter a number between 1 and %d: ", MAXSIZE);
				}

				while(getchar() != '\n');
				clear_bit(bits, bit_index);
				break;

			case 'a':
				printf("Enter the bit index(1 to %d) you want to assign: ", MAXSIZE);
				while(scanf("%u", &bit_index) != 1 && (bit_index < 1 || bit_index > MAXSIZE))
				{
					while(getchar() != '\n');
					printf("Invalid number! Please enter a number between 1 and %d: ", MAXSIZE);
				}
				while(getchar() != '\n');

				int value;
				printf("Enter the value(0 or 1) you want to assign: ");
				while(scanf("%d", &value) != 1 && (value != 0 || value != 1))
				{
					while(getchar() != '\n');
					printf("Invalid number! Please enter 0 or 1: ");
				}
				while(getchar() != '\n');

				assign_bit(bits, bit_index, value);
				break;

			case 't': 
				printf("Enter the bit index(1 to %d) you want to test(set to 0): ", MAXSIZE);
				while(scanf("%u", &bit_index) != 1 && (bit_index < 1 || bit_index > MAXSIZE))
				{
					while(getchar() != '\n');
					printf("Invalid number! Please enter a number between 1 and %d: ", MAXSIZE);
				}

				while(getchar() != '\n');
				if(test_bit(bits, bit_index))
				{
					printf("True! The bit is 1.\n");
				}
				else
				{
					printf("False! The bit is 0.\n");
				}
				break;

			default: 
				printf("You input is invalid! Please enter(s, c, a, t or q) again: ");
				continue;
		}

		printf("Some another operation?\n");
		printf("s) set_bit  c) clear_bit  a) assign_bit  t) test_bit  q) quit\n");
		printf("Operation: ");
	}

	printf("Bye!\n");

	return 0;
}

void set_bit(char bit_array[], unsigned int bit_number)
{
	bit_array[bit_number - 1] = '1';

	printf("The bit string now is:\n");
	printf("%s\n", bit_array);
}

void clear_bit(char bit_array[], unsigned int bit_number)
{
	bit_array[bit_number - 1] = '0';

	printf("The bit string now is:\n");
	printf("%s\n", bit_array);
}

void assign_bit(char bit_array[], unsigned int bit_number, int value)
{
	bit_array[bit_number - 1] = value ? '1' : '0';

	printf("The bit string now is:\n");
	printf("%s\n", bit_array);
}

int test_bit(char bit_array[], unsigned int bit_number)
{
	return bit_array[bit_number - 1] == '1' ? 1 : 0;
}
