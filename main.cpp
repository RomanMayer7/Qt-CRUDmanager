#include "mainWindow.h"
#include "loginWindow.h"
#include <iostream>
//#include<QCoreApplication>



#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     std::cout<<"Hello Qt"<<std::endl;
    //MainWindow mainWindow; //create instance of mainWindow
    LoginWindow loginWindow; //create instance of loginWindow
   // mainWindow.show();
     loginWindow.show();

    return a.exec();
}
