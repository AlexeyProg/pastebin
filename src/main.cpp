#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QTranslator t;
//    t.load(":/pastebin_ru.qm");
//    a.installTranslator(&t);
    MainWindow w;
    w.show();
    return a.exec();
}
