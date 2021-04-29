section .text
    global ft_strlen
ft_strlen:
xor rax, rax
	again:
		mov cl, [rdi]
		cmp cl, 0
        	je  exit
        	inc rax
		inc rdi
		jmp again
	exit:
		ret
