// 2020-11-10 created by Akson

#include <stdio.h>

#define SIZE 40

char * mystrncpy(char * str1, char * str2, int n);
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
		int n;
		printf("Enter a number: ");
		scanf("%d", &n);
		getchar();
		puts(mystrncpy(pts1, pts2, n));

		puts("Please enter two str.");
		printf("Enter the first one: ");
		pts1 = s_gets(str1, SIZE);
		printf("Enter the second one: ");
		pts2 = s_gets(str2, SIZE);
	}

	puts("Done!");

	return 0;
}

char * mystrncpy(char * str1, char * str2, int n)
{
	char * ret_val = str1;
	int index = 0;
	int count = 0;

	while(str1[index] != '\0')
	{
		index++;
	}

	while(index < SIZE - 1 && count < n && str2[count] != '\0')
	{
		str1[index] = str2[count];
		index++;
		count++;
	}

	str1[index] = '\0';

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