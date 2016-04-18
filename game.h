#ifndef GAME_H
#define GAME_H
#include "pile.h"
#include "solwindow.h"
#include "deck.h"
#include "pile.h"
//class Deck;
class SolWindow;
class Card;
class Game
{
public:
    SolWindow *board;
    int gameType = 0; //0 = klondike, 1 = spider, 2 = freecell
    Deck *deck = 0;
    Pile *fDown = new Pile(-100,-100);
    Pile *field[10];
    Pile *moving= new Pile(-100,-100);

    virtual void setup()=0; //inital field
    virtual void deal()=0; //spider 1 to each, klondike is 3 up top
    virtual bool canDrag(Card *c)=0; //spider same suit, others alternate colors, all must be sequential
    void drag(int x, int y){
        moving->movePile(x,y);
    }
    virtual Pile* canDrop(QPoint p)=0; //[0] card must be one less and correct suit/color than top one
    void drop(Pile *p){
        for(int i = 0; i < moving->cardsInPile; i++){
            p->addCard(moving->stack[i],false);
        }
        moving->cardsInPile = 0;
    }
    void returnToPile(){
        //always to back to original pile, add logic to add to current pile
        // if able to based on where cursor is

        for(int i = 0 ; i < moving->cardsInPile;i++){
            moving->stack[i]->prevPile->addCard(moving->stack[i],false);
        }

        moving->cardsInPile = 0;
    }

    virtual void winCon()=0; //Notification when wins.
    virtual void drawBoxes() = 0;
    virtual void newGame() =0;
    void resetField(){
        if (deck) delete deck;
        fDown->cardsInPile = 0;
        for(int i = 0; i < 8; i++){
            field[i]->cardsInPile=0;
        }
        moving->cardsInPile = 0;
    }
    void addMoving(Card *c,int wX, int wY){
        //c->offset= event->localPos().toPoint(); //set offset of crard position
        moving->movePile(wX-c->offset.x(),wY-c->offset.y());
        int cardsInPile = c->pileIn->cardsInPile;
        c->prevPile = c->pileIn;
        for(int i = c->posInPile; i < cardsInPile ;i++){
            //add to moving pile
            c->prevPile->stack[i]->prevPile = c->prevPile; //I'm giving the janitor unfilterd access to the server
            c->prevPile->moveCard(moving,c->prevPile->stack[i]);

        }
    }
    virtual void doubleClick(Card *c) = 0;
    void flipAfterMove(Pile *p){
        if(p->cardsInPile>0){
            if(!p->getTopCard()->isFaceUp)p->getTopCard()->flip();
        }
    }

    ~Game(){
        delete deck;
        delete fDown;
        delete moving;
    }
    friend class Card;
};









#endif // GAME_H
