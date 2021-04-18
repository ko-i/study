// 2020-12-14 created by Akson
// Code9.3 token.c 提取标记

// 从一个字符数组中提取空白字符分割的标记并把他们打印出来（每行一个）

#include <stdio.h>
#include <string.h>

void print_tokens(char* line)
{
	static char whitespace[] = " \t\f\r\v\n";
	char* token;

	for(token = strtok(line, whitespace); token != NULL; token = strtok(NULL, whitespace))
	{
		printf("Next token is %s\n", token);
	}
}