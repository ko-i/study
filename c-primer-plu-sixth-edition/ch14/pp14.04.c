// 2020-11-13 created by Akson

#include <stdio.h>
#include <string.h>

#define LEN 30

struct Name
{
	char fname[LEN];
	char mname[LEN];
	char lname[LEN];
};

struct SocialProtact
{
	int id;
	struct Name name;
};

int main(void)
{
	struct SocialProtact sp[5] = 
	{
		{302039823, {"Dribble", "M", "Flossie"}},
		{302039824, {"Benwei", "NB", "Lu"}},
		{302039825, {"Xiaochuan", "", "Sun"}},
		{302039826, {"Wangkson", "", "Li"}},
		{302039827, {"Meowkson", "", "Li"}}
	};

	struct SocialProtact * Psp;
	Psp = sp;

	for(int i = 0; i < 5; i++)
	{
		printf("%s, %s ", Psp -> name.fname, Psp -> name.lname);
		if(strlen(Psp -> name.mname) != 0)
		{
			printf("%c. ", Psp -> name.mname[0]);
		}
		printf("--- %d\n", Psp -> id);
		Psp++;
	}

	for(int i = 0; i < 5; i++)
	{
		printf("%s, %s ", sp[i].name.fname, sp[i].name.lname);
		if(strlen(sp[i].name.mname) != 0)
		{
			printf("%c. ", sp[i].name.mname[0]);
		}
		printf("--- %d\n", sp[i].id);
	}

	return 0;
}