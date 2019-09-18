#include "productbuilder.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <sstream>
#include <iostream>


using namespace std;

void ProductBuilder::addItem(string line, MainWindow* parent){

    string value;

    vector<QString> values;
    istringstream iss(line);

    //loop through each item on the line
    while(getline(iss, value, ',')){

        QString valueQ = QString::fromStdString(value);
        values.push_back(valueQ);
    }

    //make the row and insert items where assigned
    parent->getUi()->tableWidgetTop->insertRow(parent->getUi()->tableWidgetTop->rowCount());

    QTableWidgetItem *productNameQ = new QTableWidgetItem;
    QTableWidgetItem *typeQ = new QTableWidgetItem;
    QTableWidgetItem *priceQ = new QTableWidgetItem;
    QTableWidgetItem *specialAttributeQ = new QTableWidgetItem;

    parent->getUi()->tableWidgetTop->setItem(parent->getUi()->tableWidgetTop->rowCount()-1, 0, productNameQ);
    productNameQ->setText(values[1]);

    parent->getUi()->tableWidgetTop->setItem(parent->getUi()->tableWidgetTop->rowCount()-1, 1, typeQ);
    typeQ->setText(values[0]);

    parent->getUi()->tableWidgetTop->setItem(parent->getUi()->tableWidgetTop->rowCount()-1, 2, priceQ);
    priceQ->setText(values[4]);

    parent->getUi()->tableWidgetTop->setItem(parent->getUi()->tableWidgetTop->rowCount()-1, 3, specialAttributeQ);
    specialAttributeQ->setText(values[5]);
}
