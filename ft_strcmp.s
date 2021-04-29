; str1 = rsi, str2 = rdi

section .text
    global ft_strcmp
ft_strcmp:
	xor rax, rax ; initalise rax to 0

again: ;declare 'label' for loop
		mov cl, [rdi + rax] ;move rsi[rax] to cl (a 8-bit char-sized register)
		mov dl, [rsi + rax], ; move rdi[rax] to dl (a 8-bit char-sized reg)
		cmp cl, dl ;check if cl is same as dl
		jnz diff
		cmp cl, 0
		je same
		inc rax
		jmp again ;if it is, exit

diff:
	movzx rcx, byte [rdi + rax] ; copy just the char and fill rest of rcx
	movzx rdx, byte [rsi + rax] ; copy just the char and fill rest of rdx
	mov rax, rcx
	sub rax, rdx
	;mov rdi, rax
	;mov rax, 1
	;mov rdi, 1
	;mov rdx, 1
	;syscall
	ret

same:
	mov rax, 0 ;return 0 value
	ret
