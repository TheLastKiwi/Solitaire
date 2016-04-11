#ifndef SOLWINDOW_H
#define SOLWINDOW_H

#include <QMainWindow>
class Card;
namespace Ui {
class SolWindow;
}

class SolWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SolWindow(QWidget *parent = 0);
    ~SolWindow();
    Card *arr[52];// = new Card[52];

private:
    Ui::SolWindow *ui;
};

#endif // SOLWINDOW_H
