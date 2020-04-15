#include "actualite.h"
#include <QDebug>


actualite::actualite()
{
    reff=0;
    description="";
    titre="";


}
actualite::actualite(int reff,QString description, QString titre)
{
    this->reff=reff;
    this->description=description;
    this->titre=titre;
}


bool actualite::ajouter()
{
QSqlQuery query;
QString res= QString::number(reff);
query.prepare("INSERT INTO actualite (id, titre, description) "
                    "VALUES (:id, :titre, :description)");
query.bindValue(":id", res);
query.bindValue(":titre", titre);
query.bindValue(":description", description);



return    query.exec();
}
QSqlQueryModel * actualite::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from actualite order by ref");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
    return model;
}
QString actualite::get_description(){return description;}
QString actualite::get_titre(){return titre;}
int actualite::get_ref(){return reff;}

bool actualite::supprimer(int reff)
{
QSqlQuery query;
QString res= QString::number(reff);
if (reff==0)
{
    return false;
}
else
{
    query.prepare("delete from actualite where ref = :ref ");
    query.bindValue(":ref", res);
    return    query.exec();
}

}
bool actualite::modifier(int reff,QString titre,QString description)
{

        QSqlQuery query;
        QString res= QString::number(reff);
        //QString res1= QString::number(titree);
        query.prepare("UPDATE actualite SET titre=:titre, description=:description WHERE ref ='"+res+"' ");

       // query.bindValue(":ref", res);
        query.bindValue(":titre", titre);
        query.bindValue(":description", description);
         return    query.exec();
}


