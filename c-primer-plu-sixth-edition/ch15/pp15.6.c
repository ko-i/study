// 2020-11-16 created by Akson

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define LEFT 0
#define CENTER 1
#define RIGHT 2

struct font_props
{
	unsigned int id : 8;
	unsigned int size : 7;
	unsigned int align : 2;
	bool b : 1;
	bool i : 1;
	bool u : 1;
};

const char * aligns[3] = {"left", "center", "right"};

char getChoice(struct font_props * pf);
void showSettings(const struct font_props * pf);

void changeFontID(struct font_props * pf);
void changeFontSize(struct font_props * pf);			
void changeFontAlign(struct font_props * pf);
void toggleBold(struct font_props * pf);
void toggleItalic(struct font_props * pf);
void toggleUnderline(struct font_props * pf);

int main(void)
{
	struct font_props font = {127, 12, LEFT, false, false, false};

	int choice;
	while((choice = getChoice(&font)) != 'q')
	{
		switch(choice)
		{
			case 'f': changeFontID(&font); break;
			case 's': changeFontSize(&font); break;
			case 'a': changeFontAlign(&font); break;
			case 'b': toggleBold(&font); break;
			case 'i': toggleItalic(&font); break;
			case 'u': toggleUnderline(&font); break;
		}
	}

	printf("Bye.\n");

	return 0;
}

void showSettings(const struct font_props * pf)
{
	printf(" ID SIZE ALIGNMENT   B    I    U\n");
	printf("%3d ", pf -> id);
	printf("%4d ", pf -> size);
	printf("%7s ", aligns[pf -> align]);
	printf("   %s ", (pf -> b) ? "on" : "off");
	printf(" %s ", (pf -> i) ? "on" : "off");
	printf(" %s", (pf -> u) ? "on" : "off");
	printf("\n");
}

char getChoice(struct font_props * pf)
{
	showSettings(pf);

	printf("f) change font  s) change size    a) change alignment\n");
	printf("b) toggle bold  i) toggle italic  u) toggle underline\n");
	printf("q) quit\n");

	printf("Enter a choice: ");

	int ch;
	while((ch = getchar()) != EOF)
	{
		while(getchar() != '\n')
		{
			continue;
		}

		ch = tolower(ch);
		if(strchr("fsabiuq", ch) == NULL)
		{
			printf("Please enter f, s, a, b, i, u or q: ");
		}
		else
		{
			break;
		}
	}
	return ch;
}

void changeFontID(struct font_props * pf)
{
	printf("Please enter a number(0 - 255): ");
	int num;
	scanf("%d", &num);
	while(getchar() != '\n')
	{
		continue;
	}

	pf -> id = num;
}

void changeFontSize(struct font_props * pf)
{
	printf("Please enter a number(0 - 127): ");
	int num;
	scanf("%d", &num);
	while(getchar() != '\n')
	{
		continue;
	}

	pf -> size = num;
}

void changeFontAlign(struct font_props * pf)
{
	printf("Select alignment:\n");
	printf("l) left   c) center   r) right\n");
	int ch;
	while((ch = getchar()) != EOF)
	{
		while(getchar() != '\n')
		{
			continue;
		}

		ch = tolower(ch);
		if(strchr("lcr", ch) == NULL)
		{
			printf("Please enter l, c or r: ");
		}
		else
		{
			break;
		}
	}

	switch(ch)
	{
		case 'l': pf -> align = 0; break;
		case 'c': pf -> align = 1; break;
		case 'r': pf -> align = 2; break;
	}
}

void toggleBold(struct font_props * pf)
{
	pf -> b = !(pf -> b); 
}

void toggleItalic(struct font_props * pf)
{
	pf -> i = !(pf -> i); 
}

void toggleUnderline(struct font_props * pf)
{
	pf -> u = !(pf -> u); 
}
