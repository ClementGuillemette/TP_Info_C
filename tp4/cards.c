#include "cards.h"
#include <stdlib.h>
#include <stdio.h>

void display_hand(t_card *head)
{
    t_card *ptr = NULL;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d , %d \n", ptr->value, ptr->color);
        ptr = ptr->next;
    }
}

t_card *create_deck()
{
    struct s_card *addr_lastCard = NULL;
    t_card *Card;

    for (int i = 0; i < MAX_VAL; i++)
    {
        for (int j = 0; j < MAX_COLOR; j++)
        {
            Card = (t_card *)malloc(sizeof(t_card));
            Card->value = i;
            Card->color = j;
            Card->next = addr_lastCard;
            addr_lastCard = Card;
        }
    }
    return Card;
}

// void dispatch_2p(t_card* deck, t_card **hand_p1, t_card **hand_p2)
// {
// }