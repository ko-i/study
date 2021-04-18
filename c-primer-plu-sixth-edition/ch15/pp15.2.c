// 2020-11-14 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * my_not(const char * str, int len);
char * my_and(const char * str1, const char * str2, int len);
char * my_or(const char * str1, const char * str2, int len);
char * my_xor(const char * str1, const char * str2, int len);

int main(int argc, char const *argv[])
{
	if(argc != 3)
	{
		fprintf(stderr, "Usage: %s binarynumber1 binarynumber2\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int str_len = strlen(argv[1]);
	if(str_len != strlen(argv[2]))
	{
		fprintf(stderr, "Number1's length should equal to number2's\n");
		exit(EXIT_FAILURE);
	}

	char * not_num1 = my_not(argv[1], str_len);
	char * not_num2 = my_not(argv[2], str_len);
	printf("~%s is %s.\n", argv[1], not_num1);
	printf("~%s is %s.\n", argv[2], not_num2);

	char * num1_and_num2 = my_and(argv[1], argv[2], str_len);
	char * num1_or_num2 = my_or(argv[1], argv[2], str_len);
	char * num1_xor_num2 = my_xor(argv[1], argv[2], str_len);
	printf("%s & %s is %s\n", argv[1], argv[2], num1_and_num2);
	printf("%s | %s is %s\n", argv[1], argv[2], num1_or_num2);
	printf("%s ^ %s is %s\n", argv[1], argv[2], num1_xor_num2);

	free(not_num1);
	free(not_num2);
	free(num1_and_num2);
	free(num1_or_num2);
	free(num1_xor_num2);

	return 0;
}

char * my_not(const char * str, int len)
{
	char * result = (char *)malloc((len + 1) * sizeof(char));

	for(int i = 0; i < len; i++)
	{
		result[i] = str[i] == '0' ? '1' : '0';
	}

	result[len] = '\0';

	return result;
}

char * my_and(const char * str1, const char * str2, int len)
{
	char * result = (char *)malloc((len + 1) * sizeof(char));

	for(int i = 0; i < len; i++)
	{
		if(str1[i] == '0' || str2[i] == '0')
		{
			result[i] = '0';
		}
		else
		{
			result[i] = '1';
		}
	}

	result[len] = '\0';

	return result;
}

char * my_or(const char * str1, const char * str2, int len)
{
	char * result = (char *)malloc((len + 1) * sizeof(char));

	for(int i = 0; i < len; i++)
	{
		if(str1[i] == '1' || str2[i] == '1')
		{
			result[i] = '1';
		}
		else
		{
			result[i] = '0';
		}
	}

	result[len] = '\0';

	return result;
}

char * my_xor(const char * str1, const char * str2, int len)
{
	char * result = (char *)malloc((len + 1) * sizeof(char));

	for(int i = 0; i < len; i++)
	{
		if(str1[i] == str2[i])
		{
			result[i] = '0';
		}
		else
		{
			result[i] = '1';
		}
	}

	result[len] = '\0';

	return result;
}
