	.file	"Zahlenraten.cpp"
.lcomm __ZStL8__ioinit,1,1
.globl _target
	.bss
_target:
	.space 1
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	call	__Z5Startv
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZNSirsERi
	movl	$0, %eax
	leave
	ret
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "Willkommen beim Spiel Zahlenraten. Du denkst dir eine Zahl und ich muss versuchen sie zu erraten. Die must mir jede Runde sagen ob deine Zahl groszer(b), kleiner(s) oder ob ich sie erraten habe(t). Fangen wir an! \0"
	.align 4
LC1:
	.ascii "Bis zu welcher Zahl soll ich raten? \0"
	.text
.globl __Z5Startv
	.def	__Z5Startv;	.scl	2;	.type	32;	.endef
__Z5Startv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZNSirsERi
	call	__Z3Wtlv
	movl	-28(%ebp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	leal	(%edx,%eax), %eax
	sarl	%eax
	movl	%eax, -24(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	$0, -16(%ebp)
	jmp	L4
L6:
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z5Queryi
	movl	%eax, -12(%ebp)
	cmpl	$1, -12(%ebp)
	jne	L5
	movl	-24(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	-20(%ebp), %edx
	leal	(%edx,%eax), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	leal	(%edx,%eax), %eax
	sarl	%eax
	movl	%eax, -24(%ebp)
	jmp	L4
L5:
	cmpl	$0, -12(%ebp)
	jne	L4
	movl	-24(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-16(%ebp), %eax
	movl	-20(%ebp), %edx
	leal	(%edx,%eax), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	leal	(%edx,%eax), %eax
	sarl	%eax
	movl	%eax, -24(%ebp)
L4:
	movzbl	_target, %eax
	xorl	$1, %eax
	testb	%al, %al
	jne	L6
	call	__Z3Winv
	leave
	ret
	.section .rdata,"dr"
LC2:
	.ascii "Ich habe die Zahl erraten!\0"
	.text
.globl __Z3Winv
	.def	__Z3Winv;	.scl	2;	.type	32;	.endef
__Z3Winv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	leave
	ret
	.section .rdata,"dr"
	.align 4
LC3:
	.ascii "Ist die Zahl groszer oder kleiner als \0"
LC4:
	.ascii "? Deine Antwort: \0"
LC5:
	.ascii "b\0"
LC6:
	.ascii "s\0"
LC7:
	.ascii "t\0"
	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.text
.globl __Z5Queryi
	.def	__Z5Queryi;	.scl	2;	.type	32;	.endef
__Z5Queryi:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$124, %esp
	movl	$___gxx_personality_sj0, -68(%ebp)
	movl	$LLSDA941, -64(%ebp)
	leal	-60(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L18, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$-1, -88(%ebp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEi
	movl	$LC4, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1Ev
	leal	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	movl	$1, -88(%ebp)
	call	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	movl	$LC5, 4(%esp)
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	testb	%al, %al
	je	L11
	movl	$1, -104(%ebp)
	jmp	L12
L11:
	movl	$LC6, 4(%esp)
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -88(%ebp)
	call	__ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	testb	%al, %al
	je	L13
	movl	$0, -104(%ebp)
	jmp	L12
L13:
	movl	$LC7, 4(%esp)
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -88(%ebp)
	call	__ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	testb	%al, %al
	je	L14
	movb	$1, _target
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	movl	$1, -88(%ebp)
	call	__ZNSolsEPFRSoS_E
	jmp	L19
L14:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -88(%ebp)
	call	__Z5Queryi
	movl	%eax, -104(%ebp)
	jmp	L12
L19:
	movl	$2, -104(%ebp)
	jmp	L12
L18:
	leal	24(%ebp), %ebp
	movl	-84(%ebp), %eax
	movl	-80(%ebp), %edx
L16:
	movl	%edx, -96(%ebp)
	movl	%eax, -100(%ebp)
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -88(%ebp)
	call	__ZNSsD1Ev
	movl	-100(%ebp), %eax
	movl	-96(%ebp), %edx
	movl	%eax, (%esp)
	movl	$-1, -88(%ebp)
	call	__Unwind_SjLj_Resume
L12:
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -88(%ebp)
	call	__ZNSsD1Ev
	movl	-104(%ebp), %eax
	movl	%eax, -108(%ebp)
L10:
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	-108(%ebp), %eax
	addl	$124, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA941:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE941-LLSDACSB941
LLSDACSB941:
	.uleb128 0x0
	.uleb128 0x0
LLSDACSE941:
	.text
.globl __Z3Wtlv
	.def	__Z3Wtlv;	.scl	2;	.type	32;	.endef
__Z3Wtlv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	leave
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
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitD1Ev
	leave
	ret
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L28
	cmpl	$65535, 12(%ebp)
	jne	L28
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L28:
	leave
	ret
	.def	__GLOBAL__I_target;	.scl	3;	.type	32;	.endef
__GLOBAL__I_target:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__I_target
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNKSs7compareEPKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
