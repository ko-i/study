// 2020-11-11 created by Akson

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *fp;
	double sum = 0;
	int count = 0;
	double temp;

	if(argc == 1)
	{
		fp = stdin;
	}
	else if(argc == 2)
	{
		if((fp = fopen(argv[1], "r")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	while(fscanf(fp, "%lf", &temp) == 1)
	{
		sum += temp;
		count++;
	}

	if(count > 0)
	{
		printf("Average: %lf\n", sum / count);
	}

	return 0;
}