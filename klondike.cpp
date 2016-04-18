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




void Klondike::deal(){ //spider 1 to each, klondike is 3 up top

}

bool Klondike::canDrag(Card *c){ //spider same suit, others alternate colors, all must be sequential
            if(c->pileIn->getTopCard() == c){
               return true; //if top card it's always movable
            }
            else{
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
