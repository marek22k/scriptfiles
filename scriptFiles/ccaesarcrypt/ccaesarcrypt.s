	.file	"ccaesarcrypt.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "option( 1: encrypt / 2: decrypt / 3: version ): \0"
LC1:
	.ascii "%i\0"
LC2:
	.ascii "Text and Key(text key): \0"
LC3:
	.ascii "%s %i\0"
	.align 4
LC4:
	.ascii "\12ccaesarcrypt\12============\12\12The program ccaesarcrypt was written on 18.03.2018 by Marek K. in the C programming language.\0"
LC5:
	.ascii "Errorcode: 0x0001\0"
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$288, %esp
	call	___main
	movl	$LC0, (%esp)
	call	_printf
	movl	$3, 28(%esp)
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	movl	28(%esp), %eax
	cmpl	$2, %eax
	je	L4
	cmpl	$3, %eax
	je	L5
	cmpl	$1, %eax
	jne	L8
L3:
	movl	$LC2, (%esp)
	call	_printf
	leal	24(%esp), %eax
	movl	%eax, 8(%esp)
	leal	33(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_scanf
	leal	33(%esp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	%eax, %edx
	movl	24(%esp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	33(%esp), %eax
	movl	%eax, (%esp)
	call	_encrypt
	jmp	L6
L4:
	movl	$LC2, (%esp)
	call	_printf
	leal	24(%esp), %eax
	movl	%eax, 8(%esp)
	leal	33(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_scanf
	leal	33(%esp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	24(%esp), %edx
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	leal	33(%esp), %eax
	movl	%eax, (%esp)
	call	_decrypt
	jmp	L6
L5:
	movl	$LC4, (%esp)
	call	_puts
	jmp	L6
L8:
	movl	__imp___iob, %eax
	addl	$64, %eax
	movl	%eax, 12(%esp)
	movl	$17, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC5, (%esp)
	call	_fwrite
L6:
	movl	$0, %eax
	leave
	ret
.globl _encrypt
	.def	_encrypt;	.scl	2;	.type	32;	.endef
_encrypt:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$88, %esp
	movb	$0, -15(%ebp)
	jmp	L10
L11:
	movzbl	-15(%ebp), %eax
	movzbl	-15(%ebp), %edx
	addl	$97, %edx
	movb	%dl, -41(%ebp,%eax)
	addb	$1, -15(%ebp)
L10:
	cmpb	$25, -15(%ebp)
	jbe	L11
	movb	$0, -14(%ebp)
	jmp	L12
L13:
	movzbl	-14(%ebp), %eax
	movl	12(%ebp), %edx
	addb	-14(%ebp), %dl
	addl	$97, %edx
	movb	%dl, -67(%ebp,%eax)
	addb	$1, -14(%ebp)
L12:
	movzbl	-14(%ebp), %edx
	movl	$26, %eax
	subl	12(%ebp), %eax
	cmpl	%eax, %edx
	jb	L13
	movl	12(%ebp), %eax
	movl	$26, %edx
	movl	%edx, %ecx
	subb	%al, %cl
	movl	%ecx, %eax
	movb	%al, -13(%ebp)
	jmp	L14
L15:
	movzbl	-13(%ebp), %eax
	movl	12(%ebp), %edx
	addb	-13(%ebp), %dl
	addl	$71, %edx
	movb	%dl, -67(%ebp,%eax)
	addb	$1, -13(%ebp)
L14:
	cmpb	$25, -13(%ebp)
	jbe	L15
	movl	$0, -12(%ebp)
	jmp	L16
L17:
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	leal	(%edx,%eax), %eax
	movzbl	(%eax), %eax
	movsbl	%al,%eax
	movl	%eax, 4(%esp)
	leal	-41(%ebp), %eax
	movl	%eax, (%esp)
	call	_strchr
	movl	%eax, %edx
	leal	-41(%ebp), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movzbl	-67(%ebp,%eax), %eax
	movsbl	%al,%eax
	movl	%eax, (%esp)
	call	_putchar
	addl	$1, -12(%ebp)
L16:
	movl	-12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jb	L17
	movl	$10, (%esp)
	call	_putchar
	leave
	ret
.globl _decrypt
	.def	_decrypt;	.scl	2;	.type	32;	.endef
_decrypt:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$88, %esp
	movb	$0, -15(%ebp)
	jmp	L20
L21:
	movzbl	-15(%ebp), %eax
	movzbl	-15(%ebp), %edx
	addl	$97, %edx
	movb	%dl, -41(%ebp,%eax)
	addb	$1, -15(%ebp)
L20:
	cmpb	$25, -15(%ebp)
	jbe	L21
	movb	$0, -14(%ebp)
	jmp	L22
L23:
	movzbl	-14(%ebp), %eax
	movl	12(%ebp), %edx
	addb	-14(%ebp), %dl
	addl	$97, %edx
	movb	%dl, -67(%ebp,%eax)
	addb	$1, -14(%ebp)
L22:
	movzbl	-14(%ebp), %edx
	movl	$26, %eax
	subl	12(%ebp), %eax
	cmpl	%eax, %edx
	jb	L23
	movl	12(%ebp), %eax
	movl	$26, %edx
	movl	%edx, %ecx
	subb	%al, %cl
	movl	%ecx, %eax
	movb	%al, -13(%ebp)
	jmp	L24
L25:
	movzbl	-13(%ebp), %eax
	movl	12(%ebp), %edx
	addb	-13(%ebp), %dl
	addl	$71, %edx
	movb	%dl, -67(%ebp,%eax)
	addb	$1, -13(%ebp)
L24:
	cmpb	$25, -13(%ebp)
	jbe	L25
	movl	$0, -12(%ebp)
	jmp	L26
L27:
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	leal	(%edx,%eax), %eax
	movzbl	(%eax), %eax
	movsbl	%al,%eax
	movl	%eax, 4(%esp)
	leal	-67(%ebp), %eax
	movl	%eax, (%esp)
	call	_strchr
	movl	%eax, %edx
	leal	-67(%ebp), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movzbl	-41(%ebp,%eax), %eax
	movsbl	%al,%eax
	movl	%eax, (%esp)
	call	_putchar
	addl	$1, -12(%ebp)
L26:
	movl	-12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jb	L27
	movl	$10, (%esp)
	call	_putchar
	leave
	ret
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_fwrite;	.scl	2;	.type	32;	.endef
	.def	_strchr;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
