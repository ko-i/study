	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_try4                   ## -- Begin function try4
	.p2align	4, 0x90
_try4:                                  ## @try4
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	_y@GOTPCREL(%rip), %rax
	movq	_x@GOTPCREL(%rip), %rcx
	movl	$0, -20(%rbp)
	movq	%rcx, -8(%rbp)
	movq	%rax, -16(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$50, -20(%rbp)
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	addq	$4, %rcx
	movq	%rcx, -16(%rbp)
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	addq	$4, %rcx
	movq	%rcx, -8(%rbp)
	movl	%edx, (%rax)
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB0_1
LBB0_4:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.comm	_x,200,4                ## @x
	.comm	_y,200,4                ## @y
.subsections_via_symbols
