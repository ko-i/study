// 2020-12-22 created by Akson
// pe16.8

#include <stdio.h>
#include <stdlib.h>

#define LINESIZE 512

int main(int argc, char const *argv[])
{
	char* filename = "age_data";
	FILE* fp = fopen(filename, "r");
	if(fp == NULL)
	{
		fprintf(stderr, "Open %s failed.\n", filename);

		exit(EXIT_FAILURE);
	}

	char line[LINESIZE];

	int family_count = 0;
	while(fgets(line, LINESIZE, fp) != NULL)
	{
		family_count++;
		double family_member_count = 0;
		double family_member_age_sum = 0;

		char* pl = line;
		long int this_age = 1;
		while(*pl != '\0' && this_age != 0)
		{
			this_age = strtol(pl, &pl, 10);

			family_member_age_sum += this_age;
			family_member_count++;
		}

		printf("Family #%2d's average age is: %.2lf\n", family_count ,family_member_age_sum / family_member_count);
	}

	fclose(fp);
	printf("Bye!\n");

	return 0;
}