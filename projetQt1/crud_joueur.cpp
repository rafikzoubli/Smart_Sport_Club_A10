#include "crud_joueur.h"
#include "ui_crud_joueur.h"
#include "joueurs.h"

crud_joueur::crud_joueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crud_joueur)
{
    ui->setupUi(this);
    ui->tabjoueur->setModel(tmpjoueur.afficher());
}

crud_joueur::~crud_joueur()
{
    delete ui;
}

void crud_joueur::on_pushButton_16_clicked()
{
    int id = ui->id->text().toInt();
    QString nom= ui->nom->text();
    QString prenom= ui->prenom->text();
    QString poste= ui->poste->text();
        int num= ui->num->text().toInt();
    joueurs e(id,nom,prenom,poste,num);
     bool test=e.ajouter();
    if(test)
    {
        ui->tabjoueur->setModel(tmpjoueur.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Joueur"),
        QObject::tr("Joueur ajouté"), QMessageBox::Ok);


    }
    else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un joueur"),
                  QObject::tr("Erreur !"), QMessageBox::Cancel);}


void crud_joueur::on_pushButton_21_clicked()
{
    int id = ui->idd->text().toInt();
    QString nom=ui->nomm->text();
    QString prenom=ui->prenomm->text();
    QString poste=ui->postee->text();
    int num = ui->num->text().toInt();

    if (id==0)
    {
        QMessageBox::warning(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez selectionner un joueur"), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox msgBox;
        QPushButton *connectButton = msgBox.addButton(tr("Confirmer"), QMessageBox::ActionRole);
         QPushButton *abortButton = msgBox.addButton(QMessageBox::Cancel);
         msgBox.setText("Voullez-vous vraiment supprimer "+nom+" de la liste ?");
         msgBox.exec();

         if (msgBox.clickedButton() == connectButton)
         {
             msgBox.close();

                 QMessageBox::information(nullptr, QObject::tr("Supprimer un joueur"),
                             QObject::tr("Joueur supprimée"), QMessageBox::Ok);
         }
         else if (msgBox.clickedButton() == abortButton) {
             msgBox.close();
         }
    }
}

void crud_joueur::on_pushButton_19_clicked()
{
    crud_joueur w;
        int idd=ui->idd->text().toInt();
        QSqlQuery qry;
        QString nomm=ui->nomm->text();
        QString prenomm=ui->prenomm->text();
        QString postee=ui->postee->text();
        int num=ui->num->text().toInt();
        if (nomm=="" || idd ==0)
        {
            QMessageBox::warning(nullptr, QObject::tr("Modification"),
                              QObject::tr("Veuillez selectionner un joueur"), QMessageBox::Ok);
        }
        else
        {
          /*  modification d;
           *d.setidd(idd);
            d.setnomm(nomm);
            d.setprenomm(prenomm);
            d.setpostee(postee);
            d.setnum(num);

            d.exec(); */
            ui->idd->setText(qry.value(0).toString());
            ui->nomm->setText(qry.value(1).toString());
            ui->prenomm->setText(qry.value(2).toString());
            ui->postee->setText(qry.value(3).toString());
            ui->num->setText(qry.value(4).toString());
            bool test=tmpjoueur.modifier(idd,nomm,prenomm,postee,num);
            if (test)
            {
                QMessageBox::information(nullptr, QObject::tr("Modifier joueur"),
                            QObject::tr("Joueur modifié"), QMessageBox::Ok);

            }
            w.show();
        }
        ui->tabjoueur->setModel(tmpjoueur.afficher());
}
