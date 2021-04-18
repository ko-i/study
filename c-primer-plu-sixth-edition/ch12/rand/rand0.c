// 2020-11-11 created by Akson
// Code12.7 rand0.c

static unsigned long int next = 1;

unsigned int rand0(void)
{
	next = next * 1103515245 + 12345;

	return (unsigned int)(next / 65535) % 32768; 
}