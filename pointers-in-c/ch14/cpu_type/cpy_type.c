// 2020-12-19 created by Akson
// pe14.2 cpu_type.c

int cpu_type(void)
{
	int result = 0;
	int count = 0;
#ifdef VAX
	result = CPU_VAX;
	count++;
#endif
#ifdef M68000
	result = CPU_68000;
	count++;
#endif
#ifdef M68020
	result = CPU_68020;
	count++;
#endif
#ifdef I80386
	result = CPU_80386;
	count++;
#endif
#ifdef X6809
	result = CPU_6809;
	count++;
#endif
#ifdef X6502
	result = CPU_6502;
	count++;
#endif
#ifdef U3B2
	result = CPU_3B2;
	count++;
#endif

	if(count != 1)
	{
		return 0;
	}

	return result;
}