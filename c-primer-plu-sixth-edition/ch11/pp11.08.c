// 2020-11-10 created by Akson

#include <stdio.h>

#define SIZE 40

char * string_in(char * str1, char * str2);
char * s_gets(char * st, int n);

int main(void)
{
	char str1[SIZE];
	char str2[SIZE];

	char* pts1;
	char* pts2;

	puts("Please enter two str.");
	printf("Enter the first one: ");
	pts1 = s_gets(str1, SIZE);
	printf("Enter the second one: ");
	pts2 = s_gets(str2, SIZE);
	while(pts1 != NULL && pts2 != NULL && *pts1 != '\0' && *pts2 != '\0')
	{
		if(string_in(str1, str2))
		{
			puts("Find it!");
		}
		else
		{
			puts("None");
		}

		puts("Please enter two str.");
		printf("Enter the first one: ");
		pts1 = s_gets(str1, SIZE);
		printf("Enter the second one: ");
		pts2 = s_gets(str2, SIZE);
	}

	puts("Done!");

	return 0;
}

char * string_in(char * str1, char * str2)
{
	char * ret_val = NULL;

	char * pts1 = str1;
	char * pts2;

	while(*pts1 != '\0')
	{
		char * pts11 = pts1;
		pts2 = str2;
		while(*pts11 != '\0' && *pts2 != '\0')
		{
			if(*pts11 == *pts2)
			{

				pts11++;
				pts2++;
				continue;
			}
			break;
		}

		if(*pts2 == '\0')
		{
			ret_val = pts1;
			break;
		}

		pts1++;
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