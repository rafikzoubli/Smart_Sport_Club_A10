#include "crud_evenement.h"
#include "ui_crud_evenement.h"
#include "evenement.h"
#include "first.h"
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QDate>

crud_evenement::crud_evenement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::crud_evenement)
{
    ui->setupUi(this);
    ui->tabevent->setModel(tmpevent.afficher());
}

crud_evenement::~crud_evenement()
{
    delete ui;
}

void crud_evenement::on_pushButton_ajout_C_clicked()
{
    int ref = ui->ref->text().toInt();
    int budget= ui->budget->text().toInt();
    QString nom= ui->nom->text();
    QString type= ui->type->text();
    QString date= ui->date->text();
    first w;

    evenement e(ref,nom,type,date,budget);
     bool test=e.ajouter();
    if(test)
    {
        ui->tabevent->setModel(tmpevent.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un evenement"),
        QObject::tr("Event ajouté"), QMessageBox::Ok);
        ui->comboBox->setModel(tmpevent.affichernom());
          w.show();


    }
    else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un event"),
                  QObject::tr("Erreur !"), QMessageBox::Cancel);




    // allocated space for a new MyDialog
                                 // while also giving a parent class of
                                 // this, the MainWindow class
 // call the show method on the object
}

void crud_evenement::on_pushButton_supprimer_C_clicked()
{
    first w;
        int ref = ui->ref->text().toInt();
        QString nom=ui->nom->text();
        if (ref==0)
        {
            QMessageBox::warning(nullptr, QObject::tr("Modification"),
                              QObject::tr("Veuillez selectionner un matériel"), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox msgBox;
            QPushButton *connectButton = msgBox.addButton(tr("Confirmer"), QMessageBox::ActionRole);
             QPushButton *abortButton = msgBox.addButton(QMessageBox::Cancel);
             msgBox.setText("Voulez-vous vraiment supprimer "+nom+" de la liste ?");
             msgBox.exec();

             if (msgBox.clickedButton() == connectButton)
             {
                 msgBox.close();
                 tmpevent.supprimer(ref);
                 ui->tabevent->setModel(tmpevent.afficher());
                     QMessageBox::information(nullptr, QObject::tr("Supprimer Evenement"),
                                 QObject::tr("Evenement supprimé"), QMessageBox::Ok);
                       w.show();
                     ui->comboBox->setModel(tmpevent.affichernom());


             }
             else if (msgBox.clickedButton() == abortButton) {
                 msgBox.close();
             }
        }

}

void crud_evenement::on_pushButton_Modifier_C_clicked()
{
    first w;
        QString reff=ui->ref->text();
        QSqlQuery qry;
        int budgett=ui->budget->text().toInt();
        QString nomm=ui->nom->text();
        QString typee=ui->type->text();
        QString datee=ui->date->text();
        if (nomm=="" || reff ==0)
        {
            QMessageBox::warning(nullptr, QObject::tr("Modification"),
                              QObject::tr("Veuillez selectionner un matériel"), QMessageBox::Ok);
        }
        else
        {
          /*  modification d;
            d.setnom(nom);
            d.setref(reff);
            d.exec(); */
            ui->ref->setText(qry.value(0).toString());
            ui->nom->setText(qry.value(1).toString());
            ui->type->setText(qry.value(2).toString());
            ui->date->setText(qry.value(3).toString());
            ui->budget->setText(qry.value(4).toString());

            bool test=tmpevent.modifier(reff,nomm,typee,datee,budgett);
            if (test)
            {
                QMessageBox::information(nullptr, QObject::tr("Modifier evenement"),
                            QObject::tr("evenenement modifié"), QMessageBox::Ok);

            }
            w.show();
        }
        ui->tabevent->setModel(tmpevent.afficher());
        ui->comboBox->setModel(tmpevent.affichernom());
}

void crud_evenement::on_pushButton_clicked()
{
    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tabevent->model()->rowCount();
                const int columnCount = ui->tabevent->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title>ERP - COMmANDE LIST<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> ******Liste des events ****** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tabevent->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tabevent->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tabevent->isColumnHidden(column)) {
                            QString data =ui->tabevent->model()->data(ui->tabevent->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                if (dialog->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;
}

void crud_evenement::on_pushButton_2_clicked()
{
    first w;
    hide();
    w.exec();
}
