section .data
	x dd 10		; define double word (32-bit)
	name db "Nahom", 0

section .bss
	y resd 1	; reserve a 32-bit variable
