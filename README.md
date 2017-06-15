# 42 corewar

![screenshot](/resources/screenshots/corewar1.gif)

## Description:

Tested on OS X 10.11 and Ubuntu 16.04. Requires ncurses to be installed.

A variant of the Core War game developed by D. G. Jones [https://en.wikipedia.org/wiki/Core_War](https://en.wikipedia.org/wiki/Core_War).

This is a copy of school 42's implementaion. Code dumped at any time when run with the same champion will be the same. Simulation and assembly language very greatly from original corewar game.

Reference materials incuding compiled macos executables, instruction pdf's, and champtions can be found in /resources.

### Compile:

```
make
make champions
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

	+1: e
	+10: r
	-1: w
	-10: q

Frameskip:

	+1: d
	+10: f
	-1: s
	-10: a

Reverse Frameskip:
    
	z: -10
	x: -1
	c: +1
	v: +10

Set top proccess on display:

	u: -10
	i: -1
	o: +1
	p: +10

Frameskip can be negative to reverse the game.

