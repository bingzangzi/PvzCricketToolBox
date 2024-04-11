#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(660,400);
    w.setWindowTitle("植物大战僵尸：斗蛐蛐工具箱 2.0");
    w.show();
    return a.exec();
}
