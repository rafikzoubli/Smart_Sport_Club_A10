#include "don.h"
#include "database.h"
#include <QMessageBox>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database c;
    bool test=c.ouvrirConnexion();
    if(test)
    {
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
else

        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    Don w;
    w.show();
    return a.exec();
}
