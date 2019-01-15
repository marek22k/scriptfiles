	.file	"mbfinterpreter.c"
	.comm	_bfin, 262143, 5
	.comm	_bfout, 262143, 5
	.comm	_cell, 32767, 5
	.comm	_inpos, 4, 2
	.comm	_cur, 4, 2
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "r\0"
LC1:
	.ascii "Input: \0"
LC2:
	.ascii "%s\0"
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	subl	$88, %esp
	movl	%ecx, %ebx
	call	___main
	movl	%esp, %eax
	movl	%eax, -60(%ebp)
	movl	4(%ebx), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	$LC0, 4(%esp)
	movl	%eax, (%esp)
	call	_fopen
	movl	%eax, -32(%ebp)
	movl	$2, 8(%esp)
	movl	$0, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_fseek
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_ftell
	movl	%eax, %ecx
	leal	-1(%ecx), %eax
	movl	%eax, -40(%ebp)
	movl	%ecx, %eax
	movl	$0, %edx
	movl	%eax, %esi
	andl	$-1, %esi
	movl	%edx, %edi
	andl	$15, %edi
	movl	%esi, %eax
	movl	%edi, %edx
	shldl	$3, %eax, %edx
	sall	$3, %eax
	movl	%eax, %ebx
	andb	$255, %bh
	movl	%ebx, -72(%ebp)
	movl	%edx, %ebx
	andl	$15, %ebx
	movl	%ebx, -68(%ebp)
	movl	-72(%ebp), %eax
	movl	-68(%ebp), %edx
	movl	%ecx, %eax
	movl	$0, %edx
	movl	%eax, %ebx
	andb	$255, %bh
	movl	%ebx, -80(%ebp)
	movl	%edx, %ebx
	andl	$15, %ebx
	movl	%ebx, -76(%ebp)
	movl	-80(%ebp), %eax
	movl	-76(%ebp), %edx
	shldl	$3, %eax, %edx
	sall	$3, %eax
	movl	%eax, %ebx
	andb	$255, %bh
	movl	%ebx, -88(%ebp)
	movl	%edx, %ebx
	andl	$15, %ebx
	movl	%ebx, -84(%ebp)
	movl	-88(%ebp), %eax
	movl	-84(%ebp), %edx
	movl	%ecx, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	call	___chkstk
	leal	12(%esp), %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	movl	%eax, -36(%ebp)
	movl	$0, 8(%esp)
	movl	$0, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_fseek
	jmp	L2
