#ifndef PRODUCTBUILDER_H
#define PRODUCTBUILDER_H

#include "builder.h"
#include "mainwindow.h"

#include <string>

class ProductBuilder : public Builder
{
public:
    virtual void addItem(string, MainWindow*);
};

#endif // PRODUCTBUILDER_H
