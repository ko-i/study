// 2020-11-14 created by Akson
// Code16.6 names_st.h

#include <string.h>

#define SLEN 32

struct names_st
{
	char first[SLEN];
	char last[SLEN];
};

typedef struct names_st names;

void get_names(names *);
void show_names(const names *);
char * s_gets(char * st, int n);