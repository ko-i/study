// 2020-11-11 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 30

int main(void)
{
	int word_num = 0;
	char temp[LIMIT];

	printf("How many words do you wish to enter? ");
	scanf("%d", &word_num);
	char ** words = (char**)malloc(word_num * sizeof(char *));

	printf("Enter %d words now.\n", word_num);
	for(int i = 0; i < word_num; i++)
	{
		scanf("%s", temp);
		int word_len = strlen(temp);
		char * word = (char *)malloc((word_len + 1) * sizeof(char));
		for(int j = 0; j < word_len + 1; j++)
		{
			word[j] = temp[j];
		}

		words[i] = word;
	}

	for(int i = 0; i < word_num; i++)
	{
		printf("%s\n", words[i]);
	}

	for(int i = 0; i < word_num; i++)
	{
		free(words[i]);
	}

	free(words)；

	return 0;
}