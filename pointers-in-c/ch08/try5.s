	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_try5                   ## -- Begin function try5
	.p2align	4, 0x90
_try5:                                  ## @try5
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	_y@GOTPCREL(%rip), %rax
	movq	_x@GOTPCREL(%rip), %rcx
	movq	%rcx, -8(%rbp)
	movq	%rax, -16(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	_x@GOTPCREL(%rip), %rax
	addq	$200, %rax
	cmpq	%rax, -8(%rbp)
	jae	LBB0_3
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
	jmp	LBB0_1
LBB0_3:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.comm	_x,200,4                ## @x
	.comm	_y,200,4                ## @y
.subsections_via_symbols
