#include "actions.h"
#include <stdio.h>
#define MAX_PLAY_ACTION 24

char play_actions[] = {
    ACTION_MOVE_L,
    ACTION_MOVE_L,
    ACTION_MOVE_U,
    ACTION_MOVE_U,
    ACTION_MOVE_R,
    ACTION_MOVE_R,
    ACTION_MOVE_D,
    ACTION_MOVE_D,

    ACTION_TELEPORT_L,
    ACTION_TELEPORT_D,
    ACTION_TELEPORT_D,

    ACTION_DASH_L,
    ACTION_DASH_U,
    ACTION_DASH_R,
    ACTION_DASH_D,
 
    ACTION_TELEPORT_L,
    ACTION_SPLASH,
    ACTION_TELEPORT_D,
    ACTION_SPLASH,

    ACTION_TELEPORT_D,

    ACTION_TELEPORT_L,
    ACTION_TELEPORT_R,
    ACTION_TELEPORT_U,
    ACTION_TELEPORT_D,    
};

char get_action()
{
    static unsigned int idx = 0;
    char ret_val = 0;

    printf("player 1 action:[%u]\n", idx);
    ret_val = play_actions[idx];
    idx++;
    if (idx >= MAX_PLAY_ACTION)
    {
        idx = 0;
    } 
    return (ret_val);
}