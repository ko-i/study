// 2020-11-12 created by Akson

#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

int main(void)
{
	char filename[SIZE];
	FILE *fp;
	long int posi;
	char str[SIZE];


	printf("Please enter a filename: ");
	scanf("%s", filename);

	if((fp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Can't open the file: %s\n", filename);
		exit(EXIT_FAILURE);
	}

	printf("Please enter a number i and I will print the words between position i to the next \\n.\n");
	printf("Number i(< 0 or other to quit): ");
	while(scanf("%ld", &posi) == 1 && posi > 0)
	{
		fseek(fp, posi, SEEK_SET);
		if(fgets(str, SIZE,fp) != NULL)
		{
			printf("%s\n", str);
		}

		printf("Enter number i(< 0 or other to quit): ");
	}

	printf("Done!\n");

	return 0;
}