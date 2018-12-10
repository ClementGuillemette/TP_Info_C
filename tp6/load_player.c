#include "world.h"
#include <dlfcn.h>
#include <stdio.h>
#include "player.h"

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void load_players(int argc, char *argv[])
{
    int i = 0;
    char *error;
    
    for (i = 0; i < MAX_PLAYERS; i++)
    {
        // A Completer 
        
        players[i]->so_handle = dlopen(argv[i+1], RTLD_LAZY);
        if (!players[i]->so_handle)
        {
            fputs(dlerror(), stderr);
            exit(1);
        }

        players[i]->get_action = dlsym(players[i]->so_handle, "get_action");
        if ((error = dlerror()) != NULL)
        {
            fputs(error, stderr);
            exit(1);
        }
    }
}