#include "solwindow.h"
#include "ui_solwindow.h"
#include <QPainter>
#include "freecell.h"
#include "klondike.h"
#include "spider.h"
#include "QMouseEvent"
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

}

SolWindow::~SolWindow()
{
    delete ui;
}

void SolWindow::paintEvent(QPaintEvent *event){
    if(theGame)theGame->drawBoxes();
}

void SolWindow::on_actionNew_Game_triggered()
{
    if(theGame){
        theGame->newGame();
        theGame->setup();
    }
}

void SolWindow::on_actionKlondike_triggered()
{
    delete theGame;
    theGame = new Klondike(this);
    theGame->setup();
    isKlondike = true;
}

void SolWindow::on_actionFreeCell_triggered()
{

    delete theGame;
    theGame = new FreeCell(this);
    theGame->setup();
    isKlondike = false;
}

void SolWindow::on_actionEasy_triggered()
{
    delete theGame;
    theGame = new Spider(this,0);
    theGame->setup();
    isKlondike = false;
}

void SolWindow::on_actionMedium_triggered()
{
    delete theGame;
    theGame = new Spider(this,1);
    theGame->setup();
    isKlondike = false;
}

void SolWindow::on_actionHard_triggered()
{
    delete theGame;
    theGame = new Spider(this,2);
    theGame->setup();
    isKlondike = false;
}
void SolWindow::mousePressEvent(QMouseEvent *ev){
    QPointF p(ev->windowPos());
    if(isKlondike){
       if(p.x()>20 && p.x()<91 && p.y()>30 && p.y()<126){

       }



    }
}
