global ft_list_size

section .text

ft_list_size:
	xor rax, rax ;counter = 0
	push rdi
	jmp loop
loop:
	cmp rdi, 0 ;if it is zero return
	je end
	mov rdi, [rdi + 8] ;change rdi to next- pointer is 1 byte, so adding 8 bits goes to next pointer
	inc rax ;increase counter
	jmp loop
end:
	pop rdi
	ret

