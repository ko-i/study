// 2020-11-08 created by Akson

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	int upper = 0;
	int lower = 0;

	// printf("Please enter a sentence and I will count the upper and lower alpha in it!(EOF for end)\n");
	while((ch = getchar()) != EOF)
	{
		if(isupper(ch))
		{
			upper++;
			continue;
		}

		if(islower(ch))
		{
			lower++;
			continue;
		}
	}

	printf("Upper count: %d\n", upper);
	printf("Lower count: %d\n", lower);

	return 0;

}