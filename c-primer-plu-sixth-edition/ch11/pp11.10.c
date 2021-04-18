// 2020-11-10 created by Akson

#include <stdio.h>

#define SIZE 40

char * delete_blank(char * str);
char * s_gets(char * st, int n);

int main(void)
{
	char str1[SIZE];

	char* pts1;

	printf("Please enter a str and I will delete blank in it: ");
	pts1 = s_gets(str1, SIZE);
	while(pts1 != NULL && *pts1 != '\0')
	{
		puts(delete_blank(pts1));

		printf("Please enter a str and I will delete blank in it: ");
		pts1 = s_gets(str1, SIZE);
	}

	puts("Done!");

	return 0;
}

char * delete_blank(char * str)
{
	char * ret_val = str;
	char * pts;
	while(*str != '\0')
	{
		if(*str == ' ')
		{
			pts = str;
			while(*pts != '\0')
			{
				*pts = *(pts + 1);
				pts++;
			}
			str--;
		}
		str++;
	}

	return ret_val;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
		{
			i++;
		}

		if(st[i] == '\n')
		{
			st[i] = '\0';
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