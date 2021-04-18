// 2020-12-16 created by Akson
// pe10.1

#include <stdio.h> 

typedef struct CallInfo
{
	int year;
	int month;
	int day;

	int area_code_caller;
	int exchange_code_caller;
	int stand_code_caller;

	int area_code_callee;
	int exchange_code_callee;
	int stand_code_callee;

	int area_code_pay;
	int exchange_code_pay;
	int stand_code_pay;
} CallInfo;