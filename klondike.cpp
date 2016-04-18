#include "klondike.h"
#include "QPainter"

Klondike::Klondike(SolWindow *gameBoard)
{
    board =gameBoard;
}
//SolWindow *board

void Klondike::setup(){//inital field

    //creates 8 piles
    for(int i = 20;i < 660; i+=80){
        field[i/80] = new Pile(i,140);
    }

    fDown->movePile(20,30); //moves deck to top left
    fDown->isDeckStyle = true;
    fUpPile->isDeckStyle = true;

    //sets window size and title
    board->setWindowTitle("Klondike");
    board->setMinimumSize(684,485);
    board->setMaximumWidth(684);

    //**************************************************
    //move top 4 right piles off screen
    //move dealt pile off screen
    //**************************************************

    //creates a new deck and deals
    newGame();

}

void Klondike::flipOver(){
    for(int i = fUpPile->cardsInPile-1; i >=0; i--){
        fUpPile->stack[i]->flip();
        fDown->addCard(fUpPile->stack[i],true);
    }
    fUpPile->cardsInPile = 0;

}


void Klondike::deal(){ //spider 1 to each, klondike is 3 up top
    for(int i = 0; i < fUpPile->cardsInPile; i++){
        fUpPile->stack[i]->move(100,30);
    }
    int dealCards = std::min(fDown->cardsInPile,3);
    int initCards = fDown->cardsInPile;
    for(int i = initCards-1; i>initCards-1-dealCards;i--){
        fDown->stack[i]->flip();
        fDown->moveCard(fUpPile,fDown->stack[i]);
    }
    for(int i = 0; i < dealCards; i++){
        fUpPile->stack[fUpPile->cardsInPile-1-((dealCards-1)-i)]->move(100+20*i,30);
        fUpPile->getTopCard()->raise();
    }
}

bool Klondike::canDrag(Card *c){ //spider same suit, others alternate colors, all must be sequential
            if(!c->isFaceUp){
                if(c->pileIn->isDeckStyle){
                    deal();
                    return false;
                }
                return false;
            }

            if(c->pileIn->getTopCard() == c){
               return true; //if top card it's always movable
            }
            else{
                //if not the top card
                if(c->pileIn->isDeckStyle) return false; //if it's a deck style you can't drag it because it's the face up pile of 3s
                for(int i = c->posInPile; i < c->pileIn->cardsInPile-1;i++){
                    if((c->pileIn->stack[i]->isBlack != c->pileIn->stack[i+1]->isBlack)// && //different color
                        //(pileIn->stack[i]->value - pileIn->stack[i+1]->value)==1) && //one lower value
                        //(pileIn->stack[i]->isFaceUp == true) //and is face up
                    )
                    {
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
            return true;
}

Pile* Klondike::canDrop(QPoint p){ //[0] card must be one less and correct suit/color than top one
    //search piles to find location dropped
    //if top card of pile is opposite color, and one greater than bottom of moving then return that pile
    //elese return 0
    if (moving->cardsInPile > 1){
        for(int i = 0; i < 8; i++){
            if((p.x() >= field[i]->getX()) && (p.x()<= field[i]->getX()+71)) return field[i];
        }
    }
    else{
        //check all possible piles


        //rough check field
        for(int i = 0; i < 8; i++){
            if((p.x() >= field[i]->getX()) && (p.x()<= field[i]->getX()+71)) return field[i];
        }
    }
    return 0;
}

void Klondike::winCon(){ //Notification when wins.

}

void Klondike::drawBoxes(){
    QPainter painter(board);
    QBrush brush;
    brush.setColor(Qt::black);
    painter.setBrush(brush);

    for(int i = 345; i < 640; i+=80)
    {
        QRect r(i,30,71,96);
        painter.drawRect(r);
    }
    //board->update();
}
void Klondike::newGame(){
    resetField();
    //creates a new deck
    deck = new Deck(board);

    //all cards face down and shuffle
    deck->reset(52,false);
    deck->shuffle(52);

    //deals cards to each pile appropriately and flips top card
    for(int i = 0; i < 8; i++){
        deck->dealX(field[i],i+1,false);
        field[i]->getTopCard()->flip();
    }
    //deals the rest of the cards to the deck
    deck->dealX(fDown,16,true);
}
