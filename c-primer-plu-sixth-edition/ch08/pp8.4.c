// 2020-11-08 created by Akson

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	float words_count = 0.0;
	float letters_count = 0.0;

	int ch;
	int last = 1;
	while((ch = getchar()) != EOF)
	{
		if(isalpha(ch))
		{
			letters_count++;
			if(!isalpha(last))
			{
				words_count++;
			}
		}

		last = ch;
	}

	printf("The average letters of per word is: %.2f\n", letters_count / words_count);
}