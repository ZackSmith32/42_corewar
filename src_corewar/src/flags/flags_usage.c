#include <corewar.h>

void    print_usage(char *filename)
{
    ft_printf("Usage: %s%s%s%s%s%s%s%d%s%s%d%s%s%s",
        filename, " [-d N -s N -v [N] | -p] [-n N <champion1.cor>] <...>\n",
        "-d N       : Dumps memory after N cycles then exits\n",
        "-s N       : Runs N cycles, dumps memory, pauses, then repeats\n",
        "-v N       : Verbosity levels, can be added together to enable",
        " several, N is optional, default is all\n",
        "             - ", V_STATE, " : Show game state\n",
        "             - ", V_PROCESS, " : Show process list\n",
        "-p         : Display memory byte map\n",
        "-n N <...> : Explicitly choose champion position\n"       
        );

    exit(0);
}