#include "solwindow.h"
#include "ui_solwindow.h"
#include "card.h"
SolWindow::SolWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SolWindow)
{
    ui->setupUi(this);
    deck = new Deck(this);
}

SolWindow::~SolWindow()
{
    delete ui;
}
