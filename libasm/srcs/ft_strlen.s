
global _ft_strlen

section .text

_ft_strlen:
	push rbp
	mov rbp, rsp

	mov rax, rdi

.loop:
	cmp byte [rax], 0
	je _ft_strlen.exit
	INC rax
	jmp _ft_strlen.loop

.exit:
	sub rax, rdi
	pop rbp
	ret