#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDir::setCurrent(QApplication::applicationDirPath()); //设置程序当前路径

    MainWindow w;
    w.show();

    return a.exec();
}
