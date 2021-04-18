// 2020-11-10 created by Akson

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	char ch;
	int word_cnt = 0;
	int upper_cnt = 0;
	int lower_cnt = 0;
	int punct_cnt = 0;
	int num_cnt = 0;

	bool alpha_start = false;

	puts("Please enter a sentence (EOF to stop)");

	while((ch = getchar()) != EOF)
	{
		if(isalpha(ch))
		{
			alpha_start = true;
			if(islower(ch))
			{
				lower_cnt++;
			}
			else
			{
				upper_cnt++;
			}
		}
		else
		{
			if(alpha_start == true)
			{
				word_cnt++;
				alpha_start = false;
			}

			if(isdigit(ch))
			{
				num_cnt++;
			}
			if(ispunct(ch))
			{
				punct_cnt++;
			}
		}
	}

	printf("word count: %d\n", word_cnt);
	printf("upper count: %d\n", upper_cnt);
	printf("lower count: %d\n", lower_cnt);
	printf("punct count: %d\n", punct_cnt);
	printf("num count: %d\n", num_cnt);

	return 0;
}