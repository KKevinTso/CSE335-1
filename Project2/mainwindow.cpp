#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "observerdialog.h"
#include "ui_observerdialog.h"
#include "dpushbutton.h"
#include "productbuilder.h"
#include "bundlebuilder.h"

#include <string>
#include <QDebug>
#include <fstream>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //init shopping cart
    cart = new ObserverDialog;

    //disable buttons until they proper conditions are met
    ui->pushButtonShowCart->setEnabled(false);
    ui->pushButtonAddToCart->setEnabled(false);

    //loads the data from csv files
    connect(ui->pushButtonLoadDatabase, SIGNAL(clicked()),ui->pushButtonLoadDatabase, SLOT(pushed()));
    connect(ui->pushButtonLoadDatabase, SIGNAL(iChanged(QObject*)), this, SLOT(changeAction(QObject*)));

    //takes the shopping list and adds all items to the shopping cart QTable
    connect(ui->pushButtonAddToCart, SIGNAL(clicked()), ui->pushButtonAddToCart, SLOT(pushed()));
    connect(ui->pushButtonAddToCart, SIGNAL(iChanged(QObject*)), this, SLOT(changeAction(QObject*)));

    //shows the shopping cart
    connect(ui->pushButtonShowCart, SIGNAL(clicked()), ui->pushButtonShowCart, SLOT(pushed()));
    connect(ui->pushButtonShowCart, SIGNAL(iChanged(QObject*)), this, SLOT(changeAction(QObject*)));

    //adds items clicked to the shopping list
    connect(ui->tableWidgetTop, SIGNAL(itemClicked(QTableWidgetItem*)), ui->tableWidgetTop, SLOT(itemClicked(QTableWidgetItem*)));
    connect(ui->tableWidgetTop, SIGNAL(iChanged(QObject*)), this, SLOT(changeAction(QObject*)));

    //adds items clicked from bottom table to shopping list
    connect(ui->tableWidgetBottom, SIGNAL(itemClicked(QTableWidgetItem*)), ui->tableWidgetBottom, SLOT(itemClicked(QTableWidgetItem*)));
    connect(ui->tableWidgetBottom, SIGNAL(iChanged(QObject*)), this, SLOT(changeAction(QObject*)));

}



//action changes depending on signal
void MainWindow::changeAction(QObject* obj){

    //if load data pressed
    if(obj == ui->pushButtonLoadDatabase){

        qDebug() << "File Read!";

        //read data
        ifstream infile("C:/Users/D'errah/Documents/QtProjects/335proj2/Technology.csv");
        string type, productName, companyName, weight, price, specialAttribute, line, value;

        while(getline(infile, line)){

            //build QWidgetItem
            ProductBuilder pb;
            pb.addItem(line, this);
        }

        //bundles now
        infile.close();
        infile.open("C:/Users/D'errah/Documents/QtProjects/335proj2/Bundles.csv");

        while(getline(infile, line)){

            BundleBuilder bb;
            bb.addItem(line, this);
        }

        ui->pushButtonLoadDatabase->setEnabled(false);
        ui->pushButtonShowCart->setEnabled(true);
    }

    else if(obj == ui->pushButtonAddToCart){

        //loop through shopping list and insert all QTableWidgetItems into shopping cart
        for(QTableWidgetItem* qtwi : shoppingList){

            cart->getUi()->tableWidget->insertRow(cart->getUi()->tableWidget->rowCount());

            QTableWidgetItem *name = new QTableWidgetItem;
            QTableWidgetItem *price = new QTableWidgetItem;

            //if its the top one vs bottom one there are specific indexes for items
            if(qtwi->tableWidget() == ui->tableWidgetTop){

                cart->getUi()->tableWidget->setItem(cart->getUi()->tableWidget->rowCount()-1, 0, name);
                name->setText(qtwi->tableWidget()->item(qtwi->row(),0)->text());

                cart->getUi()->tableWidget->setItem(cart->getUi()->tableWidget->rowCount()-1, 1, price);
                price->setText(qtwi->tableWidget()->item(qtwi->row(),2)->text());
            }

            else if (qtwi->tableWidget() == ui->tableWidgetBottom){

                cart->getUi()->tableWidget->setItem(cart->getUi()->tableWidget->rowCount()-1, 0, name);
                name->setText(qtwi->tableWidget()->item(qtwi->row(),0)->text());

                cart->getUi()->tableWidget->setItem(cart->getUi()->tableWidget->rowCount()-1, 1, price);
                price->setText(qtwi->tableWidget()->item(qtwi->row(),1)->text());
            }
        }

        //clear the shopping list for future use
        shoppingList.clear();

        ui->pushButtonAddToCart->setEnabled(false);
        cart->getUi()->labelNum->setVisible(false);
        cart->getUi()->labelText->setVisible(false);
    }

    else if(obj == ui->pushButtonShowCart){

        if(!display){

            cart->show();
            display = true;
            ui->pushButtonShowCart->setText("Hide Cart");
        }

        else{

            cart->hide();
            display = false;
            ui->pushButtonShowCart->setText("Show Cart");
            cart->getUi()->labelNum->setVisible(false);
            cart->getUi()->labelText->setVisible(false);
        }

    }

    else if(obj == ui->tableWidgetTop){

        //add the next item and let the user know
        shoppingList.push_back(ui->tableWidgetTop->getNextItem());
        std::cout<< "item queued " << std::endl;
        ui->pushButtonAddToCart->setEnabled(true);
    }

    else if(obj == ui->tableWidgetBottom){


        shoppingList.push_back(ui->tableWidgetBottom->getNextItem());
        std::cout<< "item queued " << std::endl;
        ui->pushButtonAddToCart->setEnabled(true);
    }

}




MainWindow::~MainWindow()
{
    delete ui;
}
