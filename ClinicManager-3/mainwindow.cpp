#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<QWidget>
#include<QHBoxLayout>//水平布局

#include<QtSql/qsqldatabase>//对数据库的操作
#include<QDebug>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>

#include <QObject>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QLibrary>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createCornerVtn();//调用函数

    initUI();

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    m_ppatient=new patient;//wiget实例化
    ui->tabWidget->addTab(m_ppatient,tr("病人"));//添加TAB


    m_pdoctor =new doctor;
    ui->tabWidget->addTab(m_pdoctor,tr("医生"));

    m_pbill = new bill;
//    ui->tabWidget->addTab(m_pbill,tr("账单"));

    ui->tabWidget->setStyleSheet("QTabBar::tab{min-width:30ex;min-height:10ex;}");

//         createCornerVtn();//调用函数

//         buttonJmp();

//    connect(e,SIGNAL(clicked(bool)),this,SLOT(buttonJmp()));


}

void MainWindow::createCornerVtn()
{
    QPushButton *btnFresh = new QPushButton(tr("刷新"));//添加四个按钮

    QPushButton *btnAdd = new QPushButton(tr("添加患者信息"));

    QPushButton *btnAdo = new QPushButton(tr("添加医生信息"));

    QWidget *cornerWiget = new QWidget;

    QHBoxLayout *hLayout = new QHBoxLayout;//水平布局
    hLayout->addWidget(btnFresh);
    hLayout->addWidget(btnAdd);
    hLayout->addWidget(btnAdo);

    cornerWiget->setFixedSize(300,170);//设置大小
     cornerWiget->setContentsMargins(0,0,0,130);

    cornerWiget->setLayout(hLayout);
    ui->tabWidget->setCornerWidget(cornerWiget,Qt::TopRightCorner);//放置默认右上角

    connect(btnAdd,SIGNAL(clicked()),this,SLOT(buttonTo()));//
    connect(btnFresh,SIGNAL(clicked()),this,SLOT(onBtnRefresh()));
    connect(btnAdo,SIGNAL(clicked()),this,SLOT(onBtnAdo()));

}

void MainWindow::buttonJmp()
{
    m_PAddPatient = new AddPatient(this);
    m_PAddPatient->show();
}

void MainWindow::initAddPat()
{
    m_PAddPatient = new AddPatient();
    connect(m_PAddPatient , SIGNAL(signalStuInf(QVariantMap)) , this ,SLOT(PxecAddSql(QVariantMap)));
}

void MainWindow::buttonTo()
{
//    m_operate = Adds;
    m_PAddPatient = new AddPatient(this);
//    m_PAddPatient->show();
    m_PAddPatient->activateWindow();
    m_PAddPatient->setWindowTitle(tr("添加: 病人信息"));
    m_PAddPatient->exec();
}

void MainWindow::onBtnAdo()
{
    m_paddoctor = new addoctor();
    m_paddoctor->activateWindow();
    m_paddoctor->setWindowTitle(tr("添加: 医生信息"));
    m_paddoctor->exec();
}

void MainWindow::onBtnRefresh()
{
    m_ppatient = new patient();
//    m_ppatient->activateWindow();
    m_ppatient->show();
//    this->close();
//    this->show();
}

void MainWindow::PxecAddSql(QVariantMap stuInfo)
{

    QString Pname = stuInfo.value("Pname").toString();
    QString Pgender = stuInfo.value("Pgender").toString();
    QString Page = stuInfo.value("Page").toString();
    QString ptime = stuInfo.value("ptime").toString();
    QString pdisease = stuInfo.value("pdisease").toString();
    QString pMdoctor = stuInfo.value("pMdoctor").toString();
    QString pfree = stuInfo.value("pfree").toString();
    QString pmadicalFree = stuInfo.value("pmadicalFree").toString();

    QString sql;
    sql = QString("insert into patient (Pname,age ,gender ,Rtime ,disease ,Mdoctor , free ,medicalFree)"
                  " VALUES ('%1', '%2' , '%3' , '%4' , '%5' , '%6' , '%7' , '%8')")
            .arg(Pname).arg(Page).arg(Pgender).arg(ptime).arg(pdisease).arg(pMdoctor).arg(pfree).arg(pmadicalFree);

    QSqlQuery query;
    bool ok = query.exec(sql);
    if(ok)
    {
        QStringList rowData;
//        rowData << Pname <<Page <<sex <<age << address <<phone << description ;
//        m_pTableWidget->appendRowData(rowData);

        QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
    }
    else
    {
        QMessageBox::information(this ,tr("提示") , tr("添加失败!"));
    }
}

void MainWindow::PxecEditSql(QVariantMap stuInfo)
{
    close();
//    ui->IDEdit->setEnabled(true);
}




