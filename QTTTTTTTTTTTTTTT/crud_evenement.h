#ifndef CRUD_EVENEMENT_H
#define CRUD_EVENEMENT_H

#include <QDialog>
#include "evenement.h"

namespace Ui {
class crud_evenement;
}

class crud_evenement : public QDialog
{
    Q_OBJECT

public:
    explicit crud_evenement(QWidget *parent = nullptr);
    ~crud_evenement();

private slots:
    void on_pushButton_ajout_C_clicked();

    void on_pushButton_supprimer_C_clicked();

    void on_pushButton_Modifier_C_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::crud_evenement *ui;
     evenement tmpevent;
};

#endif // CRUD_EVENEMENT_H