L3:
	movl	-36(%ebp), %eax
	movl	$1, 8(%esp)
	leal	-41(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strncat
L2:
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_fgetc
	movb	%al, -41(%ebp)
	movzbl	-41(%ebp), %eax
	cmpb	$-1, %al
	jne	L3
	movl	-36(%ebp), %eax
	movl	$44, 4(%esp)
	movl	%eax, (%esp)
	call	_strchr
	testl	%eax, %eax
	je	L4
	movl	$LC1, (%esp)
	call	_printf
	movl	$_bfin, 4(%esp)
	movl	$LC2, (%esp)
	call	_scanf
L4:
	movl	$0, -28(%ebp)
	jmp	L5
L6:
	movl	-28(%ebp), %edx
	movl	-36(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_bfhandle
	addl	%eax, -28(%ebp)
	addl	$1, -28(%ebp)
L5:
	movl	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	_strlen
	cmpl	-28(%ebp), %eax
	ja	L6
	movl	$_bfout, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$0, %eax
	movl	-60(%ebp), %esp
	leal	-16(%ebp), %esp
	addl	$0, %esp
	popl	%ecx
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
.globl _bfhandle
	.def	_bfhandle;	.scl	2;	.type	32;	.endef
_bfhandle:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$92, %esp
	movl	12(%ebp), %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movsbl	%al,%eax
	subl	$43, %eax
	cmpl	$48, %eax
	ja	L9
	movl	L17(,%eax,4), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L17:
	.long	L10
	.long	L11
	.long	L12
	.long	L13
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L14
	.long	L9
	.long	L15
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L9
	.long	L16
	.text
L10:
	movl	_cur, %eax
	movzbl	_cell(%eax), %edx
	addl	$1, %edx
	movb	%dl, _cell(%eax)
	jmp	L9
L12:
	movl	_cur, %eax
	movzbl	_cell(%eax), %edx
	subl	$1, %edx
	movb	%dl, _cell(%eax)
	jmp	L9
L14:
	movl	_cur, %eax
	subl	$1, %eax
	movl	%eax, _cur
	jmp	L9
L15:
	movl	_cur, %eax
	addl	$1, %eax
	movl	%eax, _cur
	jmp	L9
L13:
	movl	_cur, %eax
	addl	$_cell, %eax
	movl	$1, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$_bfout, (%esp)
	call	_strncat
	jmp	L9
L11:
	movl	_cur, %edx
	movl	_inpos, %eax
	movzbl	_bfin(%eax), %ecx
	movb	%cl, _cell(%edx)
	addl	$1, %eax
	movl	%eax, _inpos
	jmp	L9
L16:
	movl	12(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -40(%ebp)
	movl	$0, -36(%ebp)
	movl	$0, -32(%ebp)
	jmp	L18
L20:
	movl	-36(%ebp), %edx
	movl	-40(%ebp), %eax
	addl	%edx, %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$93, %al
	jne	L19
	cmpl	$0, -32(%ebp)
	je	L19
	subl	$1, -32(%ebp)
L19:
	movl	-40(%ebp), %edx
	movl	-36(%ebp), %eax
	addl	%edx, %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$91, %al
	sete	%al
	addl	$1, -36(%ebp)
	testb	%al, %al
	je	L18
	addl	$1, -32(%ebp)
L18:
	movl	-36(%ebp), %edx
	movl	-40(%ebp), %eax
	addl	%edx, %eax
	addl	8(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	$93, %al
	jne	L20
	cmpl	$0, -32(%ebp)
	jne	L20
	movl	%esp, %eax
	movl	%eax, %ebx
	movl	-36(%ebp), %ecx
	leal	-1(%ecx), %eax
	movl	%eax, -48(%ebp)
	movl	%ecx, %eax
	movl	$0, %edx
	movl	%eax, %esi
	andl	$-1, %esi
	movl	%edx, %edi
	andl	$15, %edi
	movl	%esi, %eax
	movl	%edi, %edx
	shldl	$3, %eax, %edx
	sall	$3, %eax
	movl	%eax, %esi
	andl	$-1, %esi
	movl	%esi, -64(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -60(%ebp)
	movl	-64(%ebp), %eax
	movl	-60(%ebp), %edx
	movl	%ecx, %eax
	movl	$0, %edx
	movl	%eax, %esi
	andl	$-1, %esi
	movl	%esi, -72(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -68(%ebp)
	movl	-72(%ebp), %eax
	movl	-68(%ebp), %edx
	shldl	$3, %eax, %edx
	sall	$3, %eax
	movl	%eax, %esi
	andl	$-1, %esi
	movl	%esi, -80(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -76(%ebp)
	movl	-80(%ebp), %eax
	movl	-76(%ebp), %edx
	movl	%ecx, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	call	___chkstk
	leal	12(%esp), %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	movl	%eax, -44(%ebp)
	movl	-36(%ebp), %ecx
	movl	-40(%ebp), %eax
	movl	%eax, %edx
	addl	8(%ebp), %edx
	movl	-44(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_strncpy
	jmp	L21
L24:
	movl	$0, -28(%ebp)
	jmp	L22
L23:
	movl	-28(%ebp), %edx
	movl	-44(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_bfhandle
	addl	%eax, -28(%ebp)
	addl	$1, -28(%ebp)
L22:
	movl	-36(%ebp), %eax
	cmpl	-28(%ebp), %eax
	ja	L23
L21:
	movl	_cur, %eax
	movzbl	_cell(%eax), %eax
	testb	%al, %al
	jne	L24
	movl	-36(%ebp), %eax
	addl	$1, %eax
	movl	%ebx, %esp
	jmp	L25
L9:
	movl	$0, %eax
L25:
	leal	-12(%ebp), %esp
	addl	$0, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.def	_fopen;	.scl	2;	.type	32;	.endef
	.def	_ftell;	.scl	2;	.type	32;	.endef
	.def	_fseek;	.scl	2;	.type	32;	.endef
	.def	_fgetc;	.scl	2;	.type	32;	.endef
	.def	_strchr;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_strncat;	.scl	2;	.type	32;	.endef
	.def	_strncpy;	.scl	2;	.type	32;	.endef
