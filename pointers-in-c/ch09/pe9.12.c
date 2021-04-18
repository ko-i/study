// 2020-12-15 created by Akson
// pe9.12 pe9.13 pe9.14

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEY_LEN 26
#define STR_LEN 100

int prepare_key(char * key);
void encrypt(char * data, char const * key);
void decrypt(char * data, char const * key);
// 好用的获取一行内容的方法
char * s_gets(char * st, int n);

int main(int argc, char const *argv[])
{
	printf("Welcome carp's endecrypt program!\n");

	char key[KEY_LEN + 1];
	printf("Enter your key for encrypt and decrypt\n");
	printf("Key enter(nothing to quit): ");
	while(s_gets(key, KEY_LEN) != NULL && key[0] != '\0')
	{
		if(prepare_key(key) == 0)
		{
			printf("Invalid key, please only enter alpha different and the lenth not lenger than 26.\n");
			printf("Key enter(nothing to quit): ");
			continue;
		}

		printf("Key create success!\n");
		printf("\nYou key: %s\n", key);

		char str_to_encrypt[STR_LEN];
		printf("\nNow enter the string you want to encrypt.\n");
		printf("String enter(nothing to skip): ");
		if(s_gets(str_to_encrypt, STR_LEN) != NULL && str_to_encrypt[0] != '\0')
		{
			printf("\nEncrypt Success!\n");
			printf("Source string: %s\n", str_to_encrypt);
			encrypt(str_to_encrypt, key);
			printf("Encrypt string: %s\n\n", str_to_encrypt);
		}

		char str_to_decrypt[STR_LEN];
		printf("Now enter the string you want to decrypt.\n");
		printf("String enter(nothing to skip): ");
		if(s_gets(str_to_decrypt, STR_LEN) != NULL && str_to_decrypt[0] != '\0')
		{
			printf("\nDecrypt Success!\n");
			printf("Encrypt string: %s\n", str_to_decrypt);
			decrypt(str_to_decrypt, key);
			printf("Decrypt string: %s\n\n", str_to_decrypt);
		}

		printf("Next key enter(nothing to quit): ");
	}

	printf("Bye!\n");

	return 0;
}

int prepare_key(char * key)
{
	// validation
	if(strlen(key) == 0)
	{
		return 0;
	}

	// validation and to upper
	char * pkey = key;
	while(*pkey != '\0')
	{
		if(!isalpha(*pkey))
		{
			return 0;
		}

		*pkey = toupper(*pkey);

		pkey++;
	}

	// detect and delete surplus
	pkey = key;
	while(*pkey != '\0')
	{
		char * temp = pkey + 1;
		while(*temp != '\0')
		{
			if(*temp == *pkey)
			{
				*temp = '0';
			}

			temp++;
		}

		pkey++;
		while(*pkey == '0' && *pkey != '\0')
		{
			pkey++;
		}
	}

	int surplus_count = 0;
	pkey = key;
	while(*pkey != '\0')
	{
		if(*pkey == '0')
		{
			surplus_count++;
			pkey++;
			continue;
		}

		*(pkey - surplus_count) = *pkey;
		pkey++;
	}

	*(pkey - surplus_count) = '\0';
	pkey = pkey - surplus_count;

	int key_len = strlen(key);
	int alpha_index = 0;
	for(int i = key_len; i < KEY_LEN; i++)
	{
		while(strchr(key, 'A' + alpha_index) != NULL)
		{
			alpha_index++;
		}

		*pkey = 'A' + alpha_index;
		*(pkey + 1) = '\0';
		pkey++;
	}

	*pkey = '\0';

	return 1;
}

void encrypt(char * data, char const * key)
{
	char * pdata = data;
	while(*pdata != '\0')
	{
		if(isalpha(*pdata))
		{
			if(islower(*pdata))
			{
				*pdata = toupper(*pdata);
				*pdata = key[*pdata - 'A'];
				*pdata = tolower(*pdata);
			}
			else
			{
				*pdata = key[*pdata - 'A'];
			}
		}
	
		pdata++;
	}
}

void decrypt(char * data, char const * key)
{
	char * pdata = data;

	while(*pdata != '\0')
	{
		if(isalpha(*pdata))
		{
			int index = 0;
			char const * pkey = key;
			int lower_flag = 0;
			if(islower(*pdata))
			{
				*pdata = toupper(*pdata);
				lower_flag = 1;
			}

			while(*pdata != *pkey && *pkey != '\0')
			{
				index++;
				pkey++;
			}

			*pdata = 'A' + index;
			if(lower_flag == 1)
			{
				*pdata = tolower(*pdata);
			}
		}
		
		pdata++;
	}
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

