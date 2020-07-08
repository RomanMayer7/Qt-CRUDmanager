#ifndef DBREPOSITORY_H
#define DBREPOSITORY_H

#include<QObject>
#include <QDebug>
#include <QtSql>

class DbRepository:public QObject
{

public:
     explicit DbRepository(QObject *parent = nullptr);

    QSqlDatabase myDB;
    bool OpenDBConnection();
    void CloseDBConnection();
    bool LoginToApplication(QString username,QString password);

};

#endif // DBREPOSITORY_H
