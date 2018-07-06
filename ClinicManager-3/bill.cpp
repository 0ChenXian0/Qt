#include "bill.h"
#include "ui_bill.h"

#include<QtSql/qsqldatabase>//对数据库的操作
#include<QDebug>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>

bill::bill(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bill)
{
    ui->setupUi(this);
}

bill::~bill()
{
    delete ui;
}
