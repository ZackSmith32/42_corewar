.name "pork"
.comment "porkie lil pig"

l2:		sti r1, %:live, %1
		ld	%7, r3
		ldi	r3, %3, r4
		and r1, %0, r1

live:	live %1
		zjmp %:live
