#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>
#include <QTextStream>
#include <QTextCodec>

#include "crypttools.h"
#include "configkeywindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    CryptTools crypt;
    configKeyWindow configKey;

    //编码
    QTextCodec *textcodec;

private slots:

    /*选择加密文件*/
    void chooseFileSlot();

    /*加密*/
    void encryptSlot();

    /*解密*/
    void decryptSlot();

    /*输出到文件*/
    void saveToFileSlot();

    /*设置密匙*/
    void configKeySlot();

    /*选择编码*/
    void chooseCodeSlot(QString codec);

};

#endif // MAINWINDOW_H
