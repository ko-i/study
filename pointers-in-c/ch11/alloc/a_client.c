// 2020-12-16 created by Akson
// Code11.1c a_client.c 使用错误检查分配器

// 使用不易发生错误的内存分配器

#include "alloc.h"

void function()
{
	int* new_memory;

	// 获得一串整形数的空间
	new_memory = MALLOC(25, int);
}