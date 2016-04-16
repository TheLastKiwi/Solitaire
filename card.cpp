#include "card.h"
#include "QMouseEvent"

#include "deck.h"
#include "pile.h"
#include "solwindow.h"


//Public
Card::Card(int val, QString im, bool isBl, int cardSuit, SolWindow *parent):
    front(im),value(val),isBlack(isBl),suit(cardSuit)
{
    gameWindow = parent;
    setParent(parent);
    setFixedSize(71,96);
    setPixmap(back);
    isFaceUp = false;
    //connect(this,SIGNAL(clicked()),this,SLOT(onClick()));

}
Card::~Card(){

}
void Card::flip(){

    if (isFaceUp){
        setPixmap(back);
    }
    else{
        setPixmap(front);
    }
    isFaceUp = !isFaceUp;
}
Card *Card::operator =(Card *c){
    return c;
}

//Protected
void Card::mousePressEvent(QMouseEvent* event)
{
    std::cout << event->localPos().x() << " " << event->localPos().y() << std::endl;
    if(event->button() == Qt::LeftButton){//if left click
        offset= event->localPos().toPoint(); //set offset of crard position
        bool movable = true;  //one time variable to determine if the card stack is movable
        if(pileIn->getTopCard() == this){
            movable == true; //if top card it's always movable
        }
        else{
            for(int i = posInPile; i < pileIn->cardsInPile-1;i++){
                if((pileIn->stack[i]->isBlack != pileIn->stack[i+1]->isBlack)){// && //different color
                    //((pileIn->stack[i]->value - pileIn->stack[i+1]->value)==1)){ //one lower value
                    continue;
                }
                else{
                    movable = false;
                    break;
                }
            }
        }

        if (movable){ //so if the stack is movable


            //window->moving->movePile(event->windowPos().x()-offset.x(),event->windowPos().y()-offset.y()-20);
            gameWindow->moving->movePile(event->windowPos().x()-offset.x(),event->windowPos().y()-offset.y());
            int cardsInPile = pileIn->cardsInPile;
            prevPile = pileIn;
            for(int i = posInPile; i < cardsInPile ;i++){
                //add to moving pile
                prevPile->stack[i]->prevPile = prevPile; //I'm giving the janitor unfilterd access to the server
                prevPile->moveCard(gameWindow->moving,prevPile->stack[i]);

            }
        }
    }
}
void Card::mouseMoveEvent(QMouseEvent *ev){                                    //-20 for toolbar
    gameWindow->moving->movePile(ev->windowPos().x()-offset.x(),ev->windowPos().y()-offset.y());
}

void Card::mouseReleaseEvent(QMouseEvent *ev){

    //always to back to original pile, add logic to add to current pile
    // if able to based on where cursor is
    if(prevPile == gameWindow->fDown){ //if it's the deck
                  //will need to change this for all decks(spider has 5)
        gameWindow->fDown->addCard(gameWindow->moving->stack[0],true);
    }
    else{
        for(int i = 0 ; i < gameWindow->moving->cardsInPile;i++){
            gameWindow->moving->stack[i]->prevPile->addCard(gameWindow->moving->stack[i],false);
        }
    }
    gameWindow->moving->cardsInPile = 0;
}

//Public Slots


