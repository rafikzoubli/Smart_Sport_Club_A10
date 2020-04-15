#ifndef FIRST_H
#define FIRST_H
#include <QObject>
#include <QDialog>
#include <QWidget>
#include "crud_evenement.h"
#include "crud_materiel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class first; }
QT_END_NAMESPACE

class first : public QDialog
{
    Q_OBJECT

public:
    first(QWidget *parent = nullptr);
    ~first();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::first *ui;

      crud_evenement * mDialo;
      //crud_materiel * mDialog;

};
#endif // FIRST_H
