#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>

class Database
{
private:
    QSqlDatabase db;
public:
    Database();
    bool ouvrirConnexion();
    void fermerConnexion();

};

#endif // DATABASE_H
