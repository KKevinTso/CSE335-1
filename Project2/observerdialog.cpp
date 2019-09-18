#include "observerdialog.h"
#include "ui_observerdialog.h"
#include "nonstackbasedsumvisitor.h"
#include "dtablewidget.h"

#include <QString>
#include <iomanip>
#include <string>
#include <sstream>
#include <QLabel>


using namespace std;

ObserverDialog::ObserverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ObserverDialog)
{
    ui->setupUi(this);

    ui->pushButtonDelete->setEnabled(false);

    ui->labelText->setVisible(false);
    ui->labelNum->setVisible(false);

    //queues item clicked for deletion
    connect(ui->tableWidget, SIGNAL(itemClicked(QTableWidgetItem*)), ui->tableWidget, SLOT(itemClicked(QTableWidgetItem*)));
    connect(ui->tableWidget, SIGNAL(iChanged(QObject*)), this, SLOT(changeAction(QObject*)));

    //deletes queued item
    connect(ui->pushButtonDelete, SIGNAL(clicked()), ui->pushButtonDelete, SLOT(pushed()));
    connect(ui->pushButtonDelete, SIGNAL(iChanged(QObject*)), this, SLOT(changeAction(QObject*)));

    //shows total of items in cart for checkout
    connect(ui->pushButtonCheckout, SIGNAL(clicked()), ui->pushButtonCheckout, SLOT(pushed()));
    connect(ui->pushButtonCheckout, SIGNAL(iChanged(QObject*)), this, SLOT(changeAction(QObject*)));
}




void ObserverDialog::changeAction(QObject* obj){

    if(obj == ui->tableWidget){

        deleteQueue = ui->tableWidget->getNextItem();
        ui->pushButtonDelete->setEnabled(true);
    }

    else if(obj == ui->pushButtonDelete){

        ui->tableWidget->removeRow(deleteQueue->row());
        ui->pushButtonDelete->setEnabled(false);
        deleteQueue = nullptr;
        ui->labelNum->setVisible(false);
        ui->labelText->setVisible(false);
    }

    else if(obj == ui->pushButtonCheckout){

        //init visitor
        NonStackBasedSumVisitor nsbsv;

        //loop through each item in the shopping cart
        for(int i = 0; i < ui->tableWidget->rowCount(); i++){

            //call visitor function for storing total
            ui->tableWidget->Accept(&nsbsv, i);
        }

        //display result
        stringstream ss;
        ss << fixed << setprecision(2) << nsbsv.getResult();

        ui->labelText->setText("TOTAL: ");
        ui->labelNum->setText("$" + QString::fromStdString(ss.str()));
        ui->labelText->setVisible(true);
        ui->labelNum->setVisible(true);
    }
}




ObserverDialog::~ObserverDialog()
{
    delete ui;
}
