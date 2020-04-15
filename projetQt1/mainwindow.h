#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "crud_actualite.h"
#include "crud_joueur.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    crud_joueur *mDialog;
    crud_actualite *mDialo;
};
#endif // MAINWINDOW_H
