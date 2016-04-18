#include "freecell.h"
#include "QPainter"

FreeCell::FreeCell(SolWindow *gameBoard)
{
    board =gameBoard;
    //setup();
}
//SolWindow *board

void FreeCell::setup(){//inital field

    //creates 8 piles
    for(int i = 20;i < 660; i+=80){
        field[i/80] = new Pile(i,140);
    }


    //*******************************************************
    //set top 4 left to have 0 cards
    //set top 4 right to have 0 cards
    //*******************************************************


    //set window dimensions and title
    board->setWindowTitle("Freecell");
    board->setFixedSize(674,485);

    newGame();
}

bool FreeCell::canDrag(Card *c){ //spider same suit, others alternate colors, all must be sequential
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

Pile* FreeCell::canDrop(QPoint p){ //[0] card must be one less and correct suit/color than top one
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

void FreeCell::winCon(){ //Notification when wins.

}

void FreeCell::drawBoxes(){

    QPainter painter(board);
    QBrush brush;
    brush.setColor(Qt::black);
    painter.setBrush(brush);


        for(int i = 10; i < 640; i+=80)
        {
            if(i == 330) i+=15;
            QRect r(i,30,71,96);
            painter.drawRect(r);
        }
        //board->update();
}

FreeCell::~FreeCell(){
    for(int i = 0; i < 8; i++){
        delete field[i];
    }
    delete deck;
}
void FreeCell::newGame(){
    resetField();
    deck = new Deck(board);
    deck->reset(52,true); //set all faceup

    //shuffle deck 5x for good measure
    for(int i = 0; i < 5; i++)
        deck->shuffle(52);

    deck->dealAll(field,8);
}

