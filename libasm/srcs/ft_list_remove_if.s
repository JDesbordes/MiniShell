section .text
    global _ft_list2_remove_if
	extern _ft_cmp, _free

_ft_list2_remove_if:
    push    rbp
	cmp     rdi,	0
	je		.return
	cmp     rsi,	0
	je		.return
	cmp     rdx,	0
	je		.return
	cmp     rcx,	0
	je		.return
    mov     r12,	rdi
    mov	    r13,	rdx
	mov		r14,	rsi
    mov     r15,    rcx

.Loop1:
    cmp     r12,	0
    je      .return
	cmp     qword	[r12],	0
    je      .return
	mov	    rcx,    qword	[r12]
	mov		rsi,	r14
    mov     rdi,	qword	[rcx]
	call	r13
	cmp		ax,	0
	jne		.SetupLoop2

	mov	    rdi,    qword	[r12]
    mov     rdi,	qword	[rdi]
	call	r15
	mov		r11,	qword	[r12]
	mov		r11,	qword	[r11 + 8]
	push	r11
	mov		rdi,	qword	[r12]
	call	_free
	pop		r11
	mov		qword	[r12],	r11
	;change list2 first to second
	jmp		.Loop1

.SetupLoop2:
	cmp     r12,	0
    je      .return
	cmp     qword	[r12],	0
    je      .return
	mov		r12,	qword	[r12]
	cmp		qword	[r12 + 8],	0
	je		.return

.Loop2:
	mov		rsi,	r14
    mov     rdi,	qword	[r12 + 8]
	mov		rdi,	qword	[rdi]
	call	r13
	cmp		ax,	0
	jne		.nextLoop2

	mov	    rdi,    qword	[r12 + 8]
    mov     rdi,	qword	[rdi]
	call	r15
	mov		r11,	qword	[r12 + 8]
	mov		r11,	qword	[r11 + 8]
	push	r11
	mov		rdi,	qword	[r12 + 8]
	call	_free
	pop		r11
	mov		qword	[r12 + 8],	r11
	cmp		r11,	0
	je		.return

.nextLoop2:
	mov		r12,	qword	[r12 + 8]
	cmp		qword	[r12 + 8],	0
	je		.return
	jmp		.Loop2

.return:
	pop		rbp
    ret
