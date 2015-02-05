TITLE Assignment 1.1						(Assign1a.asm)

; Description: Solves problems in form
;	finalVal = A[3] - (A[0] - A[1]) - A[2]
;	finalVal = A[3] - A[0] + A[1] - A[2]

INCLUDE Irvine32.inc

.data
array1 dword 4 dup(?)
finalVal dword ?

.code
main PROC
	mov eax, [array1+12]	;eax = A[3]
	sub eax, [array1]		;eax = A[3] - A[0]
	add eax, [array1+4]		;eax = A[3] - A[0] + A[1]
	sub eax, [array1+8]		;eax = A[3] - A[0] + A[1] - A[2]
	mov finalVal, eax		;Move answer to finalVal
	exit
main ENDP

END main