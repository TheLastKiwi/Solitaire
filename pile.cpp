#include "pile.h"

Pile::Pile(int xPos, int yPos):x(xPos),y(yPos)
{

}
Pile::Pile():x(25),y(25){
    //This will be used for the face down deck
}

void Pile::moveCard(Pile *toPile, Card *c){
    cardsInPile--;
    toPile->addCard(c,false);
}
Card *Pile::getTopCard(){
    return stack[cardsInPile];
}

void Pile::addCard(Card *c, bool deck){
    c->pileIn = this;
    c->posInPile= cardsInPile++;
    if(deck){
        c->move(x,y);
    }
    else{
        c->move(x,y+cardsInPile*20);
    }
    std::cout << cardsInPile << std::endl;

    stack[cardsInPile] = c;
}

Pile::~Pile(){
    for(int i = 0; i < 52;i++){
        delete stack[i];
    }
}
void Pile::movePile(int xPos, int yPos){
    x=xPos;
    y=yPos;
}
