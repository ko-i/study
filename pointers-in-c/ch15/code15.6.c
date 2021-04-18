// 2020-12-19 created by Akson
// Code15.6 rd_rand.c 随机文件访问

// 从一个文件读取一个特定的记录，参数分别是进行读取的流、需要读取的记录数和指向放置数据的缓冲区的指针

#include <stdio.h>

typedef struct
{
	int student_id;
} StudentInfo;

int read_random_record(FILE* f, size_t rec_number, StudentInfo* buffer)
{
	fseek(f, (long)rec_number * sizeof(StudentInfo), SEEK_SET);

	return fread(buffer, sizeof(StudentInfo), 1, f);
}