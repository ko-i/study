// 2020-11-10 created by Akson

#include <stdio.h>
#include <string.h>

#define SIZE 81
#define LIM 10

char * s_gets(char * st, int n);
void stsrt(char * strings [], int num);
void stlensrt(char * strings [], int num);
void stfwnsrt(char * strings [], int num);
int first_word_number(char * str);

int main(void)
{
	char input[LIM][SIZE];
	char *ptstr[LIM];
	int ct = 0;

	printf("Input up to %d lines, and I will do something on them.\n", LIM);
	printf("To stop, press the Enter key at a line's start.\n");
	while(ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct];
		ct++;
	}

	puts("\nHere's the strings i got:\n");
	for(int i = 0; i < ct; i++)
	{
		puts(input[i]);
	}

	printf("What would you want to do to this strings?\n");
	printf("a) print              b) print in ASC sort\n");
	printf("c) print in first words letter number order\n");
	printf("d) print in lenth order\n");
	printf("other) quit\n");

	int choice;
	while((choice = getchar()) && choice >= 'a' && choice <= 'd')
	{
		if(choice == 'a')
		{
			for(int i = 0; i < ct; i++)
			{
				puts(input[i]);
			}
		}
		else if(choice == 'b')
		{
			stsrt(ptstr, ct);
			puts("\nHere's the sorted list:\n");
			for(int i = 0; i < ct; i++)
			{
				puts(ptstr[i]);
			}

		}
		else if(choice == 'c')
		{
			stlensrt(ptstr, ct);
			puts("\nHere's the sorted list:\n");
			for(int i = 0; i < ct; i++)
			{
				puts(ptstr[i]);
			}
		}
		else
		{
			stfwnsrt(ptstr, ct);
			puts("\nHere's the sorted list:\n");
			for(int i = 0; i < ct; i++)
			{
				puts(ptstr[i]);
			}
		}

		while(getchar() != '\n')
		{
			continue;
		}
		printf("\n\n\nAny else?(a, b, c, d)(other to quit): ");
	}

	puts("Done!");

	return 0;
}

void stsrt(char * strings [], int num)
{
	char *temp;
	int top, seek;

	for(top = 0; top < num -1; top++)
	{
		for(seek = top + 1; seek < num; seek++)
		{
			if(strcmp(strings[top], strings[seek]) > 0)
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
		}
	}
}

void stlensrt(char * strings [], int num)
{
	char *temp;
	int top, seek;

	for(top = 0; top < num -1; top++)
	{
		for(seek = top + 1; seek < num; seek++)
		{
			if(strlen(strings[top]) > strlen(strings[seek]))
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
		}
	}
}

void stfwnsrt(char * strings [], int num)
{
	char *temp;
	int top, seek;

	for(top = 0; top < num -1; top++)
	{
		for(seek = top + 1; seek < num; seek++)
		{
			if(first_word_number(strings[top]) > first_word_number(strings[seek]))
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
		}
	}
}

int first_word_number(char * str)
{
	int count = 0;
	char * pts = str;
	while(*pts != '\0')
	{
		count++;
		pts++;
	}

	return count;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
		{
			i++;
		}

		if(st[i] == '\n')
		{
			st[i] = '\0';
		}
		else
		{
			while(getchar() != '\n')
			{
				continue;
			}
		}
	}

	return ret_val;
}