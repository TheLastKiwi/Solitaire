#ifndef CARD_H
#define CARD_H

#include <QLabel>
//class Pile; //use if using pile down below
class Card : public QLabel
{
    Q_OBJECT

public:
    ~Card();
    Card *operator =(Card *c);
    Card(int val, QString im, bool isBl, int cardSuit,QWidget* parent);
    void flip();
private:
    const bool isBlack;
    const int suit;
    const int value;
    const QString front;
    const QString back = ":/Back/CardPics/Back.png";
    bool isFaceUp;
    //    int posInPile;
    //    Pile *pileIn;

signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
public slots:
    void onClick();
};

#endif // CARD_H
