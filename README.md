# 42 corewar

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

A variant of the Core War game developed by D. G. Jones [https://en.wikipedia.org/wiki/Core_War](https://en.wikipedia.org/wiki/Core_War). Program run and tested on macos and ubuntu 10.11.6 and Ubuntu 16.04.

This is a copy of school 42's implementaion. Code dumped at any time when run with the same champion will be the same.

Reference materials incuding compiled macos executables, instruction pdf's, and champtions can be found in /resources.

