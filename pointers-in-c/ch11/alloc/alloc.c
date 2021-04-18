// 2020-12-16 created by Akson
// Code11.1b alloc.c 错误检查分配器：实现

// 实现一个不易发生错误的内存分配器

#include <stdlib.h>
#include <stdio.h>
#include "alloc.h"

#undef malloc

void* alloc(size_t size)
{
	void* new_mem;

	// 请求所需要的内存，并检查确实分配成功
	new_mem = malloc(size);
	if(new_mem == NULL)
	{
		printf("Out of memory!\n");
		exit(EXIT_FAILURE);
	}

	return new_mem;
}