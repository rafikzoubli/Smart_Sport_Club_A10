#include "doncontroller.h"

DonController::DonController()
{

}

DonController::DonController(int id_don, double montant_don, int id_donateur, QDate datee)
{
    this->id_don=id_don;
    this->montant_don=montant_don;
    this->id_donateur=id_donateur;
    this->datee=datee;
}

bool DonController::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO DON (ID_DON, MONTANT_DON, ID_DONATEUR,DATEE) "
                            "VALUES (:id_don, :montant_don, :id_donateur,:datee)");
        query.bindValue(":id_don", id_don);
        query.bindValue(":montant_don", montant_don);
        query.bindValue(":id_donateur", id_donateur);
        query.bindValue(":datee", datee);
        return    query.exec();
}

QSqlQueryModel *DonController::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from DON");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Donateur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Montant"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEE"));
    return model;
}

bool DonController::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE DON SET MONTANT_DON=:montant_don, ID_DONATEUR=:id_donateur,DATEE=:datee "
                        "WHERE ID_DON=:id_don");
    query.bindValue(":id_don", id_don);
    query.bindValue(":montant_don", montant_don);
    query.bindValue(":id_donateur", id_donateur);
    query.bindValue(":datee", datee);
    return    query.exec();
}

bool DonController::supprimer()
{
    QSqlQuery query;
    query.prepare("DELETE FROM DON"
                        "WHERE ID_DON=:id_don");
    query.bindValue(":id_don", id_don);
    return    query.exec();
}

QSqlQueryModel *DonController::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from DON " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Donateur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Montant"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATEE"));
    return model;
}

QSqlQueryModel *DonController::getIDs()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from DON");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model;
}
