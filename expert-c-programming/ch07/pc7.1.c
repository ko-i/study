// 2020-12-27 created by Akson
// pc7.1

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int MB = 0;
	while(malloc(1 << 20)) ++MB;

	printf("Allocated %d MB total\n", MB);

	return 0;
}