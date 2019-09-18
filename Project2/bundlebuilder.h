#ifndef BUNDLEBUILDER_H
#define BUNDLEBUILDER_H

#include "builder.h"

#include <string>


using namespace std;

class BundleBuilder : public Builder
{
public:
    virtual void addItem(string, MainWindow*);
};

#endif // BUNDLEBUILDER_H
