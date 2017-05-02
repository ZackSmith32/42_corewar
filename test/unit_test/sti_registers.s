.name "sti_registers"
.comment "test different values in registers set IDX_MOD = 512"

ld		%266448865, r2
ld		%-74747,r3
ld		%99999, r4
ld		%-600, 	r5
ld		%500, 	r6
ld		%490, 	r7
ld		%513, 	r8
ld		%0, 	r9
ld		%-15, 	r10

sti 	r2, r3, r4
live 	%1
sti 	r2, r3, r5
live 	%1
sti		r2, r6, r7
live 	%1
sti		r2, r8, r4
live 	%1
sti		r2, r9, r4
live 	%1
sti		r2, r10, r3

