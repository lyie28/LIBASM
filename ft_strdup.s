;str 1 = rdi

global ft_strdup

section .text
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
	push rdi
	call ft_strlen ;since rdi = str1, all will work
	pop rdi 
	inc rax ;adjust for null char
	mov rsi, rdi
	push rsi
	mov rdi, rax ; move strlen output to rdi- ready for malloc
	call malloc wrt ..plt
	cmp rax, 0 ;check for error
	je error
	pop rsi
	mov rdi, rax ;send output of malloc (dest) to rdi (par 1)
	call ft_strcpy ; (par 2 is already str1- source), call strcpy
	ret
	
error:
	mov rax, 0
	ret
