TITLE Assignment 1.2						(Assign1b.asm)

; Description: Finds the sum of the first n odd integers by squaring the input
;	An odd number has the formula 2n-1
;
;	Sum(2(1)-1) = 2 - 1 = 1 = 1^2
;	Assume the Sum 1 -> n (2n-1) = n^2
;	Sum 1 -> n+1 = (Sum 1 -> n (2n-1)) + (2(n+1) - 1) 
;				 = n^2 + (2(n+1) - 1)
;				 = n^2 + 2n + 2 - 1
;				 = n^2 + 2n + 1 = (n+1)^2
;	Therefore, the sum of the first n odd integers is n^2

INCLUDE Irvine32.inc

.data
string byte "Input a number in [1, 100]: ",0
mySum word 0

.code
main PROC
	mov edx, OFFSET string
	call WriteString
	call ReadInt				;Read an integer into eax
	
	;If input isn't in [1, 100], jump to exit
	cmp eax, 1
	jb	done
	cmp eax, 100
	ja	done

	mul eax						;(eax * eax)

done:
	exit
main ENDP

END main