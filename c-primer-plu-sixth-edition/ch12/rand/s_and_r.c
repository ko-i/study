// 2020-11-11 created by Akson
// Code12.9 s_and_r.c

static unsigned long int next = 1;

int rand1(void)
{
	next = next * 1103515245 + 12345;

	return (unsigned int)(next / 65535) % 32768;
}

void srand1(unsigned int seed)
{
	next = seed;
}