	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.intel_syntax noprefix
	.globl	_ft_setup
	.p2align	4, 0x90
_ft_setup:                              ## @ft_setup
	.cfi_startproc
## BB#0:
	push	rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Lcfi2:
	.cfi_def_cfa_register rbp
	sub	rsp, 48
	mov	qword ptr [rbp - 16], rdi
	mov	qword ptr [rbp - 24], rsi
	mov	qword ptr [rbp - 32], rdx
	mov	qword ptr [rbp - 40], rcx
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_9 Depth 2
                                        ##     Child Loop BB0_20 Depth 2
	xor	eax, eax
	mov	cl, al
	mov	rdx, qword ptr [rbp - 16]
	mov	rsi, qword ptr [rbp - 40]
	movsxd	rsi, dword ptr [rsi]
	movsx	eax, byte ptr [rdx + rsi]
	cmp	eax, 0
	mov	byte ptr [rbp - 45], cl ## 1-byte Spill
	je	LBB0_6
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	rcx, qword ptr [rbp - 40]
	movsxd	rcx, dword ptr [rcx]
	movsx	edx, byte ptr [rax + rcx]
	cmp	edx, 9
	jl	LBB0_4
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	xor	eax, eax
	mov	cl, al
	mov	rdx, qword ptr [rbp - 16]
	mov	rsi, qword ptr [rbp - 40]
	movsxd	rsi, dword ptr [rsi]
	movsx	eax, byte ptr [rdx + rsi]
	cmp	eax, 13
	mov	byte ptr [rbp - 45], cl ## 1-byte Spill
	jle	LBB0_6
LBB0_4:                                 ##   in Loop: Header=BB0_1 Depth=1
	xor	eax, eax
	mov	cl, al
	mov	rdx, qword ptr [rbp - 16]
	mov	rsi, qword ptr [rbp - 40]
	movsxd	rsi, dword ptr [rsi]
	movsx	eax, byte ptr [rdx + rsi]
	cmp	eax, 32
	mov	byte ptr [rbp - 45], cl ## 1-byte Spill
	je	LBB0_6
## BB#5:                                ##   in Loop: Header=BB0_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	rcx, qword ptr [rbp - 40]
	movsxd	rcx, dword ptr [rcx]
	movsx	edx, byte ptr [rax + rcx]
	cmp	edx, 59
	setne	sil
	mov	byte ptr [rbp - 45], sil ## 1-byte Spill
LBB0_6:                                 ##   in Loop: Header=BB0_1 Depth=1
	mov	al, byte ptr [rbp - 45] ## 1-byte Reload
	test	al, 1
	jne	LBB0_7
	jmp	LBB0_35
LBB0_7:                                 ##   in Loop: Header=BB0_1 Depth=1
	mov	dword ptr [rbp - 44], 1
	mov	rax, qword ptr [rbp - 16]
	mov	rcx, qword ptr [rbp - 40]
	movsxd	rcx, dword ptr [rcx]
	movsx	edx, byte ptr [rax + rcx]
	cmp	edx, 34
	jne	LBB0_18
## BB#8:                                ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_9
LBB0_9:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	xor	eax, eax
	mov	cl, al
	mov	rdx, qword ptr [rbp - 16]
	mov	rsi, qword ptr [rbp - 40]
	mov	eax, dword ptr [rsi]
	add	eax, dword ptr [rbp - 44]
	movsxd	rsi, eax
	movsx	eax, byte ptr [rdx + rsi]
	cmp	eax, 0
	mov	byte ptr [rbp - 46], cl ## 1-byte Spill
	je	LBB0_11
## BB#10:                               ##   in Loop: Header=BB0_9 Depth=2
	mov	rax, qword ptr [rbp - 16]
	mov	rcx, qword ptr [rbp - 40]
	mov	edx, dword ptr [rcx]
	add	edx, dword ptr [rbp - 44]
	movsxd	rcx, edx
	movsx	edx, byte ptr [rax + rcx]
	cmp	edx, 34
	setne	sil
	mov	byte ptr [rbp - 46], sil ## 1-byte Spill
LBB0_11:                                ##   in Loop: Header=BB0_9 Depth=2
	mov	al, byte ptr [rbp - 46] ## 1-byte Reload
	test	al, 1
	jne	LBB0_12
	jmp	LBB0_13
LBB0_12:                                ##   in Loop: Header=BB0_9 Depth=2
	mov	eax, dword ptr [rbp - 44]
	add	eax, 1
	mov	dword ptr [rbp - 44], eax
	jmp	LBB0_9
LBB0_13:                                ##   in Loop: Header=BB0_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	rcx, qword ptr [rbp - 40]
	mov	edx, dword ptr [rcx]
	add	edx, dword ptr [rbp - 44]
	movsxd	rcx, edx
	cmp	byte ptr [rax + rcx], 0
	jne	LBB0_15
## BB#14:
	lea	rdi, [rip + L_.str]
	mov	al, 0
	call	_ft_printf
	mov	dword ptr [rbp - 4], eax
	jmp	LBB0_36
LBB0_15:                                ##   in Loop: Header=BB0_1 Depth=1
	cmp	dword ptr [rbp - 44], 1
	jle	LBB0_17
