	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_try2                   ## -- Begin function try2
	.p2align	4, 0x90
_try2:                                  ## @try2
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
	movq	%rsi, (%rdx)
	movq	%rcx, (%rax)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	_x@GOTPCREL(%rip), %rax
	movq	_p1@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	subq	%rax, %rcx
	sarq	$2, %rcx
	cmpq	$50, %rcx
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_3
LBB0_3:                                 ##   in Loop: Header=BB0_1 Depth=1
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
	jmp	LBB0_1
LBB0_4:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.comm	_x,200,4                ## @x
	.comm	_p1,8,3                 ## @p1
	.comm	_y,200,4                ## @y
	.comm	_p2,8,3                 ## @p2
.subsections_via_symbols
