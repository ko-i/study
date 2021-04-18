// 2020-12-14 created by Akson
// pe9.1

#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	printf("Enter a sentence and I will count the char in different of them.\n");
	printf("String enter(EOF to quit):\n");

	int cntrl_cnt = 0;
	int space_cnt = 0;
	int digit_cnt = 0;
	int lower_cnt = 0;
	int upper_cnt = 0;
	int punct_cnt = 0;
	int cantprint_cnt = 0;

	int ch;
	while((ch = getchar()) && ch != EOF)
	{
		if(iscntrl(ch))
		{
			cntrl_cnt++;
			continue;
		}

		if(isspace(ch))
		{
			space_cnt++;
			continue;
		}

		if(isdigit(ch))
		{
			digit_cnt++;
			continue;
		}

		if(islower(ch))
		{
			lower_cnt++;
			continue;
		}

		if(isupper(ch))
		{
			upper_cnt++;
			continue;
		}

		if(ispunct(ch))
		{
			punct_cnt++;
			continue;
		}

		if(!isprint(ch))
		{
			cantprint_cnt++;
			continue;
		}
	}

	printf("These are count of different type:\n");
	printf("    cntrl count: %3d\n", cntrl_cnt);
	printf("    digit count: %3d\n", digit_cnt);
	printf("    lower count: %3d\n", lower_cnt);
	printf("    upper count: %3d\n", upper_cnt);
	printf("    punct count: %3d\n", punct_cnt);
	printf("cantprint count: %3d\n", cantprint_cnt);

	printf("\nBye!\n");
	
	return 0;
}