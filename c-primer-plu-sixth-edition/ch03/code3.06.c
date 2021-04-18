// 2020-11-05 created by Akson
// Code3.6

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int32_t me32;

	me32 = 45933945;

	printf("First, assume int32_t is int: ");
	printf("me32 = %d\n", me32);
	printf("Next, let's not make ant assumptions.\n");
	printf("Instead, use a \"macro\" from inttypes.h: ");
	printf("me32 = %" PRId32 "\n", me32);

	return 0;
}