// 2020-12-11 created by Akson
// Code8.1 strcpy.c 字符串复制

// 把第2个参数中的字符串复制到第1个参数指定的缓冲区

void strcpy(char* buffer, char const * string)
{
	// 重复复制字符串，直到遇见NUL字符
	while((*buffer++ = *string++) != '\0')
	{
		
	}
}