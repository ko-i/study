// 2020-11-13 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char *s_gets(char * st, int n);

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	int isdeleted;
};

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int book_count = 0;
	int index, filecount;
	FILE * pbooks;
	int size = sizeof(struct book);

	if((pbooks = fopen("book.dat", "r+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}

	rewind(pbooks);

	while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if(count == 0)
		{
			puts("Current contents of book.dat:");
		}

		if(library[count].isdeleted == 0)
		{
			printf("%d: %s by %s $%.2f\n", count, library[count].title, library[count].author, library[count].value);
			book_count++;
		}
		count++;
	}

	filecount = count;
	if(book_count == MAXBKS)
	{
		fputs("The book.dat file is full.", stderr);
	}

	if(book_count > 0)
	{
		int the_number_to_delete;
		printf("Would you want to delete some book?\n");
		printf("Enter the number and [Enter] to delete.\n");
		printf("Only enter to quit.\n");
		while(scanf("%d", &the_number_to_delete) == 1 && the_number_to_delete >= 0)
		{
			while(getchar() != '\n')
			{
				continue;
			}
		
			library[the_number_to_delete].isdeleted = 1;
			book_count--;

			printf("Delete %s success. This is the book list now.\n", library[the_number_to_delete].title);
			for(int i = 0; i < count; i++)
			{
				if(library[i].isdeleted == 0)
				{
					printf("%d: %s by %s $%.2f\n", i, library[i].title, library[i].author, library[i].value);
				}
			}

			printf("Enter the number and [Enter] to delete.\n");
			printf("Only enter to quit.\n");
		}
	}

	while(getchar() != '\n')
	{
		continue;
	}
	
	puts("Please add new book titles.");
	puts("Press [Enter] at the start of a line to stop.");
	char temp_title[MAXTITL];
	char temp_author[MAXAUTL];
	float temp_value;
	while(book_count < MAXBKS && s_gets(temp_title, MAXTITL) != NULL && temp_title[0] != '\0')
	{
		puts("Now enter the author.");
		s_gets(temp_author, MAXAUTL);
		puts("Now enter the value.");
		scanf("%f", &temp_value);

		int can_put_index = 0;
		while(library[can_put_index].isdeleted != 1 && can_put_index < count)
		{
			can_put_index++;
		}
		strcpy(library[can_put_index].title ,temp_title);
		strcpy(library[can_put_index].author, temp_author);
		library[can_put_index].value = temp_value;
		library[can_put_index].isdeleted = 0;
		book_count++;
		count++;
		while(getchar() != '\n')
		{
			continue;
		}

		if(count < MAXBKS)
		{
			puts("Enter the next title.");
		}
	}

	if(count > 0)
	{
		puts("Here is the list of your books:");
		for(index = 0; index < count; index++)
		{
			if(library[index].isdeleted == 0)
			{
				printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
			}	
		}

		fwrite(&library[0], size, count, pbooks);
	}
	else
	{
		puts("No books? Too bad.\n");
	}

	puts("Bye.\n");
	fclose(pbooks);

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