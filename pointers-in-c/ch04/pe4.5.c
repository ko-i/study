// 2020-12-05 created by Akson
// pe4.5.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

char * s_gets(char * st, int n);

int main(int argc, char const *argv[])
{
	printf("Enter some lines and I will print them in my mind(Nothing for quit).\n");

	char str1[MAXSIZE];
	char str2[MAXSIZE];

	int same_flag = 0;

	while(s_gets(str2, MAXSIZE) != NULL && str2[0] != '\0')
	{
		if(strcmp(str1, str2) == 0)
		{
			if(!same_flag)
			{
				printf("%s\n", str2);
			}
			same_flag = 1;
		}
		else
		{
			same_flag = 0;
		}

		strcpy(str1, str2);
	}

	printf("Bye!\n");

	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n');
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