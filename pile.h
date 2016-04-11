#ifndef PILE_H
#define PILE_H


#include "card.h"
//class Card;
class Pile
{
private:
    int cardsInPile;
    Card *stack[52];
public:
    void moveCard(Pile *toPile);
    Card *getTopCard();
    void addCard(Card *c);
    Pile();
};

#endif // PILE_H
