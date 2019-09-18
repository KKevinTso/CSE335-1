#ifndef NONSTACKBASEDSUMVISITOR_H
#define NONSTACKBASEDSUMVISITOR_H

#include "visitor.h"

#include <QTableWidget>


class NonStackBasedSumVisitor : public Visitor
{
public:
    virtual void visitQTableWidget(QTableWidget*, int);

    float getResult();

private:
    float sum;
};

#endif // NONSTACKBASEDSUMVISITOR_H
