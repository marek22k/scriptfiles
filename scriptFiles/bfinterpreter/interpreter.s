	.file	"interpreter.cpp"
	.text
	.align 2
.globl __ZN11Interpreter11interpreter5icodeESs
	.def	__ZN11Interpreter11interpreter5icodeESs;	.scl	2;	.type	32;	.endef
__ZN11Interpreter11interpreter5icodeESs:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	8(%ebp), %ebx
	movl	12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSsaSERKSs
	movl	%ebx, %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSsC1ERKSs
	movl	%ebx, %eax
	movl	%ebx, %eax
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret	$4
	.align 2
.globl __ZN11Interpreter11interpreter5inputESs
	.def	__ZN11Interpreter11interpreter5inputESs;	.scl	2;	.type	32;	.endef
__ZN11Interpreter11interpreter5inputESs:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	8(%ebp), %ebx
	movl	12(%ebp), %eax
	leal	4(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSsaSERKSs
	movl	%ebx, %eax
	movl	12(%ebp), %edx
	addl	$4, %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSsC1ERKSs
	movl	%ebx, %eax
	movl	%ebx, %eax
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret	$4
	.align 2
.globl __ZN11Interpreter11interpreter6actionEc
	.def	__ZN11Interpreter11interpreter6actionEc;	.scl	2;	.type	32;	.endef
__ZN11Interpreter11interpreter6actionEc:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$52, %esp
	movl	12(%ebp), %eax
	movb	%al, -28(%ebp)
	movsbl	-28(%ebp),%eax
	subl	$43, %eax
	cmpl	$19, %eax
	ja	L14
	movl	L13(,%eax,4), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L13:
	.long	L7
	.long	L8
	.long	L9
	.long	L10
	.long	L14
	.long	L14
	.long	L14
	.long	L14
	.long	L14
	.long	L14
	.long	L14
	.long	L14
	.long	L14
	.long	L14
	.long	L14
	.long	L14
	.long	L14
	.long	L11
	.long	L14
	.long	L12
	.text
L7:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN11Interpreter11interpreter11INCREMENTEDEv
	jmp	L14
L9:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN11Interpreter11interpreter11DECREMENTEDEv
	jmp	L14
L11:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN11Interpreter11interpreter4LEFTEv
	jmp	L14
L12:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN11Interpreter11interpreter5RIGHTEv
	jmp	L14
L10:
	movl	8(%ebp), %eax
	movl	32776(%eax), %eax
	movl	8(%ebp), %edx
	movzbl	8(%edx,%eax), %eax
	movb	%al, -9(%ebp)
	movsbl	-9(%ebp),%eax
	movl	8(%ebp), %edx
	addl	$32780, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSspLEc
	jmp	L14
L8:
	movl	8(%ebp), %eax
	movl	32776(%eax), %ebx
	movl	8(%ebp), %eax
	movl	32784(%eax), %eax
	movl	8(%ebp), %edx
	addl	$4, %edx
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSsixEj
	movzbl	(%eax), %edx
	movl	8(%ebp), %eax
	movb	%dl, 8(%eax,%ebx)
	movl	8(%ebp), %eax
	movl	32784(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 32784(%eax)
L14:
	addl	$52, %esp
	popl	%ebx
	popl	%ebp
	ret
	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.align 2
.globl __ZN11Interpreter11interpreter6bfloopEiSs
	.def	__ZN11Interpreter11interpreter6bfloopEiSs;	.scl	2;	.type	32;	.endef
__ZN11Interpreter11interpreter6bfloopEiSs:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$140, %esp
	movl	$___gxx_personality_sj0, -84(%ebp)
	movl	$LLSDA528, -80(%ebp)
	leal	-76(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L35, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	12(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -44(%ebp)
	movl	$0, -40(%ebp)
	movl	$0, -36(%ebp)
	jmp	L16
L24:
	movl	-40(%ebp), %eax
	movl	-44(%ebp), %edx
	leal	(%edx,%eax), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -104(%ebp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	cmpb	$93, %al
	jne	L17
	cmpl	$0, -36(%ebp)
	je	L17
	movl	$1, %eax
	jmp	L18
L17:
	movl	$0, %eax
L18:
	testb	%al, %al
	je	L19
	subl	$1, -36(%ebp)
L19:
	movl	-40(%ebp), %eax
	movl	-44(%ebp), %edx
	leal	(%edx,%eax), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -104(%ebp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	cmpb	$91, %al
	sete	%al
	testb	%al, %al
	je	L20
	addl	$1, -36(%ebp)
L20:
	addl	$1, -40(%ebp)
L16:
	movl	-40(%ebp), %eax
	movl	-44(%ebp), %edx
	leal	(%edx,%eax), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -104(%ebp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	cmpb	$93, %al
	jne	L21
	cmpl	$0, -36(%ebp)
	je	L22
L21:
	movl	$1, %eax
	jmp	L23
L22:
	movl	$0, %eax
L23:
	testb	%al, %al
	jne	L24
	movl	-40(%ebp), %ecx
	movl	-44(%ebp), %edx
	leal	-52(%ebp), %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	movl	$-1, -104(%ebp)
	call	__ZNKSs6substrEjj
	subl	$4, %esp
	jmp	L25
L32:
	movl	$0, -32(%ebp)
	jmp	L26
L31:
	movl	-44(%ebp), %eax
	addl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	movl	$2, -104(%ebp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	movb	%al, -25(%ebp)
	cmpb	$91, -25(%ebp)
	jne	L27
	leal	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1ERKSs
	movl	-32(%ebp), %eax
	leal	-48(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -104(%ebp)
	call	__ZN11Interpreter11interpreter6bfloopEiSs
	addl	%eax, -32(%ebp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	movl	$2, -104(%ebp)
	call	__ZNSsD1Ev
	jmp	L30
L35:
	leal	24(%ebp), %ebp
	movl	-104(%ebp), %ecx
	movl	-100(%ebp), %eax
	movl	-96(%ebp), %edx
	cmpl	$1, %ecx
	je	L33
L29:
	movl	%edx, -120(%ebp)
	movl	%eax, -124(%ebp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -104(%ebp)
	call	__ZNSsD1Ev
	movl	-124(%ebp), %eax
	movl	-120(%ebp), %edx
	jmp	L33
L27:
	movl	-44(%ebp), %eax
	addl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	movl	$2, -104(%ebp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	movsbl	%al,%eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN11Interpreter11interpreter6actionEc
L30:
	addl	$1, -32(%ebp)
L26:
	movl	-40(%ebp), %eax
	cmpl	-32(%ebp), %eax
	seta	%al
	testb	%al, %al
	jne	L31
L25:
	movl	8(%ebp), %eax
	movl	32776(%eax), %eax
	movl	8(%ebp), %edx
	movzbl	8(%edx,%eax), %eax
	testb	%al, %al
	setne	%al
	testb	%al, %al
	jne	L32
	movl	-40(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -128(%ebp)
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -104(%ebp)
	call	__ZNSsD1Ev
	movl	-128(%ebp), %eax
	movl	%eax, -132(%ebp)
L15:
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	-132(%ebp), %eax
	leal	-12(%ebp), %esp
	addl	$0, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L33:
	movl	%edx, -112(%ebp)
	movl	%eax, -116(%ebp)
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -104(%ebp)
	call	__ZNSsD1Ev
	movl	-116(%ebp), %eax
	movl	-112(%ebp), %edx
	movl	%eax, (%esp)
	movl	$-1, -104(%ebp)
	call	__Unwind_SjLj_Resume
	.section	.gcc_except_table,"w"
LLSDA528:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE528-LLSDACSB528
LLSDACSB528:
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 0x1
	.uleb128 0x0
LLSDACSE528:
	.text
	.section .rdata,"dr"
LC0:
	.ascii "\0"
LC1:
	.ascii "0x0001\0"
	.text
	.align 2
.globl __ZN11Interpreter11interpreter9interpretEv
	.def	__ZN11Interpreter11interpreter9interpretEv;	.scl	2;	.type	32;	.endef
__ZN11Interpreter11interpreter9interpretEv:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$124, %esp
	movl	$___gxx_personality_sj0, -68(%ebp)
	movl	$LLSDA529, -64(%ebp)
	leal	-60(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L46, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	12(%ebp), %eax
	movl	$LC0, 4(%esp)
	movl	%eax, (%esp)
	movl	$-1, -88(%ebp)
	call	__ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	testb	%al, %al
	je	L37
	movl	8(%ebp), %eax
	movl	%eax, -112(%ebp)
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-37(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	-112(%ebp), %edx
	movl	%edx, (%esp)
	movl	$2, -88(%ebp)
	call	__ZNSsC1EPKcRKSaIcE
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L36
L39:
	movl	%edx, -104(%ebp)
	movl	%eax, -108(%ebp)
	leal	-37(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	-108(%ebp), %eax
	movl	-104(%ebp), %edx
	movl	%eax, (%esp)
	movl	$-1, -88(%ebp)
	call	__Unwind_SjLj_Resume
L37:
	movl	$0, -32(%ebp)
	jmp	L40
L44:
	movl	12(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	movl	$-1, -88(%ebp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	movb	%al, -25(%ebp)
	cmpb	$91, -25(%ebp)
	jne	L41
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1ERKSs
	movl	-32(%ebp), %eax
	leal	-36(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -88(%ebp)
	call	__ZN11Interpreter11interpreter6bfloopEiSs
	addl	%eax, -32(%ebp)
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -88(%ebp)
	call	__ZNSsD1Ev
	jmp	L42
L46:
	leal	24(%ebp), %ebp
	movl	-88(%ebp), %ecx
	movl	-84(%ebp), %eax
	movl	-80(%ebp), %edx
	cmpl	$1, %ecx
	je	L39
L43:
	movl	%edx, -96(%ebp)
	movl	%eax, -100(%ebp)
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -88(%ebp)
	call	__ZNSsD1Ev
	movl	-100(%ebp), %eax
	movl	-96(%ebp), %edx
	movl	%eax, (%esp)
	movl	$-1, -88(%ebp)
	call	__Unwind_SjLj_Resume
L41:
	movl	12(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	movl	$-1, -88(%ebp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	movsbl	%al,%eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN11Interpreter11interpreter6actionEc
L42:
	addl	$1, -32(%ebp)
L40:
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -88(%ebp)
	call	__ZNKSs6lengthEv
	cmpl	-32(%ebp), %eax
	seta	%al
	testb	%al, %al
	jne	L44
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	addl	$32780, %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSsC1ERKSs
L36:
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	8(%ebp), %eax
	movl	8(%ebp), %eax
	addl	$124, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret	$4
	.section	.gcc_except_table,"w"
LLSDA529:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE529-LLSDACSB529
LLSDACSB529:
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 0x1
	.uleb128 0x0
LLSDACSE529:
	.text
	.section .rdata,"dr"
LC2:
	.ascii ",\0"
	.text
	.align 2
.globl __ZN11Interpreter11interpreter6qinputEv
	.def	__ZN11Interpreter11interpreter6qinputEv;	.scl	2;	.type	32;	.endef
__ZN11Interpreter11interpreter6qinputEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$0, 8(%esp)
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSs4findEPKcj
	cmpl	$-1, %eax
	setne	%al
	testb	%al, %al
	je	L48
	movl	$1, %eax
	jmp	L49
L48:
	movl	$0, %eax
L49:
	leave
	ret
	.align 2
.globl __ZN11Interpreter11interpreter4LEFTEv
	.def	__ZN11Interpreter11interpreter4LEFTEv;	.scl	2;	.type	32;	.endef
__ZN11Interpreter11interpreter4LEFTEv:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	32776(%eax), %eax
	leal	-1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 32776(%eax)
	popl	%ebp
	ret
	.align 2
.globl __ZN11Interpreter11interpreter5RIGHTEv
	.def	__ZN11Interpreter11interpreter5RIGHTEv;	.scl	2;	.type	32;	.endef
__ZN11Interpreter11interpreter5RIGHTEv:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	32776(%eax), %eax
	leal	1(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, 32776(%eax)
	popl	%ebp
	ret
	.align 2
.globl __ZN11Interpreter11interpreter11INCREMENTEDEv
	.def	__ZN11Interpreter11interpreter11INCREMENTEDEv;	.scl	2;	.type	32;	.endef
__ZN11Interpreter11interpreter11INCREMENTEDEv:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	32776(%eax), %eax
	movl	8(%ebp), %edx
	movzbl	8(%edx,%eax), %edx
	leal	1(%edx), %ecx
	movl	8(%ebp), %edx
	movb	%cl, 8(%edx,%eax)
	popl	%ebp
	ret
	.align 2
.globl __ZN11Interpreter11interpreter11DECREMENTEDEv
	.def	__ZN11Interpreter11interpreter11DECREMENTEDEv;	.scl	2;	.type	32;	.endef
__ZN11Interpreter11interpreter11DECREMENTEDEv:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	32776(%eax), %eax
	movl	8(%ebp), %edx
	movzbl	8(%edx,%eax), %edx
	leal	-1(%edx), %ecx
	movl	8(%ebp), %edx
	movb	%cl, 8(%edx,%eax)
	popl	%ebp
	ret
	.section	.text$_ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_,"x"
	.linkonce discard
.globl __ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	.def	__ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_;	.scl	2;	.type	32;	.endef
__ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSs7compareEPKc
	testl	%eax, %eax
	sete	%al
	leave
	ret
	.def	__ZNSsaSERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSspLEc;	.scl	2;	.type	32;	.endef
	.def	__ZNKSs6substrEjj;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1EPKcRKSaIcE;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsixEj;	.scl	2;	.type	32;	.endef
	.def	__ZNKSs6lengthEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1ERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNKSs4findEPKcj;	.scl	2;	.type	32;	.endef
	.def	__ZNKSs7compareEPKc;	.scl	2;	.type	32;	.endef
