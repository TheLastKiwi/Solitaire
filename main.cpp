#include "solwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SolWindow w;
    w.show();

    return a.exec();
}
