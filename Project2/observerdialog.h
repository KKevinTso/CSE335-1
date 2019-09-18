#ifndef OBSERVERDIALOG_H
#define OBSERVERDIALOG_H

#include <QDialog>
#include <QTableWidget>


namespace Ui {
class ObserverDialog;
}

class ObserverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ObserverDialog(QWidget *parent = nullptr);

    ~ObserverDialog();

    Ui::ObserverDialog* getUi()const {return ui;}

private slots:
    void changeAction(QObject*);

private:
    Ui::ObserverDialog *ui;

    //next item up for deletion
    QTableWidgetItem* deleteQueue;
};

#endif // OBSERVERDIALOG_H
