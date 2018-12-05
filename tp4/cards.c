#include "cards.h"
#include <stdlib.h>
#include <stdio.h>

void display_hand(t_card *head)
{
    t_card *ptr = NULL;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d\n", ptr->value);
        printf("%d\n", ptr->color);
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

void dispatch_2p(t_card* deck, t_card **hand_p1, t_card **hand_p2)
{
    int nb_cards = 32;
    t_card *Card = deck;
    t_card *addr_prec;
    t_card *addr_prec_p1 = NULL;

    for(int i=0;i<16;i++)
    {
        int alea_card = rand() % nb_cards;
        for(int j = 1; j < alea_card;j++)
        {
            addr_prec = Card;
            Card = Card->next;
        }
        addr_prec->next = Card->next;
        Card->next = addr_prec_p1;
        hand_p1 = &Card;
        addr_prec_p1 = Card;

    }
}