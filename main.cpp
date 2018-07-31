#include "mainwindow.h"
#include <QApplication>
#include "shouye.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Shouye w;
    w.show();

    return a.exec();
}
