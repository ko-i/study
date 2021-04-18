// 2020-12-18 created by Akson
// pe13.4

#include <stdio.h>

typedef int ElemType;

int compare_elem(void* elem1, void* elem2)
{
	if(*(ElemType*)elem1 > *(ElemType*)elem2)
	{
		return 1;
	}

	if(*(ElemType*)elem1 == *(ElemType*)elem2)
	{
		return 0;
	}

	if(*(ElemType*)elem1 < *(ElemType*)elem2)
	{
		return -1;
	}

}

int sort(ElemType* list, int len, int (*compare)(void*, void*))
{
	for(int i = 0; i < len - 1; i++)
	{
		for(int j = i + 1; j < len; j++)
		{
			if(compare(&list[i], &list[j]) > 0)
			{
				ElemType temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}