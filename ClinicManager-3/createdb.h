#ifndef CREATEDB_H
#define CREATEDB_H



#include<QList>
#include<QStringList>

class CreatDb{
public:
    CreatDb();

    void initDB();

    QList<QStringList> selectDataFromBase();
};

#endif // CREATEDB_H
