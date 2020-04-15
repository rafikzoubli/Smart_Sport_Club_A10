#include "first.h"
#include "ui_first.h"
#include "crud_materiel.h"
#include "crud_evenement.h"
#include "connexion.h"
#include <QLabel>
#include <QDialog>

first::first(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::first)
{
    ui->setupUi(this);
    QLabel topLevelLabel;
      QPixmap pixmap("..:/img/stade.jpg");
      topLevelLabel.setPixmap(pixmap);


}

first::~first()
{
    delete ui;
}


void first::on_pushButton_clicked()
{
    hide();
   // mDialog = new crud_materiel(this); // allocated space for a new MyDialog
   crud_materiel c;

   c.exec();// while also giving a parent class of
                                 // this, the MainWindow class
  //  mDialog->show(); // call the show method on the object

}

void first::on_pushButton_2_clicked()
{
    hide();
    mDialo = new crud_evenement(this); // allocated space for a new MyDialog
                                 // while also giving a parent class of
                                 // this, the MainWindow class
    mDialo->show();

}
