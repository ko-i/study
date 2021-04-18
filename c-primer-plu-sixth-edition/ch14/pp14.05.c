// 2020-11-13 created by Akson

#include <stdio.h>

#define CSIZE 4
#define SUBNUM 3
#define LEN 20


struct name
{
	char fname[LEN];
	char lname[LEN];
};

struct student
{
	struct name student_name;
	double grade[SUBNUM];
	double average;
};

void getinfo(struct student *stu);
void calcu_student_ave(struct student *stu);
void print_stu(struct student *stu);
void calce_class_ave(struct student * stus, int n);

int main(void)
{
	struct student stus[CSIZE] = 
	{
		{{"Benwei", "Lu"}, {0, 0, 0}, 0},
		{{"Xiaochuan", "Sun"}, {0, 0, 0}, 0},
		{{"Xukun", "Cai"}, {0, 0, 0}, 0},
		{{"Baoguo", "Ma"}, {0, 0, 0}, 0}
	};

	for(int i = 0; i < CSIZE; i++)
	{
		getinfo(&stus[i]);
	}

	for(int i = 0; i < CSIZE; i++)
	{
		calcu_student_ave(&stus[i]);
	}

	for(int i = 0; i < CSIZE; i++)
	{
		print_stu(&stus[i]);
	}

	calce_class_ave(stus, CSIZE);

	return 0;
}


void getinfo(struct student *stu)
{
	printf("Student: %s %s\n", stu -> student_name.fname, stu -> student_name.lname);
	for(int i = 0; i < SUBNUM; i++)
	{
		printf("Enter the %d-th grade: ", i + 1);
		scanf("%.2lf", &(stu -> grade[i]));
	}
}

void calcu_student_ave(struct student *stu)
{
	double sum = 0.0;

	for(int i = 0; i < SUBNUM; i++)
	{
		sum += stu -> grade[i];
	}

	stu -> average = sum / SUBNUM;
}

void print_stu(struct student *stu)
{
	printf("%s %s:\n", stu -> student_name.fname, stu -> student_name.lname);
	for(int i = 0; i < SUBNUM; i++)
	{
		printf("Subject(%d): %.2lf\n", i + 1, stu -> grade[i]);
	}
	printf("Average: %.2lf\n", stu -> average);
}

void calce_class_ave(struct student * stus, int n)
{
	double sum = 0.0;
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < SUBNUM; j++)
		{
			sum += stus[i].grade[j];
			count++;
		}
	}

	printf("Class average: %.2lf\n", sum / count);
}