#ifndef CRUD_ACTUALITE_H
#define CRUD_ACTUALITE_H
#include "actualite.h"
#include <QDialog>
#include <QMessageBox>

#include <QDialog>

namespace Ui {
class crud_actualite;
}

class crud_actualite : public QDialog
{
    Q_OBJECT

public:
    explicit crud_actualite(QWidget *parent = nullptr);
    ~crud_actualite();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::crud_actualite *ui;
   actualite tmpactualite;
};

#endif // CRUD_ACTUALITE_H
