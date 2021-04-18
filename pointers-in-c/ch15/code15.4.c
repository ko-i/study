// 2020-12-19 created by Akson
// Code15.4 scanf1.c 用sscanf处理行定向的输入

// 用sscanf处理行定向的输入

#include <stdio.h>

#define BUFFER_SIZE 100 // 我们将要处理的最长行

void function(FILE* input)
{
	int a, b, c, d, e;
	char buffer[BUFFER_SIZE];

	while(fgets(buffer, BUFFER_SIZE, input) != NULL)
	{
		if(sscanf(buffer, "%d %d %d %d %d", &a, &b, &c, &d, &e) != 4)
		{
			fprintf(stderr, "Bed input skiped: %s\n", buffer);
			continue;
		}

		// 处理这组输入
	}
}