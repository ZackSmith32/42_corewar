.name "Name of champion"
.comment "What your champion screams when
			it bathes in the blood of its enemies"   

#instruction	var1,	var2,				var3 ...
	sti			r1,		%:example_label,	%1
	 ld			50, 	r4
		
example_label:
	live	%10
	zjmp	%:example_label
