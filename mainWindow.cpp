#include "mainWindow.h"
#include "ui_mainWindow.h"
#include "dbRepository.h"
#include "winapiwrapper.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(dbRepository.GetAllGameRecords());
    ui->comboBox->setModel(dbRepository.GetAllGenreRecords());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   winAPIWrapper.HideSystemTray();
}



void MainWindow::on_pushButton_2_clicked()
{
    winAPIWrapper.ShowSystemTray();
}


void MainWindow::on_pushButton_3_clicked()
{
  winAPIWrapper.ToggleSystemTray();
}

void MainWindow::on_pushButton_5_clicked()
{
     ui->tableView->setModel(dbRepository.GetAllGameRecords());
}

void MainWindow::on_pushButton_4_clicked()
{
    QString title =ui->lineEdit->text();
    QString publisher =ui->lineEdit_2->text();
    int genre=ui->comboBox->currentIndex();
    QString year=ui->lineEdit_4->text();
    dbRepository.AddGameRecord(title,publisher,genre,year);
    ui->tableView->setModel(dbRepository.GetAllGameRecords());
}
