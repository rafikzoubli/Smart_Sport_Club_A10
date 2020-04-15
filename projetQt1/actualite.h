#ifndef ACTUALITE_H
#define ACTUALITE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class actualite
{
public:
    actualite();
    actualite(int,QString,QString);
    int get_ref();
    QString get_description();
    QString get_titre();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString);

private:
    QString description,titre;
    int reff;
};

#endif // ACTUALITE_H
