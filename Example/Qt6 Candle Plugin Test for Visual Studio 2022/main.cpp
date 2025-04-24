#include "Qt6CandlePluginTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt6CandlePluginTest w;
    w.show();
    return a.exec();
}
