#include "widget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle(QStringLiteral("Qt/C++ Shake Generator"));
    w.show();
    return a.exec();
}
