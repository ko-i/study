// 2020-12-16 created by Akson
// Code11.3 strdup.c 复制字符串

// 用动态分配内存只做一个字符串的一份拷贝。
// 注意：调用程序应该负责检查这块内存是否成功分配。这样做允许调用程序以任何它所希望的方式对错误做出反应。

#include <string.h>

char* strdup(const char* str)
{
	// 请求足够长度的内存，用于存储字符串和它的结尾NUL字节。
	char* new_string = (char*)malloc((strlen(str) + 1) * sizeof(char));

	// 如果我们得到内存，就复制字符串。
	if(new_string != NULL)
	{
		strcpy(new_string, str);
	}

	return new_string;
}