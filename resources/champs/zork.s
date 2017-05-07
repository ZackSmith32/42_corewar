.name "ldi_carry"
.comment "test if ldi modifies carry"

zjmp 	10
ld		15, r2
ldi		4, 6, r2


l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
