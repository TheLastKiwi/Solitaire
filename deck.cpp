#include "deck.h"
#include "QElapsedTimer"
#include "pile.h"
Deck::Deck(QWidget *parent)
{

    for(int i = 0; i < 52; i++){
                            //value        image                isBlack    suit  parent
        deck[i] = new Card((i%13)+1,cardResourceStrings[i],((i/13)%2)==1,(i/13),parent);
        deck[i]->show();

        //deck[i] = new Card(parent);
    }
    cardsInDeck=52;
    qsrand(seed.nsecsElapsed());
}

Deck::Deck(int n,QWidget *parent)
{
    switch (n){
    case 0: // easy
        for(int j = 0; j < 8; j++){
            for(int i = 39; i < 52; i++){
                deck[(j*13)+(i-39)] = new Card((i%13)+1,cardResourceStrings[i],((i/13)%2)==1,(i/13),parent);
                deck[(j*13)+(i-39)]->show();
            }
        }
        break;
    case 1: //medium
        for(int j = 0; j < 4; j++){
            for(int i = 26; i < 52; i++){
                deck[(j*26)+(i-26)] = new Card((i%13)+1,cardResourceStrings[i],((i/13)%2)==1,(i/13),parent);
                deck[(j*26)+(i-26)]->show();
            }
        }
        break;
    case 2: //hard
        for(int j = 0; j < 2; j++){
            for(int i = 0; i < 52; i++){
                deck[(j*52)+(i)] = new Card((i%13)+1,cardResourceStrings[i],((i/13)%2)==1,(i/13),parent);
                deck[(j*52)+(i)]->show();
            }
        }
    }

}

void Deck::reset(int n, bool setFaceUp){
    cardsInDeck = n;
    for(int i = 0; i < n; i++){
        if (deck[i]->isFaceUp != setFaceUp) deck[i]->flip();
    }
}

void Deck::dealX(Pile *p, int n, bool d){
    for(int i = 0; i < n; i++){
        p->addCard(deck[--cardsInDeck],d);
        p->getTopCard()->raise();

    }
}
void Deck::dealAll(Pile *field[],int n){
    for(int i = 0; i < 52; i++){
        field[i % n]->addCard(deck[i],false);

//    deck[i]->move(70*(i%13),(i/13+1)*95);//displays them pretty
    deck[i]->show();
    deck[i]->raise();
    }
}
void Deck::shuffle(int n){
    Card *c;
    int swapPos;

    for(int i = 0; i < n; i++){

       swapPos = qrand()%n;

       c = deck[i];
       deck[i] = deck[swapPos];
       deck[swapPos] = c;
    }

}
Deck::~Deck(){
    int n = deck[52]==deck[53]?52:104;
    for(int i = 0; i < n; i++){
        delete deck[i];
    }
}
