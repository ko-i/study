// 2020-11-10 created by Akson

#include <stdio.h>
#include <ctype.h>

#define MAX 100

char * get_word(char * st);

int main(void)
{
	char str[MAX];
	char * word;

	puts("You can enter some sentence and I will pick the first word in it.");
	word = get_word(str);
	puts("Here is the word I pick:");
	puts(word);

	return 0;
}

char * get_word(char * st)
{
	char * ret_val;
	int index = 0;

	ret_val = fgets(st, MAX, stdin);

	if(ret_val)
	{
		while(isspace(st[index]))
		{
			index++;
		}
		ret_val = &st[index];

		while(!isspace(st[index]))
		{
			index++;
		}

		st[index] = '\0';
	}
	
	return ret_val;
}