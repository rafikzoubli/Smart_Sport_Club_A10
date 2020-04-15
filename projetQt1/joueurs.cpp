#include "joueurs.h"
#include <QDebug>


joueurs::joueurs()
{
    id=0;
    nom="";
    prenom="";
    poste="";
    num=0;

}


joueurs::joueurs(int id,QString nom, QString prenom, QString poste, int num)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->poste=poste;
    this->num=num;

}
QString joueurs::get_nom(){return nom;}
QString joueurs::get_prenom(){return prenom;}
QString joueurs::get_poste(){return poste;}
int joueurs::get_id(){return id;}
int joueurs::get_num(){return num;}

bool joueurs::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString res1= QString::number(num);
query.prepare("INSERT INTO joueurs (id, nom, prenom, poste, num) "
                    "VALUES (:id, :nom, :prenom, :poste, :num)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":poste", poste);
query.bindValue(":num", res1);


return    query.exec();
}



QSqlQueryModel * joueurs::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from joueurs order by id");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poste"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));
    return model;
}
bool joueurs::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
if (idd==0)
{
    return false;
}
else
{
    query.prepare("Delete from joueur where id = :ref ");
    query.bindValue(":ref", res);
    return    query.exec();
}

}
bool joueurs::modifier(int idd,QString nomm,QString prenomm,QString postee,int num)
{

        QSqlQuery query;
        QString res= QString::number(idd);
        QString res1= QString::number(num);
        query.prepare("UPDATE joueurs SET nom=:nomm, prenom=:prenomm, poste=:postee, num=:num WHERE id ='"+res+"' ");

        query.bindValue(":id", idd);
        query.bindValue(":nom", nomm);
        query.bindValue(":prenom", prenomm);
        query.bindValue(":poste", postee);
        query.bindValue(":num", num);
         return    query.exec();
}

QSqlQueryModel * joueurs::afficher2(int idd,QString nomm)
{QSqlQueryModel * model= new QSqlQueryModel();
    QString res= QString::number(idd);
    QString cherche="Select * from joueur where id like '"+res+"%' or nom like '"+nomm+"%'";
if (idd==0)
{
    model->setQuery("select * from joueur order by idd");

}
else
{
    model->setQuery(cherche);

}
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poste"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));


    return model;
}

QSqlQueryModel * joueurs::affichernom()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select nom from joueur");
    return model;
}

