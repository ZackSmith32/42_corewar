#by max

.name		"garg"
.comment	"hello world"

#r2: offset
#r3: cache
#r4: increment

			sti		r1, %:live, %1
			ld		%4, r4
hello:		ld		%0, r2

live:		live	%1
			ldi		r2, %:hello,r1
			sti		r1, %200, r2
			add		r4, r2, r2
			and		r1, %0, r1
			zjmp	%:live
