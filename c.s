	.file	"c.c"
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%d,%d,%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	andl	$-16, %esp
	subl	$176, %esp
	.cfi_offset 3, -12
	call	___main
	movl	$5, 32(%esp)
	movl	$6, 36(%esp)
	movl	$7, 40(%esp)
	movl	$3, 20(%esp)
	movl	$3, 24(%esp)
	movl	$3, 28(%esp)
	leal	44(%esp), %eax
	movl	%eax, 172(%esp)
	leal	44(%esp), %eax
	addl	$116, %eax
	addl	$4, %eax
	movl	%eax, 164(%esp)
	movl	$0, 168(%esp)
	jmp	L2
L3:
	movl	168(%esp), %eax
	leal	1(%eax), %ecx
	movl	168(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	176(%esp), %ebx
	addl	%ebx, %eax
	subl	$132, %eax
	movl	%ecx, (%eax)
	movl	168(%esp), %eax
	leal	1(%eax), %ecx
	movl	168(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	176(%esp), %ebx
	addl	%ebx, %eax
	addl	$-128, %eax
	movl	%ecx, (%eax)
	movl	168(%esp), %eax
	leal	1(%eax), %ecx
	movl	168(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	176(%esp), %ebx
	addl	%ebx, %eax
	subl	$124, %eax
	movl	%ecx, (%eax)
	addl	$1, 168(%esp)
L2:
	cmpl	$9, 168(%esp)
	jle	L3
	movl	$0, 168(%esp)
	jmp	L4
L5:
	movl	168(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	176(%esp), %ecx
	addl	%ecx, %eax
	subl	$124, %eax
	movl	(%eax), %ebx
	movl	168(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	176(%esp), %ecx
	addl	%ecx, %eax
	addl	$-128, %eax
	movl	(%eax), %ecx
	movl	168(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	176(%esp), %edx
	addl	%edx, %eax
	subl	$132, %eax
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	addl	$1, 168(%esp)
L4:
	cmpl	$9, 168(%esp)
	jle	L5
	jmp	L6
L7:
	movl	172(%esp), %eax
	movl	$11, (%eax)
	addl	$4, 172(%esp)
L6:
	movl	172(%esp), %eax
	cmpl	164(%esp), %eax
	jne	L7
	movl	$0, 168(%esp)
	jmp	L8
L9:
	movl	168(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	176(%esp), %ebx
	addl	%ebx, %eax
	subl	$124, %eax
	movl	(%eax), %ebx
	movl	168(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	176(%esp), %ecx
	addl	%ecx, %eax
	addl	$-128, %eax
	movl	(%eax), %ecx
	movl	168(%esp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	176(%esp), %edx
	addl	%edx, %eax
	subl	$132, %eax
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	addl	$1, 168(%esp)
L8:
	cmpl	$9, 168(%esp)
	jle	L9
	movl	$0, %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.ident	"GCC: (MinGW.org GCC-8.2.0-5) 8.2.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
