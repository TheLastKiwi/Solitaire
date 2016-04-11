#include "pile.h"

Pile::Pile()
{

}
void Pile::moveCard(Pile *toPile){
    cardsInPile--;
    toPile->addCard(getTopCard());
}
Card *Pile::getTopCard(){
    return stack[cardsInPile];
}
void Pile::addCard(Card *c){
    stack[++cardsInPile] = c;
}
