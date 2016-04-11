#include "card.h"
#include "QMouseEvent"
//Public
Card::Card(int val, QString im, bool isBl, int cardSuit, QWidget *parent):
    front(im),value(val),isBlack(isBl),suit(cardSuit)
{
    setParent(parent);
    setFixedSize(71,96);
    setPixmap(front);
    //setText("Testing");
    isFaceUp = false;
    connect(this,SIGNAL(clicked()),this,SLOT(onClick()));
}
Card::~Card(){

}
void Card::flip(){
    isFaceUp = !isFaceUp;
}
Card *Card::operator =(Card *c){
    return c;
}

//Protected
void Card::mousePressEvent(QMouseEvent* event)
{
    //signal
    if(event->button() == Qt::LeftButton){
    emit clicked();
    }
}
//Public Slots
void Card::onClick(){
    move(this->x()+20,this->y()+20);
    //    this->raise();
}
