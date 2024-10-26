	.file	"a.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d bytes\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movabsq	$40000000000, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movl	$400000000, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movl	$0, -16(%rbp)
	jmp	.L2
.L5:
	movl	$0, -12(%rbp)
	jmp	.L3
.L4:
	call	rand@PLT
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	imulq	$40000, %rdx, %rcx
	movq	-8(%rbp), %rdx
	leaq	(%rcx,%rdx), %rsi
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$100, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	-12(%rbp), %eax
	cltq
	movl	%edx, (%rsi,%rax,4)
	addl	$1, -12(%rbp)
.L3:
	cmpl	$9999, -12(%rbp)
	jle	.L4
	addl	$1, -16(%rbp)
.L2:
	cmpl	$9999, -16(%rbp)
	jle	.L5
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (GNU) 14.2.1 20240910"
	.section	.note.GNU-stack,"",@progbits
