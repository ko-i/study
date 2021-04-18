	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 0
	.globl	_try1                   ## -- Begin function try1
	.p2align	4, 0x90
_try1:                                  ## @try1
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	_i@GOTPCREL(%rip), %rax
	movl	$0, (%rax)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	_i@GOTPCREL(%rip), %rax
	cmpl	$50, (%rax)
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	_x@GOTPCREL(%rip), %rax
	movq	_i@GOTPCREL(%rip), %rcx
	movq	_y@GOTPCREL(%rip), %rdx
	movslq	(%rcx), %rsi
	movl	(%rdx,%rsi,4), %edi
	movslq	(%rcx), %rcx
	movl	%edi, (%rax,%rcx,4)
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
	.comm	_y,200,4                ## @y
	.comm	_x,200,4                ## @x
.subsections_via_symbols
