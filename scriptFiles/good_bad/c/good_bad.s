	.file	"good_bad.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Hello User! Enter a number:\0"
LC1:
	.ascii "%d\0"
LC2:
	.ascii "The number is crazy!\0"
LC3:
	.ascii "The number is good!\0"
LC4:
	.ascii "The number is bad!\0"
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$LC0, (%esp)
	call	_puts
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	movl	28(%esp), %eax
	testl	%eax, %eax
	jns	L2
	movl	$LC2, (%esp)
	call	_puts
	jmp	L3
L2:
	movl	28(%esp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	L4
	movl	$LC3, (%esp)
	call	_puts
	jmp	L3
L4:
	movl	$LC4, (%esp)
	call	_puts
L3:
	movl	$0, %eax
	leave
	ret
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
