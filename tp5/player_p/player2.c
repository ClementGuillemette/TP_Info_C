#include "actions.h"
#include <stdio.h>

#define MAX_PLAY_ACTION 20

char play_actions2[] = {
    ACTION_STILL,
    // ACTION_MOVE_L,
    ACTION_MOVE_R,
    // ACTION_MOVE_U,
    ACTION_MOVE_D,
    // ACTION_DASH_L,
    ACTION_DASH_R,
    // ACTION_DASH_U,
    ACTION_DASH_D,
    // ACTION_TELEPORT_L,
    ACTION_TELEPORT_R,
    // ACTION_TELEPORT_U,
    ACTION_TELEPORT_D,   
};

unsigned int j = 0;

char get_action()
{
    char ret_val = play_actions2[j];
    j++;
    if(j>7)
        j = 0;
    return (ret_val);
}

void player_init(t_player* p_player, uint8_t num)
{
    
}
