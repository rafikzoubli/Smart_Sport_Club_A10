#include "crud_actualite.h"
#include "ui_crud_actualite.h"
#include "actualite.h"

crud_actualite::crud_actualite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crud_actualite)
{
    ui->setupUi(this);
    ui->tabactualite->setModel(tmpactualite.afficher());

}

crud_actualite::~crud_actualite()
{
    delete ui;
}

void crud_actualite::on_pushButton_3_clicked()
{
    int reff= ui->ref->text().toInt();
    QString description= ui->description->text();
    QString titre= ui->titre->text();
    actualite a(reff,titre,description);
     bool test=a.ajouter();
    if(test)
    {
        ui->tabactualite->setModel(tmpactualite.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter une actualite"),
        QObject::tr("Actualite ajoutée"), QMessageBox::Ok);


    }
    else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une actualite"),
                  QObject::tr("Erreur !"), QMessageBox::Cancel);
}

void crud_actualite::on_pushButton_11_clicked()
{
    int reff = ui->reff->text().toInt();
    QString description=ui->descriptionn->text();
    QString titre=ui->titree->text();
    if (reff==0)
    {
        QMessageBox::warning(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez selectionner une actualite"), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox msgBox;
        QPushButton *connectButton = msgBox.addButton(tr("Confirmer"), QMessageBox::ActionRole);
         QPushButton *abortButton = msgBox.addButton(QMessageBox::Cancel);
         msgBox.setText("Voullez-vous vraiment supprimer "+titre+" de la liste ?");
         msgBox.exec();

         if (msgBox.clickedButton() == connectButton)
         {
             msgBox.close();

                 QMessageBox::information(nullptr, QObject::tr("Supprimer une actualite"),
                             QObject::tr("Actualite supprimée"), QMessageBox::Ok);
         }
         else if (msgBox.clickedButton() == abortButton) {
             msgBox.close();
         }
    }

}

void crud_actualite::on_pushButton_10_clicked()
{
        int ref=ui->reff->text().toInt();
        QSqlQuery qry;
        QString titre=ui->titree->text();

        QString description=ui->descriptionn->text();
        if (titre=="" || ref ==0)
        {
            QMessageBox::warning(nullptr, QObject::tr("Modification"),
                              QObject::tr("Veuillez selectionner une actualité"), QMessageBox::Ok);
        }
        else
        {
          /*  modification d;
            d.settitre(titree);
            d.setref(reff);
            d.exec(); */
            ui->reff->setText(qry.value(0).toString());
            ui->titree->setText(qry.value(1).toString());
            ui->descriptionn->setText(qry.value(2).toString());
           bool test=tmpactualite.modifier(ref,titre,description);
            if (test)
            {
                QMessageBox::information(nullptr, QObject::tr("Modifier actualité"),
                            QObject::tr("Actualité modifié"), QMessageBox::Ok);

            }
        }
        ui->tabactualite->setModel(tmpactualite.afficher());
}
