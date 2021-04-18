// 2020-12-05 created by Akson
// pe4.6.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

int substr(char dst[], char src[], int start, int len);
char * s_gets(char * st, int n);

int main(int argc, char const *argv[])
{
	printf("Enter a string and two number i will copy it.\n");
	char src[MAXSIZE];

	printf("Enter a string(nothing to quit): ");
	while(s_gets(src, MAXSIZE) != NULL && src[0] != '\0')
	{
		printf("The string you entered: %s\n", src);
		int start;
		printf("Enter the start index of string to copy: ");
		scanf("%d", &start);
		while(getchar() != '\n')
		{
			continue;
		}

		int n;
		printf("Enter the number of letters to copy: ");
		scanf("%d", &n);
		while(getchar() != '\n')
		{
			continue;
		}

		char* dst = (char*)malloc(n * sizeof(char));
		int letters_copy_count = substr(dst, src, start, n);
		printf("Copy %d letters, And result: %s\n", letters_copy_count, dst);
		free(dst);

		printf("Enter a string(nothing to quit): ");
	}

	printf("Bye!\n");

	return 0;
}

int substr(char dst[], char src[], int start, int len)
{
	if(start > strlen(src) || start < 0 || len <= 0)
	{
		dst[0] = '\0';
		return 0;
	}

	char* ps = &src[start];
	char* pd = dst;

	int success_copy_count = 0;
	int count = 0;
	while(count < len)
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
		success_copy_count++;
	}

	return success_copy_count;
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