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
    Pile *fDown;
    Pile *field[10];
    int gameID = 1;
private:
    void resetField();
    void initKlondike();
    void initSpider();
    void initFreecell();
protected:
    void paintEvent(QPaintEvent *event);

private slots:

    void on_actionNew_Game_triggered();

    void on_actionKlondike_triggered();

    void on_actionFreeCell_triggered();

    void on_actionEasy_triggered();

    void on_actionMedium_triggered();

    void on_actionHard_triggered();

private:
    Ui::SolWindow *ui;
};

#endif // SOLWINDOW_H
