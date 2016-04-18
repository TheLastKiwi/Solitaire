#include "card.h"
#include "QMouseEvent"

#include "deck.h"
#include "pile.h"
#include "solwindow.h"
#include "game.h"

//Public
Card::Card(int val, QString im, bool isBl, int cardSuit, SolWindow *parent):
    front(im),value(val),isBlack(isBl),suit(cardSuit)
{
    theGame = parent->theGame;
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
    //std::cout << event->localPos().x() << " " << event->localPos().y() << std::endl;
    if(event->button() == Qt::LeftButton){//if left click


        if(theGame->canDrag(this)){
            offset=event->localPos().toPoint();
            theGame->moving->prev = pileIn;
            theGame->addMoving(this,event->windowPos().x(),event->windowPos().y());

        }

    }
}
void Card::mouseMoveEvent(QMouseEvent *ev){                                    //-20 for toolbar

        theGame->drag(ev->windowPos().x() - offset.x(),ev->windowPos().y() - offset.y());
}

void Card::mouseReleaseEvent(QMouseEvent *ev){
    Pile *movingTo = theGame->canDrop(ev->windowPos().toPoint());
    if(movingTo){
        theGame->drop(movingTo);

        if(!theGame->moving->prev->isDeck)theGame->flipAfterMove(theGame->moving->prev);
    }
    else{
        theGame->returnToPile();
    }

}

//Public Slots


