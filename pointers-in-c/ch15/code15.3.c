// 2020-12-19 created by Akson
// Code15.3 copyline.c 从一个文件向另一个文件复制文本行

// 把标准输入读入的文本行逐行复制到标准输出

#include <stdio.h>

#define MAX_LINE_LENGTH 1024  // 我可以复制的最长行

void copylines(FILE* input, FILE* output)
{
	char buffer[MAX_LINE_LENGTH];

	while(fgets(buffer, MAX_LINE_LENGTH, input) != NULL)
	{
		fputs(buffer, output);
	}
}