// 2020-12-19 created by Akson
// pe15.5

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
	if((fp2 = fopen(file2, "a")) == NULL)
	{
		fprintf(stderr, "Open %s Failed.\n", file2);
		exit(EXIT_FAILURE);
	}

	int sum = 0;
	int temp;

	char buffer[BUFFERSIZE];
	while(fgets(buffer, BUFFERSIZE, fp1) != NULL)
	{
		if(sscanf(buffer, "%d", &temp) == 1)
		{
			sum += temp;
		}
		fputs(buffer, fp2);
	}

	fprintf(fp2, "\n%d\n", sum);

	fclose(fp1);
	fclose(fp2);

	printf("\nBye!\n");

	return 0;
}