#ifndef DONCONTROLLER_H
#define DONCONTROLLER_H

#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class DonController
{
public:
    DonController();
    DonController(int,double,int,QDate);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool modifier();
    bool supprimer();
    QSqlQueryModel *displayClause(QString cls);
    QSqlQueryModel *getIDs();
private:
    int id_don;
    double montant_don;
    int id_donateur;
    QDate datee;
};

#endif // DONCONTROLLER_H
