// 2020-12-19 created by Akson
// pe14.1

void print_ledger_long(int n);
void print_ledger_detailed(int n);
void print_ledger_default(int n);

void print_ledger(int n);

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

void print_ledger(int n)
{
#if defined(A)
	print_ledger_long(n);
#elif defined(B)
	print_ledger_detailed(n);
#else
	print_ledger_default(n);
#endif
}