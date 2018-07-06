#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include"mainwindow.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private:
    Ui::login *ui;

public slots:

    void on_login_but();

private:

    MainWindow m;
};

#endif // LOGIN_H
