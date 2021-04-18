// 2020-11-11 created by Akson

#include <stdio.h>
#include "pp12.3a.h"

int main(void)
{
	int mode;
	int last_mode = 0;

	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);

	while(mode >= 0)
	{
		if(mode > 1)
		{
			mode = last_mode;
			printf("Invalid mode specified. Mode %d(%s) used.\n", mode, mode ? "US" : "metric");;
		}
		last_mode = mode;
		get_info(mode);
		printf("Enter 0 for metric mode, 1 for US mode (-1 to quit): ");
		scanf("%d", &mode);
	}

	printf("Done.\n");

	return 0;
}