	.file	"bfinterpreter.cpp"
.lcomm __ZStL8__ioinit,1,1
	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.section	.text$_ZN11Interpreter11interpreterC1Ev,"x"
	.linkonce discard
	.align 2
.globl __ZN11Interpreter11interpreterC1Ev
	.def	__ZN11Interpreter11interpreterC1Ev;	.scl	2;	.type	32;	.endef
__ZN11Interpreter11interpreterC1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$108, %esp
	movl	$___gxx_personality_sj0, -52(%ebp)
	movl	$LLSDA1004, -48(%ebp)
	leal	-44(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L5, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -72(%ebp)
	call	__ZNSsC1Ev
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	movl	$2, -72(%ebp)
	call	__ZNSsC1Ev
	movl	8(%ebp), %eax
	addl	$32780, %eax
	movl	%eax, (%esp)
	movl	$1, -72(%ebp)
	call	__ZNSsC1Ev
	jmp	L6
L5:
	leal	24(%ebp), %ebp
	movl	-72(%ebp), %ecx
	movl	-68(%ebp), %eax
	movl	-64(%ebp), %edx
	cmpl	$1, %ecx
	je	L3
L2:
	movl	%edx, -88(%ebp)
	movl	%eax, -92(%ebp)
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	movl	$0, -72(%ebp)
	call	__ZNSsD1Ev
	movl	-92(%ebp), %eax
	movl	-88(%ebp), %edx
L3:
	movl	%edx, -80(%ebp)
	movl	%eax, -84(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -72(%ebp)
	call	__ZNSsD1Ev
	movl	-84(%ebp), %eax
	movl	-80(%ebp), %edx
	movl	%eax, (%esp)
	movl	$-1, -72(%ebp)
	call	__Unwind_SjLj_Resume
L1:
L6:
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	addl	$108, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA1004:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1004-LLSDACSB1004
LLSDACSB1004:
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 0x1
	.uleb128 0x0
LLSDACSE1004:
	.section	.text$_ZN11Interpreter11interpreterC1Ev,"x"
	.linkonce discard
	.section	.text$_ZN11Interpreter11interpreterD1Ev,"x"
	.linkonce discard
	.align 2
.globl __ZN11Interpreter11interpreterD1Ev
	.def	__ZN11Interpreter11interpreterD1Ev;	.scl	2;	.type	32;	.endef
__ZN11Interpreter11interpreterD1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$108, %esp
	movl	$___gxx_personality_sj0, -52(%ebp)
	movl	$LLSDA1007, -48(%ebp)
	leal	-44(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L13, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	8(%ebp), %eax
	addl	$32780, %eax
	movl	%eax, (%esp)
	movl	$1, -72(%ebp)
	call	__ZNSsD1Ev
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	movl	$2, -72(%ebp)
	call	__ZNSsD1Ev
	jmp	L14
L13:
	leal	24(%ebp), %ebp
	movl	-72(%ebp), %ecx
	movl	-68(%ebp), %eax
	movl	-64(%ebp), %edx
	cmpl	$1, %ecx
	je	L11
L9:
	movl	%edx, -88(%ebp)
	movl	%eax, -92(%ebp)
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, (%esp)
	movl	$0, -72(%ebp)
	call	__ZNSsD1Ev
	movl	-92(%ebp), %eax
	movl	-88(%ebp), %edx
	jmp	L11
L14:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -72(%ebp)
	call	__ZNSsD1Ev
L7:
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	addl	$108, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L11:
	movl	%edx, -80(%ebp)
	movl	%eax, -84(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -72(%ebp)
	call	__ZNSsD1Ev
	movl	-84(%ebp), %eax
	movl	-80(%ebp), %edx
	movl	%eax, (%esp)
	movl	$-1, -72(%ebp)
	call	__Unwind_SjLj_Resume
	.section	.gcc_except_table,"w"
LLSDA1007:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1007-LLSDACSB1007
LLSDACSB1007:
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 0x1
	.uleb128 0x0
LLSDACSE1007:
	.section	.text$_ZN11Interpreter11interpreterD1Ev,"x"
	.linkonce discard
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Input: \0"
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
	movl	$33224, %eax
	call	___chkstk
	movl	%ecx, -33224(%ebp)
	movl	$___gxx_personality_sj0, -33124(%ebp)
	movl	$LLSDA1001, -33120(%ebp)
	leal	-33116(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L34, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-33148(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	call	___main
	leal	-33096(%ebp), %eax
	movl	$32788, %edx
	movl	%edx, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	_memset
	leal	-33096(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -33144(%ebp)
	call	__ZN11Interpreter11interpreterC1Ev
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	movl	$8, -33144(%ebp)
	call	__ZNSsC1Ev
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	movl	$7, -33144(%ebp)
	call	__ZNSsC1Ev
	movl	-33224(%ebp), %edx
	movl	4(%edx), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	$8, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-308(%ebp), %eax
	movl	%eax, (%esp)
	movl	$6, -33144(%ebp)
	call	__ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
	jmp	L16
L17:
	leal	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	movl	$5, -33144(%ebp)
	call	__ZNSspLERKSs
L16:
	leal	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-308(%ebp), %eax
	movl	%eax, (%esp)
	movl	$5, -33144(%ebp)
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
	jne	L17
	leal	-308(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt14basic_ifstreamIcSt11char_traitsIcEE5closeEv
	leal	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1ERKSs
	leal	-40(%ebp), %eax
	leal	-36(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-33096(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	movl	$4, -33144(%ebp)
	call	__ZN11Interpreter11interpreter5icodeESs
	subl	$4, %esp
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	movl	$5, -33144(%ebp)
	call	__ZNSsD1Ev
	jmp	L35
L19:
	movl	%edx, -33208(%ebp)
	movl	%eax, -33212(%ebp)
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -33144(%ebp)
	call	__ZNSsD1Ev
	movl	-33212(%ebp), %eax
	movl	-33208(%ebp), %edx
	jmp	L27
L35:
	leal	-33096(%ebp), %eax
	movl	%eax, (%esp)
	movl	$5, -33144(%ebp)
	call	__ZN11Interpreter11interpreter6qinputEv
	testb	%al, %al
	je	L20
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1Ev
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$3, -33144(%ebp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1ERKSs
	leal	-32(%ebp), %eax
	leal	-28(%ebp), %edx
	movl	%edx, 8(%esp)
	leal	-33096(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	movl	$2, -33144(%ebp)
	call	__ZN11Interpreter11interpreter5inputESs
	subl	$4, %esp
	leal	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	$3, -33144(%ebp)
	call	__ZNSsD1Ev
	jmp	L36
L22:
	movl	%edx, -33200(%ebp)
	movl	%eax, -33204(%ebp)
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -33144(%ebp)
	call	__ZNSsD1Ev
	movl	-33204(%ebp), %eax
	movl	-33200(%ebp), %edx
	jmp	L23
L36:
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$5, -33144(%ebp)
	call	__ZNSsD1Ev
	jmp	L20
L23:
	movl	%edx, -33192(%ebp)
	movl	%eax, -33196(%ebp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -33144(%ebp)
	call	__ZNSsD1Ev
	movl	-33196(%ebp), %eax
	movl	-33192(%ebp), %edx
	jmp	L27
L20:
	leal	-52(%ebp), %eax
	leal	-33096(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	movl	$5, -33144(%ebp)
	call	__ZN11Interpreter11interpreter9interpretEv
	subl	$4, %esp
	leal	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$1, -33144(%ebp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$0, -33216(%ebp)
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	movl	$5, -33144(%ebp)
	call	__ZNSsD1Ev
	jmp	L37
L34:
	leal	24(%ebp), %ebp
	movl	-33144(%ebp), %ecx
	movl	-33140(%ebp), %eax
	movl	-33136(%ebp), %edx
	cmpl	$1, %ecx
	je	L22
	cmpl	$2, %ecx
	je	L23
	cmpl	$3, %ecx
	je	L19
	cmpl	$4, %ecx
	je	L27
	cmpl	$5, %ecx
	je	L29
	cmpl	$6, %ecx
	je	L31
	cmpl	$7, %ecx
	je	L32
L25:
	movl	%edx, -33184(%ebp)
	movl	%eax, -33188(%ebp)
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -33144(%ebp)
	call	__ZNSsD1Ev
	movl	-33188(%ebp), %eax
	movl	-33184(%ebp), %edx
	jmp	L27
L37:
	leal	-308(%ebp), %eax
	movl	%eax, (%esp)
	movl	$6, -33144(%ebp)
	call	__ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
	jmp	L38
L27:
	movl	%edx, -33176(%ebp)
	movl	%eax, -33180(%ebp)
	leal	-308(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -33144(%ebp)
	call	__ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
	movl	-33180(%ebp), %eax
	movl	-33176(%ebp), %edx
	jmp	L29
L38:
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	movl	$7, -33144(%ebp)
	call	__ZNSsD1Ev
	jmp	L39
L29:
	movl	%edx, -33168(%ebp)
	movl	%eax, -33172(%ebp)
	leal	-48(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -33144(%ebp)
	call	__ZNSsD1Ev
	movl	-33172(%ebp), %eax
	movl	-33168(%ebp), %edx
	jmp	L31
L39:
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	movl	$8, -33144(%ebp)
	call	__ZNSsD1Ev
	jmp	L40
L31:
	movl	%edx, -33160(%ebp)
	movl	%eax, -33164(%ebp)
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -33144(%ebp)
	call	__ZNSsD1Ev
	movl	-33164(%ebp), %eax
	movl	-33160(%ebp), %edx
	jmp	L32
L40:
	leal	-33096(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -33144(%ebp)
	call	__ZN11Interpreter11interpreterD1Ev
	movl	-33216(%ebp), %eax
	movl	%eax, -33220(%ebp)
L15:
	leal	-33148(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	-33220(%ebp), %eax
	leal	-16(%ebp), %esp
	addl	$0, %esp
	popl	%ecx
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
L32:
	movl	%edx, -33152(%ebp)
	movl	%eax, -33156(%ebp)
	leal	-33096(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -33144(%ebp)
	call	__ZN11Interpreter11interpreterD1Ev
	movl	-33156(%ebp), %eax
	movl	-33152(%ebp), %edx
	movl	%eax, (%esp)
	movl	$-1, -33144(%ebp)
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
	.uleb128 0x5
	.uleb128 0x0
	.uleb128 0x6
	.uleb128 0x0
	.uleb128 0x7
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
	jne	L45
	cmpl	$65535, 12(%ebp)
	jne	L45
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L45:
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
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	__ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode;	.scl	2;	.type	32;	.endef
	.def	__ZNSspLERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt9basic_iosIcSt11char_traitsIcEEcvPvEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt14basic_ifstreamIcSt11char_traitsIcEE5closeEv;	.scl	2;	.type	32;	.endef
	.def	__ZN11Interpreter11interpreter5icodeESs;	.scl	2;	.type	32;	.endef
	.def	__ZN11Interpreter11interpreter6qinputEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1ERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZN11Interpreter11interpreter5inputESs;	.scl	2;	.type	32;	.endef
	.def	__ZN11Interpreter11interpreter9interpretEv;	.scl	2;	.type	32;	.endef
	.def	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
