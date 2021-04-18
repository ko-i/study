// 2020-12-16 created by Akson
// Code11.4a inventor.h 存货系统声明

// 存货记录的声明

#ifndef _INVENTOR_H_
#define _INVENTOR_H_

// 包含零件专用信息的结构
typedef struct
{
	int cost;
	int supplier;
} Partinfo;

// 存储装配件专用信息的结构
typedef struct
{
	int n_parts;
	struct SUBASSYPART
	{
		char partno[10];
		short quan;
	} *part;
} Subassyinfo;

// 存货记录结构，它是一个变体记录。
typedef struct 
{
	char partno[10];
	int quan;
	enum {PART, SUBASSY} type;
	union {
		Partinfo* part;
		Subassyinfo* subassy;
	} info;
} Invrec;

Invrec* create_subassy_record(int n_parts);
void discard_inventory_record(Invrec* record);

#endif