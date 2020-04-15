#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crud_joueur.h"
#include "connexion.h"
#include <QApplication>
#include "crud_actualite.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    hide();
    mDialog = new crud_joueur(this); // allocated space for a new MyDialog
                                 // while also giving a parent class of
                                 // this, the MainWindow class
    mDialog->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    mDialo = new crud_actualite(this); // allocated space for a new MyDialog
                                 // while also giving a parent class of
                                 // this, the MainWindow class
    mDialo->show();
}
