// 2020-11-10 created by Akson
// Code11.24 starsrch.c

#include <stdio.h>
#include <string.h>

#define LISTSIZE 6

int main(void)
{
	const char * list[LISTSIZE] = 
	{
		"astronomy",
		"astounding",
		"astrophysics",
		"ostracize",
		"asterism",
		"astrophobia"
	};

	int count = 0;
	int i;

	for(i = 0; i < LISTSIZE; i++)
	{
		if(strncmp(list[i], "astro", 5) == 0)
		{
			printf("Found: %s\n", list[i]);
			count++;
		}
	}

	printf("The list contained %d words beginning with astro.\n", count);

	return 0;
}