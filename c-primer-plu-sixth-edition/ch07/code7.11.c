// 2020-11-07 created by Akson
// Code7.11 animals.c

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;

	printf("Give me a letter of the alphabet, and I will give an animal name gefinning with the letter.\n");
	printf("Please type in a letter; type # to end my act.\n");
	while((ch = getchar()) != '#')
	{
		if('\n' == ch)
		{
			continue;
		}
		if(islower(ch))
		{
			switch(ch)
			{
				case 'a':
					printf("argali, a wild sheep of Asia\n");
					break;
				case 'b':
					printf("babirusa, a wild pig of Malay\n");
					break;
				case 'c':
					printf("coati, recoonlike mammal\n");
					break;
				case 'd':
					printf("desman, aquatic, molelike critter\n");
					break;
				case 'e':
					printf("echidna, the spiny anteater\n");
					break;
				case 'f':
					printf("fisher, brownish marten\n");
					break;
				default:
					printf("That is a stumper!\n");
			}
		}
		else
		{
			printf("I recongnize only lowercase letters.\n");
		}

		while(getchar() != '\n')
		{
			continue;
		}
		printf("Please type another letter or a #.\n");
	}

	printf("Bye!\n");

	return 0;
}