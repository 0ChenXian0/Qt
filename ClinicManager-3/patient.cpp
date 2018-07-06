#include "patient.h"
#include "ui_patient.h"
#include"createdb.h"
#include<QtSql/qsqldatabase>//对数据库的操作
#include<QDebug>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>
#include<QSqlQueryModel>
using namespace std;

patient::patient(QWidget *parent) :QWidget(parent),ui(new Ui::patient)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(8);

//    ui->tableWidget->setRowCount(2);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<tr("姓名") <<tr("年龄")<<tr("性别")<<tr("就诊日期")<<tr("病种")<<tr("主治医生")<<tr("医药费")<<tr("诊费"));

//    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
//    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
//    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个

    int RowCont;
    RowCont=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(RowCont);//增加一行

    //插入元素
//    ui->tableWidget->setItem(RowCont,0,new QTableWidgetItem(PaperName));
//    ui->tableWidget->setItem(RowCont,1,new QTableWidgetItem(KeyWord));
//    ui->tableWidget->setItem(RowCont,2,new QTableWidgetItem(PaperBrief));

//    CreatDb.selectDataFromBase();

//    for(int i=0;i<stuInfo.size();i++){
//        ui->tableWidget->setHorizontalHeaderItem(i,new QTableWidgetItem(stuInfo.at(i)));

//    }

//    QSqlQuery sql_query(database_);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    query = QSqlQuery::QSqlQuery(db);

     //   db.setDatabaseName("my.db");

        db.setHostName("127.0.0.1");

        db.setDatabaseName("doctor");

//        db.setPort(3306);

        db.setUserName("root");

        db.setPassword("");


        if (db.open()) {

//    qDebug()<<"失败";
}


        QSqlQuery query("selsect * from patient");
//        QList<QStringList> stuInfo;

        bool success = query.exec("select * from patient");
            if(success){
//                qDebug() << "查询ok";

            }

        while (query.next()){



            ui->tableWidget->setItem(RowCont,0,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(RowCont,1,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(RowCont,2,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->setItem(RowCont,3,new QTableWidgetItem(query.value(4).toString()));
            ui->tableWidget->setItem(RowCont,4,new QTableWidgetItem(query.value(5).toString()));
            ui->tableWidget->setItem(RowCont,5,new QTableWidgetItem(query.value(6).toString()));
            ui->tableWidget->setItem(RowCont,6,new QTableWidgetItem(query.value(8).toString()));


            ui->tableWidget->insertRow(RowCont);//增加一行


}
}

patient::~patient()
{
    delete ui;
}




void patient::on_pushButton_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    query = QSqlQuery::QSqlQuery(db);

     //   db.setDatabaseName("my.db");

    db.setHostName("127.0.0.1");

    db.setDatabaseName("doctor");

//        db.setPort(3306);

    db.setUserName("root");

    db.setPassword("");

        if (db.open()) {

//    qDebug()<<"失败";
}



    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select SUM(med+cost) from patient");
    model->setHeaderData(0, Qt::Horizontal, tr("诊费总计"));

    QTableView *view = new QTableView;
    view->setModel(model);
    view->setStyleSheet("gridline-color:rgb(0,0,0)");
    view->horizontalHeader()->setFixedHeight(30);
    view->resize(560,450);
    view->show();
}
