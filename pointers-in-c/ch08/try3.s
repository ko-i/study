	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_try3                   ## -- Begin function try3
	.p2align	4, 0x90
_try3:                                  ## @try3
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	_p2@GOTPCREL(%rip), %rax
	movq	_y@GOTPCREL(%rip), %rcx
	movq	_p1@GOTPCREL(%rip), %rdx
	movq	_x@GOTPCREL(%rip), %rsi
	movq	_i@GOTPCREL(%rip), %rdi
	movl	$0, (%rdi)
	movq	%rsi, (%rdx)
	movq	%rcx, (%rax)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	_i@GOTPCREL(%rip), %rax
	cmpl	$50, (%rax)
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	_p1@GOTPCREL(%rip), %rax
	movq	_p2@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rdx
	movq	%rdx, %rsi
	addq	$4, %rsi
	movq	%rsi, (%rcx)
	movl	(%rdx), %edi
	movq	(%rax), %rcx
	movq	%rcx, %rdx
	addq	$4, %rdx
	movq	%rdx, (%rax)
	movl	%edi, (%rcx)
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	_i@GOTPCREL(%rip), %rax
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
	jmp	LBB0_1
LBB0_4:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.comm	_i,4,2                  ## @i
	.comm	_x,200,4                ## @x
	.comm	_p1,8,3                 ## @p1
	.comm	_y,200,4                ## @y
	.comm	_p2,8,3                 ## @p2
.subsections_via_symbols
