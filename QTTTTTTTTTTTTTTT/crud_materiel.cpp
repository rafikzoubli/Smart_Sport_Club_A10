#include "crud_materiel.h"
#include "ui_crud_materiel.h"
#include "QMessageBox"
#include "connexion.h"
#include "first.h"
#include "QStringListModel"
#include "modification.h"
#include <QFile>
#include <QTimer>
#include <QPrintDialog>
#include <QPrinter>
#include <QDate>
#include <QTextDocument>
#include <QTextStream>
#include <QDialog>

/*crud_materiel::crud_materiel(QDialog *parent) :
    QMainWindow(parent),
    ui(new Ui::crud_materiel)
{
    //ui->setupUi(this);


    ui->tabmateriel->setModel(tmpmateriel.afficher());
    ui->comboBox->setModel(tmpmateriel.affichernom());
}*/

crud_materiel::crud_materiel(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::crud_materiel)
{
ui->setupUi(this);
ui->tabmateriel->setModel(tmpmateriel.afficher());
ui->comboBox->setModel(tmpmateriel.affichernom());
ui->comboBox_2->addItem("Trier par :");
ui->comboBox_2->addItem("Référence");
ui->comboBox_2->addItem("Nom");
ui->comboBox_2->addItem("Nombre");



}

crud_materiel::~crud_materiel()
{
    delete ui;
}


void crud_materiel::on_pb_ajouter_clicked()
{

    int ref = ui->ref->text().toInt();
    QString nom= ui->nom->text();
    first w;
    int nbr= ui->nbr->text().toInt();
    Materiel e(ref,nom,nbr);
     bool test=e.ajouter();
    if(test)
    {
        ui->tabmateriel->setModel(tmpmateriel.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Materiel"),
        QObject::tr("Materiel ajouté"), QMessageBox::Ok);
        ui->comboBox->setModel(tmpmateriel.affichernom());
        w.show();


    }
    else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Materiel"),
                  QObject::tr("Erreur !"), QMessageBox::Cancel);




    // allocated space for a new MyDialog
                                 // while also giving a parent class of
                                 // this, the MainWindow class
 // call the show method on the object
}






void crud_materiel::on_pb_supprimer_4_clicked()
{   first w;
    int ref = ui->ref->text().toInt();
    QString nom=ui->nom->text();
    if (ref==0)
    {
        QMessageBox::warning(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez selectionner un matériel"), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox msgBox;
        QPushButton *connectButton = msgBox.addButton(tr("Confirmer"), QMessageBox::ActionRole);
         QPushButton *abortButton = msgBox.addButton(QMessageBox::Cancel);
         msgBox.setText("Voulez-vous vraiment supprimer "+nom+" de la liste ?");
         msgBox.exec();

         if (msgBox.clickedButton() == connectButton)
         {
             msgBox.close();
             tmpmateriel.supprimer(ref);
             ui->tabmateriel->setModel(tmpmateriel.afficher());
                 QMessageBox::information(nullptr, QObject::tr("Supprimer Matériel"),
                             QObject::tr("Matériel supprimé"), QMessageBox::Ok);
                   w.show();
                 ui->comboBox->setModel(tmpmateriel.affichernom());


         }
         else if (msgBox.clickedButton() == abortButton) {
             msgBox.close();
         }
    }


}

void crud_materiel::on_pb_supprimer_3_clicked()
{   first w;
    QString ref=ui->ref->text();
    QSqlQuery qry;
    int nbr=ui->nbr->text().toInt();
    QString nom=ui->nom->text();
    if (nom=="" || ref ==0)
    {
        QMessageBox::warning(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez selectionner un matériel"), QMessageBox::Ok);
    }
    else
    {
      /*  modification d;
        d.setnom(nom);
        d.setref(reff);
        d.exec(); */
        ui->ref->setText(qry.value(0).toString());
        ui->nom->setText(qry.value(1).toString());
        ui->nbr->setText(qry.value(2).toString());
        bool test=tmpmateriel.modifier(ref,nbr);
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Modifier Matériel"),
                        QObject::tr("Matériel modifié"), QMessageBox::Ok);

        }
        w.show();
    }
    ui->tabmateriel->setModel(tmpmateriel.afficher());
    ui->comboBox->setModel(tmpmateriel.affichernom());

}

void crud_materiel::on_tabmateriel_activated(const QModelIndex &index)
{
    QString nom=ui->tabmateriel->model()->data(index).toString();
    QSqlQuery qry;

    qry.prepare("select * from materiel where nom = '"+nom+"' or ref ='"+nom+"'");
    if (qry.exec())
    {
        while(qry.next())
        {
            ui->ref->setText(qry.value(0).toString());
            ui->nom->setText(qry.value(1).toString());
            ui->nbr->setText(qry.value(2).toString());
        }
    }
    else
    {
        QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }
}

void crud_materiel::on_comboBox_2_activated(const QString &arg1)
{
    ui->tabmateriel->setModel( tmpmateriel.affichernomtrie(arg1));

}

void crud_materiel::on_comboBox_activated(const QString &arg1)
{
    QSqlQuery qry;

    qry.prepare("select * from materiel where nom = '"+arg1+"'");
    if (qry.exec())
    {
        while(qry.next())
        {
            ui->ref->setText(qry.value(0).toString());
            ui->nom->setText(qry.value(1).toString());
            ui->nbr->setText(qry.value(2).toString());
        }
    }
    else
    {
        QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }
}

void crud_materiel::on_lineEdit_id_6_returnPressed()
{
    QString ref=ui->lineEdit_id_6->text();
    ui->tabmateriel->setModel(tmpmateriel.afficher2(ref));//refresh
    QSqlQuery qry;
        qry.prepare("select * from materiel where ref = '"+ref+"'");
        if (qry.exec())
        {
            while(qry.next())
            {
                ui->ref->setText(qry.value(0).toString());
                ui->nom->setText(qry.value(1).toString());
                ui->nbr->setText(qry.value(2).toString());
            }
        }
        else

            QMessageBox::critical(this,tr("error"),qry.lastError().text());

}

void crud_materiel::on_lineEdit_id_6_textChanged(const QString &arg1)
{
    ui->tabmateriel->setModel(tmpmateriel.afficher2(arg1));//refresh
}


void crud_materiel::on_pushButton0_clicked()
{
    first w;
    hide();
    w.exec();
}
