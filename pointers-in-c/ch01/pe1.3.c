// 2020-12-02 created by Akson
// pe1.3.c checksum

#include <stdio.h>

int main(int argc, char const *argv[])
{
	signed char checksum = -1;

	printf("Enter a string and I will calculate is checksum.\n");
	printf("Enter string: ");

	int ch;
	while((ch = getchar()))
	{
		checksum += ch;

		if(ch == '\n')
		{
			break;
		}
	}

	printf("Checksum: %d\n", checksum);

	printf("Bye!\n");

	return 0;
}