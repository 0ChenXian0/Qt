#include "mainwindow.h"
#include <QApplication>
#include"login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    login log;
    w.hide();
    log.show();

    return a.exec();
}
