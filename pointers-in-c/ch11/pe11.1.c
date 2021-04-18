// 2020-12-16 created by Akson
// pe11.1

#include <stdlib.h>

#define my_calloc(num,type) (type*)mycalloc((num) * sizeof(type))

void* mycalloc(size_t size)
{
	char* new_mem = malloc(size);

	if(new_mem == NULL)
	{
		return NULL;
	}

	for(int i = 0; i < size; i++)
	{
		new_mem[i] = 0;
	}

	return (void*)new_mem;
}