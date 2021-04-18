// 2020-11-12 created by Akson

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1

int main(int argc, char const *argv[])
{
	FILE *fps;
	FILE *fpt;

	char ch[SIZE];
	
	if(argc != 3)
	{
		fprintf(stderr, "Usage: %s [targetfile] [sourcefile]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		if((fps = fopen(argv[2], "rb")) == NULL)
		{
			fprintf(stderr, "Can't open file: %s\n", argv[2]);
			exit(EXIT_FAILURE);
		}
		if((fpt = fopen(argv[1], "wb")) == NULL)
		{
			fprintf(stderr, "Can't open file: %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}

	while(fread(ch, sizeof(char), SIZE, fps) != 0)
	{
		fwrite(ch, sizeof(char), SIZE, fpt);
	}

	fclose(fps);
	fclose(fpt);

	return 0;
}