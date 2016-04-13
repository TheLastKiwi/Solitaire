#include "solwindow.h"
#include "ui_solwindow.h"
#include "card.h"
#include <QPainter>
#include "pile.h"
SolWindow::SolWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SolWindow)
{
    ui->setupUi(this);


    // set green background
    QPalette Pal(palette());
    QColor c(54,115,28);
    Pal.setColor(QPalette::Background, c);
    setAutoFillBackground(true);
    setPalette(Pal);
    //

    deck = new Deck(this);
    deck->shuffle(52);
    fDown = new Pile(20,30);



    //initialize field for 10 piles
    for(int i = 20;i < 820; i+=80){
        field[i/80] = new Pile(i,111);
    }

    on_actionFreeCell_triggered();

}

SolWindow::~SolWindow()
{
    delete ui;
}

void SolWindow::drawBoxes(){
    QPainter painter(this);
    QBrush brush;
    brush.setColor(Qt::black);
    painter.setBrush(brush);

    switch (gameID)  {
    case 0: //klondike

        for(int i = 345; i < 640; i+=80)
        {

            QRect r(i,30,71,96);
            painter.drawRect(r);
        }
        update();
    break;
    case 1: //freeCell
        for(int i = 10; i < 640; i+=80)
        {
            if(i == 330) i+=15;
            QRect r(i,30,71,96);
            painter.drawRect(r);
        }
        update();
        break;
    case 2: //spider
        update();
        break;
    }

}
void SolWindow::paintEvent(QPaintEvent *event){

    drawBoxes();
}



void SolWindow::on_actionNew_Game_triggered()
{
    resetField();
    switch(gameID){
        case 0://klondike
        fDown->cardsInPile = 0;
        deck->reset(52,false);
        deck->shuffle(52);
        //make all face down
        for(int i = 0; i < 8; i++){
            deck->dealX(field[i],i+1,false);
            field[i]->getTopCard()->flip();
        }
        deck->dealX(fDown,16,true);
        break;
    case 1: //freecell
        //make all face up
        deck->reset(52,true);
        deck->shuffle(52);

        deck->dealAll(field,8);
        break;
    case 2: //spider
        //make all face down
        fDown->cardsInPile=0;
        deck->reset(104,false);
        for(int i = 0; i < 10; i++)
            deck->shuffle(104);
        for(int i = 0; i < 10; i++){
            if(i<4)
                deck->dealX(field[i],6,false);
            else{
                deck->dealX(field[i],5,false);
            }
            field[i]->getTopCard()->flip();
        }
            deck->dealX(fDown,50,true);
        break;
    }
}
void SolWindow::resetField(){
    for(int i = 0; i < 10; i++){
        if (field[i])
        field[i]->cardsInPile = 0;
    }
}

void SolWindow::on_actionKlondike_triggered()
{
    //684x485 or 684x666
    initKlondike();
    delete deck;
    deck = new Deck(this);
    gameID = 0;
    on_actionNew_Game_triggered();
}

void SolWindow::on_actionFreeCell_triggered()
{

    //684x485
    initFreecell();
    delete deck;
    deck = new Deck(this);
    gameID = 1;
    on_actionNew_Game_triggered();
}

void SolWindow::on_actionEasy_triggered()
{
    //846x688
    initSpider();
    delete deck;
    deck = new Deck(0,this);
    gameID = 2;
    on_actionNew_Game_triggered();
}

void SolWindow::on_actionMedium_triggered()
{
    //delete every card in the deck
    //104 cards
    //generate new cards 2x 2 suits
    initSpider();
    delete deck;
    deck = new Deck(1,this);
    gameID = 2;
    on_actionNew_Game_triggered();
}

void SolWindow::on_actionHard_triggered()
{
    //delete every card in the deck
    //104 cards
    //generate new cards 2 full decks
    initSpider();
    delete deck;
    deck = new Deck(2,this);
    gameID = 2;
    on_actionNew_Game_triggered();
}

void SolWindow::initKlondike(){
    for(int i = 20;i < 660; i+=80){
        field[i/80]->movePile(i,120);
    }
    field[8]->movePile(-100,0);
    field[9]->movePile(-100,0);

    setWindowTitle("Klondike");
    setMinimumSize(684,485);
    setMaximumWidth(684);
}

void SolWindow::initSpider(){
    for(int i = 20;i < 820; i+=80){
        field[i/80]->movePile(i,20);
    }
    setWindowTitle("Spider");
    setMinimumSize(846,485);
    setMaximumWidth(846);
}

void SolWindow::initFreecell(){
    for(int i = 20;i < 660; i+=80){
        field[i/80]->movePile(i,120);
    }
    field[8]->movePile(-100,0);
    field[9]->movePile(-100,0);
    setWindowTitle("Freecell");
    setFixedSize(684,485);
}
