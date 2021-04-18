// 2020-12-15 created by Akson
// pe9.15

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 100

int dollars(char * dest, char const * src);
char * s_gets(char * st, int n);

int main(int argc, char const *argv[])
{
	printf("Enter a dollars in penny numbers, and i will format it in \"$XX,XXX.XX\"\n");
	printf("Pennys numbers(nothing to quit): ");

	char src[MAXSIZE];
	while(s_gets(src, MAXSIZE) != NULL && src[0] != '\0')
	{
		char dest[MAXSIZE] = {"$0.00"};
		if(dollars(dest, src) == 0)
		{
			printf("Invilid Input, please only include digit\n");
			printf("Pennys numbers(nothing to quit): ");
			continue;
		}

		printf("You have %s\n\n", dest);

		printf("Next pennys numbers(nothing to quit): ");
	}

	printf("Bye!\n");

	return 0;
}

int dollars(char * dest, char const * src)
{
	int src_len = 0;
	char const * psrc = src;
	
	while(*psrc != '\0')
	{
		if(!isdigit(*psrc))
		{
			return 0;
		}

		src_len++;
		psrc++;
	}

	if(src_len == 0)
	{
		return 1;
	}

	psrc--;
	char* pdest = dest;

	if(src_len <= 3)
	{
		pdest += 4;
		while(psrc != src)
		{
			if(*pdest == '.')
			{
				pdest--;
			}

			*pdest = *psrc;
			psrc--;
			pdest--;
		}

		if(*pdest == '.')
		{
			pdest--;
		}

		*pdest = *psrc;

		return 1;
	}

	int head_count = (src_len - 2) % 3;
	if(head_count == 0)
	{
		head_count = 3;
	}
	
	int punc_count = (src_len - 2 - 1) / 3;
	*pdest = '$';
	pdest++;
	while(head_count > 0)
	{
		*pdest = '#';
		pdest++;
		head_count--;
	}

	while(punc_count > 0)
	{
		*pdest = ',';
		pdest++;
		*pdest = '#';
		pdest++;
		*pdest = '#';
		pdest++;
		*pdest = '#';
		pdest++;

		punc_count--;
	}

	*pdest = '.';
	pdest++;
	*pdest = '#';
	pdest++;
	*pdest = '#';
	pdest++;
	*pdest = '\0';

	pdest = dest;
	psrc = src;

	while(*psrc != '\0')
	{
		if(*pdest != '#')
		{
			pdest++;
		}
		*pdest = *psrc;

		pdest++;
		psrc++;
	}

	return 1;
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