#include "solwindow.h"
#include "ui_solwindow.h"
#include "card.h"
SolWindow::SolWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SolWindow)
{
    ui->setupUi(this);
    for(int i = 0; i < 52; i++){
        QString s = "Testing";
        s.append(i);
        arr[i] = new Card(s,this);
        arr[i]->move(2*i,2*i);
    }
}

SolWindow::~SolWindow()
{
    delete ui;
}
