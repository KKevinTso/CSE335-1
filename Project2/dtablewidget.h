#ifndef DTABLEWIDGET_H
#define DTABLEWIDGET_H

#include "visitor.h"

#include <QTableWidget>


class DTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    DTableWidget(QWidget* qw):QTableWidget(qw){}

    QTableWidgetItem* getNextItem(){return nextItem;}

    //visitor for adding up prices in a QTableWidget
    void Accept(Visitor* v, int n){v->visitQTableWidget(this, n);}

signals:
    void iChanged(QObject*)const;

public slots:
    void itemClicked(QTableWidgetItem*);

private:
    QTableWidgetItem* nextItem;
};


#endif // DTABLEWIDGET_H
