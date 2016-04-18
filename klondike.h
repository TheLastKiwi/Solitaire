#ifndef KLONDIKE_H
#define KLONDIKE_H
#include "game.h"
#include "solwindow.h"

class Klondike : public Game
{
private:
    SolWindow *board;
public:
    void setup(); //inital field
    void deal(); //spider 1 to each, klondike is 3 up top
    bool canDrag(Card *c); //spider same suit, others alternate colors, all must be sequential
    Pile* canDrop(QPoint p); //[0] card must be one less and correct suit/color than top one
    void winCon(); //Notification when wins.
    void drawBoxes();
    void newGame();
    Klondike(SolWindow *gameBoard);
};

#endif // KLONDIKE_H
