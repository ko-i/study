// 2020-12-19 created by Akson
// Code15.2 char_int.c 把字符转换为整数

// 把一串从标准输入读取的数字转换为整数

#include <stdio.h>
#include <ctype.h>

int read_int()
{
	int value = 0;
	int ch;

	// 转换从标准输入读入的数字，当我们得到一个非数字字符时就停止。
	while((ch = getchar()) != EOF && isdigit(ch))
	{
		value *= 10;
		value += (ch - '0');
	}

	// 把非数字退回到流中，这样他就不会丢失
	ungetc(ch, stdin);

	return value;
}