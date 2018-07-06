#include "login.h"
#include "ui_login.h"

#include<QtSql/qsqldatabase>//对数据库的操作
#include<QDebug>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>
#include <QLibrary>
#include<QWidget>
#include<qstring.h>
#include<QMessageBox>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    connect(ui->loginTo,SIGNAL(clicked()),this,SLOT(on_login_but()));

}

login::~login()
{
    delete ui;
}

void login::on_login_but()
{
    QVariantMap stuInfo;
    QString username=ui->username->text();
    QString password = ui->password->text();

    stuInfo.insert("username" ,username );
    stuInfo.insert("password" ,password );


    QSqlDatabase db;

    if(QSqlDatabase::contains("qt_sql_default_connection"))

      db = QSqlDatabase::database("qt_sql_default_connection");

    else

      db = QSqlDatabase::addDatabase("QSQLITE");


    db.setHostName("127.0.0.1");

    db.setDatabaseName("doctor");

//        db.setPort(3306);

    db.setUserName("root");

    db.setPassword("");

        if (db.open()) {


}

//        QString sql=("selsect password from admin where (username='%1')").arg(username);

        QSqlQuery query;
        bool i = query.exec(QString("SELECT password FROM admin WHERE (username='%1')").arg(stuInfo.value("username").toString()));

            if(i)
            {
                while(query.next()){

                if(query.value(0).toString()==stuInfo.value("password").toString()){

                    this->hide();
                    m.show();
                }
                else{
                    QMessageBox::information(this ,tr("提示") , tr("密码有误!"));
                }

            }

}
            else{

                QMessageBox::information(this ,tr("提示") , tr("账号不存在!"));
                }
}
