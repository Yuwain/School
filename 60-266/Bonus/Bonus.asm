TITLE Bonus Assignment						(Bonus.asm)

; Description: Given arrays A and B, if A[i] and B[i] are even, D[i] = A[i] + B[i]
;	if A[i] and B[i] are odd, D[i] = A[i] - B[i] 
;	if one is odd and the other even, D[i] = (A[i]/16) + (B[i]*17)

; I didn't bother initializing the arrays because it works regardless of elements
; I also didn't bother commenting the lines that should be immediately obvious

INCLUDE Irvine32.inc

.data
A sdword 10 dup(?)			;
B sdword 10 dup(?)			;Create 3 uninitialized arrays of 10 elements
D sdword 10 dup(?)			;

.code
main PROC
	xor  esi, esi			;Set esi to 0
	mov  ecx, lengthof A	;Initialize loop counter to size of arrays
array:
	mov  eax, [A+esi]
	test eax, 1				;And A[i] with 1 to test even/odd
	jz	 firstEven			;If zf = 1, jump
	jmp  firstOdd
firstEven:
	test [B+esi], 1			;And B[i] with 1 to test even/odd
	jz	 bothEven			;If zf = 1, jump
	jmp	 neither				
bothEven:
	add  eax, [B+esi]		;eax = A[i] + B[i]
	mov  [D+esi], eax		;D[i] = A[i] + B[i]
	jmp  done
firstOdd:
	test [B+esi], 1			;And B[i] with 1 to test even/odd
	jz	 neither			;If zf = 1, jump
	jmp  bothOdd				
bothOdd:
	sub  eax, [B+esi]		;eax = A[i] - B[i]
	mov  [D+esi], eax		;D[i] = A[i] - B[i]
	jmp  done
neither:
	cdq						;Sign extend eax into edx to allow us to use idiv
	mov  [D+esi], 16		;Use D[i] to temporarily hold our divisor
	idiv [D+esi]			;eax = A[i] / 16
	push eax				;Push eax to the stack
	mov  eax, [B+esi]		;eax = B[i]
	imul eax, 17			;eax = B[i] * 17
	pop  [D+esi]			;D[i] = A[i]/16
	add  [D+esi], eax		;D[i] = A[i]/16 + B[i]*17
done:
	add  esi, type A		;Go to next position in each array
	dec  ecx				;Decrease counter
	jnz  array				;If ecx != 0, go back to start
	exit
main ENDP

END main