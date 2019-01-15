	.file	"bfchecker.cpp"
.lcomm __ZStL8__ioinit,1,1
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "\0"
LC1:
	.ascii "[: \0"
LC2:
	.ascii "]: \0"
LC3:
	.ascii ">: \0"
LC4:
	.ascii "<: \0"
LC5:
	.ascii "+: \0"
LC6:
	.ascii "-: \0"
LC7:
	.ascii ".: \0"
LC8:
	.ascii ",: \0"
LC9:
	.ascii "Comments: \0"
LC10:
	.ascii " - \0"
LC11:
	.ascii "ok - while\0"
LC12:
	.ascii "not ok - while\0"
LC13:
	.ascii "ok - cell\0"
LC14:
	.ascii "not ok - cell\0"
	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$452, %esp
	movl	$___gxx_personality_sj0, 100(%esp)
	movl	$LLSDA1001, 104(%esp)
	leal	108(%esp), %eax
	movl	%ebp, (%eax)
	movl	$L28, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	76(%esp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	call	___main
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$-1, 80(%esp)
	call	__ZNSsC1Ev
	leal	396(%esp), %eax
	movl	%eax, (%esp)
	movl	$5, 80(%esp)
	call	__ZNSsC1Ev
	movl	12(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	$8, 8(%esp)
	movl	%eax, 4(%esp)
	leal	140(%esp), %eax
	movl	%eax, (%esp)
	movl	$4, 80(%esp)
	call	__ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
	jmp	L2
L3:
	leal	396(%esp), %eax
	movl	%eax, 4(%esp)
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$3, 80(%esp)
	call	__ZNSspLERKSs
L2:
	leal	396(%esp), %eax
	movl	%eax, 4(%esp)
	leal	140(%esp), %eax
	movl	%eax, (%esp)
	movl	$3, 80(%esp)
	call	__ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	movl	%eax, %edx
	movl	(%eax), %eax
	subl	$12, %eax
	movl	(%eax), %eax
	leal	(%edx,%eax), %eax
	movl	%eax, (%esp)
	call	__ZNKSt9basic_iosIcSt11char_traitsIcEEcvPvEv
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	jne	L3
	leal	140(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14basic_ifstreamIcSt11char_traitsIcEE5closeEv
	movl	$0, 408(%esp)
	movl	$0, 412(%esp)
	movl	$0, 416(%esp)
	movl	$0, 420(%esp)
	movl	$0, 424(%esp)
	movl	$0, 428(%esp)
	movl	$0, 432(%esp)
	movl	$0, 436(%esp)
	movl	$0, 440(%esp)
	leal	407(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	407(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$LC0, 4(%esp)
	leal	392(%esp), %eax
	movl	%eax, (%esp)
	movl	$2, 80(%esp)
	call	__ZNSsC1EPKcRKSaIcE
	leal	407(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	$0, 444(%esp)
	jmp	L4
L5:
	movl	%edx, 40(%esp)
	movl	%eax, 36(%esp)
	leal	407(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	36(%esp), %eax
	movl	40(%esp), %edx
	jmp	L23
L15:
	movl	444(%esp), %eax
	movl	%eax, 4(%esp)
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$1, 80(%esp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	cmpb	$91, %al
	sete	%al
	testb	%al, %al
	je	L6
	addl	$1, 408(%esp)
	jmp	L7
L6:
	movl	444(%esp), %eax
	movl	%eax, 4(%esp)
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$1, 80(%esp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	cmpb	$93, %al
	sete	%al
	testb	%al, %al
	je	L8
	addl	$1, 412(%esp)
	jmp	L7
L8:
	movl	444(%esp), %eax
	movl	%eax, 4(%esp)
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$1, 80(%esp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	cmpb	$62, %al
	sete	%al
	testb	%al, %al
	je	L9
	addl	$1, 416(%esp)
	jmp	L7
L9:
	movl	444(%esp), %eax
	movl	%eax, 4(%esp)
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$1, 80(%esp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	cmpb	$60, %al
	sete	%al
	testb	%al, %al
	je	L10
	addl	$1, 420(%esp)
	jmp	L7
L10:
	movl	444(%esp), %eax
	movl	%eax, 4(%esp)
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$1, 80(%esp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	cmpb	$43, %al
	sete	%al
	testb	%al, %al
	je	L11
	addl	$1, 424(%esp)
	jmp	L7
L11:
	movl	444(%esp), %eax
	movl	%eax, 4(%esp)
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$1, 80(%esp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	cmpb	$45, %al
	sete	%al
	testb	%al, %al
	je	L12
	addl	$1, 428(%esp)
	jmp	L7
L12:
	movl	444(%esp), %eax
	movl	%eax, 4(%esp)
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$1, 80(%esp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	cmpb	$46, %al
	sete	%al
	testb	%al, %al
	je	L13
	addl	$1, 432(%esp)
	jmp	L7
L13:
	movl	444(%esp), %eax
	movl	%eax, 4(%esp)
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$1, 80(%esp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	cmpb	$44, %al
	sete	%al
	testb	%al, %al
	je	L14
	addl	$1, 436(%esp)
	jmp	L7
L14:
	addl	$1, 440(%esp)
	movl	444(%esp), %eax
	movl	%eax, 4(%esp)
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$1, 80(%esp)
	call	__ZNSsixEj
	movzbl	(%eax), %eax
	movsbl	%al,%eax
	movl	%eax, 4(%esp)
	leal	392(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSspLEc
L7:
	addl	$1, 444(%esp)
L4:
	movl	444(%esp), %eax
	movl	%eax, 28(%esp)
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$1, 80(%esp)
	call	__ZNKSs6lengthEv
	cmpl	%eax, 28(%esp)
	setb	%al
	testb	%al, %al
	jne	L15
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	408(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	412(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	416(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC4, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	420(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC5, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	424(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC6, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	428(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC7, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	432(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC8, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	436(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC9, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	440(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEi
	movl	$LC10, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	392(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	408(%esp), %eax
	cmpl	412(%esp), %eax
	jne	L16
	movl	$LC11, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	jmp	L17
L16:
	movl	$LC12, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$1, 80(%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
L17:
	movl	420(%esp), %eax
	movl	416(%esp), %edx
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	testl	%eax, %eax
	js	L18
	movl	$LC13, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$1, 80(%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	jmp	L19
L18:
	movl	$LC14, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$1, 80(%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
L19:
	movl	$0, 32(%esp)
	leal	392(%esp), %eax
	movl	%eax, (%esp)
	movl	$3, 80(%esp)
	call	__ZNSsD1Ev
	jmp	L29
L28:
	movl	80(%esp), %ecx
	movl	84(%esp), %eax
	movl	88(%esp), %edx
	cmpl	$1, %ecx
	je	L5
	cmpl	$2, %ecx
	je	L23
	cmpl	$3, %ecx
	je	L25
	cmpl	$4, %ecx
	je	L26
L21:
	movl	%edx, 48(%esp)
	movl	%eax, 44(%esp)
	leal	392(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 80(%esp)
	call	__ZNSsD1Ev
	movl	44(%esp), %eax
	movl	48(%esp), %edx
	jmp	L23
L29:
	leal	140(%esp), %eax
	movl	%eax, (%esp)
	movl	$4, 80(%esp)
	call	__ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
	jmp	L30
L23:
	movl	%edx, 56(%esp)
	movl	%eax, 52(%esp)
	leal	140(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 80(%esp)
	call	__ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
	movl	52(%esp), %eax
	movl	56(%esp), %edx
	jmp	L25
L30:
	leal	396(%esp), %eax
	movl	%eax, (%esp)
	movl	$5, 80(%esp)
	call	__ZNSsD1Ev
	jmp	L31
L25:
	movl	%edx, 64(%esp)
	movl	%eax, 60(%esp)
	leal	396(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 80(%esp)
	call	__ZNSsD1Ev
	movl	60(%esp), %eax
	movl	64(%esp), %edx
	jmp	L26
L31:
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$-1, 80(%esp)
	call	__ZNSsD1Ev
	movl	32(%esp), %eax
	movl	%eax, 24(%esp)
L1:
	leal	76(%esp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	24(%esp), %eax
	addl	$452, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	movl	%ebp, %esp
	popl	%ebp
	ret
L26:
	movl	%edx, 72(%esp)
	movl	%eax, 68(%esp)
	leal	400(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 80(%esp)
	call	__ZNSsD1Ev
	movl	68(%esp), %eax
	movl	72(%esp), %edx
	movl	%eax, (%esp)
	movl	$-1, 80(%esp)
	call	__Unwind_SjLj_Resume
	.section	.gcc_except_table,"w"
LLSDA1001:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1001-LLSDACSB1001
LLSDACSB1001:
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 0x1
	.uleb128 0x0
	.uleb128 0x2
	.uleb128 0x0
	.uleb128 0x3
	.uleb128 0x0
	.uleb128 0x4
	.uleb128 0x0
LLSDACSE1001:
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
	jne	L36
	cmpl	$65535, 12(%ebp)
	jne	L36
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L36:
	leave
	ret
	.def	__GLOBAL__I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__I_main:
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
	.long	__GLOBAL__I_main
	.def	__ZNSsC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode;	.scl	2;	.type	32;	.endef
	.def	__ZNSspLERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt9basic_iosIcSt11char_traitsIcEEcvPvEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt14basic_ifstreamIcSt11char_traitsIcEE5closeEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1EPKcRKSaIcE;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsixEj;	.scl	2;	.type	32;	.endef
	.def	__ZNSspLEc;	.scl	2;	.type	32;	.endef
	.def	__ZNKSs6lengthEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
