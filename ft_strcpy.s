; str1 = rsi, str2 = rdi

section .text
    global ft_strcpy
ft_strcpy:
	xor rax, rax ; initalise rax to 0
	again: ;declare 'label' for loop
		mov cl, [rsi + rax] ;move rsi[rax] to cl (a 8-bit char-sized register)
		mov [rdi + rax], cl ;send the char into str2[rax]
		cmp cl, 0 ;check if cl is NULL
        	je  exit ;if it is, exit
        	inc rax ;if not increase rax- our counter
		jmp again ;repeat
	exit:
		mov [rdi + rax], cl
		mov rax, rdi ;send str2 into rax
		ret ;return (rax automatically returns)
