// 2020-11-14 created by Akson

#include <stdio.h>
#include <string.h>

#define STRLEN 20

char * s_gets(char * str, int n);

int main(void)
{
	char str[STRLEN];
	int num;

	printf("Enter a number in binary: ");
	while(s_gets(str, STRLEN) != NULL && str[0] != '\0')
	{
		int index = strlen(str) - 1;
		int count = 1;
		num = 0;
		while(index >= 0)
		{
			if(str[index] == '1')
			{
				num += count; 
			}

			index--;
			count *= 2;
		}

		printf("The number in digital is: %d\n", num);
		printf("Enter a number in binary: ");
	}

	printf("Bye!\n");

	return 0;
}

char * s_gets(char * str, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(str, n, stdin);
	if(ret_val)
	{
		find = strchr(str, '\n');
		if(find)
		{
			*find = '\0';
		}
		else
		{
			while(getchar() != '\n')
			{
				continue;
			}
		}
	}

	return ret_val;
}