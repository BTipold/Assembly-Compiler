MEMORY SIZE: 512
INSTRUCTIONS: 0
STACK: 200
HEAP: 300

MAIN:
	addi	r3, r6, 624
	and		r1, r2, r3
	ldi		r1, 300

LOOP:
	st		r2, 100
	shra	r2, r3, r4
	brpl	r2, LOOP