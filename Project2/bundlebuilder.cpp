#include "bundlebuilder.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QTableWidget>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>


void BundleBuilder::addItem(string line, MainWindow* parent){

    string value;

    vector<QString> values;
    istringstream iss(line);

    float price = 0;

    //loop through each item on the line
    while(getline(iss, value, ',')){

        QString valueQ = QString::fromStdString(value);
        values.push_back(valueQ);
    }

    //make the row and insert items where assigned
    parent->getUi()->tableWidgetBottom->insertRow(parent->getUi()->tableWidgetBottom->rowCount());

    QTableWidgetItem *productNameQ = new QTableWidgetItem;
    QTableWidgetItem *savingsQ = new QTableWidgetItem;
    QTableWidgetItem *priceQ = new QTableWidgetItem;

    parent->getUi()->tableWidgetBottom->setItem(parent->getUi()->tableWidgetBottom->rowCount()-1, 0, productNameQ);
    productNameQ->setText(values[0]);

    parent->getUi()->tableWidgetBottom->setItem(parent->getUi()->tableWidgetBottom->rowCount()-1, 1, priceQ);
    priceQ->setText(values[1]);

    //find items in bundle individual prices using the product QTable
    for(int i = 2; i < values.size(); i++){
        for(int j = 0; j < parent->getUi()->tableWidgetTop->rowCount(); j++){
            if(parent->getUi()->tableWidgetTop->item(j, 0)->text() == values[i]){
                price += parent->getUi()->tableWidgetTop->item(j, 2)->text().toFloat();
                break;
            }
        }
    }

    //calculate the percent saved by the bundle and put it in proper column
    float difference = price - parent->getUi()->tableWidgetBottom->item(parent->getUi()->tableWidgetBottom->rowCount()-1, 1)->text().toFloat();
    float percent = (difference/price)*100;

    stringstream ss;
    ss << fixed << setprecision(0) << percent;

    parent->getUi()->tableWidgetBottom->setItem(parent->getUi()->tableWidgetBottom->rowCount()-1, 2, savingsQ);
    savingsQ->setText(QString::fromStdString(ss.str()) + "%");

}
