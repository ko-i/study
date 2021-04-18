// 2020-12-22 created by Akson
// pe16.10

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(void* array, size_t n_elements, size_t el_size, int (*compare)(void const *, void const *));
int compare(void const *, void const *);

int main(int argc, char const *argv[])
{
	// some test

	return 0;
}

void insertion_sort(void* array, size_t n_elements, size_t el_size, int (*compare)(void const *, void const *))
{
	for(int i = 0; i < n_elements - 1; i++)
	{
		for(int j = i + 1; j < n_elements; j++)
		{
			if(compare(array[i * el_size], array[j * el_size]) == 1)
			{
				void* temp = (void*)malloc(1);
				for(int k = 0; k < el_size; k++)
				{
					temp = array[i + k];
					array[i + k] = array[j + k];
					array[j + k] = temp;
				}
			}
		}
	}
}