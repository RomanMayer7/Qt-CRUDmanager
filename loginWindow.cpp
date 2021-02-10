#include "loginWindow.h"
#include "ui_loginWindow.h"
#include "KeyPress.h"
#include <QMessageBox>
#include<QKeyEvent>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    installEventFilter(this);

}


LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::keyPressEvent(QKeyEvent *event)
{
    if((event->key() == Qt::Key_Enter)||(event->key() == Qt::Key_Return))
    {
         LoginWindow::Login();
    }
}

void LoginWindow::on_loginButton_clicked()  //Slot for Click Event on LoginButton
{
  LoginWindow::Login();

}
void LoginWindow::Login()
{
    QString username=ui->lineEdit_usr->text();
    QString password=ui->lineEdit_psw->text();

    bool loginSuccess=dbRepository.LoginToApplication(username,password);

    if(loginSuccess)
    {
        QMessageBox::information(this,"Login","Logged In Successfully","Proceed");
        hide();//Hiding he current window: LoginWindow
        mainWindow=new MainWindow(this);//Creating the instance of mainWindow
        mainWindow->show();//making it visible

    }
    else
    {
        QMessageBox::warning(this,"Login","Your Credentials are Wrong!");
    }
}
