section .data
		text1 db "You are in function B now.", 10, 0
		text2 db "The number interpreted as 8byte ASCII String:", 0
		text3 db "In B before calling the function C", 10, 0
		text4 db 10, "--------------------------------------", 10, 0	


section .bss
		name resb 8


section .text
	
		extern C
		global B


B:		
		;--------
		mov		[name], rdi			; tring to access by first storing in memory
		;--------
		;--------
		mov 	rax, text1
		call _print
		;--------
		;--------
		mov 	rax, text2
		call _print
		;--------
		;--------
		call _interpreter
		;--------
		;--------
		mov 	rax, text3
		call _print
		;--------
		;--------
		mov 	r10, $C
		mov [rbp + 8], r10
		ret
		;--------

_interpreter:

		;-------- printing by memory saving method (this prints correct but in reverse order)
		;after normal comilation of this file it throws an error of some pie object which i want to clarify)
		
		;--------
		mov 	rax, text4
		call _print
		;--------
		;--------
		mov 	rax, 1
		mov 	rdi, 1
		mov 	rsi, name
		mov 	rdx, 8
		syscall
		;--------
		;--------
		mov 	rax, text4
		call _print
		;--------
		;--------
		ret
		;--------
		

_print:
		;--------
		push 	rax
		mov 	rbx, 0
		;--------


_printLoop:

		;--------
		inc 	rax
		inc 	rbx
		mov 	cl, [rax]
		cmp 	cl, 0
		jne _printLoop
		;--------
		;--------
		mov 	rax, 1
		mov 	rdi, 1
		pop 	rsi
		mov 	rdx, rbx
		syscall
		;--------
		;--------
		ret
		;--------
	