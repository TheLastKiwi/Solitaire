#include "solwindow.h"
#include "ui_solwindow.h"
#include "card.h"
SolWindow::SolWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SolWindow)
{
    ui->setupUi(this);
    deck = new Deck(this);
    drawBoxes();
}

SolWindow::~SolWindow()
{
    delete ui;
}

void SolWindow::drawBoxes(){

}
