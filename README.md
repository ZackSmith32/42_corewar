# 42 corewar

![screenshot](/resources/screenshots/corewar1.gif)

## Description:

Tested on OS X 10.11 and Ubuntu 16.04. Requires ncurses to be installed.

A variant of the Core War game developed by D. G. Jones [https://en.wikipedia.org/wiki/Core_War](https://en.wikipedia.org/wiki/Core_War).

This is a copy of school 42's implementaion. Code dumped at any time when run with the same champion will be the same. Simulation and assembly language very greatly from original corewar game.

Reference materials incuding compiled macos executables, instruction pdf's, and champtions can be found in /resources.

### Compile and Run:

```
make
make champions
./corewar -p -v  resources/champs/Gagnant.cor resources/champs/examples/helltrain.cor resources/champs/knut.cor resources/champs/examples/bee_gees.cor
```
## Start Simulation:

```
Usage: ./corewar [-d N -s N -v [N] | -p] [-n N <champion1.cor>] <...>
-d N       : Dumps memory after N cycles then exits
-s N       : Runs N cycles, dumps memory, pauses, then repeats
-v N       : Verbosity levels, can be added together to enable several, N is optional, default is all
             - 1 : Show game state
             - 2 : Show process list
             - 4 : Show registors in process list
-p         : Display memory byte map
-n N <...> : Explicitly choose champion position
-w N       : Dumps per second, default 1
Game Settings:
-Max Players    : 4
-Max Champ Size : 682 bytes
```

## Control Game when Running with Display:

Pause/Play: space

Framerate:

	q: -10
	w: -1
	e: +1
	r: +10

Frameskip:

	a: -25
	s: -1
	d: +1
	f: +25

Reverse Frameskip:
    
	z: -25
	x: -1
	c: +1
	v: +25

Set top proccess on display:

	u: Default top process
	i: -1
	o: +1
	p: +100

Frameskip can be negative to reverse the game.

## Assembler:

	Usage: ./asm <champion.s>
    
   The assembler converts a file containing assembly instructions into a champion binary.

###	.S File Format Example:

	.name "Name of champion"
    .comment "What your champion screams when it bathes in the blood of its enemies"   
 
    #instruction	var1,		var2,			var3 ...
    	sti	r1,		%:example_label,	%1
    	ld	50, 		r4
            
    example_label:
    	live	%10
 		zjmp	%:example_label
 
 Special characters:
* ':' Label character: Proceeds the creation of a label, and preceeds the usage of a label
* '#' Comment character: Preceeds comments
* ';' Alternate comment character
* '0x': Preceeds numbers in hexadecimal format
* '%' Direct character: Preceeds direct variables. Direct variables will use the raw value of the variable.
* 'r' Registry character: Preceeds a registry number
* Variables that are not preceeded by either '%' or 'r' are indirect variables. The process will use the value in memory that is located at the offset of the indirect variable.
