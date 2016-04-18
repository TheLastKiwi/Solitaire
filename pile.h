#ifndef PILE_H
#define PILE_H
#include "card.h"

class Pile
{
private:


    int x;
    int y;
public:
    //Moved to public
    Card *stack[52];
    //-------------
    int cardsInPile = 0;
    void moveCard(Pile *toPile, Card *c);
    Card *getTopCard();
    void addCard(Card *c, bool deck);

    void movePile(int xPos, int yPos);
    int getX(){return x;}
    int getY(){return y;}
    Pile(int x, int y);
    Pile* prev = 0;
    Pile();
    ~Pile();

};

#endif // PILE_H
