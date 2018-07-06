#include "addpatient.h"
#include "ui_addpatient.h"
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

AddPatient::AddPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPatient)
{
    ui->setupUi(this);

    InputFrom();
}

AddPatient::~AddPatient()
{
    delete ui;
}

void AddPatient::setEditData(QStringList rowData)
{
    ui->P_name->setText(rowData.at(0));
    ui->P_gender->setText(rowData.at(1));
    ui->P_age->setText(rowData.at(3));
    ui->P_time->setText(rowData.at(2));
    ui->P_disease->setText(rowData.at(4));
    ui->P_Mdoctor->setText(rowData.at(5));
    ui->P_free->setText(rowData.at(6));
    ui->P_madicalFree->setText(rowData.at(7));

//    ui->IDEdit->setEnabled(false);
}

void AddPatient::InputFrom()
{

}

void AddPatient::clearData()
{

        ui->P_name->clear();
        ui->P_gender->clear();
        ui->P_age->clear();
        ui->P_time->clear();
        ui->P_disease->clear();
        ui->P_madicalFree->clear();
        ui->P_Mdoctor->clear();
        ui->P_free->clear();


}

void AddPatient::on_Pbutton_accepted()
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

   QString pname0 = ui->P_name->text();
   QString pgender0 = ui->P_gender->text();
   QString page0 = ui->P_age->text();
   QString ptime0 = ui->P_time->text();
   QString pdisease0 = ui->P_disease->text();
   QString pMdoctor0 = ui->P_Mdoctor->text();
   QString pfree0 = ui->P_free->text();
   QString pmadicalFree0 = ui->P_madicalFree->text();

//    QString datetime = QDateTime::currentDateTime().toString();

    stuInfo.insert("pname" ,pname0 );
    stuInfo.insert("pgender" ,pgender0 );
    stuInfo.insert("page" ,page0 );
    stuInfo.insert("ptime" ,ptime0 );
    stuInfo.insert("pdisease" ,pdisease0 );
    stuInfo.insert("pMdoctor" ,pMdoctor0 );
    stuInfo.insert("pfree" ,pfree0 );
    stuInfo.insert("pmadicalFree" ,pmadicalFree0 );

    QString pname = stuInfo.value("pname").toString();
    QString pgender = stuInfo.value("pgender").toString();
    QString page = stuInfo.value("page").toString();
    QString ptime = stuInfo.value("ptime").toString();
    QString pdisease = stuInfo.value("pdisease").toString();
    QString pMdoctor = stuInfo.value("pMdoctor").toString();
    QString pfree = stuInfo.value("pfree").toString();
    QString pmadicalFree = stuInfo.value("pmadicalFree").toString();

    QString sql;
    sql = QString("insert into patient (Pname,age ,gender ,Rtime ,disease ,Mdoctor , free ,medicalFree)"
                  " VALUES ('%1', '%2' , '%3' , '%4' , '%5' , '%6' , '%7' , '%8')").arg(pname).arg(page).arg(pgender).arg(ptime).arg(pdisease).arg(pMdoctor).arg(pfree).arg(pmadicalFree);

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
