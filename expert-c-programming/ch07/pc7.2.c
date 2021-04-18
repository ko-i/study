// 2020-12-27 created by Akson
// 体验一下cache

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#define DUMBCOPY for(i = 0; i < 65536; i++) destination[i] = source[i]
#define SMARTCOPY memcpy(destination, source, 65536)

int main(int argc, char const *argv[])
{
	char source[65536], destination[65536];
	int i, j;

	clock_t start, end;
	start = clock();
	for(j = 0; j < 100; j++)
		DUMBCOPY;

	end = clock();

	printf("%.6lf seconds user time.\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}