global ft_read

section .text
extern __errno_location ;_error function appears to be named like this in the "error.h" for the VM's Linux

ft_read:
	mov rax, 0 ;function is no.0 = read function
	syscall ; all other arguments already set so just call write function
	cmp rax, 0 ;compare output with 0
	jl error ;if less than 0 go to error function
	jmp no_error ;make sure errno is 0

no_error:
	mov r9, 0
	push rax ; save rax for later use
	call __errno_location wrt ..plt ;call to get pointer to error
	mov [rax], r9 ; put 0 into the location of error
	pop rax ; restore original rax 
	ret
error:
	neg rax
	mov r8, rax ;mov error number into rdi
	call __errno_location wrt ..plt;call to get pointer to error
	mov [rax], r8 ; put error number into the location of error
	mov rax, -1 ;make rax now -1 so return val will be -1
	ret
