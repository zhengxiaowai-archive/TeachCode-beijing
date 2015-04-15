.globl _start

_start:
	ldr r1, =0xE0200280
	ldr r0, =0x00000001
	str r0,[r1]

	ldr r1, =0xE0200284
	mov r0, #0
	str r0, [r1]

halt:
	b halt
