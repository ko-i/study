// 2020-12-14 created by Akson
// pe8.7

#include <stdio.h>
#include <stdarg.h>

int array_offset(int arrayinfo[], ...);

int main(int argc, char const *argv[])
{
	int nums[7] = {3, 4, 6, 1, 5, -3, 3};
	printf("%d\n", array_offset(nums, 4, 1, 3));

	return 0;
}

int array_offset(int arrayinfo[], ...)
{
	va_list var_arg;
	int* pa = arrayinfo;
	int dimension = *pa;

	
	va_start(var_arg, dimension);

	pa++;

	int low;
	int high;

	// 一维
	int s = va_arg(var_arg, int);
	int offset = s - *pa;
	pa++;

	for(int i = 2; i <= dimension; i++)
	{
		pa++;
		low = *pa;
		pa++;
		high = *pa;
		s = va_arg(var_arg, int);

		if(s < low && s > high)
		{
			va_end(var_arg);
			return -1;
		}

		offset += offset * (high - low + 1) + s - low;
	}

	va_end(var_arg);
	return offset;
}
