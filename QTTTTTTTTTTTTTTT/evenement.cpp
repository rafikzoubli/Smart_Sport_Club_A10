#include "evenement.h"
#include <QDebug>

evenement::evenement()
{
ref=0;
nom="";
type="";
budget=0;
datee="";

}
evenement::evenement(int ref,QString nom,QString type, QString datee, int budget)
{
  this->ref=ref;
  this->nom=nom;
  this->type=type;
  this->budget=budget;
    this->datee=datee;

}

int evenement::get_ref(){return  ref;}
QString evenement::get_type(){return  type;}
QString evenement::get_date(){return  datee;}
QString evenement::get_nom(){return  nom;}
int evenement::get_budget(){return budget;}

bool evenement::ajouter()
{
QSqlQuery query;
QString res= QString::number(ref);
QString res1= QString::number(budget);
query.prepare("INSERT INTO evenement (ref, nom, type, datee, budget) "
                    "VALUES (:ref, :nom, :type, :datee, :budget)");
query.bindValue(":ref", res);
query.bindValue(":nom", nom);
query.bindValue(":type", type);
query.bindValue(":datee", datee);
query.bindValue(":budget", res1);


return    query.exec();
}

QSqlQueryModel * evenement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from evenement order by ref");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Budget"));
    return model;
}

bool evenement::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
if (idd==0)
{
    return false;
}
else
{
    query.prepare("Delete from evenement where ref = :ref ");
    query.bindValue(":ref", res);
    return    query.exec();
}

}

bool evenement::modifier(QString ref,QString nom, QString type, QString datee, int budget)
{

        QSqlQuery query;
       // QString res=QString::number(reff);
        //QString res1=QString ::number(budget);
        query.prepare("UPDATE evenement SET nom=:nom, type=:type, datee=:datee, budget=:budget WHERE ref ='"+ref+"' ");


        query.bindValue(":nom", nom);
        query.bindValue(":type", type);
        query.bindValue(":datee", datee);
         query.bindValue(":budget", budget);
        return    query.exec();
}


QSqlQueryModel * evenement::afficher2(QString ref)
{QSqlQueryModel * model= new QSqlQueryModel();
    //QString res= QString::number(ref);
    QString cherche="Select * from evenement where ref like '"+ref+"%' or nom like '"+ref+"%'";
if (ref=="")
{
    model->setQuery("select * from evenement order by ref");

}
else
{
    model->setQuery(cherche);

}
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Budget"));


    return model;
}

QSqlQueryModel * evenement::affichernom()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select nom from evenement");
    return model;
}

QSqlQueryModel * evenement::affichernomtrie(QString trie)
{QSqlQueryModel * model= new QSqlQueryModel();
    if(trie=="Référence")
    {
        model->setQuery("select * from materiel order by ref");

    }
    else if (trie=="Nom")
    {
        model->setQuery("select * from materiel order by nom");

    }
    else if (trie=="budget")
    {
        model->setQuery("select * from materiel order by budget");

    }
    else
    {
        model->setQuery("select * from evenement");
    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Budget"));
    return model;
}

QSqlQueryModel * evenement::afficherfiltre(QString budgett)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from evenement where budget<='"+budgett+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Budget"));
    return  model;
}

