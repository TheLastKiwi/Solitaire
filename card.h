#ifndef CARD_H
#define CARD_H

#include <QLabel>
class SolWindow;
class Pile; //use if using pile down below
class Card : public QLabel
{
    Q_OBJECT

public:
    ~Card();
    Card *operator =(Card *c);
    Card(int val, QString im, bool isBl, int cardSuit, SolWindow *parent);
    void flip();
private:
    const bool isBlack;
    const int suit;
    const int value;
    const QString front;
    const QString back = ":/Back/CardPics/Back.png";
    bool isFaceUp;
    int posInPile;
    Pile *pileIn;
    //NEW STUFF BELOW THIS
    QPoint offset;
    SolWindow *gameWindow;
    Pile * prevPile;
signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);
    //NEW STUFF BELOW THIS
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

public slots:
//    void onClick();
    //DELETED STUFF BELOW THIS
//    void onRClick();
//    void onLClick();
friend class Pile;
friend class Deck;
};

#endif // CARD_H
