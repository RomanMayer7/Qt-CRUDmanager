#include "dbRepository.h"
#include <QMessageBox>


DbRepository::DbRepository(QObject *parent):QObject (parent){}


bool DbRepository::OpenDBConnection()
{

    qDebug()<<"Initializing our DB";
    myDB=QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(QCoreApplication::applicationDirPath() + "/myDemoDB.db");

    if(!myDB.open())
    {
        return false;
        qDebug()<<("There is Some Error when Connecting to DB");
    }
    else
    {

        qDebug()<<("Yay! Your database host is "+myDB.hostName()+" .\n"+" The name of the database is "+myDB.databaseName()+".");
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
   // queryReader.prepare(sql);
    bool success=queryReader.exec(sql);

    if(!success)
    {
        qDebug()<<(queryReader.lastError());
    }

       int count=0;
       while(queryReader.next())
       {
           count++;
       }
        if(count>0)
        {
           CloseDBConnection();
           return true;
        }

     CloseDBConnection();
     return false;
}
