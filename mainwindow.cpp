#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(QString::fromLocal8Bit("自制加密解密软件"));

    //连接
    connect(ui->pushButtonChoose,SIGNAL(clicked(bool)),this,SLOT(chooseFileSlot()));//选择加密文件

    connect(ui->pushButtonDecryptToFile,SIGNAL(clicked(bool)),this,SLOT(saveToFileSlot()));//保存解密文件

    connect(ui->pushButtonEncrypt,SIGNAL(clicked(bool)),this,SLOT(encryptSlot()));//加密
    connect(ui->pushButtonDecrypt,SIGNAL(clicked(bool)),this,SLOT(decryptSlot()));//解密

    connect(ui->actionConfig,SIGNAL(triggered(bool)),this,SLOT(configKeySlot())); //设置密匙
}

MainWindow::~MainWindow()
{
    delete ui;
}

//******************************************************slots
/*选择加密文件*/
void MainWindow::chooseFileSlot()
{
    QString path=QFileDialog::getOpenFileName(this,"",QDir::currentPath());
    if(path.isEmpty()) return ;
    ui->lineEditPath->setText(path);

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this,"",QString::fromLocal8Bit("文件读取失败！"));
        return;
    }
    QString content=QString::fromLocal8Bit(file.readAll());
    file.close();
    ui->textEditEncrypt->setText(content);
}

/*加密*/
void MainWindow::encryptSlot()
{
    //读取文件得到密匙
    QSettings *setting=new QSettings(KEY_FILE,QSettings::IniFormat);
    setting->setIniCodec("UTF8");
    QString key1=setting->value(QString(KEY_SECTION).append("/").append(KEY_KEY1)).toString();
    QString key2=setting->value(QString(KEY_SECTION).append("/").append(KEY_KEY2)).toString();
    if(key1.isEmpty()) key1="1111";
    if(key2.isEmpty()) key2="1111";
    delete setting;
    crypt.setKeys(key1.toInt(),key2.toInt());

    QString enText=ui->textEditEncrypt->toPlainText();

    QString afterEncrypt=QString::fromStdString(crypt.EnCrypt(enText.toStdString()));

    ui->textEditDecrypt->setText(afterEncrypt);

}

/*解密*/
void MainWindow::decryptSlot()
{
    //读取文件得到密匙
    QSettings *setting=new QSettings(KEY_FILE,QSettings::IniFormat);
    setting->setIniCodec("UTF8");
    QString key1=setting->value(QString(KEY_SECTION).append("/").append(KEY_KEY1)).toString();
    QString key2=setting->value(QString(KEY_SECTION).append("/").append(KEY_KEY2)).toString();
    if(key1.isEmpty()) key1="1111";
    if(key2.isEmpty()) key2="1111";
    delete setting;
    crypt.setKeys(key1.toInt(),key2.toInt());

    QString deText=ui->textEditEncrypt->toPlainText();

    QString afterDecrypt=QString::fromStdString(crypt.DeCrpty(deText.toStdString()));

    ui->textEditDecrypt->setText(afterDecrypt);
}

/*输出到文件*/
void MainWindow::saveToFileSlot()
{
    QString saveTo=QFileDialog::getSaveFileName(this,"",QDir::currentPath()+"/decrypt.txt");
    if(saveTo.isEmpty()) return ;
    QFile file(saveTo);
    if(!file.open(QIODevice::ReadWrite|QIODevice::Truncate|QIODevice::Text))
    {
        QMessageBox::information(this,"",QString::fromLocal8Bit("打开保存文件失败！"));
        return ;
    }
    file.write(ui->textEditDecrypt->toPlainText().toLocal8Bit().toStdString().c_str());
    file.close();
    QMessageBox::information(this,"",QString::fromLocal8Bit("文件保存成功！"));
}

/*设置密匙*/
void MainWindow::configKeySlot()
{
    configKey.show();
}
