
#include "connexion.h"
Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet");
db.setUserName("bali");//inserer nom de l'utilisateur
db.setPassword("bali");//inserer mot de passe de cet utilisateur


if (db.open())
test=true;

else
    qDebug()<<db.lastError().text();
     // qDebug() << "Connexion FAILED.";
       qDebug() << "Driver disponible: " << db.drivers();
       qDebug() << "Driver fonctionnel(QODBC): " << db.isDriverAvailable("QODBC");
       qDebug() << "numero de l'erreur: " << db.lastError().number();
       qDebug() << "database erreur: " << db.lastError().databaseText();
       qDebug() << "driver erreur: " << db.lastError().driverText();
       qDebug() << "type erreur: " << db.lastError().type();



    return  test;
}
