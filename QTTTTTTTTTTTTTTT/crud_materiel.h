#ifndef CRUD_MATERIEL_H
#define CRUD_MATERIEL_H

#include <QDialog>
#include <QObject>
#include <QMainWindow>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "materiel.h"
#include "first.h"
#include "ui_crud_materiel.h"
namespace Ui {
class crud_materiel;
}

class crud_materiel : public QDialog
{
    Q_OBJECT

public:
    explicit crud_materiel(QDialog *parent = nullptr);
    ~crud_materiel();

private slots:
    void on_pb_ajouter_clicked();



    void on_pb_supprimer_4_clicked();

    void on_pb_supprimer_3_clicked();

    void on_tabmateriel_activated(const QModelIndex &index);

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_lineEdit_id_6_returnPressed();

    void on_lineEdit_id_6_textChanged(const QString &arg1);

   // void on_pushButton_clicked();

    void on_pushButton0_clicked();

private:
    Ui::crud_materiel *ui;

    Materiel tmpmateriel;
};

#endif // CRUD_MATERIEL_H
