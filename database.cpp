#include "database.h"

Database::Database()
{

}

bool Database::ouvrirConnexion()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("amine");//inserer nom de l'utilisateur
    db.setPassword("ward3265");//inserer mot de passe de cet utilisateur
    if (db.open())
        test=true;
    return  test;
}

void Database::fermerConnexion()
{
    db.close();
}
