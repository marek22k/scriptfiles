	.file	"caesarcrypt.cpp"
	.section	.text$_ZNSt11char_traitsIcE7compareEPKcS2_j,"x"
	.linkonce discard
	.globl	__ZNSt11char_traitsIcE7compareEPKcS2_j
	.def	__ZNSt11char_traitsIcE7compareEPKcS2_j;	.scl	2;	.type	32;	.endef
__ZNSt11char_traitsIcE7compareEPKcS2_j:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_memcmp
	leave
	ret
	.section	.text$_ZStorSt13_Ios_OpenmodeS_,"x"
	.linkonce discard
	.globl	__ZStorSt13_Ios_OpenmodeS_
	.def	__ZStorSt13_Ios_OpenmodeS_;	.scl	2;	.type	32;	.endef
__ZStorSt13_Ios_OpenmodeS_:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	orl	%edx, %eax
	popl	%ebp
	ret
.lcomm __ZStL8__ioinit,1,1
	.section .rdata,"dr"
LC0:
	.ascii "Key: \0"
LC1:
	.ascii "Text: \0"
LC2:
	.ascii "; Result: \0"
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.text
	.globl	__Z7encryptv
	.def	__Z7encryptv;	.scl	2;	.type	32;	.endef
__Z7encryptv:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$300, %esp
	movl	$___gxx_personality_sj0, -260(%ebp)
	movl	$LLSDA1048, -256(%ebp)
	leal	-252(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L23, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-284(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	$0, -28(%ebp)
	leal	-180(%ebp), %eax
	movl	$-1, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	leal	-204(%ebp), %eax
	movl	$1, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$2, -280(%ebp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZSt3cin, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-180(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movl	$0, -32(%ebp)
L7:
	cmpl	$25, -32(%ebp)
	jg	L6
	movl	-32(%ebp), %eax
	addl	$97, %eax
	movl	%eax, %ecx
	leal	-126(%ebp), %edx
	movl	-32(%ebp), %eax
	addl	%edx, %eax
	movb	%cl, (%eax)
	addl	$1, -32(%ebp)
	jmp	L7
L6:
	movl	$0, -36(%ebp)
L10:
	cmpl	$25, -36(%ebp)
	jg	L8
	movl	-36(%ebp), %eax
	movl	%eax, %edx
	movl	-156(%ebp), %eax
	addl	%edx, %eax
	addl	$97, %eax
	movb	%al, -49(%ebp)
	cmpb	$122, -49(%ebp)
	jle	L9
	movl	-36(%ebp), %eax
	movl	%eax, -28(%ebp)
	jmp	L8
L9:
	leal	-152(%ebp), %edx
	movl	-36(%ebp), %eax
	addl	%eax, %edx
	movzbl	-49(%ebp), %eax
	movb	%al, (%edx)
	addl	$1, -36(%ebp)
	jmp	L10
L8:
	movl	-28(%ebp), %eax
	movl	%eax, -40(%ebp)
L12:
	cmpl	$25, -40(%ebp)
	jg	L11
	movl	-40(%ebp), %eax
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	addl	$97, %eax
	movl	%eax, %ecx
	leal	-152(%ebp), %edx
	movl	-40(%ebp), %eax
	addl	%edx, %eax
	movb	%cl, (%eax)
	addl	$1, -40(%ebp)
	jmp	L12
L11:
	movl	$0, -44(%ebp)
L17:
	leal	-180(%ebp), %eax
	movl	$2, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv
	movl	%eax, %edx
	movl	-44(%ebp), %eax
	cmpl	%eax, %edx
	seta	%al
	testb	%al, %al
	je	L13
	movl	-44(%ebp), %edx
	leal	-228(%ebp), %eax
	movl	$1, 8(%esp)
	movl	%edx, 4(%esp)
	leal	-180(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6substrEjj
	subl	$12, %esp
	movl	$0, -48(%ebp)
L16:
	cmpl	$25, -48(%ebp)
	jg	L14
	leal	-126(%ebp), %edx
	movl	-48(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	leal	-100(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	movl	$3, -280(%ebp)
	call	__Z8toStringIcENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_
	leal	-100(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-228(%ebp), %eax
	movl	%eax, (%esp)
	movl	$4, -280(%ebp)
	call	__ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKNSt7__cxx1112basic_stringIS3_St11char_traitsIS3_ESaIS3_EEESE_
	movb	%al, -288(%ebp)
	leal	-100(%ebp), %eax
	movl	$3, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	cmpb	$0, -288(%ebp)
	je	L15
	leal	-152(%ebp), %edx
	movl	-48(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	leal	-76(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z8toStringIcENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_
	leal	-204(%ebp), %eax
	leal	-76(%ebp), %edx
	movl	%edx, (%esp)
	movl	$5, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLERKS4_
	subl	$4, %esp
	leal	-76(%ebp), %eax
	movl	$3, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
L15:
	addl	$1, -48(%ebp)
	jmp	L16
L14:
	leal	-228(%ebp), %eax
	movl	$2, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	addl	$1, -44(%ebp)
	jmp	L17
L13:
	movl	-156(%ebp), %eax
	movl	%eax, -288(%ebp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$2, -280(%ebp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	-288(%ebp), %esi
	movl	%esi, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	leal	-204(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	leal	-204(%ebp), %eax
	movl	$1, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	leal	-180(%ebp), %eax
	movl	$-1, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	L29
L27:
	movl	%edx, -288(%ebp)
	leal	-100(%ebp), %eax
	movl	$0, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-288(%ebp), %eax
	movl	%eax, -288(%ebp)
	jmp	L19
L28:
	movl	%edx, -288(%ebp)
	leal	-76(%ebp), %eax
	movl	$0, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-288(%ebp), %eax
	movl	%eax, -288(%ebp)
	jmp	L19
L26:
	movl	%edx, -288(%ebp)
L19:
	leal	-228(%ebp), %eax
	movl	$0, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-288(%ebp), %eax
	movl	%eax, -288(%ebp)
	jmp	L21
L25:
	movl	%edx, -288(%ebp)
L21:
	leal	-204(%ebp), %eax
	movl	$0, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-288(%ebp), %eax
	movl	%eax, -288(%ebp)
	jmp	L22
L23:
	leal	24(%ebp), %ebp
	movl	-276(%ebp), %edx
	movl	-280(%ebp), %eax
	testl	%eax, %eax
	je	L24
	subl	$1, %eax
	testl	%eax, %eax
	je	L25
	subl	$1, %eax
	testl	%eax, %eax
	je	L26
	subl	$1, %eax
	testl	%eax, %eax
	je	L27
	subl	$1, %eax
	testl	%eax, %eax
	je	L28
	subl	$1, %eax
	ud2
L24:
	movl	%edx, -288(%ebp)
L22:
	leal	-180(%ebp), %eax
	movl	$0, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-288(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -280(%ebp)
	call	__Unwind_SjLj_Resume
L29:
	leal	-284(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA1048:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1048-LLSDACSB1048
LLSDACSB1048:
	.uleb128 0
	.uleb128 0
	.uleb128 0x1
	.uleb128 0
	.uleb128 0x2
	.uleb128 0
	.uleb128 0x3
	.uleb128 0
	.uleb128 0x4
	.uleb128 0
LLSDACSE1048:
	.text
	.section .rdata,"dr"
LC3:
	.ascii "Key: 0\0"
	.text
	.globl	__Z7decryptiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.def	__Z7decryptiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE;	.scl	2;	.type	32;	.endef
__Z7decryptiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$300, %esp
	movl	$___gxx_personality_sj0, -260(%ebp)
	movl	$LLSDA1049, -256(%ebp)
	leal	-252(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L50, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-284(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	$0, -28(%ebp)
	leal	-200(%ebp), %eax
	movl	$-1, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	movl	$0, -32(%ebp)
L32:
	cmpl	$25, -32(%ebp)
	jg	L31
	movl	-32(%ebp), %eax
	addl	$97, %eax
	movl	%eax, %ecx
	leal	-150(%ebp), %edx
	movl	-32(%ebp), %eax
	addl	%edx, %eax
	movb	%cl, (%eax)
	addl	$1, -32(%ebp)
	jmp	L32
L31:
	movl	$0, -36(%ebp)
L35:
	cmpl	$25, -36(%ebp)
	jg	L33
	movl	-36(%ebp), %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	addl	$97, %eax
	movb	%al, -49(%ebp)
	cmpb	$122, -49(%ebp)
	jle	L34
	movl	-36(%ebp), %eax
	movl	%eax, -28(%ebp)
	jmp	L33
L34:
	leal	-176(%ebp), %edx
	movl	-36(%ebp), %eax
	addl	%eax, %edx
	movzbl	-49(%ebp), %eax
	movb	%al, (%edx)
	addl	$1, -36(%ebp)
	jmp	L35
L33:
	movl	-28(%ebp), %eax
	movl	%eax, -40(%ebp)
L37:
	cmpl	$25, -40(%ebp)
	jg	L36
	movl	-40(%ebp), %eax
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	addl	$97, %eax
	movl	%eax, %ecx
	leal	-176(%ebp), %edx
	movl	-40(%ebp), %eax
	addl	%edx, %eax
	movb	%cl, (%eax)
	addl	$1, -40(%ebp)
	jmp	L37
L36:
	movl	$0, -44(%ebp)
L42:
	movl	12(%ebp), %eax
	movl	$1, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv
	movl	%eax, %edx
	movl	-44(%ebp), %eax
	cmpl	%eax, %edx
	seta	%al
	testb	%al, %al
	je	L38
	movl	-44(%ebp), %edx
	leal	-224(%ebp), %eax
	movl	$1, 8(%esp)
	movl	%edx, 4(%esp)
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6substrEjj
	subl	$12, %esp
	movl	$0, -48(%ebp)
L41:
	cmpl	$25, -48(%ebp)
	jg	L39
	leal	-176(%ebp), %edx
	movl	-48(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	leal	-124(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	movl	$2, -280(%ebp)
	call	__Z8toStringIcENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_
	leal	-124(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-224(%ebp), %eax
	movl	%eax, (%esp)
	movl	$3, -280(%ebp)
	call	__ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKNSt7__cxx1112basic_stringIS3_St11char_traitsIS3_ESaIS3_EEESE_
	movb	%al, -288(%ebp)
	leal	-124(%ebp), %eax
	movl	$2, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	cmpb	$0, -288(%ebp)
	je	L40
	leal	-150(%ebp), %edx
	movl	-48(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %edx
	leal	-100(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__Z8toStringIcENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_
	leal	-200(%ebp), %eax
	leal	-100(%ebp), %edx
	movl	%edx, (%esp)
	movl	$4, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLERKS4_
	subl	$4, %esp
	leal	-100(%ebp), %eax
	movl	$2, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
L40:
	addl	$1, -48(%ebp)
	jmp	L41
L39:
	leal	-224(%ebp), %eax
	movl	$1, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	addl	$1, -44(%ebp)
	jmp	L42
L38:
	leal	-76(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	movl	$1, -280(%ebp)
	call	__Z8toStringIiENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_
	leal	-76(%ebp), %eax
	movl	$5, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv
	cmpl	$1, %eax
	sete	-288(%ebp)
	leal	-76(%ebp), %eax
	movl	$1, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	cmpb	$0, -288(%ebp)
	je	L43
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	leal	-200(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	jmp	L44
L43:
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$1, -280(%ebp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	leal	-200(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
L44:
	leal	-200(%ebp), %eax
	movl	$-1, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	L56
L53:
	movl	%edx, -288(%ebp)
	leal	-124(%ebp), %eax
	movl	$0, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-288(%ebp), %eax
	movl	%eax, -288(%ebp)
	jmp	L46
L54:
	movl	%edx, -288(%ebp)
	leal	-100(%ebp), %eax
	movl	$0, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-288(%ebp), %eax
	movl	%eax, -288(%ebp)
	jmp	L46
L52:
	movl	%edx, -288(%ebp)
L46:
	leal	-224(%ebp), %eax
	movl	$0, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-288(%ebp), %eax
	movl	%eax, -288(%ebp)
	jmp	L48
L55:
	movl	%edx, -288(%ebp)
	leal	-76(%ebp), %eax
	movl	$0, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-288(%ebp), %eax
	movl	%eax, -288(%ebp)
	jmp	L48
L50:
	leal	24(%ebp), %ebp
	movl	-276(%ebp), %edx
	movl	-280(%ebp), %eax
	testl	%eax, %eax
	je	L51
	subl	$1, %eax
	testl	%eax, %eax
	je	L52
	subl	$1, %eax
	testl	%eax, %eax
	je	L53
	subl	$1, %eax
	testl	%eax, %eax
	je	L54
	subl	$1, %eax
	testl	%eax, %eax
	je	L55
	subl	$1, %eax
	ud2
L51:
	movl	%edx, -288(%ebp)
L48:
	leal	-200(%ebp), %eax
	movl	$0, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-288(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -280(%ebp)
	call	__Unwind_SjLj_Resume
L56:
	leal	-284(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA1049:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1049-LLSDACSB1049
LLSDACSB1049:
	.uleb128 0
	.uleb128 0
	.uleb128 0x1
	.uleb128 0
	.uleb128 0x2
	.uleb128 0
	.uleb128 0x3
	.uleb128 0
	.uleb128 0x4
	.uleb128 0
LLSDACSE1049:
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC4:
	.ascii "The developer of the program is Marek K.; The program uses Caesar cipher.\0"
	.align 4
LC5:
	.ascii "Enter \"encrypt\" or \"decrypt\": \0"
LC6:
	.ascii "encrypt\0"
LC7:
	.ascii "decrypt\0"
LC8:
	.ascii "Error: Invalid input\0"
	.text
	.globl	_main
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
	subl	$168, %esp
	movl	$___gxx_personality_sj0, -132(%ebp)
	movl	$LLSDA1050, -128(%ebp)
	leal	-124(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L67, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	call	___main
	movl	$LC4, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$-1, -152(%ebp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	movl	$LC5, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-76(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	leal	-76(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	movl	$1, -152(%ebp)
	call	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movl	$LC6, 4(%esp)
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	testb	%al, %al
	je	L58
	call	__Z7encryptv
	jmp	L59
L58:
	movl	$LC7, 4(%esp)
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -152(%ebp)
	call	__ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	testb	%al, %al
	je	L60
	leal	-100(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$2, -152(%ebp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-100(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movl	$0, -28(%ebp)
L62:
	cmpl	$25, -28(%ebp)
	jg	L61
	leal	-52(%ebp), %eax
	leal	-100(%ebp), %edx
	movl	%edx, (%esp)
	movl	$2, -152(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_
	subl	$4, %esp
	leal	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	$3, -152(%ebp)
	call	__Z7decryptiNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	leal	-52(%ebp), %eax
	movl	$2, -152(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	addl	$1, -28(%ebp)
	jmp	L62
L61:
	leal	-100(%ebp), %eax
	movl	$1, -152(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	L59
L60:
	movl	$LC8, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$1, -152(%ebp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
L59:
	movl	$0, -160(%ebp)
	leal	-76(%ebp), %eax
	movl	$-1, -152(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-160(%ebp), %eax
	movl	%eax, -160(%ebp)
	jmp	L71
L70:
	movl	%edx, -160(%ebp)
	leal	-52(%ebp), %eax
	movl	$0, -152(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-160(%ebp), %eax
	movl	%eax, -160(%ebp)
	jmp	L65
L69:
	movl	%edx, -160(%ebp)
L65:
	leal	-100(%ebp), %eax
	movl	$0, -152(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-160(%ebp), %eax
	movl	%eax, -160(%ebp)
	jmp	L66
L67:
	leal	24(%ebp), %ebp
	movl	-148(%ebp), %edx
	movl	-152(%ebp), %eax
	testl	%eax, %eax
	je	L68
	subl	$1, %eax
	testl	%eax, %eax
	je	L69
	subl	$1, %eax
	testl	%eax, %eax
	je	L70
	subl	$1, %eax
	ud2
L68:
	movl	%edx, -160(%ebp)
L66:
	leal	-76(%ebp), %eax
	movl	$0, -152(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movl	-160(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -152(%ebp)
	call	__Unwind_SjLj_Resume
L71:
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	-160(%ebp), %eax
	leal	-16(%ebp), %esp
	popl	%ecx
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.section	.gcc_except_table,"w"
LLSDA1050:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1050-LLSDACSB1050
LLSDACSB1050:
	.uleb128 0
	.uleb128 0
	.uleb128 0x1
	.uleb128 0
	.uleb128 0x2
	.uleb128 0
LLSDACSE1050:
	.text
	.section	.text$_Z8toStringIcENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_,"x"
	.linkonce discard
	.globl	__Z8toStringIcENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_
	.def	__Z8toStringIcENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_;	.scl	2;	.type	32;	.endef
__Z8toStringIcENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$300, %esp
	movl	12(%ebp), %eax
	movb	%al, -236(%ebp)
	movl	$___gxx_personality_sj0, -264(%ebp)
	movl	$LLSDA1066, -260(%ebp)
	leal	-256(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L75, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-288(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	$8, 4(%esp)
	movl	$16, (%esp)
	call	__ZStorSt13_Ios_OpenmodeS_
	movl	%eax, %edx
	leal	-232(%ebp), %eax
	movl	%edx, (%esp)
	movl	$-1, -284(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEEC1ESt13_Ios_Openmode
	subl	$4, %esp
	movsbl	-236(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-232(%ebp), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
	movl	$1, -284(%ebp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movl	8(%ebp), %eax
	leal	-232(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEE3strEv
	subl	$4, %esp
	leal	-232(%ebp), %eax
	movl	$-1, -284(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev
	jmp	L77
L75:
	leal	24(%ebp), %ebp
	movl	-280(%ebp), %eax
	movl	%eax, -292(%ebp)
	leal	-232(%ebp), %eax
	movl	$0, -284(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev
	movl	-292(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -284(%ebp)
	call	__Unwind_SjLj_Resume
L77:
	leal	-288(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	8(%ebp), %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA1066:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1066-LLSDACSB1066
LLSDACSB1066:
	.uleb128 0
	.uleb128 0
LLSDACSE1066:
	.section	.text$_Z8toStringIcENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_,"x"
	.linkonce discard
	.section	.text$_ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKNSt7__cxx1112basic_stringIS3_St11char_traitsIS3_ESaIS3_EEESE_,"x"
	.linkonce discard
	.globl	__ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKNSt7__cxx1112basic_stringIS3_St11char_traitsIS3_ESaIS3_EEESE_
	.def	__ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKNSt7__cxx1112basic_stringIS3_St11char_traitsIS3_ESaIS3_EEESE_;	.scl	2;	.type	32;	.endef
__ZSteqIcEN9__gnu_cxx11__enable_ifIXsrSt9__is_charIT_E7__valueEbE6__typeERKNSt7__cxx1112basic_stringIS3_St11char_traitsIS3_ESaIS3_EEESE_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	movl	8(%ebp), %ecx
	call	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv
	cmpl	%eax, %ebx
	jne	L79
	movl	8(%ebp), %ecx
	call	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4dataEv
	movl	%eax, %ebx
	movl	8(%ebp), %ecx
	call	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4dataEv
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt11char_traitsIcE7compareEPKcS2_j
	testl	%eax, %eax
	jne	L79
	movl	$1, %eax
	jmp	L81
L79:
	movl	$0, %eax
L81:
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.section	.text$_Z8toStringIiENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_,"x"
	.linkonce discard
	.globl	__Z8toStringIiENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_
	.def	__Z8toStringIiENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_;	.scl	2;	.type	32;	.endef
__Z8toStringIiENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$300, %esp
	movl	$___gxx_personality_sj0, -260(%ebp)
	movl	$LLSDA1072, -256(%ebp)
	leal	-252(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L85, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-284(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	$8, 4(%esp)
	movl	$16, (%esp)
	call	__ZStorSt13_Ios_OpenmodeS_
	movl	%eax, %edx
	leal	-232(%ebp), %eax
	movl	%edx, (%esp)
	movl	$-1, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEEC1ESt13_Ios_Openmode
	subl	$4, %esp
	leal	-232(%ebp), %eax
	leal	8(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -280(%ebp)
	movl	%edx, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	8(%ebp), %eax
	leal	-232(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEE3strEv
	subl	$4, %esp
	leal	-232(%ebp), %eax
	movl	$-1, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev
	jmp	L87
L85:
	leal	24(%ebp), %ebp
	movl	-276(%ebp), %eax
	movl	%eax, -288(%ebp)
	leal	-232(%ebp), %eax
	movl	$0, -280(%ebp)
	movl	%eax, %ecx
	call	__ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev
	movl	-288(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -280(%ebp)
	call	__Unwind_SjLj_Resume
L87:
	leal	-284(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	8(%ebp), %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA1072:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1072-LLSDACSB1072
LLSDACSB1072:
	.uleb128 0
	.uleb128 0
LLSDACSE1072:
	.section	.text$_Z8toStringIiENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEET_,"x"
	.linkonce discard
	.section	.text$_ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_,"x"
	.linkonce discard
	.globl	__ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_
	.def	__ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_;	.scl	2;	.type	32;	.endef
__ZSteqIcSt11char_traitsIcESaIcEEbRKNSt7__cxx1112basic_stringIT_T0_T1_EEPKS5_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7compareEPKc
	subl	$4, %esp
	testl	%eax, %eax
	sete	%al
	leave
	ret
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	ret
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L93
	cmpl	$65535, 12(%ebp)
	jne	L93
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L93:
	nop
	leave
	ret
	.def	__GLOBAL__sub_I__Z7encryptv;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z7encryptv:
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
	.long	__GLOBAL__sub_I__Z7encryptv
	.ident	"GCC: (tdm-1) 5.1.0"
	.def	_memcmp;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6lengthEv;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6substrEjj;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLERKS4_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEEC1ESt13_Ios_Openmode;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEE3strEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4dataEv;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7compareEPKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
