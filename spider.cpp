#include "spider.h"
#include "QPainter"

Spider::Spider(SolWindow *gameBoard, int i)
{
    board =gameBoard;
    difficulty = i;
    //setup();
}
//SolWindow *board

void Spider::setup(){//inital field
    //creates 10 piles
    for(int i = 20;i < 820; i+=80){
        field[i/80] = new Pile(i,40);
    }

    //moves facedown to bottom right, might need 4 here
    fDown->movePile(765,380);

    //sets window size and title
    board->setWindowTitle("Spider");
    board->setMinimumSize(846,485);
    board->setMaximumWidth(846);

    //gets new deck, deals cards
    newGame();

}

void Spider::deal(){ //spider 1 to each, klondike is 3 up top

}

bool Spider::canDrag(Card *c){ //spider same suit, others alternate colors, all must be sequential
    if(c->pileIn->getTopCard() == c){
       return true; //if top card it's always movable
    }
    else{
        for(int i = c->posInPile; i < c->pileIn->cardsInPile-1;i++){
            if((c->pileIn->stack[i]->suit == c->pileIn->stack[i+1]->suit)// && //same suit
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

Pile* Spider::canDrop(QPoint p){ //[0] card must be one less and correct suit/color than top one
    //search piles to find location dropped
    //if top card of pile is same suti, and one greater than bottom of moving then return that pile
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

void Spider::winCon(){ //Notification when wins.

}

void Spider::drawBoxes(){
    //board->update();

}
void Spider::newGame(){
    resetField();
    field[8]->cardsInPile = 0;
    field[9]->cardsInPile= 0;

    deck = new Deck(difficulty,board);

    //all face down
    deck->reset(104,false);

    //shuffles 5 times for no reason but good measure
    for(int i = 0; i < 5; i++)
        deck->shuffle(104);

    //deals 6 cards to first 4 piles and 5 cards to the next 6
    //flips top card
    for(int i = 0; i < 10; i++){
        if(i<4)
            deck->dealX(field[i],6,false);
        else{
            deck->dealX(field[i],5,false);
        }
        field[i]->getTopCard()->flip();
    }
    //deals the rest into the deck
    deck->dealX(fDown,50,true);
}
