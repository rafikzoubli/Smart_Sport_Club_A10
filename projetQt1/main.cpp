#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"
#include "crud_joueur.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    c.ouvrirConnexion();
    MainWindow s;
    s.show();
    return a.exec();
}
