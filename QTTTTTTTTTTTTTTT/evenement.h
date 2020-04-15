#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include "connexion.h"
#include <QSqlQuery>
#include <QSqlQueryModel>


class evenement
{
public:
    evenement();
    evenement(int,QString,QString,QString,int);
    QString get_nom();
    QString get_type();
    QString get_date();
    int get_budget();
    int set_budget();

    int get_ref();
    void set_nom(QString a);
    void set_ref(int n);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2(QString);
    bool supprimer(int);
    bool modifier(QString,QString,QString,QString,int);
    QSqlQueryModel * affichernom();
    QSqlQueryModel * affichernomtrie(QString);
    QSqlQueryModel * afficherfiltre(QString);



private:
    QString nom,type,datee;
    int ref, budget;

};

#endif // EVENEMENT_H
