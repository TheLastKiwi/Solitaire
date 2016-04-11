#include "card.h"

//Public
Card::Card(const QString& text, QWidget* parent)
    : QLabel(parent)
{
    setText(text);
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );
}
Card::~Card(){

}
Card *Card::operator =(Card *c){
    return c;
}

//Protected
void Card::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}
//Public Slots
void Card::slotClicked(){
    move(this->x()+20,this->y()+20);
    //    this->raise();
}
