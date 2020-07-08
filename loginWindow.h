#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "mainWindow.h"
#include "dbRepository.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
     LoginWindow(QWidget *parent = nullptr);
     ~LoginWindow();
private slots:
     void on_loginButton_clicked();

private:
    Ui::LoginWindow *ui;
    MainWindow *mainWindow; //pointer to MainWindow object
    DbRepository dbRepository; //pointer to DbRepository object
};

#endif // LOGIN_H

