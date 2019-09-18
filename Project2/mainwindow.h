#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "observerdialog.h"

#include <QMainWindow>
#include <QTableWidgetItem>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    Ui::MainWindow* getUi()const{return ui;}

    std::vector<QTableWidgetItem*> getShoppingList()const{return shoppingList;}

public slots:
    void changeAction(QObject*);

private:
    Ui::MainWindow *ui;

    //stores items queued for cart
    std::vector<QTableWidgetItem*> shoppingList;

    ObserverDialog* cart;

    bool display = false;
};

#endif // MAINWINDOW_H
