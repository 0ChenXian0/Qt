#include"createdb.h"
#include<QtSql/qsqldatabase>//对数据库的操作
#include<QDebug>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>

CreatDb::CreatDb(){

}

void CreatDb::initDB(){

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

     //   db.setDatabaseName("my.db");

        db.setHostName("localhost");

        db.setDatabaseName("DatabasenName");

        db.setUserName("root");

        db.setPassword("123456");


        if (!db.open()) {

    qDebug()<<"失败";
}
}
        QList<QStringList> CreatDb::selectDataFromBase()
        {
            QSqlQuery query("selsect * from patient");
            QList<QStringList> stuInfo;

            while (query.next()){

                QStringList rowData;
                rowData<<query.value(1).toString();
                rowData<<query.value(2).toString();
                rowData<<query.value(3).toString();
                rowData<<query.value(4).toString();
                rowData<<query.value(5).toString();
                rowData<<query.value(6).toString();
                rowData<<query.value(7).toString();

                stuInfo.append(rowData);

            }

            return stuInfo;
        }
