// 2020-12-18 created by Akson
// pe13.1

#include <stdio.h>
#include <ctype.h>
#include <stdio.h>

int is_not_printable(int ch)
{
	return !isprint(ch);
}

int (*test_func[])(int) = 
{
	iscntrl,
	isspace,
	isdigit,
	islower,
	isupper,
	ispunct,
	is_not_printable
};

#define N_CATE (sizeof(test_func) / sizeof(test_func[0]))

int main(int argc, char const *argv[])
{
	int count = 0;
	int item_count[N_CATE] = {0};
	char* item_name[] = 
	{
		"Cntrl", "Space", "Digit", "Lower", "Upper", "Punct", "Unprintable"
	};

	printf("Enter a sentence and I will count every number of them.\n");
	printf("Sentence enter(EOF to quit): ");
	int ch;
	while((ch = getchar()) != EOF)
	{
		count++;
		for(int i = 0; i < N_CATE; i++)
		{
			if(test_func[i](ch))
			{
				item_count[i]++;
			}
		}
	}

	printf("There is the numbers i got:\n");
	for(int i = 0; i < N_CATE; i++)
	{
		printf("%s count: %d\n", item_name[i], item_count[i]);
	}

	printf("Whole: %d\n", count);
	printf("\nBye!\n");

	return 0;
}