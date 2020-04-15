#include "don.h"
#include "ui_don.h"
#include "doncontroller.h"
#include "donateurcontroller.h"
#include "QMessageBox"

Don::Don(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Don)
{

    ui->setupUi(this);

    ui->data->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->data_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->DATE->setDate(QDate::currentDate());
    DonController tmp;
    DonateruController tmp2;
    ui->data->setModel(tmp.afficher());
    ui->ID_DONATEUR->setModel(tmp2.getIDs());
    ui->data_2->setModel(tmp2.afficher());
    ui->REF->setModel(tmp.getIDs());
}

Don::~Don()
{
    delete ui;
}


void Don::on_pb_ajouter_clicked()
{
    DonController tmp(ui->ID_DON->text().toInt(),ui->MONTANT_DON->text().toDouble(),ui->ID_DONATEUR->currentText().toInt(),ui->DATE->date());
    if(tmp.ajouter())
    {
        ui->data->setModel(tmp.afficher());
        ui->lineEdit_id_6->setText("");
        ui->REF->setModel(tmp.getIDs());
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                          QObject::tr("Success.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                          QObject::tr("Erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void Don::on_pb_supprimer_3_clicked()
{
    if(ui->data->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez Choisir un Don du Tableau.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
        DonController tmp(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toInt(),ui->MONTANT_DON->text().toDouble(),ui->ID_DONATEUR->currentText().toInt(),ui->DATE->date());
        if(tmp.modifier())
        {
            ui->data->setModel(tmp.afficher());
            ui->lineEdit_id_6->setText("");
            ui->REF->setModel(tmp.getIDs());
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }

}

void Don::on_pb_supprimer_4_clicked()
{

    if(ui->data->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                          QObject::tr("Veuillez Choisir un Don du Tableau.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
        DonController tmp(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toInt(),ui->MONTANT_DON->text().toDouble(),ui->ID_DONATEUR->currentText().toInt(),ui->DATE->date());
        if(tmp.supprimer())
        {
            ui->data->setModel(tmp.afficher());
            ui->lineEdit_id_6->setText("");
            ui->REF->setModel(tmp.getIDs());
            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }

}

void Don::on_data_clicked(const QModelIndex &index)
{
    ui->ID_DON->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toString());
    ui->MONTANT_DON->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),2)).toString());
    ui->ID_DONATEUR->setCurrentText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),1)).toString());
    ui->DATE->setDate(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),3)).toDate());

}

void Don::on_lineEdit_id_6_textChanged(const QString &arg1)
{
     DonController tmp;
     if(ui->lineEdit_id_6->text()!="")
     ui->data->setModel(tmp.displayClause("WHERE "+ui->comboBox->currentText()+"="+ui->lineEdit_id_6->text()+" ORDER BY "+ui->ID_DONATEUR_2->currentText()));
     else
     ui->data->setModel(tmp.afficher());
}

void Don::on_comboBox_currentTextChanged(const QString &arg1)
{
    DonController tmp;
    if(ui->lineEdit_id_6->text()!="")
    ui->data->setModel(tmp.displayClause("WHERE "+ui->comboBox->currentText()+"="+ui->lineEdit_id_6->text()+" ORDER BY "+ui->ID_DONATEUR_2->currentText()));
    else
    ui->data->setModel(tmp.afficher());
}

void Don::on_ID_DONATEUR_2_currentTextChanged(const QString &arg1)
{
    DonController tmp;
    if(ui->lineEdit_id_6->text()!="")
    ui->data->setModel(tmp.displayClause("WHERE "+ui->comboBox->currentText()+"="+ui->lineEdit_id_6->text()+" ORDER BY "+ui->ID_DONATEUR_2->currentText()));
    else
    ui->data->setModel(tmp.displayClause("ORDER BY "+ui->ID_DONATEUR_2->currentText()));
}

void Don::on_pb_ajouter_2_clicked()
{
    DonateruController tmp(ui->ID_DONATEUR_3->text().toInt(),ui->NOM->text(),ui->PRENOM->text(),ui->REF->currentText().toInt(),ui->MONTANT->text().toDouble());
    if(tmp.ajouter())
    {
        ui->data_2->setModel(tmp.afficher());
        ui->lineEdit_id_7->setText("");
        ui->ID_DONATEUR->setModel(tmp.getIDs());
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                          QObject::tr("Success.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                          QObject::tr("Erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Don::on_pb_supprimer_5_clicked()
{
    if(ui->data_2->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez Choisir un Don du Tableau.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
        DonateruController tmp(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),0)).toInt(),ui->NOM->text(),ui->PRENOM->text(),ui->REF->currentText().toInt(),ui->MONTANT->text().toDouble());
        if(tmp.modifier())
        {
            ui->data_2->setModel(tmp.afficher());
            ui->lineEdit_id_7->setText("");
            ui->ID_DONATEUR->setModel(tmp.getIDs());
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void Don::on_pb_supprimer_6_clicked()
{
    if(ui->data_2->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                          QObject::tr("Veuillez Choisir un Donateur du Tableau.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
        DonateruController tmp(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),0)).toInt(),ui->NOM->text(),ui->PRENOM->text(),ui->REF->currentText().toInt(),ui->MONTANT->text().toDouble());
        if(tmp.supprimer())
        {
            ui->data_2->setModel(tmp.afficher());
            ui->lineEdit_id_7->setText("");
            ui->ID_DONATEUR->setModel(tmp.getIDs());
            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void Don::on_lineEdit_id_7_textChanged(const QString &arg1)
{
    DonateruController tmp;
    if(ui->lineEdit_id_7->text()!="")
    ui->data_2->setModel(tmp.displayClause("WHERE "+ui->comboBox_2->currentText()+"='"+ui->lineEdit_id_7->text()+"' ORDER BY "+ui->ID_DONATEUR_4->currentText()));
    else
    ui->data_2->setModel(tmp.afficher());
}

void Don::on_ID_DONATEUR_4_currentTextChanged(const QString &arg1)
{
    DonateruController tmp;
    if(ui->lineEdit_id_7->text()!="")
    ui->data_2->setModel(tmp.displayClause("WHERE "+ui->comboBox_2->currentText()+"='"+ui->lineEdit_id_7->text()+"' ORDER BY "+ui->ID_DONATEUR_4->currentText()));
    else
    ui->data_2->setModel(tmp.displayClause("ORDER BY "+ui->ID_DONATEUR_4->currentText()));
}

void Don::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    DonateruController tmp;
    if(ui->lineEdit_id_7->text()!="")
    ui->data_2->setModel(tmp.displayClause("WHERE "+ui->comboBox_2->currentText()+"='"+ui->lineEdit_id_7->text()+"' ORDER BY "+ui->ID_DONATEUR_4->currentText()));
    else
    ui->data_2->setModel(tmp.afficher());
}

void Don::on_data_2_clicked(const QModelIndex &index)
{
    ui->ID_DONATEUR_3->setText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),0)).toString());
    ui->NOM->setText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),1)).toString());
    ui->PRENOM->setText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),2)).toString());
    ui->REF->setCurrentText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),3)).toString());
    ui->MONTANT->setText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),4)).toString());
}
