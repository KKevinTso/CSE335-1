#ifndef VISITOR_H
#define VISITOR_H

class QTableWidget;

class Visitor
{
public:
    //add total price of shopping cart
    virtual void visitQTableWidget(QTableWidget*, int) = 0;
};

#endif // VISITOR_H
