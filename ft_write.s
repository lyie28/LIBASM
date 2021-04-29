global ft_write

section .text
extern __errno_location ;_error function appears to be named like this in the "error.h" for the VM's Linux

ft_write:
	mov rax, 1 ;function is no.1 = write function
	syscall ; all other arguments already set so just call write function
	cmp rax, 0 ;compare output with 0
	jl error ;if less than 0 go to error function
	jmp no_error

no_error: 
	mov r8, 0 ;will need this late to ensure errno is 0
	push rax ;save rax to memory for later use
	call __errno_location wrt ..plt;call to get pointer to error
	mov [rax], r8 ; put 0 into errno
	pop rax ; bring back original rax
	ret ;else return
error:
	neg rax ;errno needs to be times by -1 else there is error with signed/unsigned
	mov r8, rax ;mov error number into rdi
	call __errno_location wrt ..plt;call to get pointer to error
	mov [rax], r8; put error number into the location of error
	mov rax, -1 ;make rax now -1 so return val will be -1
	ret
