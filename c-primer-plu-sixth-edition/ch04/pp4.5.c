// 2020-11-05 created by Akson

#include <stdio.h>

int main(void)
{
	float mbs;
	float file_size;
	printf("Please input Mbs and file size in MB:");
	scanf("%f %f", &mbs, &file_size);

	printf("At %.2f megabits per second, a file of %.2f megabytes downloads in %.2f seconds\n", mbs, file_size, file_size * 8.0 / mbs);

	return 0;
}