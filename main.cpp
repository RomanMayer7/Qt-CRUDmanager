#include "mainWindow.h"
#include "loginWindow.h"



#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow mainWindow; //create instance of mainWindow
    LoginWindow loginWindow; //create instance of loginWindow
   // mainWindow.show();
     loginWindow.show();

    return a.exec();
}
