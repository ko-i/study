// 2020-12-05 created by Akson
// pe4.4.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

void copy_n(char dst[], char src[], int n);
char * s_gets(char * st, int n);

int main(int argc, char const *argv[])
{
	printf("Enter a string and a number i will copy it.\n");
	char src[MAXSIZE];

	printf("Enter a string(nothing to quit): ");
	while(s_gets(src, MAXSIZE) != NULL && src[0] != '\0')
	{
		printf("The string you entered: %s\n", src);
		int n;
		printf("Enter the number of letters to copy: ");
		scanf("%d", &n);

		char* dst = (char*)malloc(n * sizeof(char));
		copy_n(dst, src, n);
		printf("Copy result: %s\n", dst);
		free(dst);

		while(getchar() != '\n')
		{
			continue;
		}
		printf("Enter a string(nothing to quit): ");
	}

	printf("Bye!\n");

	return 0;
}

void copy_n(char dst[], char src[], int n)
{
	char* pd = dst;
	char* ps = src;

	int count = 0;
	while(count < n)
	{
		if(*ps == '\0')
		{
			*pd = '\0';
			pd++;
			count++;
			continue;
		}

		*pd = *ps;
		pd++;
		ps++;
		count++;
	}
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