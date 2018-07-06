#include "addoctor.h"
#include "ui_addoctor.h"


#include<QHBoxLayout>//水平布局
#include<QLabel>
#include<QFormLayout>
#include<QPushButton>
#include<QLineEdit>
#include<QTextEdit>
#include<QLayout>
#include<QGridLayout>
#include<QDialog>
#include<QApplication>
#include <QDateTime>
#include <QStringList>
#include <QString>

#include<QtSql/qsqldatabase>//对数据库的操作
#include<QDebug>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>

#include <QMessageBox>


addoctor::addoctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addoctor)
{
    ui->setupUi(this);
}

addoctor::~addoctor()
{
    delete ui;
}

void addoctor::clearData()
{
    ui->Dname->clear();
    ui->Dgender->clear();
    ui->Dage->clear();
    ui->Dprofession->clear();
    ui->Dfree->clear();


}

void addoctor::on_Dbutton_accepted()
{
    QVariantMap stuInfo;
    QSqlDatabase db;

    if(QSqlDatabase::contains("qt_sql_default_connection"))

      db = QSqlDatabase::database("qt_sql_default_connection");

    else

      db = QSqlDatabase::addDatabase("QSQLITE");

        db.setHostName("localhost");

        db.setDatabaseName("DatabasenName");

        db.setUserName("root");

        db.setPassword("123456");


        if (db.open()) {


}

   QString pname0 = ui->Dname->text();
   QString pgender0 = ui->Dgender->text();
   QString page0 = ui->Dage->text();
   QString pprofession0 = ui->Dprofession->text();
   QString pfree0 = ui->Dfree->text();


    stuInfo.insert("pname" ,pname0 );
    stuInfo.insert("pgender" ,pgender0 );
    stuInfo.insert("page" ,page0 );
    stuInfo.insert("pprofession" ,pprofession0 );
    stuInfo.insert("pfree" ,pfree0 );


    QString pname = stuInfo.value("pname").toString();
    QString pgender = stuInfo.value("pgender").toString();
    QString page = stuInfo.value("page").toString();
    QString pprofession = stuInfo.value("pprofession").toString();
    QString pfree = stuInfo.value("pfree").toString();


    QString sql;
    sql = QString("insert into doctor (Dname,age ,gender ,profession, Dfree )"
                  " VALUES ('%1', '%2' , '%3' , '%4' , '%5')").arg(pname).arg(page).arg(pgender).arg(pprofession).arg(pfree);

    QSqlQuery query;
    bool ok = query.exec(sql);
    if(ok)
    {
//        QStringList rowData;
//        rowData << Pname <<Page <<sex <<age << address <<phone << description ;
//        m_pTableWidget->appendRowData(rowData);

        QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
        close();
    }
    else
    {
        QMessageBox::information(this ,tr("提示") , tr("添加失败!"));
    }

    clearData(); //清除编辑的数据
}
