#ifndef DON_H
#define DON_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class Don; }
QT_END_NAMESPACE

class Don : public QDialog
{
    Q_OBJECT

public:
    Don(QWidget *parent = nullptr);
    ~Don();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pb_supprimer_4_clicked();

    void on_data_clicked(const QModelIndex &index);

    void on_lineEdit_id_6_textChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_ID_DONATEUR_2_currentTextChanged(const QString &arg1);

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_5_clicked();

    void on_pb_supprimer_6_clicked();

    void on_lineEdit_id_7_textChanged(const QString &arg1);

    void on_ID_DONATEUR_4_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_data_2_clicked(const QModelIndex &index);

private:
    Ui::Don *ui;

};
#endif // DON_H
