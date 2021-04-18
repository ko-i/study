// 2020-12-19 created by Akson
// Code15.5 scanf2.c 使用sscanf处理可变格式的输入

// 使用sscanf处理可变格式的输入

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_A 1
#define DEFAULT_B 1

void function(char* buffer)
{
	int a, b, c;

	// 看看3个值是否都已给出。
	if(sscanf(buffer, "%d %d %d", &a, &b, &c) != 3)
	{
		// 否，对a使用缺省值，看看其他两个值是否都已给出。
		a = DEFAULT_A;

		if(sscanf(buffer, "%d %d", &b, &c) != 2)
		{
			// 也为b使用缺省值，寻找剩余的值
			b = DEFAULT_B;

			if(sscanf(buffer, "%d", &c) != 1)
			{
				fprintf(stderr, "Bad input: %s\n", buffer);
				exit(EXIT_FAILURE);
			}
		}
	}

	// 处理a, b, c
}

