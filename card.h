#ifndef CARD_H
#define CARD_H

#include <QLabel>
class Card : public QLabel
{
    Q_OBJECT

public:
    explicit Card(const QString& text="", QWidget* parent=0);
    ~Card();
    Card *operator =(Card *c);
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
public slots:
    void slotClicked();
};

#endif // CARD_H
