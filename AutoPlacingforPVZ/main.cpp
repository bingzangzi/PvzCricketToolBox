#include "mainwindow.h"

#include <QApplication>
bool GameonFlag=false;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("植物大战僵尸：植物僵尸自动布阵器");
    w.show();
    return a.exec();
}
