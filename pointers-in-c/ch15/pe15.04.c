// 2020-12-19 created by Akson
// pe15.4

#include <stdlib.h>
#include <stdio.h>

#define NAMELEN 100
#define BUFFERSIZE 100

int main(int argc, char const *argv[])
{
	printf("Enter two file name: \"file1 file2\"\n");
	printf("I will copy file1 to file2\n");

	printf("First file: ");
	char file1[NAMELEN];
	scanf("%s", file1);

	printf("Second file: ");
	char file2[NAMELEN];
	scanf("%s", file2);

	FILE* fp1;
	if((fp1 = fopen(file1, "r")) == NULL)
	{
		fprintf(stderr, "Open %s Failed.\n", file1);
		exit(EXIT_FAILURE);
	}

	FILE* fp2;
	if((fp2 = fopen(file2, "w")) == NULL)
	{
		fprintf(stderr, "Open %s Failed.\n", file2);
		exit(EXIT_FAILURE);
	}

	char buffer[BUFFERSIZE];
	while(fgets(buffer, BUFFERSIZE, fp1) != NULL)
	{
		fputs(buffer, fp2);
	}

	fclose(fp1);
	fclose(fp2);

	printf("\nBye!\n");

	return 0;
}