
#include "actions.h"
#include "player.h"
#include "param.h"
#include "world.h"

#define DASH_LENGTH 8

static void (*pf_actions[ACTION_NUMBER])(t_player *p_player) = {0};

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_still(t_player *p_player)
{
    p_player->credits--;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_move_l(t_player *p_player)
{
    // positionne le joueur
    p_player->x = (p_player->x == 0) ? MAP_SIZE - 1 : p_player->x - 1;

    // debite les credits
    p_player->credits--;

    // peint la zone de jeu
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_move_r(t_player *p_player)
{
    // positionne le joueur
    p_player->x = (p_player->x == MAP_SIZE - 1) ? 0 : p_player->x + 1;

    // debite les credits
    p_player->credits--;

    // peint la zone de jeu
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_move_u(t_player *p_player)
{
    // positionne le joueur
    p_player->y = (p_player->y == 0) ? MAP_SIZE - 1 : p_player->y - 1;

    // debite les credits
    p_player->credits--;

    // peint la zone de jeu
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_move_d(t_player *p_player)
{
    // positionne le joueur
    p_player->y = (p_player->y == MAP_SIZE - 1) ? 0 : p_player->y + 1;

    // debite les credits
    p_player->credits--;

    // peint la zone de jeu
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_dash_l(t_player *p_player)
{
    for (int i = 0; i < 8; i++)
    {
        // positionne le joueur
        p_player->x = (p_player->x == 0) ? MAP_SIZE - 1 : p_player->x - 1;

        // peint la zone de jeu
        world_paint_spot(p_player->x, p_player->y, p_player->id);
    }
    // debite les credits
    p_player->credits -= 10;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_dash_r(t_player *p_player)
{
    for (int i = 0; i < 8; i++)
    {
        // positionne le joueur
        p_player->x = (p_player->x == MAP_SIZE - 1) ? 0 : p_player->x + 1;

        // peint la zone de jeu
        world_paint_spot(p_player->x, p_player->y, p_player->id);
    }
    // debite les credits
    p_player->credits -= 10;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_dash_u(t_player *p_player)
{
    for (int i = 0; i < 8; i++)
    {
        // positionne le joueur
        p_player->y = (p_player->y == 0) ? MAP_SIZE - 1 : p_player->y - 1;

        // peint la zone de jeu
        world_paint_spot(p_player->x, p_player->y, p_player->id);
    }
    // debite les credits
    p_player->credits -= 10;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_dash_d(t_player *p_player)
{
    for (int i = 0; i < 8; i++)
    {
        // positionne le joueur
        p_player->y = (p_player->y == MAP_SIZE - 1) ? 0 : p_player->y + 1;

        // peint la zone de jeu
        world_paint_spot(p_player->x, p_player->y, p_player->id);
    }
    // debite les credits
    p_player->credits -= 10;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_teleport_l(t_player *p_player)
{
    for (int i = 0; i < 8; i++)
    {
        // positionne le joueur
        p_player->x = (p_player->x == 0) ? MAP_SIZE - 1 : p_player->x - 1;
    }
    // debite les credits
    p_player->credits -= 4;

    // peint la zone de jeu
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_teleport_r(t_player *p_player)
{
    for (int i = 0; i < 8; i++)
    {
        // positionne le joueur
        p_player->x = (p_player->x == MAP_SIZE - 1) ? 0 : p_player->x + 1;
    }
    // debite les credits
    p_player->credits -= 4;

    // peint la zone de jeu
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_teleport_u(t_player *p_player)
{
    for (int i = 0; i < 8; i++)
    {
        // positionne le joueur
        p_player->y = (p_player->y == 0) ? MAP_SIZE - 1 : p_player->y - 1;
    }
    // debite les credits
    p_player->credits -= 4;

    // peint la zone de jeu
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_teleport_d(t_player *p_player)
{
    for (int i = 0; i < 8; i++)
    {
        // positionne le joueur
        p_player->y = (p_player->y == MAP_SIZE - 1) ? 0 : p_player->y + 1;
    }
    // debite les credits
    p_player->credits -= 4;

    // peint la zone de jeu
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_splash(t_player *p_player)
{
    p_player->credits += 10;
    action_move_r(p_player);
    action_move_d(p_player);
    action_move_l(p_player);
    action_move_l(p_player);
    action_move_u(p_player);
    action_move_u(p_player);
    action_move_r(p_player);
    action_move_r(p_player);
    action_move_d(p_player);
    action_move_l(p_player);
    p_player->credits -= 8;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_bomb(t_player *p_player)
{
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void actions_init(void)
{
    /* affecte le pointeur de fonction "action_still" a une case du tableau 
       correspondant */
    pf_actions[ACTION_STILL] = action_still;

    pf_actions[ACTION_MOVE_L] = action_move_l;
    pf_actions[ACTION_MOVE_R] = action_move_r;
    pf_actions[ACTION_MOVE_U] = action_move_u;
    pf_actions[ACTION_MOVE_D] = action_move_d;

    pf_actions[ACTION_DASH_L] = action_dash_l;
    pf_actions[ACTION_DASH_R] = action_dash_r;
    pf_actions[ACTION_DASH_U] = action_dash_u;
    pf_actions[ACTION_DASH_D] = action_dash_d;

    pf_actions[ACTION_TELEPORT_L] = action_teleport_l;
    pf_actions[ACTION_TELEPORT_R] = action_teleport_r;
    pf_actions[ACTION_TELEPORT_U] = action_teleport_u;
    pf_actions[ACTION_TELEPORT_D] = action_teleport_d;

    pf_actions[ACTION_SPLASH] = action_splash;
    pf_actions[ACTION_BOMB] = action_bomb;

    /* A COMPLETER */
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void actions_do(t_player *p_player, enum action act_id)
{
    pf_actions[act_id](p_player);
}
