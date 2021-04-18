	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 1
	.globl	_f                      ## -- Begin function f
	.p2align	4, 0x90
_f:                                     ## @f
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$128, %rsp
	movq	_a_very_long_name_to_see_how_long_they_can_be@GOTPCREL(%rip), %rax
	movl	$1, -4(%rbp)
	movl	$2, -8(%rbp)
	movl	$3, -12(%rbp)
	movl	$4, -16(%rbp)
	movl	$5, -20(%rbp)
	movl	$6, -24(%rbp)
	movl	$7, -28(%rbp)
	movl	$8, -32(%rbp)
	movl	$9, -36(%rbp)
	movl	$10, -40(%rbp)
	movl	$110, %ecx
	movq	%rcx, -48(%rbp)
	movl	$120, %ecx
	movq	%rcx, -56(%rbp)
	movl	$130, %ecx
	movq	%rcx, -64(%rbp)
	movl	$140, %ecx
	movq	%rcx, -72(%rbp)
	movl	$150, %ecx
	movq	%rcx, -80(%rbp)
	movl	$160, %ecx
	movq	%rcx, -88(%rbp)
	movl	$170, %ecx
	movq	%rcx, -96(%rbp)
	movl	$180, %ecx
	movq	%rcx, -104(%rbp)
	movl	$190, %ecx
	movq	%rcx, -112(%rbp)
	movl	$200, %ecx
	movq	%rcx, -120(%rbp)
	movl	$1, (%rax)
	movl	-4(%rbp), %esi
	movl	-40(%rbp), %edx
	movl	$10, %edi
	callq	_func_ret_int
	movl	%eax, -8(%rbp)
	callq	_func_ret_double
	movsd	%xmm0, -128(%rbp)
	movq	-48(%rbp), %rdi
	callq	_func_ret_char_ptr
	movq	%rax, -48(%rbp)
	addq	$128, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_ret_int           ## -- Begin function func_ret_int
	.p2align	4, 0x90
_func_ret_int:                          ## @func_ret_int
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	-8(%rbp), %eax
	subl	$6, %eax
	movl	%eax, -16(%rbp)
	movl	-4(%rbp), %eax
	addl	-8(%rbp), %eax
	addl	-12(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function func_ret_double
LCPI2_0:
	.quad	4614253070214989087     ## double 3.1400000000000001
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_func_ret_double
	.p2align	4, 0x90
_func_ret_double:                       ## @func_ret_double
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movsd	LCPI2_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_func_ret_char_ptr      ## -- Begin function func_ret_char_ptr
	.p2align	4, 0x90
_func_ret_char_ptr:                     ## @func_ret_char_ptr
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$1, %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.globl	_static_variable        ## @static_variable
	.p2align	2
_static_variable:
	.long	5                       ## 0x5

.subsections_via_symbols
