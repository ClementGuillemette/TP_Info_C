#include "cards.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{

    t_card *deck = create_deck();
    display_hand(deck);
    
    t_card *p1 = NULL;
    t_card *p2 = NULL;

    p1 = (t_card *)malloc(sizeof(t_card));
    p2 = (t_card *)malloc(sizeof(t_card));

    dispatch_2p(deck, &p1, &p2);

    printf("player 1\n");
    display_hand(p1);
    printf("\nplayer 2\n");
    display_hand(p2);

    return 0;
}
