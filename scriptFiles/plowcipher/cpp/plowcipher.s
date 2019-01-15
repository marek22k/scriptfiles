	.file	"plowcipher.cpp"
.lcomm __ZStL8__ioinit,1,1
	.text
.globl __Z14zufallsZeichenSs
	.def	__Z14zufallsZeichenSs;	.scl	2;	.type	32;	.endef
__Z14zufallsZeichenSs:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$36, %esp
	movl	8(%ebp), %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSs6lengthEv
	movl	%eax, -16(%ebp)
	call	_rand
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	-16(%ebp)
	movl	%edx, -12(%ebp)
	movl	%ebx, %eax
	movl	-12(%ebp), %edx
	movl	$1, 12(%esp)
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNKSs6substrEjj
	subl	$4, %esp
	movl	%ebx, %eax
	movl	%ebx, %eax
	movl	-4(%ebp), %ebx
	leave
	ret	$4
	.section .rdata,"dr"
LC0:
	.ascii "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0"
LC1:
	.ascii "Key: \0"
LC2:
	.ascii "; Result: \0"
	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.text
.globl __Z7encryptSsi
	.def	__Z7encryptSsi;	.scl	2;	.type	32;	.endef
__Z7encryptSsi:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	subl	$376, %esp
	leal	8(%ebp), %ecx
	movl	%ecx, -372(%ebp)
	movl	$___gxx_personality_sj0, -116(%ebp)
	movl	$LLSDA943, -112(%ebp)
	leal	-108(%ebp), %edx
	leal	-24(%ebp), %eax
	movl	%eax, (%edx)
	movl	$L43, %eax
	movl	%eax, 4(%edx)
	movl	%esp, 8(%edx)
	leal	-140(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	%esp, %eax
	movl	%eax, -224(%ebp)
	movl	-372(%ebp), %edx
	movl	(%edx), %eax
	movl	%eax, (%esp)
	movl	$8, -136(%ebp)
	call	__ZNKSs6lengthEv
	movl	%eax, -56(%ebp)
	movl	-372(%ebp), %ecx
	movl	4(%ecx), %eax
	movl	%eax, -52(%ebp)
	movl	-56(%ebp), %eax
	movl	-372(%ebp), %esi
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	4(%esi)
	movl	%eax, -48(%ebp)
	jmp	L4
L11:
	leal	-73(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-73(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC0, 4(%esp)
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	movl	$7, -136(%ebp)
	call	__ZNSsC1EPKcRKSaIcE
	leal	-84(%ebp), %edx
	leal	-80(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	$6, -136(%ebp)
	call	__Z14zufallsZeichenSs
	subl	$4, %esp
	leal	-84(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-372(%ebp), %edx
	movl	(%edx), %eax
	movl	%eax, (%esp)
	movl	$5, -136(%ebp)
	call	__ZNSspLERKSs
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	movl	$6, -136(%ebp)
	call	__ZNSsD1Ev
	jmp	L44
L6:
	movl	%eax, -204(%ebp)
	movl	%edx, -208(%ebp)
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -136(%ebp)
	call	__ZNSsD1Ev
	movl	-208(%ebp), %edx
	movl	-204(%ebp), %eax
	jmp	L8
L44:
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	movl	$7, -136(%ebp)
	call	__ZNSsD1Ev
	jmp	L45
L8:
	movl	%eax, -196(%ebp)
	movl	%edx, -200(%ebp)
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -136(%ebp)
	call	__ZNSsD1Ev
	movl	-200(%ebp), %edx
	movl	-196(%ebp), %eax
	jmp	L10
L45:
	leal	-73(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	-372(%ebp), %ecx
	movl	(%ecx), %eax
	movl	%eax, (%esp)
	movl	$8, -136(%ebp)
	call	__ZNKSs6lengthEv
	movl	%eax, -56(%ebp)
	movl	-56(%ebp), %eax
	movl	-372(%ebp), %esi
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	4(%esi)
	movl	%eax, -48(%ebp)
	jmp	L4
L10:
	movl	%eax, -188(%ebp)
	movl	%edx, -192(%ebp)
	leal	-73(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	-192(%ebp), %edx
	movl	-188(%ebp), %eax
	jmp	L41
L4:
	movl	-56(%ebp), %eax
	movl	-372(%ebp), %ecx
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	4(%ecx)
	movl	%edx, %eax
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	jne	L11
	movl	-52(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -260(%ebp)
	movl	-260(%ebp), %esi
	movl	%esi, -72(%ebp)
	movl	-260(%ebp), %eax
	movl	$0, %edx
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -272(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -268(%ebp)
	movl	-272(%ebp), %eax
	movl	-268(%ebp), %edx
	addl	$1, %eax
	adcl	$0, %edx
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -280(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -276(%ebp)
	movl	-280(%ebp), %eax
	movl	-276(%ebp), %edx
	shldl	$5, %eax, %edx
	sall	$5, %eax
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -288(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -284(%ebp)
	movl	-288(%ebp), %eax
	movl	-284(%ebp), %edx
	movl	-260(%ebp), %eax
	addl	$1, %eax
	sall	$2, %eax
	movl	%eax, -256(%ebp)
	movl	-48(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -252(%ebp)
	movl	-252(%ebp), %eax
	movl	%eax, -68(%ebp)
	movl	-260(%ebp), %eax
	movl	$0, %edx
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -296(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -292(%ebp)
	movl	-296(%ebp), %eax
	movl	-292(%ebp), %edx
	movl	%eax, %ecx
	movl	%edx, %ebx
	addl	$1, %ecx
	adcl	$0, %ebx
	movl	%ecx, %eax
	andb	$255, %ah
	movl	%eax, -304(%ebp)
	movl	%ebx, %edx
	andl	$15, %edx
	movl	%edx, -300(%ebp)
	movl	-304(%ebp), %ecx
	movl	-300(%ebp), %ebx
	movl	-252(%ebp), %eax
	addl	$1, %eax
	movl	$0, %edx
	movl	%eax, %esi
	andl	$-1, %esi
	movl	%esi, -312(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -308(%ebp)
	movl	-312(%ebp), %eax
	movl	-308(%ebp), %edx
	movl	%ebx, %edi
	imull	%eax, %edi
	movl	%edx, %esi
	imull	%ecx, %esi
	addl	%esi, %edi
	mull	%ecx
	addl	%edx, %edi
	movl	%edi, %edx
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -320(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -316(%ebp)
	movl	-320(%ebp), %eax
	movl	-316(%ebp), %edx
	shldl	$5, %eax, %edx
	sall	$5, %eax
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -328(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -324(%ebp)
	movl	-328(%ebp), %eax
	movl	-324(%ebp), %edx
	movl	-260(%ebp), %eax
	movl	$0, %edx
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -336(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -332(%ebp)
	movl	-336(%ebp), %eax
	movl	-332(%ebp), %edx
	movl	%eax, %ecx
	movl	%edx, %ebx
	addl	$1, %ecx
	adcl	$0, %ebx
	movl	%ecx, %eax
	andb	$255, %ah
	movl	%eax, -344(%ebp)
	movl	%ebx, %edx
	andl	$15, %edx
	movl	%edx, -340(%ebp)
	movl	-344(%ebp), %ecx
	movl	-340(%ebp), %ebx
	movl	-252(%ebp), %eax
	addl	$1, %eax
	movl	$0, %edx
	movl	%eax, %esi
	andl	$-1, %esi
	movl	%esi, -352(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -348(%ebp)
	movl	-352(%ebp), %eax
	movl	-348(%ebp), %edx
	movl	%ebx, %edi
	imull	%eax, %edi
	movl	%edx, %esi
	imull	%ecx, %esi
	addl	%esi, %edi
	mull	%ecx
	addl	%edx, %edi
	movl	%edi, %edx
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -360(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -356(%ebp)
	movl	-360(%ebp), %eax
	movl	-356(%ebp), %edx
	shldl	$5, %eax, %edx
	sall	$5, %eax
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -368(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -364(%ebp)
	movl	-368(%ebp), %eax
	movl	-364(%ebp), %edx
	movl	-260(%ebp), %eax
	leal	1(%eax), %edx
	movl	-252(%ebp), %eax
	addl	$1, %eax
	imull	%edx, %eax
	sall	$2, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	call	___chkstk
	leal	16(%esp), %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	movl	%eax, -64(%ebp)
	movl	-64(%ebp), %eax
	movl	%eax, -248(%ebp)
	movl	-248(%ebp), %edx
	movl	%edx, -244(%ebp)
	movl	-252(%ebp), %ecx
	movl	%ecx, -240(%ebp)
	jmp	L12
L18:
	movl	-244(%ebp), %esi
	movl	%esi, -236(%ebp)
	movl	-236(%ebp), %eax
	movl	%eax, -232(%ebp)
	movl	-260(%ebp), %edx
	movl	%edx, -228(%ebp)
	jmp	L13
L14:
	movl	-232(%ebp), %ecx
	movl	%ecx, (%esp)
	movl	$4, -136(%ebp)
	call	__ZNSsC1Ev
	addl	$4, -232(%ebp)
	subl	$1, -228(%ebp)
L13:
	cmpl	$-1, -228(%ebp)
	setne	%al
	testb	%al, %al
	jne	L14
	movl	-260(%ebp), %eax
	addl	$1, %eax
	sall	$2, %eax
	addl	%eax, -244(%ebp)
	subl	$1, -240(%ebp)
	jmp	L12
L15:
	movl	%eax, -180(%ebp)
	movl	%edx, -184(%ebp)
	cmpl	$0, -236(%ebp)
	je	L16
	movl	-260(%ebp), %eax
	subl	-228(%ebp), %eax
	sall	$2, %eax
	movl	-236(%ebp), %esi
	addl	%eax, %esi
	movl	%esi, -220(%ebp)
L17:
	movl	-236(%ebp), %eax
	cmpl	%eax, -220(%ebp)
	je	L16
	subl	$4, -220(%ebp)
	movl	-220(%ebp), %edx
	movl	%edx, (%esp)
	movl	$0, -136(%ebp)
	call	__ZNSsD1Ev
	jmp	L17
L16:
	movl	-184(%ebp), %edx
	movl	-180(%ebp), %eax
L20:
	movl	%eax, -172(%ebp)
	movl	%edx, -176(%ebp)
	cmpl	$0, -248(%ebp)
	je	L21
	jmp	L46
L12:
	cmpl	$-1, -240(%ebp)
	setne	%al
	testb	%al, %al
	jne	L18
	movl	$0, -44(%ebp)
	movl	$0, -40(%ebp)
	jmp	L19
L46:
	movl	-248(%ebp), %ecx
	movl	-252(%ebp), %eax
	subl	-240(%ebp), %eax
	movl	%eax, %edx
	movl	-260(%ebp), %eax
	addl	$1, %eax
	imull	%edx, %eax
	sall	$2, %eax
	addl	%eax, %ecx
	movl	%ecx, -216(%ebp)
L22:
	movl	-248(%ebp), %eax
	cmpl	%eax, -216(%ebp)
	je	L21
	subl	$4, -216(%ebp)
	movl	-216(%ebp), %ecx
	movl	%ecx, (%esp)
	movl	$0, -136(%ebp)
	call	__ZNSsD1Ev
	jmp	L22
L21:
	movl	-176(%ebp), %edx
	movl	-172(%ebp), %eax
	jmp	L41
L27:
	movl	$0, -36(%ebp)
	jmp	L23
L26:
	movl	-44(%ebp), %eax
	leal	-60(%ebp), %edx
	movl	$1, 12(%esp)
	movl	%eax, 8(%esp)
	movl	-372(%ebp), %esi
	movl	(%esi), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	$3, -136(%ebp)
	call	__ZNKSs6substrEjj
	subl	$4, %esp
	movl	-256(%ebp), %ecx
	shrl	$2, %ecx
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	imull	%ecx, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, %edx
	addl	-64(%ebp), %edx
	leal	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	$2, -136(%ebp)
	call	__ZNSsaSERKSs
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	movl	$3, -136(%ebp)
	call	__ZNSsD1Ev
	jmp	L47
L25:
	movl	%eax, -164(%ebp)
	movl	%edx, -168(%ebp)
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -136(%ebp)
	call	__ZNSsD1Ev
	movl	-168(%ebp), %edx
	movl	-164(%ebp), %eax
	jmp	L37
L47:
	movl	-256(%ebp), %ecx
	shrl	$2, %ecx
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	imull	%ecx, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	-64(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$3, -136(%ebp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	addl	$1, -44(%ebp)
	addl	$1, -36(%ebp)
L23:
	movl	-36(%ebp), %eax
	cmpl	-52(%ebp), %eax
	setl	%al
	testb	%al, %al
	jne	L26
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$3, -136(%ebp)
	call	__ZNSolsEPFRSoS_E
	addl	$1, -40(%ebp)
L19:
	movl	-40(%ebp), %eax
	cmpl	-48(%ebp), %eax
	setl	%al
	testb	%al, %al
	jne	L27
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$3, -136(%ebp)
	call	__ZNSolsEPFRSoS_E
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1Ev
	subl	$1, -48(%ebp)
	subl	$1, -52(%ebp)
	movl	-52(%ebp), %eax
	movl	%eax, -32(%ebp)
	jmp	L28
L33:
	movl	-48(%ebp), %eax
	movl	%eax, -28(%ebp)
	jmp	L29
L32:
	movl	-32(%ebp), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	movl	%eax, %ecx
	shrl	$31, %ecx
	leal	(%edx,%ecx), %eax
	andl	$1, %eax
	subl	%ecx, %eax
	cmpl	$1, %eax
	je	L30
	movl	-256(%ebp), %ecx
	shrl	$2, %ecx
	movl	-28(%ebp), %eax
	movl	-32(%ebp), %edx
	imull	%ecx, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	-64(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -136(%ebp)
	call	__ZNSspLERKSs
	jmp	L31
L30:
	movl	-256(%ebp), %ecx
	shrl	$2, %ecx
	movl	-28(%ebp), %edx
	movl	-48(%ebp), %eax
	subl	%edx, %eax
	movl	-32(%ebp), %edx
	imull	%ecx, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	-64(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -136(%ebp)
	call	__ZNSspLERKSs
L31:
	subl	$1, -28(%ebp)
L29:
	movl	-28(%ebp), %eax
	notl	%eax
	shrl	$31, %eax
	testb	%al, %al
	jne	L32
	subl	$1, -32(%ebp)
L28:
	movl	-32(%ebp), %eax
	notl	%eax
	shrl	$31, %eax
	testb	%al, %al
	jne	L33
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$1, -136(%ebp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	movl	-372(%ebp), %ecx
	movl	4(%ecx), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSolsEi
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	leal	-88(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	movl	$3, -136(%ebp)
	call	__ZNSsD1Ev
	jmp	L48
L43:
	leal	24(%ebp), %ebp
	movl	-136(%ebp), %ecx
	movl	-132(%ebp), %edx
	movl	-128(%ebp), %eax
	cmpl	$1, %ecx
	je	L25
	cmpl	$2, %ecx
	je	L37
	cmpl	$3, %ecx
	je	L15
	cmpl	$4, %ecx
	je	L6
	cmpl	$5, %ecx
	je	L8
	cmpl	$6, %ecx
	je	L10
	cmpl	$7, %ecx
	je	L41
L35:
	movl	%eax, -156(%ebp)
	movl	%edx, -160(%ebp)
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -136(%ebp)
	call	__ZNSsD1Ev
	movl	-160(%ebp), %edx
	movl	-156(%ebp), %eax
	jmp	L37
L48:
	movl	-64(%ebp), %ecx
	movl	-252(%ebp), %eax
	leal	1(%eax), %edx
	movl	-260(%ebp), %eax
	addl	$1, %eax
	imull	%edx, %eax
	sall	$2, %eax
	addl	%eax, %ecx
	movl	%ecx, -144(%ebp)
	jmp	L36
L37:
	movl	%eax, -148(%ebp)
	movl	%edx, -152(%ebp)
	movl	-64(%ebp), %eax
	movl	-252(%ebp), %edx
	leal	1(%edx), %ecx
	movl	-260(%ebp), %edx
	addl	$1, %edx
	imull	%ecx, %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	%eax, -212(%ebp)
L39:
	movl	-64(%ebp), %eax
	cmpl	%eax, -212(%ebp)
	je	L38
	subl	$4, -212(%ebp)
	movl	-212(%ebp), %esi
	movl	%esi, (%esp)
	movl	$0, -136(%ebp)
	call	__ZNSsD1Ev
	jmp	L39
L38:
	movl	-152(%ebp), %edx
	movl	-148(%ebp), %eax
	jmp	L41
L36:
	movl	-64(%ebp), %eax
	cmpl	%eax, -144(%ebp)
	je	L40
	subl	$4, -144(%ebp)
	movl	-144(%ebp), %eax
	movl	%eax, (%esp)
	movl	$8, -136(%ebp)
	call	__ZNSsD1Ev
	jmp	L36
L40:
	movl	-224(%ebp), %esp
L3:
	leal	-140(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-16(%ebp), %esp
	addl	$0, %esp
	popl	%ecx
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L41:
	movl	-224(%ebp), %esp
	movl	%edx, (%esp)
	movl	$-1, -136(%ebp)
	call	__Unwind_SjLj_Resume
	.section	.gcc_except_table,"w"
LLSDA943:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE943-LLSDACSB943
LLSDACSB943:
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
LLSDACSE943:
	.text
.globl __Z7decryptSsib
	.def	__Z7decryptSsib;	.scl	2;	.type	32;	.endef
__Z7decryptSsib:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	subl	$360, %esp
	leal	8(%ebp), %ecx
	movl	%ecx, -356(%ebp)
	movl	-356(%ebp), %edx
	movl	8(%edx), %eax
	movb	%al, -92(%ebp)
	movl	$___gxx_personality_sj0, -120(%ebp)
	movl	$LLSDA944, -116(%ebp)
	leal	-112(%ebp), %edx
	leal	-24(%ebp), %ecx
	movl	%ecx, (%edx)
	movl	$L85, %eax
	movl	%eax, 4(%edx)
	movl	%esp, 8(%edx)
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	%esp, %eax
	movl	%eax, -212(%ebp)
	movl	-356(%ebp), %esi
	movl	(%esi), %eax
	movl	%eax, (%esp)
	movl	$6, -140(%ebp)
	call	__ZNKSs6lengthEv
	movl	%eax, -56(%ebp)
	movl	-356(%ebp), %edx
	movl	4(%edx), %eax
	movl	%eax, -52(%ebp)
	movl	-56(%ebp), %eax
	movl	-356(%ebp), %ecx
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	4(%ecx)
	movl	%eax, -48(%ebp)
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1Ev
	movl	-52(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -248(%ebp)
	movl	-248(%ebp), %esi
	movl	%esi, -76(%ebp)
	movl	-248(%ebp), %eax
	movl	$0, %edx
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -256(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -252(%ebp)
	movl	-256(%ebp), %eax
	movl	-252(%ebp), %edx
	addl	$1, %eax
	adcl	$0, %edx
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -264(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -260(%ebp)
	movl	-264(%ebp), %eax
	movl	-260(%ebp), %edx
	shldl	$5, %eax, %edx
	sall	$5, %eax
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -272(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -268(%ebp)
	movl	-272(%ebp), %eax
	movl	-268(%ebp), %edx
	movl	-248(%ebp), %eax
	addl	$1, %eax
	sall	$2, %eax
	movl	%eax, -244(%ebp)
	movl	-48(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -240(%ebp)
	movl	-240(%ebp), %eax
	movl	%eax, -72(%ebp)
	movl	-248(%ebp), %eax
	movl	$0, %edx
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -280(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -276(%ebp)
	movl	-280(%ebp), %eax
	movl	-276(%ebp), %edx
	movl	%eax, %ecx
	movl	%edx, %ebx
	addl	$1, %ecx
	adcl	$0, %ebx
	movl	%ecx, %eax
	andb	$255, %ah
	movl	%eax, -288(%ebp)
	movl	%ebx, %edx
	andl	$15, %edx
	movl	%edx, -284(%ebp)
	movl	-288(%ebp), %ecx
	movl	-284(%ebp), %ebx
	movl	-240(%ebp), %eax
	addl	$1, %eax
	movl	$0, %edx
	movl	%eax, %esi
	andl	$-1, %esi
	movl	%esi, -296(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -292(%ebp)
	movl	-296(%ebp), %eax
	movl	-292(%ebp), %edx
	movl	%ebx, %edi
	imull	%eax, %edi
	movl	%edx, %esi
	imull	%ecx, %esi
	addl	%esi, %edi
	mull	%ecx
	addl	%edx, %edi
	movl	%edi, %edx
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -304(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -300(%ebp)
	movl	-304(%ebp), %eax
	movl	-300(%ebp), %edx
	shldl	$5, %eax, %edx
	sall	$5, %eax
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -312(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -308(%ebp)
	movl	-312(%ebp), %eax
	movl	-308(%ebp), %edx
	movl	-248(%ebp), %eax
	movl	$0, %edx
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -320(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -316(%ebp)
	movl	-320(%ebp), %eax
	movl	-316(%ebp), %edx
	movl	%eax, %ecx
	movl	%edx, %ebx
	addl	$1, %ecx
	adcl	$0, %ebx
	movl	%ecx, %eax
	andb	$255, %ah
	movl	%eax, -328(%ebp)
	movl	%ebx, %edx
	andl	$15, %edx
	movl	%edx, -324(%ebp)
	movl	-328(%ebp), %ecx
	movl	-324(%ebp), %ebx
	movl	-240(%ebp), %eax
	addl	$1, %eax
	movl	$0, %edx
	movl	%eax, %esi
	andl	$-1, %esi
	movl	%esi, -336(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -332(%ebp)
	movl	-336(%ebp), %eax
	movl	-332(%ebp), %edx
	movl	%ebx, %edi
	imull	%eax, %edi
	movl	%edx, %esi
	imull	%ecx, %esi
	addl	%esi, %edi
	mull	%ecx
	addl	%edx, %edi
	movl	%edi, %edx
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -344(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -340(%ebp)
	movl	-344(%ebp), %eax
	movl	-340(%ebp), %edx
	shldl	$5, %eax, %edx
	sall	$5, %eax
	movl	%eax, %ecx
	andb	$255, %ch
	movl	%ecx, -352(%ebp)
	movl	%edx, %esi
	andl	$15, %esi
	movl	%esi, -348(%ebp)
	movl	-352(%ebp), %eax
	movl	-348(%ebp), %edx
	movl	-248(%ebp), %eax
	leal	1(%eax), %edx
	movl	-240(%ebp), %eax
	addl	$1, %eax
	imull	%edx, %eax
	sall	$2, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	call	___chkstk
	leal	16(%esp), %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	movl	%eax, -68(%ebp)
	movl	-68(%ebp), %eax
	movl	%eax, -236(%ebp)
	movl	-236(%ebp), %edx
	movl	%edx, -232(%ebp)
	movl	-240(%ebp), %ecx
	movl	%ecx, -228(%ebp)
	jmp	L50
L56:
	movl	-232(%ebp), %esi
	movl	%esi, -224(%ebp)
	movl	-224(%ebp), %eax
	movl	%eax, -220(%ebp)
	movl	-248(%ebp), %edx
	movl	%edx, -216(%ebp)
	jmp	L51
L52:
	movl	-220(%ebp), %ecx
	movl	%ecx, (%esp)
	movl	$4, -140(%ebp)
	call	__ZNSsC1Ev
	addl	$4, -220(%ebp)
	subl	$1, -216(%ebp)
L51:
	cmpl	$-1, -216(%ebp)
	setne	%al
	testb	%al, %al
	jne	L52
	movl	-248(%ebp), %eax
	addl	$1, %eax
	sall	$2, %eax
	addl	%eax, -232(%ebp)
	subl	$1, -228(%ebp)
	jmp	L50
L53:
	movl	%eax, -192(%ebp)
	movl	%edx, -196(%ebp)
	cmpl	$0, -224(%ebp)
	je	L54
	movl	-248(%ebp), %eax
	subl	-216(%ebp), %eax
	sall	$2, %eax
	movl	-224(%ebp), %esi
	addl	%eax, %esi
	movl	%esi, -208(%ebp)
L55:
	movl	-224(%ebp), %eax
	cmpl	%eax, -208(%ebp)
	je	L54
	subl	$4, -208(%ebp)
	movl	-208(%ebp), %edx
	movl	%edx, (%esp)
	movl	$0, -140(%ebp)
	call	__ZNSsD1Ev
	jmp	L55
L54:
	movl	-196(%ebp), %edx
	movl	-192(%ebp), %eax
L58:
	movl	%eax, -184(%ebp)
	movl	%edx, -188(%ebp)
	cmpl	$0, -236(%ebp)
	je	L59
	jmp	L86
L50:
	cmpl	$-1, -228(%ebp)
	setne	%al
	testb	%al, %al
	jne	L56
	movl	$0, -44(%ebp)
	movl	-52(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -40(%ebp)
	jmp	L57
L86:
	movl	-236(%ebp), %ecx
	movl	-240(%ebp), %eax
	subl	-228(%ebp), %eax
	movl	%eax, %edx
	movl	-248(%ebp), %eax
	addl	$1, %eax
	imull	%edx, %eax
	sall	$2, %eax
	addl	%eax, %ecx
	movl	%ecx, -204(%ebp)
L60:
	movl	-236(%ebp), %eax
	cmpl	%eax, -204(%ebp)
	je	L59
	subl	$4, -204(%ebp)
	movl	-204(%ebp), %ecx
	movl	%ecx, (%esp)
	movl	$0, -140(%ebp)
	call	__ZNSsD1Ev
	jmp	L60
L59:
	movl	-188(%ebp), %edx
	movl	-184(%ebp), %eax
	jmp	L82
L68:
	movl	-48(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -36(%ebp)
	jmp	L61
L67:
	movl	-40(%ebp), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	movl	%eax, %ecx
	shrl	$31, %ecx
	leal	(%edx,%ecx), %eax
	andl	$1, %eax
	subl	%ecx, %eax
	cmpl	$1, %eax
	je	L62
	movl	-44(%ebp), %eax
	leal	-64(%ebp), %edx
	movl	$1, 12(%esp)
	movl	%eax, 8(%esp)
	movl	-356(%ebp), %esi
	movl	(%esi), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	$3, -140(%ebp)
	call	__ZNKSs6substrEjj
	subl	$4, %esp
	movl	-244(%ebp), %ecx
	shrl	$2, %ecx
	movl	-36(%ebp), %eax
	movl	-40(%ebp), %edx
	imull	%ecx, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, %edx
	addl	-68(%ebp), %edx
	leal	-64(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	$2, -140(%ebp)
	call	__ZNSsaSERKSs
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	movl	$3, -140(%ebp)
	call	__ZNSsD1Ev
	jmp	L65
L64:
	movl	%eax, -176(%ebp)
	movl	%edx, -180(%ebp)
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -140(%ebp)
	call	__ZNSsD1Ev
	movl	-180(%ebp), %edx
	movl	-176(%ebp), %eax
	jmp	L77
L62:
	movl	-44(%ebp), %eax
	leal	-60(%ebp), %edx
	movl	$1, 12(%esp)
	movl	%eax, 8(%esp)
	movl	-356(%ebp), %ecx
	movl	(%ecx), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	$3, -140(%ebp)
	call	__ZNKSs6substrEjj
	subl	$4, %esp
	movl	-244(%ebp), %ecx
	shrl	$2, %ecx
	movl	-36(%ebp), %edx
	movl	-48(%ebp), %eax
	subl	%edx, %eax
	subl	$1, %eax
	movl	-40(%ebp), %edx
	imull	%ecx, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, %edx
	addl	-68(%ebp), %edx
	leal	-60(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	$1, -140(%ebp)
	call	__ZNSsaSERKSs
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	movl	$3, -140(%ebp)
	call	__ZNSsD1Ev
	jmp	L65
L85:
	leal	24(%ebp), %ebp
	movl	-140(%ebp), %ecx
	movl	-136(%ebp), %edx
	movl	-132(%ebp), %eax
	cmpl	$1, %ecx
	je	L64
	cmpl	$2, %ecx
	je	L77
	cmpl	$3, %ecx
	je	L53
	cmpl	$4, %ecx
	je	L82
	cmpl	$5, %ecx
	je	L83
L66:
	movl	%eax, -168(%ebp)
	movl	%edx, -172(%ebp)
	leal	-60(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -140(%ebp)
	call	__ZNSsD1Ev
	movl	-172(%ebp), %edx
	movl	-168(%ebp), %eax
	jmp	L77
L65:
	addl	$1, -44(%ebp)
	subl	$1, -36(%ebp)
L61:
	movl	-36(%ebp), %eax
	notl	%eax
	shrl	$31, %eax
	testb	%al, %al
	jne	L67
	subl	$1, -40(%ebp)
L57:
	movl	-40(%ebp), %eax
	notl	%eax
	shrl	$31, %eax
	testb	%al, %al
	jne	L68
	movl	$0, -32(%ebp)
	jmp	L69
L74:
	movl	$0, -28(%ebp)
	jmp	L70
L72:
	movl	-244(%ebp), %ecx
	shrl	$2, %ecx
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	imull	%ecx, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	movl	$3, -140(%ebp)
	call	__ZNSspLERKSs
	cmpb	$0, -92(%ebp)
	je	L71
	movl	-244(%ebp), %ecx
	shrl	$2, %ecx
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	imull	%ecx, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
L71:
	addl	$1, -28(%ebp)
L70:
	movl	-28(%ebp), %eax
	cmpl	-52(%ebp), %eax
	setl	%al
	testb	%al, %al
	jne	L72
	cmpb	$0, -92(%ebp)
	je	L73
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$3, -140(%ebp)
	call	__ZNSolsEPFRSoS_E
L73:
	addl	$1, -32(%ebp)
L69:
	movl	-32(%ebp), %eax
	cmpl	-48(%ebp), %eax
	setl	%al
	testb	%al, %al
	jne	L74
	cmpb	$0, -92(%ebp)
	je	L75
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$3, -140(%ebp)
	call	__ZNSolsEPFRSoS_E
L75:
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$3, -140(%ebp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	movl	-356(%ebp), %esi
	movl	4(%esi), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSolsEi
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	leal	-80(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	-68(%ebp), %ecx
	movl	-240(%ebp), %eax
	leal	1(%eax), %edx
	movl	-248(%ebp), %eax
	addl	$1, %eax
	imull	%edx, %eax
	sall	$2, %eax
	addl	%eax, %ecx
	movl	%ecx, -148(%ebp)
	jmp	L76
L77:
	movl	%eax, -160(%ebp)
	movl	%edx, -164(%ebp)
	movl	-68(%ebp), %eax
	movl	-240(%ebp), %edx
	leal	1(%edx), %ecx
	movl	-248(%ebp), %edx
	addl	$1, %edx
	imull	%ecx, %edx
	sall	$2, %edx
	addl	%edx, %eax
	movl	%eax, -200(%ebp)
L79:
	movl	-68(%ebp), %eax
	cmpl	%eax, -200(%ebp)
	je	L78
	subl	$4, -200(%ebp)
	movl	-200(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -140(%ebp)
	call	__ZNSsD1Ev
	jmp	L79
L78:
	movl	-164(%ebp), %edx
	movl	-160(%ebp), %eax
	jmp	L82
L76:
	movl	-68(%ebp), %eax
	cmpl	%eax, -148(%ebp)
	je	L80
	subl	$4, -148(%ebp)
	movl	-148(%ebp), %edx
	movl	%edx, (%esp)
	movl	$5, -140(%ebp)
	call	__ZNSsD1Ev
	jmp	L76
L80:
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	movl	$6, -140(%ebp)
	call	__ZNSsD1Ev
	jmp	L87
L82:
	movl	%eax, -152(%ebp)
	movl	%edx, -156(%ebp)
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -140(%ebp)
	call	__ZNSsD1Ev
	movl	-156(%ebp), %edx
	movl	-152(%ebp), %eax
	jmp	L83
L87:
	movl	-212(%ebp), %esp
L49:
	leal	-144(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-16(%ebp), %esp
	addl	$0, %esp
	popl	%ecx
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L83:
	movl	-212(%ebp), %esp
	movl	%edx, (%esp)
	movl	$-1, -140(%ebp)
	call	__Unwind_SjLj_Resume
	.section	.gcc_except_table,"w"
LLSDA944:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE944-LLSDACSB944
LLSDACSB944:
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
LLSDACSE944:
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC3:
	.ascii "The developer of the program is Marek K.; The program uses Plow cipher.\0"
	.align 4
LC4:
	.ascii "Enter \"encrypt\", \"decrypt\" or \"bfa\" for a Brute-Force-Attack: \0"
LC5:
	.ascii "encrypt\0"
LC6:
	.ascii "Text: \0"
LC7:
	.ascii "decrypt\0"
LC8:
	.ascii "bfa\0"
LC9:
	.ascii "From Key \0"
LC10:
	.ascii "to Key \0"
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
	subl	$196, %esp
	movl	$___gxx_personality_sj0, 116(%esp)
	movl	$LLSDA945, 120(%esp)
	leal	124(%esp), %eax
	movl	%ebp, (%eax)
	movl	$L107, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	92(%esp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	call	___main
	movl	$0, (%esp)
	call	_time
	movl	%eax, (%esp)
	call	_srand
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$-1, 96(%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$LC4, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	172(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1Ev
	leal	172(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	movl	$7, 96(%esp)
	call	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	movl	$LC5, 4(%esp)
	leal	172(%esp), %eax
	movl	%eax, (%esp)
	call	__ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	testb	%al, %al
	je	L89
	leal	168(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1Ev
	movl	$LC6, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$6, 96(%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	168(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	164(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZNSirsERi
	movl	164(%esp), %eax
	movl	%eax, 24(%esp)
	leal	168(%esp), %eax
	movl	%eax, 4(%esp)
	leal	176(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1ERKSs
	movl	24(%esp), %eax
	movl	%eax, 4(%esp)
	leal	176(%esp), %eax
	movl	%eax, (%esp)
	movl	$5, 96(%esp)
	call	__Z7encryptSsi
	leal	176(%esp), %eax
	movl	%eax, (%esp)
	movl	$6, 96(%esp)
	call	__ZNSsD1Ev
	jmp	L108
L91:
	movl	%edx, 40(%esp)
	movl	%eax, 36(%esp)
	leal	176(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 96(%esp)
	call	__ZNSsD1Ev
	movl	36(%esp), %eax
	movl	40(%esp), %edx
	jmp	L93
L108:
	leal	168(%esp), %eax
	movl	%eax, (%esp)
	movl	$7, 96(%esp)
	call	__ZNSsD1Ev
	jmp	L94
L93:
	movl	%edx, 48(%esp)
	movl	%eax, 44(%esp)
	leal	168(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 96(%esp)
	call	__ZNSsD1Ev
	movl	44(%esp), %eax
	movl	48(%esp), %edx
	jmp	L105
L89:
	movl	$LC7, 4(%esp)
	leal	172(%esp), %eax
	movl	%eax, (%esp)
	movl	$7, 96(%esp)
	call	__ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	testb	%al, %al
	je	L95
	leal	160(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1Ev
	movl	$LC6, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$4, 96(%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	160(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	156(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZNSirsERi
	movl	156(%esp), %eax
	movl	%eax, 28(%esp)
	leal	160(%esp), %eax
	movl	%eax, 4(%esp)
	leal	180(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1ERKSs
	movl	$1, 8(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	leal	180(%esp), %eax
	movl	%eax, (%esp)
	movl	$3, 96(%esp)
	call	__Z7decryptSsib
	leal	180(%esp), %eax
	movl	%eax, (%esp)
	movl	$4, 96(%esp)
	call	__ZNSsD1Ev
	jmp	L109
L97:
	movl	%edx, 56(%esp)
	movl	%eax, 52(%esp)
	leal	180(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 96(%esp)
	call	__ZNSsD1Ev
	movl	52(%esp), %eax
	movl	56(%esp), %edx
	jmp	L99
L109:
	leal	160(%esp), %eax
	movl	%eax, (%esp)
	movl	$7, 96(%esp)
	call	__ZNSsD1Ev
	jmp	L94
L99:
	movl	%edx, 64(%esp)
	movl	%eax, 60(%esp)
	leal	160(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 96(%esp)
	call	__ZNSsD1Ev
	movl	60(%esp), %eax
	movl	64(%esp), %edx
	jmp	L105
L95:
	movl	$LC8, 4(%esp)
	leal	172(%esp), %eax
	movl	%eax, (%esp)
	movl	$7, 96(%esp)
	call	__ZSteqIcSt11char_traitsIcESaIcEEbRKSbIT_T0_T1_EPKS3_
	testb	%al, %al
	je	L94
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1Ev
	movl	$LC6, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$2, 96(%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	152(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	movl	$LC9, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	148(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZNSirsERi
	movl	$LC10, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	144(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZNSirsERi
	movl	148(%esp), %eax
	movl	%eax, 188(%esp)
	jmp	L100
L103:
	leal	152(%esp), %eax
	movl	%eax, 4(%esp)
	leal	184(%esp), %eax
	movl	%eax, (%esp)
	movl	$2, 96(%esp)
	call	__ZNSsC1ERKSs
	movl	$0, 8(%esp)
	movl	188(%esp), %eax
	movl	%eax, 4(%esp)
	leal	184(%esp), %eax
	movl	%eax, (%esp)
	movl	$1, 96(%esp)
	call	__Z7decryptSsib
	leal	184(%esp), %eax
	movl	%eax, (%esp)
	movl	$2, 96(%esp)
	call	__ZNSsD1Ev
	jmp	L110
L107:
	movl	96(%esp), %ecx
	movl	100(%esp), %eax
	movl	104(%esp), %edx
	cmpl	$1, %ecx
	je	L104
	cmpl	$2, %ecx
	je	L97
	cmpl	$3, %ecx
	je	L99
	cmpl	$4, %ecx
	je	L91
	cmpl	$5, %ecx
	je	L93
	cmpl	$6, %ecx
	je	L105
L102:
	movl	%edx, 72(%esp)
	movl	%eax, 68(%esp)
	leal	184(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 96(%esp)
	call	__ZNSsD1Ev
	movl	68(%esp), %eax
	movl	72(%esp), %edx
	jmp	L104
L110:
	addl	$1, 188(%esp)
L100:
	movl	144(%esp), %eax
	cmpl	%eax, 188(%esp)
	setle	%al
	testb	%al, %al
	jne	L103
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	movl	$7, 96(%esp)
	call	__ZNSsD1Ev
	jmp	L94
L104:
	movl	%edx, 80(%esp)
	movl	%eax, 76(%esp)
	leal	152(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 96(%esp)
	call	__ZNSsD1Ev
	movl	76(%esp), %eax
	movl	80(%esp), %edx
	jmp	L105
L94:
	movl	$0, 32(%esp)
	leal	172(%esp), %eax
	movl	%eax, (%esp)
	movl	$-1, 96(%esp)
	call	__ZNSsD1Ev
	movl	32(%esp), %eax
	movl	%eax, 20(%esp)
L88:
	leal	92(%esp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	20(%esp), %eax
	addl	$196, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	movl	%ebp, %esp
	popl	%ebp
	ret
L105:
	movl	%edx, 88(%esp)
	movl	%eax, 84(%esp)
	leal	172(%esp), %eax
	movl	%eax, (%esp)
	movl	$0, 96(%esp)
	call	__ZNSsD1Ev
	movl	84(%esp), %eax
	movl	88(%esp), %edx
	movl	%eax, (%esp)
	movl	$-1, 96(%esp)
	call	__Unwind_SjLj_Resume
	.section	.gcc_except_table,"w"
LLSDA945:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE945-LLSDACSB945
LLSDACSB945:
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
LLSDACSE945:
	.text
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
	jne	L117
	cmpl	$65535, 12(%ebp)
	jne	L117
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L117:
	leave
	ret
	.def	__GLOBAL__I__Z14zufallsZeichenSs;	.scl	3;	.type	32;	.endef
__GLOBAL__I__Z14zufallsZeichenSs:
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
	.long	__GLOBAL__I__Z14zufallsZeichenSs
	.def	_rand;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1EPKcRKSaIcE;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNKSs6lengthEv;	.scl	2;	.type	32;	.endef
	.def	__ZNKSs6substrEjj;	.scl	2;	.type	32;	.endef
	.def	__ZNSsaSERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSspLERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	_time;	.scl	2;	.type	32;	.endef
	.def	_srand;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1ERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNKSs7compareEPKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
