#ifndef DECK_H
#define DECK_H


#include "card.h"
#include "QWidget"
class Deck
{
private:
    int cardsInDeck;

public:
    Card *deck[52];
    void dealX(int n);
    void dealAll();
    void shuffle();
    Deck(QWidget *parent);
    ~Deck();
};

#endif // DECK_H
