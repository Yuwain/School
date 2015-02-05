TITLE Assignment 1.3						(Assign1c.asm)

; Description: Generates 16 randomly colored strings, 10 characters long in [a-z]
;
; First string is in black and won't show up on the background, but is there

INCLUDE Irvine32.inc

.data
	message byte "Generating 16 random strings...", 0dh, 0Ah, 0

.code
main PROC
	call Randomize			;Seeds future random calls
	
	mov edx, OFFSET message
	call WriteString

	mov ecx, 16				;Initialize loop counter for random string amount
	push 0					;Pushes our starting color to the stack

write:
	;Changes text color
	pop eax					;Move color to eax so it can be used
	call SetTextColor
	inc eax					;Go to next color
	push eax				;Push it back onto the stack so we can use eax

	push ecx				;Push loop counter to stack so we can use ecx
	call randomString
	pop ecx					;Get loop counter from stack so we can continue
	loop write
	
	call crlf

	exit
main ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;			Generate a 10 character long			 ;
;				 string, all in [a-z]				 ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
randomString PROC
	mov ecx, 10				;Initialize loop counter for length of string
	
string:
	;Generates a random lower case letter and writes it to screen
	mov eax, 26				;Set upper bound of random
	call RandomRange		;Get a random number [0-26)
	add eax, 97				;Add 97 to get [a-z]
	call WriteChar			;Write the random character to the screen
	loop string
	
	call crlf

	ret
randomString ENDP

END main