#include "doctor.h"
#include "ui_doctor.h"
#include<createdb.h>

#include<QtSql/qsqldatabase>//对数据库的操作
#include<QDebug>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>

doctor::doctor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doctor)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<tr("姓名")<<tr("年龄")<<tr("性别")<<tr("专业")<<tr("诊费"));

    int RowCont;
    RowCont=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(RowCont);//增加一行




    QSqlDatabase db;

    if(QSqlDatabase::contains("qt_sql_default_connection"))

      db = QSqlDatabase::database("qt_sql_default_connection");

    else

      db = QSqlDatabase::addDatabase("QSQLITE");


//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");



    db.setHostName("127.0.0.1");

    db.setDatabaseName("doctor");

//        db.setPort(3306);

    db.setUserName("root");

    db.setPassword("");


        if (db.open()) {


}


        QSqlQuery query("selsect * from doctor");

        bool success = query.exec("select * from doctor");
            if(success){


            }

        while (query.next()){

            ui->tableWidget->setItem(RowCont,0,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(RowCont,1,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(RowCont,2,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->setItem(RowCont,3,new QTableWidgetItem(query.value(4).toString()));
            ui->tableWidget->setItem(RowCont,4,new QTableWidgetItem(query.value(5).toString()));
//            ui->tableWidget->setItem(RowCont,5,new QTableWidgetItem(query.value(5).toString()));
//            ui->tableWidget->setItem(RowCont,6,new QTableWidgetItem(query.value(6).toString()));

            ui->tableWidget->insertRow(RowCont);//增加一行
}

}

doctor::~doctor()
{
    delete ui;
}
