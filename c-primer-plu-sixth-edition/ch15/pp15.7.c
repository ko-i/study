// 2020-11-16 created by Akson

#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

#define IDMASK 0xFF
#define SIZEMASK 0x7F00
#define ALIGNMASK 0x18000
#define BOLDMASK 0x20000
#define ITALICMASK 0x40000
#define UNDERLINEMASK 0x80000

const char * aligns[3] = {"left", "center", "right"};

char getChoice(unsigned long font_props);
void showSettings(const unsigned long font_props);

unsigned long changeFontID(unsigned long font_props);
unsigned long changeFontSize(unsigned long font_props);			
unsigned long changeFontAlign(unsigned long font_props);
unsigned long toggleBold(unsigned long font_props);
unsigned long toggleItalic(unsigned long font_props);
unsigned long toggleUnderline(unsigned long font_props);
char * ultobs(unsigned long n, char *ps);

int main(void)
{
	char bin_str[8 * sizeof(unsigned long) + 1];
	unsigned long font_props = 0;

	int choice;
	while((choice = getChoice(font_props)) != 'q')
	{
		switch(choice)
		{
			case 'f': font_props = changeFontID(font_props); break;
			case 's': font_props = changeFontSize(font_props); break;
			case 'a': font_props = changeFontAlign(font_props); break;
			case 'b': font_props = toggleBold(font_props); break;
			case 'i': font_props = toggleItalic(font_props); break;
			case 'u': font_props = toggleUnderline(font_props); break;
		}
	}

	printf("bits are %s\n", ultobs(font_props, bin_str));

	return 0;
}

char getChoice(unsigned long font_props)
{
	showSettings(font_props);

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

void showSettings(unsigned long font_props)
{
	printf(" ID SIZE ALIGNMENT   B    I    U\n");
	printf("%3lu ", font_props & 255);
	printf("%4lu ", (font_props >> 8) & 127);
	printf("%7s ", aligns[(font_props >> 15) & 3]);
	printf("   %s ", ((font_props >> 17) & 1) ? "on" : "off");
	printf(" %s ", ((font_props >> 18) & 1) ? "on" : "off");
	printf(" %s", ((font_props >> 19) & 1) ? "on" : "off");
	printf("\n");
}

unsigned long changeFontID(unsigned long font_props)
{
	printf("Please enter a number(0 - 255): ");
	unsigned long num;
	scanf("%lu", &num);
	while(getchar() != '\n')
	{
		continue;
	}

	font_props &= (~IDMASK);
	font_props |= num;

	return font_props;
}

unsigned long changeFontSize(unsigned long font_props)
{
	printf("Please enter a number(0 - 127): ");
	unsigned long num;
	scanf("%lu", &num);
	while(getchar() != '\n')
	{
		continue;
	}

	font_props &= (~SIZEMASK);
	font_props |= (num << 8);

	return font_props;
}

unsigned long changeFontAlign(unsigned long font_props)
{
	printf("Select alignment:\n");
	printf("l) left   c) center   r) right\n");
	unsigned long ch;
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

	font_props &= ~(ALIGNMASK);

	switch(ch)
	{
		case 'l': font_props |= (0 << 15); break;
		case 'c': font_props |= (1 << 15); break;
		case 'r': font_props |= (2 << 15); break;
	}

	return font_props;
}

unsigned long toggleBold(unsigned long font_props)
{
	font_props ^= (1 << 17);

	return font_props; 
}

unsigned long toggleItalic(unsigned long font_props)
{
	font_props ^= (1 << 18);
	
	return font_props; 
}

unsigned long toggleUnderline(unsigned long font_props)
{
	font_props ^= (1 << 19);
	
	return font_props; 
}

char * ultobs(unsigned long n, char * ps)
{
	int i;
	const static int size = CHAR_BIT * sizeof(unsigned long);
	for(i = size - 1; i >= 0; i--, n >>= 1)
	{
		ps[i] = (01 & n) + '0';
	}

	ps[size] = '\0';

	return ps;
}