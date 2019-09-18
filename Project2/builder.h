#ifndef BUILDER_H
#define BUILDER_H

#include "mainwindow.h"
#include <string>


using namespace std;

class Builder
{
public:
    //adds item to a QTable
    virtual void addItem(string, MainWindow*) = 0;
};

#endif // BUILDER_H
