#include "donateurcontroller.h"

DonateruController::DonateruController()
{

}

DonateruController::DonateruController(int id, QString nom, QString prenom, int ref_don, double montant)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->ref_don=ref_don;
    this->montant=montant;
}

bool DonateruController::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO DONATEUR (ID, NOM, PRENOM,REF_DON,MONTANT) "
                        "VALUES (:id, :nom, :prenom,:ref_don,:montant)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":ref_don", ref_don);
    query.bindValue(":montant", montant);
    return    query.exec();
}

QSqlQueryModel *DonateruController::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID,NOM,PRENOM,REF_DON,MONTANT from DONATEUR");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("REF Don"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MONTANT"));
    return model;
}

bool DonateruController::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE DONATEUR SET NOM=:nom, PRENOM=:prenom, REF_DON=:ref_don , MONTANT=:montant "
                        "WHERE ID=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":ref_don", ref_don);
    query.bindValue(":montant", montant);
    return    query.exec();
}

bool DonateruController::supprimer()
{
    QSqlQuery query;
    query.prepare("DELETE FROM DONATEUR "
                        "WHERE ID=:id");
    query.bindValue(":id", id);

    return    query.exec();
}

QSqlQueryModel *DonateruController::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID,NOM,PRENOM,REF_DON,MONTANT from DONATEUR "+cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("REF Don"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MONTANT"));
    return model;
}

QSqlQueryModel *DonateruController::getIDs()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID from DONATEUR");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

    return model;
}
