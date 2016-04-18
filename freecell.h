#ifndef FREECELL_H
#define FREECELL_H
#include "game.h"

class FreeCell : public Game
{
private:

public:
     void setup(); //inital field
     void deal(){} //spider 1 to each, klondike is 3 up top
     bool canDrag(Card *c); //spider same suit, others alternate colors, all must be sequential
     Pile* canDrop(QPoint p); //[0] card must be one less and correct suit/color than top one
     void winCon(); //Notification when wins.
     void drawBoxes();
     void newGame();
     //do nothing functions *********
     void doubleClick(Card *c){}
     void flipOver(){}
     //******************************
    FreeCell(SolWindow *gameBoard);
    ~FreeCell();
};

#endif // FREECELL_H
