// 2020-12-07 created by Akson
// pe6.2

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int del_substr(char *str, char const *substr);

int main(int argc, char const *argv[])
{
	int state;
	char str[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

	// test 1
	printf("Initial str: %s\n", str);
	char *sub_1 = "FGH";
	state = del_substr(str, sub_1);
	if(state)
	{
		printf("After delete %s, str: %s", sub_1, str);
	}
	else
	{
		printf("%s is not substr of str.\n", sub_1);
	}

	// test 2
	printf("Initial str: %s\n", str);
	char *sub_2 = "CDE";
	state = del_substr(str, sub_2);
	if(state)
	{
		printf("After delete %s, str: %s\n", sub_2, str);
	}
	else
	{
		printf("%s is not substr of str.\n", sub_2);
	}


	return 0;
}

int del_substr(char *str, char const *substr)
{
	int s_len = 0;
	char *ps = str;
	while(*ps != '\0')
	{
		s_len++;
		ps++;
	}

	int sub_len = 0;
	char const *psub = substr;
	while(*psub != '\0')
	{
		sub_len++;
		psub++;
	}

	if(s_len < sub_len || sub_len == 0)
	{
		return 0;
	}

	int count = s_len - sub_len;
	ps = str;
	int if_find;
	while(count-- >= 0)
	{
		if_find = 0;
		psub = substr;
		char *temp_ps = ps;
		while(*psub != '\0')
		{
			if(*psub == *temp_ps)
			{
				psub++;
				temp_ps++;
			}
			else
			{
				break;
			}
		}

		if(*psub == '\0')
		{
			if_find = 1;
			break;
		}
		ps++;
	}

	if(!if_find)
	{
		return 0;
	}

	while(*(ps + sub_len) != '\0')
	{
		*ps = *(ps + sub_len);
		ps++;
	}

	*ps = '\0';

	return 1;
}