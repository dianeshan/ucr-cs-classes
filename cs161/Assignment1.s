	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_matrix_init                    ## -- Begin function matrix_init
	.p2align	4, 0x90
_matrix_init:                           ## @matrix_init
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	$0, -16(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	-8(%rbp), %rax
	movslq	-16(%rbp), %rcx
	movl	$0, (%rax,%rcx,4)
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB0_1
LBB0_4:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