## BB#16:                               ##   in Loop: Header=BB0_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	rcx, qword ptr [rbp - 40]
	movsxd	rcx, dword ptr [rcx]
	add	rax, rcx
	add	rax, 1
	mov	edx, dword ptr [rbp - 44]
	sub	edx, 1
	mov	rdi, rax
	mov	esi, edx
	call	_ft_strndup
	mov	qword ptr [rbp - 32], rax
	mov	rax, qword ptr [rbp - 24]
	mov	rdi, qword ptr [rax]
	mov	rsi, qword ptr [rbp - 32]
	call	_ft_strjoinrem
	mov	rcx, qword ptr [rbp - 24]
	mov	qword ptr [rcx], rax
LBB0_17:                                ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_31
LBB0_18:                                ##   in Loop: Header=BB0_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	rcx, qword ptr [rbp - 40]
	movsxd	rcx, dword ptr [rcx]
	movsx	edx, byte ptr [rax + rcx]
	cmp	edx, 39
	jne	LBB0_29
## BB#19:                               ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_20
LBB0_20:                                ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	xor	eax, eax
	mov	cl, al
	mov	rdx, qword ptr [rbp - 16]
	mov	rsi, qword ptr [rbp - 40]
	mov	eax, dword ptr [rsi]
	add	eax, dword ptr [rbp - 44]
	movsxd	rsi, eax
	movsx	eax, byte ptr [rdx + rsi]
	cmp	eax, 0
	mov	byte ptr [rbp - 47], cl ## 1-byte Spill
	je	LBB0_22
## BB#21:                               ##   in Loop: Header=BB0_20 Depth=2
	mov	rax, qword ptr [rbp - 16]
	mov	rcx, qword ptr [rbp - 40]
	mov	edx, dword ptr [rcx]
	add	edx, dword ptr [rbp - 44]
	movsxd	rcx, edx
	movsx	edx, byte ptr [rax + rcx]
	cmp	edx, 39
	setne	sil
	mov	byte ptr [rbp - 47], sil ## 1-byte Spill
LBB0_22:                                ##   in Loop: Header=BB0_20 Depth=2
	mov	al, byte ptr [rbp - 47] ## 1-byte Reload
	test	al, 1
	jne	LBB0_23
	jmp	LBB0_24
LBB0_23:                                ##   in Loop: Header=BB0_20 Depth=2
	mov	eax, dword ptr [rbp - 44]
	add	eax, 1
	mov	dword ptr [rbp - 44], eax
	jmp	LBB0_20
LBB0_24:                                ##   in Loop: Header=BB0_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	rcx, qword ptr [rbp - 40]
	mov	edx, dword ptr [rcx]
	add	edx, dword ptr [rbp - 44]
	movsxd	rcx, edx
	cmp	byte ptr [rax + rcx], 0
	jne	LBB0_26
## BB#25:
	lea	rdi, [rip + L_.str]
	mov	al, 0
	call	_ft_printf
	mov	dword ptr [rbp - 4], eax
	jmp	LBB0_36
LBB0_26:                                ##   in Loop: Header=BB0_1 Depth=1
	cmp	dword ptr [rbp - 44], 1
	jle	LBB0_28
## BB#27:                               ##   in Loop: Header=BB0_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	rcx, qword ptr [rbp - 40]
	movsxd	rcx, dword ptr [rcx]
	add	rax, rcx
	add	rax, 1
	mov	edx, dword ptr [rbp - 44]
	sub	edx, 1
	mov	rdi, rax
	mov	esi, edx
	call	_ft_strndup
	mov	qword ptr [rbp - 32], rax
	mov	rax, qword ptr [rbp - 24]
	mov	rdi, qword ptr [rax]
	mov	rsi, qword ptr [rbp - 32]
	call	_ft_strjoinrem
	mov	rcx, qword ptr [rbp - 24]
	mov	qword ptr [rcx], rax
LBB0_28:                                ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_30
LBB0_29:                                ##   in Loop: Header=BB0_1 Depth=1
	mov	esi, 1
	mov	rax, qword ptr [rbp - 16]
	mov	rcx, qword ptr [rbp - 40]
	movsxd	rcx, dword ptr [rcx]
	add	rax, rcx
	mov	rdi, rax
	call	_ft_strndup
	mov	qword ptr [rbp - 32], rax
	mov	rax, qword ptr [rbp - 24]
	mov	rdi, qword ptr [rax]
	mov	rsi, qword ptr [rbp - 32]
	call	_ft_strjoinrem
	mov	rcx, qword ptr [rbp - 24]
	mov	qword ptr [rcx], rax
	mov	rdi, qword ptr [rbp - 32]
	call	_free
	mov	rax, qword ptr [rbp - 40]
	mov	edx, dword ptr [rax]
	sub	edx, 1
	mov	dword ptr [rax], edx
LBB0_30:                                ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_31
LBB0_31:                                ##   in Loop: Header=BB0_1 Depth=1
	cmp	dword ptr [rbp - 44], 1
	jne	LBB0_33
## BB#32:                               ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_34
LBB0_33:                                ##   in Loop: Header=BB0_1 Depth=1
	mov	rdi, qword ptr [rbp - 32]
	call	_free
LBB0_34:                                ##   in Loop: Header=BB0_1 Depth=1
	mov	eax, dword ptr [rbp - 44]
	add	eax, 1
	mov	rcx, qword ptr [rbp - 40]
	add	eax, dword ptr [rcx]
	mov	dword ptr [rcx], eax
	jmp	LBB0_1
LBB0_35:
	mov	dword ptr [rbp - 4], 0
LBB0_36:
	mov	eax, dword ptr [rbp - 4]
	add	rsp, 48
	pop	rbp
	ret
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"\033[1;31mmulti-line not supported\033[0m\n"


.subsections_via_symbols
