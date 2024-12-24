#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.timer_1.start(3);
    w.timer_plot.start(50);

    return a.exec();
}
