#ifndef SOLWINDOW_H
#define SOLWINDOW_H

#include <QMainWindow>
class Game;
namespace Ui {
class SolWindow;
}

class SolWindow : public QMainWindow
{
    Q_OBJECT
public:
    Game *theGame = 0;
    explicit SolWindow(QWidget *parent = 0);
    ~SolWindow();
    void drawBoxes();
    bool isKlondike = false;
private:
    void resetField();
    void initKlondike();
    void initSpider();
    void initFreecell();
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *ev);
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
