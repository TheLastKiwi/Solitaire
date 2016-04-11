#ifndef SOLWINDOW_H
#define SOLWINDOW_H

#include <QMainWindow>
#include "deck.h"
namespace Ui {
class SolWindow;
}

class SolWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SolWindow(QWidget *parent = 0);
    ~SolWindow();
    void drawBoxes();
    Deck *deck;

private:
    Ui::SolWindow *ui;
};

#endif // SOLWINDOW_H
