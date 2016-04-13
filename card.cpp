#include "card.h"
#include "QMouseEvent"
//Public
Card::Card(int val, QString im, bool isBl, int cardSuit, QWidget *parent):
    front(im),value(val),isBlack(isBl),suit(cardSuit)
{
    setParent(parent);
    setFixedSize(71,96);
    setPixmap(back);
    //setText("Testing");
    isFaceUp = false;
    connect(this,SIGNAL(clicked()),this,SLOT(onClick()));
    connect(this,SIGNAL(lClick()),this,SLOT(onLClick()));
    connect(this,SIGNAL(rClick()),this,SLOT(onRClick()));
}
Card::~Card(){

}
void Card::flip(){

    if (isFaceUp){
        setPixmap(back);
    }
    else{
        setPixmap(front);
    }
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
        emit lClick();
    }
    else{
        emit rClick();
    }

    //emit clicked();
}
//Public Slots
void Card::onClick(){
    move(this->x()+20,this->y()+20);
    this->raise();
}
void Card::onRClick(){

    flip();
    this->raise();
}
void Card::onLClick(){
    move(this->x()+20,this->y()+20);
    this->raise();
}
