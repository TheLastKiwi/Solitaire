#ifndef PILE_H
#define PILE_H


#include "card.h"
#include <iostream>

//class Card;
class Pile
{
private:

    Card *stack[52];
    int x;
    int y;
public:

    int cardsInPile = 0;
    void moveCard(Pile *toPile, Card *c);
    Card *getTopCard();
    void addCard(Card *c, bool deck);
    void movePile(int xPos, int yPos);
    Pile(int x, int y);
    Pile();
    ~Pile();

};

#endif // PILE_H
