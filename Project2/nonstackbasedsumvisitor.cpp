#include "nonstackbasedsumvisitor.h"


//add the price of given QTableWidget item to the sum
void NonStackBasedSumVisitor::visitQTableWidget(QTableWidget* qtw, int n){
    sum += qtw->item(n, 1)->text().toFloat();
}




float NonStackBasedSumVisitor::getResult(){
    float result = sum;
    sum = 0;
    return result;
}
