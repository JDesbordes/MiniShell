
global _ft_strcmp

section .text

_ft_strcmp:
	push rbp
	push rbx
	cmp rsi, 0
	cmp rdi, 0
	mov rbp, rsp

	xor rcx, rcx
.loop:
	mov al, [rsi]
	cmp [rdi], al
	jne _ft_strcmp.exit
	INC rdi
	INC rsi
	cmp byte [rsi], 0
	je _ft_strcmp.exit
	cmp byte [rdi], 0
	je _ft_strcmp.exit
	jmp _ft_strcmp.loop

.exit:
	movzx rax, BYTE [rdi]
	movzx rbx, BYTE [rsi]
	sub rax, rbx
	pop rbx
	pop rbp
	ret