section .text
    global _ft_list2_sort
	extern _ft_cmp
_ft_list2_sort:
    cmp     rdi,	0
	je		.return
    push    rbp
    mov     r12,	rdi
    mov	    r13,	rsi
	mov	    rcx,    r12

.Loop1:
    cmp     r12,	0
    je      .return
	mov	    rcx,    qword	[r12]
    mov     rdi,	qword	[rcx]
	mov		r14,	qword	[r12]
	cmp		r14,	0
	je		.return
	mov		r14,	qword	[r14 + 8]
	cmp		r14,	0
	je		.return
	mov		rsi,	qword	[r14]
	call	r13
	cmp		ax,	0
	jle		.setupLoop2						;if in order go to loop 2

	mov	    rcx,    r12						;rcx = pointer to list2
	mov     rdi,	qword	[rcx]			;rdi = list2
											;have to link highest to next of lowest
	mov	    rcx,    r12						;rcx = pointer to list2
	mov		r14,	qword	[rcx]			;r14 = list2
	mov		r14,	qword	[r14 + 8]		;r14 = next of list2
	mov		r15,	qword	[r14 + 8]		;r15 = next of lowest
	mov		qword	[rdi + 8],	r15			;next of rdi = r15
	mov		rcx,	qword	[rcx]			;rcx = list2
	mov		qword	[r14 + 8], rcx			;next of r14 = start of list2 list2
	mov		qword	[r12],	r14				;link pointer to new beginning at r14

.setupLoop2:
	mov	    rbx,    r12						;rbx = pointer to list2
	mov		rbx,	qword	[rbx]			;rbx = list2
	mov		r15,	rbx
	mov		rbx,	qword	[rbx + 8]		;rbx = next of list2
	mov     rdi,	qword	[rbx]			;rdi = value of rbx
	mov		r14,	qword	[rbx + 8]		;r14 = next of rbx
	cmp		r14,	0
	je		.return
	mov		rsi,	qword	[r14]			;rsi = value of r14

.Loop2:
	call	r13
	cmp		ax,	0
	jle		.next
											;Swap and restart
	mov		qword	[r15 + 8],	r14
	mov		r15,	qword [r14 + 8]
	mov		qword	[rbx + 8],	r15
	mov		qword	[r14 + 8],	rbx
	jmp			.Loop1

.next:
	mov		r15,	qword[r15 + 8]
	mov		rbx,	r14
	mov		rdi,	qword	[r14]
	mov		r14,	qword	[r14 + 8]
	cmp		r14,	0
	je		.return
	mov		rsi,	qword	[r14]
	jmp		.Loop2
.return:
	pop		rbp
    ret
