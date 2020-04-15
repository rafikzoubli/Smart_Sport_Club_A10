#include "connexion.h"

Connexion::Connexion()
{

}
bool Connexion::ouvrirConnexion()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projetQt");
    db.setUserName("faress");
    db.setPassword("fares");
    if(db.open())
        test=true;
    return test;
}
void Connexion::fermerConnexion()
{db.close();}
