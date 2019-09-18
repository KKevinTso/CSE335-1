#include <vector>
#include "BigFactory.h"

//Creates a Big Character and returns a pointer to it
Character* BigFactory::Create(string input) const{
    //Create the Big Character
    BigChar* cp = new BigChar();
    
    //store attributes of Character in a vector to be accessed later
    vector<string> cValues;
    istringstream iss(input);
    string value;
    
    while(iss >> value){
        cValues.push_back(value);
    }

    //convert attributes to proper types
    int speed = stoi(cValues[3]);
    double weight = stod(cValues[2]);
    double hairLength = stod(cValues[4]);

    //store within the Character
    cp->setName(cValues[0]);
    cp->setSize(cValues[1]);
    cp->setWeight(weight);
    cp->setSpeed(speed);
    cp->setHairLength(hairLength);
    cp->setRace(cValues[5]); 
    cp->setSpecialSkill(cValues[6]);

    return cp;
}