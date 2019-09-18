#include "SmallChar.h"

void SmallChar::print() const{
        Character::print();
        cout << boolalpha << " \tisEquipped:" << _gun << endl; 
    }

