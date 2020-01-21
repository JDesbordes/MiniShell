
global _ft_strcpy

section .text

_ft_strcpy:
	push rbp
	mov rbp, rsp

	xor rcx, rcx
.loop:
	mov ax, [rsi + rcx]
	mov [rdi + rcx], ax
	INC rcx
	cmp byte [rsi + rcx], 0
	jne _ft_strcpy.loop

.exit:
	mov rax, rdi
	;mov rsp,rbp
	pop rbp
	ret