// 2020-12-16 created by Akson
// pe10.3

typedef union 
{
	unsigned int addr;

	struct
	{
		unsigned int dst_reg : 3;
		unsigned int dst_mode : 3;
		unsigned int opcode : 10;
	} sgl_op;

	struct
	{
		unsigned int dst_reg : 3;
		unsigned int dst_mode : 3;
		unsigned int src_reg : 3;
		unsigned int src_mode : 3;
		unsigned int opcode : 4;
	} dbl_op;

	struct
	{
		unsigned int offset : 8;
		unsigned int opcode : 8;
	} misc;

	struct 
	{
		unsigned int dst_reg : 3;
		unsigned int dst_mode : 3;
		unsigned int src_reg : 3;
		unsigned int opcode : 7;
	} reg_src;

	struct
	{
		unsigned int opcode;
	} branch;
} machine_inst;