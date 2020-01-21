global _ft_atoi_base

extern  _ft_strlen

section .text

_ft_atoi_base:
	push rbp
	mov rbp, rsp

	cmp rsi, 0
	je _ft_atoi_base.error_exit
	cmp rdi, 0
	je _ft_atoi_base.error_exit
	mov rcx, -1

.checkbase1:
	INC rcx
	mov dl, byte [rsi + rcx]
	cmp dl, 45
	je _ft_atoi_base.error_exit
	cmp dl, 9
	je _ft_atoi_base.error_exit
	cmp dl, 10
	je _ft_atoi_base.error_exit
	cmp dl, 11
	je _ft_atoi_base.error_exit
	cmp dl, 12
	je _ft_atoi_base.error_exit
	cmp dl, 13
	je _ft_atoi_base.error_exit
	cmp dl, 32
	je _ft_atoi_base.error_exit
	cmp dl, 43
	je _ft_atoi_base.error_exit
	xor r8, r8

.checkdouble:
	cmp rcx, r8
	je _ft_atoi_base.checkbase2
	mov al, byte [rsi + r8]
	INC r8
	cmp al, dl
	je _ft_atoi_base.error_exit
	jmp _ft_atoi_base.checkdouble


.checkbase2:
	cmp dl, 0
	jne _ft_atoi_base.checkbase1
	cmp rcx, 0
	je _ft_atoi_base.error_exit
	cmp rcx, 1
	je _ft_atoi_base.error_exit

.init_var:
	mov r11, rcx
	xor r8, r8
	xor r9, r9					;get strlen of the whole thing
								;for every number check if present in base
	xor r12, r12				;if it is present use |!*[rcx = sizebase]*!| to calculate number

.nextchar:
	mov dl, byte [rdi + r8]
	cmp dl, 9
	je _ft_atoi_base.whitespace
	cmp dl, 10
	je _ft_atoi_base.whitespace
	cmp dl, 11
	je _ft_atoi_base.whitespace
	cmp dl, 12
	je _ft_atoi_base.whitespace
	cmp dl, 13
	je _ft_atoi_base.whitespace
	cmp dl, 32
	je _ft_atoi_base.whitespace
	cmp dl, 45
	je _ft_atoi_base.minus
	cmp dl, 43
	je _ft_atoi_base.plus
	xor r13, r13
	jmp _ft_atoi_base.checkchar

.plus2:
	mov r12, 1
	INC r8
	jmp _ft_atoi_base.nextchar

.plus:
	cmp r12, 0
	je _ft_atoi_base.plus2
	INC r8
	jmp _ft_atoi_base.nextchar

.whitespace:
	cmp r12, 0
	jne _ft_atoi_base.exit
	INC r8
	jmp _ft_atoi_base.nextchar

.minus2:
	mov r12, -1
	INC r8
	jmp _ft_atoi_base.nextchar

.minus:
	cmp r12, 0
	je _ft_atoi_base.minus2
	imul r12, -1
	INC r8
	jmp _ft_atoi_base.nextchar

.nextchar2:
	mov dl, byte [rdi + r8]
	xor r13, r13
	jmp _ft_atoi_base.checkchar

.checkchar:
	mov bl, byte [rsi + r13]
	cmp byte [rsi + r13] , 0
	je _ft_atoi_base.negative
	cmp dl, bl
	je _ft_atoi_base.maths
	INC r13
	jmp _ft_atoi_base.checkchar

.maths:
	imul r9, r11
	add r9, r13
	INC r8
	cmp byte [rdi + r8], 0
	je _ft_atoi_base.negative
	jmp _ft_atoi_base.nextchar2

.negative:
	cmp r12, -1
	je _ft_atoi_base.negative2
	jmp _ft_atoi_base.exit

.negative2:
	imul r9, -1
	jmp _ft_atoi_base.exit

.error_exit:
	mov r9, 0
	jmp _ft_atoi_base.exit

.exit:
	mov rax, r9				;movzx rax, dl
	mov rsp, rbp
	pop rbp
	ret
