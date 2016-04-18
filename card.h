#ifndef CARD_H
#define CARD_H

#include <QLabel>
//#include "game.h"
class SolWindow;
class Game;
class Pile; //use if using pile down below
class Card : public QLabel
{
    Q_OBJECT

public:
    ~Card();
    Card *operator =(Card *c);
    Card(int val, QString im, bool isBl, int cardSuit, SolWindow *parent);
    void flip();
    bool isFaceUp;
    Pile *pileIn;
private:
    const bool isBlack;
    const int suit;
    const int value;
    const QString front;
    const QString back = ":/Back/CardPics/Back.png";

    int posInPile;

    //NEW STUFF BELOW THIS
    QPoint offset;
    Game *theGame;
    Pile * prevPile;

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *ev);
public slots:
//    void onClick();
    //DELETED STUFF BELOW THIS
//    void onRClick();
//    void onLClick();
friend class Pile;
//friend class Deck;
friend class Game;
friend class Klondike;
friend class Spider;
friend class FreeCell;
};

#endif // CARD_H
