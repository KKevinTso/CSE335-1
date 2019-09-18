#include "dtablewidget.h"

#include <QTableWidget>

void DTableWidget::itemClicked(QTableWidgetItem* qtwi){

    nextItem = qtwi;
    emit iChanged(this);
}
