#ifndef SPIDER_H
#define SPIDER_H
#include "game.h"
class Spider:public Game
{
private:
    int difficulty;
    int suitsComplete = 0;
    //    enum PlayStyle{easy,med,hard};
    //    PlayStyle difficulty;
public:
        void setup(); //inital field
        void deal(); //spider 1 to each, klondike is 3 up top
        bool canDrag(Card *c); //spider same suit, others alternate colors, all must be sequential
        Pile* canDrop(QPoint p); //[0] card must be one less and correct suit/color than top one
        void winCon(); //Notification when wins.
        void drawBoxes();
        void newGame();

        Pile *tenCardStacks[5]; // 5 in the bottom right
        Pile *finished[8]; // the 8 finished piles

        void doubleClick(Card *c);
    Spider(SolWindow *gameBoard, int i);
};

#endif // SPIDER_H
