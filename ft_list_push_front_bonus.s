global ft_list_push_front
section .text
extern malloc

ft_list_push_front:
	push rdi ;save pointer to list start
	push rsi ; save data
	mov rdi, 16
	call malloc ;malloc 16 bits (size of t_list)
	pop rsi ; restore pointer to start
	pop rdi ; restore data
	cmp rax, 0 ;check if malloc returns null
	je error
	mov [rax], rsi ;put the data in new node.data
	mov rdx, [rdi] ; put orig start node in temp
	mov [rax + 8], rdx ;put start node into new.next
	mov [rdi], rax ; put new node into pointer to list start
	ret
error:
	mov rax, -1
	ret
