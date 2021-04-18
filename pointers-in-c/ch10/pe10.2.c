// 2020-12-16 created by Akson
// pe10.2

#include <stdio.h> 

#define NAME_LEN 20
#define ADDR_LEN 40
#define MODEL_LEN 20

typedef struct CashInfo
{
	float suggest_price;
	float actual_price;
	float sale_tax;
	float licensing_fee;
} CashInfo;

typedef struct LoanInfo
{
	float suggest_price;
	float actual_price;
	float sale_tax;
	float licensing_fee;
	float doun_payment;
	int loan_duration;
	float interest_rate;
	float monthly_payment;
	char name_of_bank[NAME_LEN];
} LoanInfo;

typedef struct LeaseInfo
{
	float suggest_price;
	float doun_payment;
	float secu_deposit;
	float monthly_payment;
	int lease_term;
} LeaseInfo;

typedef struct SaleInfo
{
	char customer_name[NAME_LEN];
	char customer_address[ADDR_LEN];
	char model[MODEL_LEN];

	enum {CASH, LOAN, LEASE} type;
	union {
		struct CashInfo * pcash_info;
		struct LoanInfo * ploan_info;
		struct LeaseInfo * please_info;
	} value;
} SaleInfo;
