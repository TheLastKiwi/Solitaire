#include "deck.h"

Deck::Deck(QWidget *parent)
{
    const QString cardResourceStrings[52] = {
        ":/Faces/CardPics/101.png",
        ":/Faces/CardPics/102.png",
        ":/Faces/CardPics/103.png",
        ":/Faces/CardPics/104.png",
        ":/Faces/CardPics/105.png",
        ":/Faces/CardPics/106.png",
        ":/Faces/CardPics/107.png",
        ":/Faces/CardPics/108.png",
        ":/Faces/CardPics/109.png",
        ":/Faces/CardPics/110.png",
        ":/Faces/CardPics/111.png",
        ":/Faces/CardPics/112.png",
        ":/Faces/CardPics/113.png",
        ":/Faces/CardPics/114.png",
        ":/Faces/CardPics/115.png",
        ":/Faces/CardPics/116.png",
        ":/Faces/CardPics/117.png",
        ":/Faces/CardPics/118.png",
        ":/Faces/CardPics/119.png",
        ":/Faces/CardPics/120.png",
        ":/Faces/CardPics/121.png",
        ":/Faces/CardPics/122.png",
        ":/Faces/CardPics/123.png",
        ":/Faces/CardPics/124.png",
        ":/Faces/CardPics/125.png",
        ":/Faces/CardPics/126.png",
        ":/Faces/CardPics/127.png",
        ":/Faces/CardPics/128.png",
        ":/Faces/CardPics/129.png",
        ":/Faces/CardPics/130.png",
        ":/Faces/CardPics/131.png",
        ":/Faces/CardPics/132.png",
        ":/Faces/CardPics/133.png",
        ":/Faces/CardPics/134.png",
        ":/Faces/CardPics/135.png",
        ":/Faces/CardPics/136.png",
        ":/Faces/CardPics/137.png",
        ":/Faces/CardPics/138.png",
        ":/Faces/CardPics/139.png",
        ":/Faces/CardPics/140.png",
        ":/Faces/CardPics/141.png",
        ":/Faces/CardPics/142.png",
        ":/Faces/CardPics/143.png",
        ":/Faces/CardPics/144.png",
        ":/Faces/CardPics/145.png",
        ":/Faces/CardPics/146.png",
        ":/Faces/CardPics/147.png",
        ":/Faces/CardPics/148.png",
        ":/Faces/CardPics/149.png",
        ":/Faces/CardPics/150.png",
        ":/Faces/CardPics/151.png",
        ":/Faces/CardPics/152.png"
    };

    for(int i = 0; i < 52; i++){
                            //value        image                isBlack    suit  parent
        deck[i] = new Card((i%13)+1,cardResourceStrings[i],((i/13)%2)==0,(i/13),parent);
        deck[i]->move(48*(i%13),(i/13)*35);//displays them pretty
        deck[i]->show();
        //deck[i] = new Card(parent);
    }
    cardsInDeck=52;
}

void Deck::dealX(int n){

}
void Deck::dealAll(){

}
void Deck::shuffle(){

}
Deck::~Deck(){
    for(int i = 0; i < 52; i++){
        delete deck[i];
    }
}
