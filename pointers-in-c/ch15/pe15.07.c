// 2020-12-19 created by Akson
// pe15.7

#include <stdlib.h>
#include <stdio.h>

#define FILENAMELEN 100
#define LINESIZE 200

int main(int argc, char const *argv[])
{
	printf("Enter the family data file's name.\n");

	char filename[FILENAMELEN];
	printf("File name: ");
	scanf("%s", filename);

	FILE* fp;
	if((fp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Open %s failed.\n", filename);
		exit(EXIT_FAILURE);
	}

	char line[LINESIZE];

	int family_index = 0;
	while(fgets(line, LINESIZE, fp) != NULL)
	{
		family_index++;
		int family_people_count = 0;
		int family_age_sum = 0;
		int family_age[10];
		if((family_people_count = sscanf(line, "%d %d %d %d %d %d %d %d %d %d", &family_age[0], &family_age[1], &family_age[2], &family_age[3], &family_age[4], &family_age[5], &family_age[6], &family_age[7], &family_age[8], &family_age[9])) > 0)
		{
			for(int i = 0; i < family_people_count; i++)
			{
				family_age_sum += family_age[i];
			}
		}

		double family_average_age = (double)family_age_sum / family_people_count;

		printf("Family #%d's average age: %5.2lf.\n", family_index, family_average_age);
	}

	fclose(fp);
	printf("\nDone! Bye!\n");

	return 0;
}