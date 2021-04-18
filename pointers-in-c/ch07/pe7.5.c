// 2020-12-11 created by Akson
// pe7.5

#include <stdio.h>

void my_printf(char* str, char* tar);
void print_integer(char* str);
void print_float(char* str);

int main(int argc, char const *argv[])
{
	// some test
	
	return 0;
}

void my_printf(char* str, char* tar)
{
	char* ps = str;
	while(*ps != '\0')
	{
		if(*ps == '\\')
		{
			ps++;
			putchar(*ps);
			continue;
		}

		if(*ps == '%')
		{
			ps++;

			if(*ps == '\0')
			{
				putchar('%');
				break;
			}

			if(*ps == 'd')
			{
				print_integer(tar);
				ps++;
				continue;
			}

			if(*ps == 'f')
			{
				print_float(tar);
				ps++;
				continue;
			}

			if(*ps == 's')
			{
				char* pt = tar;
				while(*pt != '\0')
				{
					putchar(*pt);
					pt++;
				}
				ps++;
				continue;
			}

			if(*ps == 'c')
			{
				putchar(*tar);
				ps++;
				continue;
			}

			putchar('%');
		}

		putchar(*ps);
		ps++;
	}
}

void print_integer(char* str)
{

}

void print_float(char* str)
{

}
