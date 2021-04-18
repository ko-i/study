// 2020-12-02 created by Akson
// pe1.4.c find the max len string

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000

int main(int argc, char const *argv[])
{
	printf("Enter some sentence and I will output the longest one!\n");
	printf("Enter sentences split by [Enter] and EOF to end.\n");

	int max_len = 0;

	char str[1000];
	char temp[1000];

	int ch;
	int len = 0;
	while((ch = getchar()) != EOF)
	{
		if(ch == '\n')
		{
			if(len > max_len)
			{
				temp[len] = '\0';
				max_len = len;
				for(int i = 0; i <= len; i++)
				{
					str[i] = temp[i];
				}
			}
			len = 0;

			continue;
		}

		temp[len] = ch;
		len++;
	}

	printf("The longet sentence is:\n");
	printf("%s\n", str);

	printf("Bye!\n");

	return 0;
}