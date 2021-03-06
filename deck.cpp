#include "deck.h"
#include "pile.h"
Deck::Deck(SolWindow *parent)
{

    for(int i = 0; i < 52; i++){
                            //value        image                isBlack    suit  parent
        deck[i] = new Card((i%13)+1,cardResourceStrings[i],((i/13)%2)==1,(i/13),parent);
        deck[i]->show();

        //deck[i] = new Card(parent);
    }
    for(int i = 52;i<104;i++) deck[i] =0; //just makes it easier to delete later

    cardsInDeck=52;
    qsrand(seed.nsecsElapsed());
}

Deck::Deck(int n,SolWindow *parent)
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
    cardsInDeck = 104;
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

    for(int i = 0; i < 104; i++){
        if(deck[i]){
            delete deck[i];
        }
        else{
            break;
        }
    }
}
