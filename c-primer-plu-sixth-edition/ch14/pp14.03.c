// 2020-11-13 created by Akson

#include <stdio.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

char * s_gets(char * st, int n);
void name_order_print(struct book * library, int n);
void price_order_print(struct book * library, int n);

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;

	printf("Please enter the book title(only [enter] to quit): ");
	while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		printf("Now enter the author: ");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value: ");
		scanf("%f", &library[count].value);

		count++;

		while(getchar() != '\n')
		{
			continue;
		}

		if(count < MAXBKS)
		{
			printf("Enter the next book title(only [enter] to quit): ");
		}
	}

	if(count > 0)
	{
		printf("Here is the list of your books:\n");
		for(index = 0; index < count; index++)
		{
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		}

		printf("Here is the list of your books in book name order:\n");
		name_order_print(library, count);

		printf("Here is the list of your books in book value order:\n");
		price_order_print(library, count);
	}
	else
	{
		printf("No books? Too bad.\n");
	}

	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n');
		if(find)
		{
			*find = '\0';
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

void name_order_print(struct book * library, int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(strcmp(library[i].title, library[j].title) > 0)
			{
				struct book temp;
				temp = library[i];
				library[i] = library[j];
				library[j] = temp;
			}
		}
	}

	for(int index = 0; index < n; index++)
	{
		printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
	}
}

void price_order_print(struct book * library, int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(library[i].value > library[j].value)
			{
				struct book temp;
				temp = library[i];
				library[i] = library[j];
				library[j] = temp;
			}
		}
	}

	for(int index = 0; index < n; index++)
	{
		printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
	}
}