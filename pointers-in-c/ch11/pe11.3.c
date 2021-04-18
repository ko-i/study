// 2020-12-16 created by Akson
// pe11.3

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("Enter a sentence and I will store it.\n");
	printf("Sentence enter(EOF to quit): ");

	int char_count = 0;
	char* str = (char*)malloc(sizeof(char));
	*str = '\0';

	int ch;
	while((ch = getchar()) != EOF)
	{
		str[char_count] = ch;
		char_count++;
		str = (char*)realloc(str, char_count * sizeof(char));
		str[char_count] = '\0';
	}

	printf("This is the sentence i got:\n");
	puts(str);

	puts("Bye!");

	return 0;
}