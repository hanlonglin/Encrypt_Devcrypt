#ifndef CONFIGKEYWINDOW_H
#define CONFIGKEYWINDOW_H

#include <QWidget>
#include <QSettings>

#define KEY_FILE              "keys.ini"
#define KEY_SECTION           "KEYS"
#define KEY_KEY1              "key1"
#define KEY_KEY2              "key2"

#define GLOBAL_SECTION        "GLOBAL"
#define LAST_CODE             "last_code"
#define LAST_OPEN_PATH        "last_open_path"
#define LAST_SAVE_PATH        "last_save_path"

namespace Ui {
class configKeyWindow;
}

class configKeyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit configKeyWindow(QWidget *parent = 0);
    ~configKeyWindow();

    QString key1;
    QString key2;

private:
    Ui::configKeyWindow *ui;

private slots:
    /*显示*/
    void showKeysSlot();

    /*保存*/
    void saveKeysSlot();


};

#endif // CONFIGKEYWINDOW_H
