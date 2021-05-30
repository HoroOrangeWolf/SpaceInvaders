#include "mainwindow.h"

#include <QApplication>
#include <QtSql/QSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.movieBackground();
    return a.exec();
}
