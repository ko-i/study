// 2020-11-12 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void)
{
	FILE *fp;
	char words[MAX];
	char line[MAX];
	int lines_cnt = 1;

	if((fp = fopen("wordy", "r+")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}

	while(fgets(line, MAX, fp) != NULL)
	{
		lines_cnt++;
	}

	puts("Enter words to add to the file; press the # key at the beginning of a line to terminate.");
	while((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
	{
		fprintf(fp, "%d. %s\n", lines_cnt, words);
		lines_cnt++;
	}

	puts("File contents:");
	rewind(fp);
	while(fscanf(fp, "%s", words) == 1)
	{
		puts(words);
	}

	puts("Done!");

	if(fclose(fp) != 0)
	{
		fprintf(stderr, "Error closing file\n");
	}

	return 0;
}