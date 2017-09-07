#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>


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

};

#endif // MAINWINDOW_H
