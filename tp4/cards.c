#include "cards.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void display_hand(t_card *head)
{
    char *convert_color[MAX_COLOR] =
        {
            "PIQUE",
            "COEUR",
            "CARREAU",
            "TREFLE"};

    char *convert_value[MAX_VAL] =
        {
            "SEPT",
            "HUIT",
            "NEUF",
            "DIX",
            "VALET",
            "REINE",
            "ROI",
            "AS"};

    t_card *ptr = NULL;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%s de %s\n", convert_value[ptr->value], convert_color[ptr->color]);
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

void dispatch_2p(t_card *deck, t_card **hand_p1, t_card **hand_p2)
{
    int nb_cards = 31;
    t_card *Card = deck;
    struct s_card *addr_prec = NULL;
    struct s_card *addr_prec_p1 = NULL;

    while (nb_cards > 16)
    {
        for (int i = 0; i < 16; i++)
        {
            Card = deck;
            srand(time(NULL));
            int alea_card = rand() % nb_cards;
            printf("nb alea : %d\n", alea_card);

            for (int j = 0; j < alea_card; j++)
            {
                addr_prec = Card;
                if (Card->next->next == NULL)
                {
                    Card = deck;
                }
                else
                {
                    Card = Card->next;
                }
            }

            addr_prec->next = Card->next;
            (*hand_p1) = Card;
            Card->next = addr_prec_p1;
            addr_prec_p1 = Card;
            nb_cards--;
        }
    }
    (*hand_p2) = deck;
}