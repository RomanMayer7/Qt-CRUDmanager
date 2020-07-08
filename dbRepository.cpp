#include "dbRepository.h"


DbRepository::DbRepository(QObject *parent):QObject (parent){}


bool DbRepository::OpenDBConnection()
{

    qDebug()<<"Initializing our DB";
    myDB=QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName("myDemoDB.db");

    if(!myDB.open())
    {
        return false;
        qDebug()<<("There is Some Error when Connecting to DB");
    }
    else
    {
        qDebug()<<("Connected to DB Successfully");
        return true;
    }
}

void DbRepository::CloseDBConnection()
{
    myDB.close();
    myDB.removeDatabase("QSQLITE");
}

bool DbRepository::LoginToApplication(QString username,QString password)
{
    OpenDBConnection();

    if(!myDB.isOpen())
    {
        qDebug()<<("Failed to Open Connection");
        return false;
    }
    QString sql="SELECT * FROM Users WHERE Username='"+username+"' AND Password='"+password+"'";
    QSqlQuery queryReader;
    queryReader.prepare(sql);
    queryReader.exec();

       int count=0;
       while(queryReader.next())
       {
           count++;
       }
        if(count>1)
        {
           CloseDBConnection();
           return true;
        }

     CloseDBConnection();
     return false;
}
