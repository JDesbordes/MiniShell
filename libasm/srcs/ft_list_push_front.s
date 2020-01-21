section .text
    global _ft_list2_push_front
    extern _ft_create_elem
_ft_list2_push_front:
    cmp     rdi, 0
    je      .return
    cmp     rsi, 0
    je      .return
    push    rdi
    push    rsi
    sub     rsp, 8
    mov     rdi, rsi
    call    _ft_create_elem
    add     rsp, 8
    pop     rsi
    pop     rdi
    cmp     rax, 0
    je      .return
    mov     rdx,	qword [rdi]		;check if rdi is NULL
    cmp     rdx,    0
    je      .empty_list2				;if list2 isnt empty point to next
    mov     qword [rax + 8], rdx	
.empty_list2:
    mov     qword [rdi], rax
.return:
    ret