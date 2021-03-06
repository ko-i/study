// 2020-12-14 created by Akson
// Code9.2 mstrrstr.c 查找子串最右一次出现的位置

// 在字符串s1中查找字符串s2最右出现的位置，并返回一个指向该位置的指针。

#include <string.h>

char* my_strrstr(char const * s1, char const * s2)
{
	register char* last;
	register char* current;

	// 把指针初始化为我们已经找到的前一次匹配的位置
	last = NULL;

	// 只在第2个字符串不为空时才进行查找，如果S2为空，返回NULL
	if(*s2 != '\0')
	{
		// 查找s2在s1中第一次出现的位置。
		current = strstr(s1, s2);

		// 我们每次找到字符串时，让指针指向它的起始位置，然后查找该字符串下一个匹配的位置。
		while(current != NULL)
		{
			last = current;
			current = strstr(last + 1, s2);
		}
	}

	return last;
}