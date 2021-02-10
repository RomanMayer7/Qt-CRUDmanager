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

QSqlQueryModel* DbRepository::GetAllGameRecords()
{
    OpenDBConnection();

    if(!myDB.isOpen())
    {
        qDebug()<<("Failed to Open Connection");
        return NULL;

    }
    else
    {
        QSqlQueryModel * model =new  QSqlQueryModel ();
        QSqlQuery* query =new   QSqlQuery(myDB);
      //  query->prepare("SELECT * FROM Games");
        query->exec("SELECT Games.Title,Games.Publisher,Games.Year,Genres.Genre FROM Games JOIN Genres ON Games.Genre=Genres.ID");
        model->setQuery(*query);

         qDebug()<<(model->rowCount());

        return model;
    }
}

QSqlQueryModel* DbRepository::GetAllGenreRecords()
{
    OpenDBConnection();

    if(!myDB.isOpen())
    {
        qDebug()<<("Failed to Open Connection");
        return NULL;

    }
    else
    {
        QSqlQueryModel * model =new  QSqlQueryModel ();
        QSqlQuery* query =new   QSqlQuery(myDB);
      //  query->prepare("SELECT * FROM Games");
        query->exec("SELECT Genre FROM Genres ORDER BY Id");
        model->setQuery(*query);

         qDebug()<<(model->rowCount());

        return model;
    }
}

void DbRepository::AddGameRecord(QString _title,QString _publisher,int _genre,QString _year)
{
    OpenDBConnection();

    if(!myDB.isOpen())
    {
        qDebug()<<("Failed to Open Connection in AddGameRecord()");

    }
    QSqlQuery* query = new  QSqlQuery(myDB);
    QString sql="INSERT INTO Games(Title,Publisher,Genre,Year) VALUES('"+_title+"','"+_publisher+"','"+QString::number(_genre+1)+"','"+_year+"')";
    query->exec(sql);

}
