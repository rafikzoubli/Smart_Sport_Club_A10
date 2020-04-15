#ifndef JOUEURS_H
#define JOUEURS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class joueurs
{
        public:
            joueurs();
            joueurs(int,QString,QString,QString,int);
            int get_id();
            QString get_nom();
            QString get_prenom();
            QString get_poste();
            int get_num();
            bool ajouter();

            bool supprimer(int);
            bool modifier(int,QString,QString,QString,int);

            QSqlQueryModel * affichernom();
            QSqlQueryModel * afficher2(int,QString nom);

            QSqlQueryModel * afficher();
            QSqlQueryModel * afficher3();
        private:
            QString nom,prenom,poste;
            int id,num;
};

#endif // JOUEURS_H
