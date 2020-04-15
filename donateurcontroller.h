#ifndef DONATEUR_CONTROLLER_H
#define DONATEUR_CONTROLLER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class DonateruController
{
public:
    DonateruController();
    DonateruController(int id, QString nom,QString prenom,int ref_don,double montant);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool modifier();
    bool supprimer();
    QSqlQueryModel *displayClause(QString cls);
    QSqlQueryModel *getIDs();
private:
    int id,ref_don;
    QString nom,prenom;
    double montant;

};

#endif // DONATEUR_CONTROLLER_H
