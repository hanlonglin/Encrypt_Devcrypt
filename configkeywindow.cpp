#include "configkeywindow.h"
#include "ui_configkeywindow.h"

configKeyWindow::configKeyWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::configKeyWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(QString::fromLocal8Bit("设置密匙"));

    ui->lineEditKey1->setValidator(new QIntValidator(0,99999999999,this));
    ui->lineEditKey2->setValidator(new QIntValidator(0,99999999999,this));

    //连接
    connect(ui->pushButtonSave,SIGNAL(clicked(bool)),this,SLOT(saveKeysSlot()));//保存密匙

    showKeysSlot();

}

configKeyWindow::~configKeyWindow()
{
    delete ui;
}

/*显示*/
void configKeyWindow::showKeysSlot()
{
    QSettings *setting=new QSettings(KEY_FILE,QSettings::IniFormat);
    setting->setIniCodec("UTF8");
    key1=setting->value(QString(KEY_SECTION).append("/").append(KEY_KEY1)).toString();
    key2=setting->value(QString(KEY_SECTION).append("/").append(KEY_KEY2)).toString();
    ui->lineEditKey1->setText(QString::number(key1.toInt()));
    ui->lineEditKey2->setText(QString::number(key2.toInt()));
    delete setting;


}

/*保存*/
void configKeyWindow::saveKeysSlot()
{
    key1=ui->lineEditKey1->text();
    key2=ui->lineEditKey2->text();
    if(key1.isEmpty()||key2.isEmpty())
    {
        return ;
    }
    QSettings *setting=new QSettings(KEY_FILE,QSettings::IniFormat);
    setting->setIniCodec("UTF8");
    setting->setValue(QString(KEY_SECTION).append("/").append(KEY_KEY1),key1);
    setting->setValue(QString(KEY_SECTION).append("/").append(KEY_KEY2),key2);
    delete setting;
    this->close();
}
