// 2020-11-14 created by Akson
// Code16.17 qsorter.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 40

struct names
{
	char fname[NUM];
	char lname[NUM];
};

void fillstruct(struct names ar [], int n);
void showstruct(const struct names ar[], int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
	struct names vals[NUM];
	fillstruct(vals, NUM);
	puts("Random list:");
	showstruct(vals, NUM);
	qsort(vals, NUM, sizeof(struct names), mycomp);
	puts("\nSorted list:");
	showstruct(vals, NUM);

	return 0;
}

void fillstruct(struct names ar [], int n)
{
	int count = 0;
	for(int index = 0; index < n; index++)
	{
		ar[index].fname[0] = '0' + (count % 10);
		count++;
		ar[index].lname[0] = '0' + (count % 10);
		ar[index].fname[1] = '\0';
		ar[index].lname[1] = '\0';
		count++;
	}
}

void showstruct(const struct names ar[], int n)
{
	int index;

	for(index = 0; index < n; index++)
	{
		printf("%s %s\n", ar[index].fname, ar[index].lname);
	}
}

int mycomp(const void * p1, const void * p2)
{
	const struct names * ps1 = (const struct names *) p1;
	const struct names * ps2 = (const struct names *) p2;

	int res;
	res = strcmp(ps1 -> fname, ps2 -> fname);
	if(res != 0)
	{
		return res;
	}
	else
	{
		return strcmp(ps1 -> lname, ps2 -> lname);
	}
}
