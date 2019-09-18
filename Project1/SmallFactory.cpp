#include <vector>
#include "SmallFactory.h"


//Creates a Small Character and returns a pointer to it
Character* SmallFactory::Create(string input) const{
        //Create Small Character
        SmallChar* cp = new SmallChar();
        
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
        
        if(cValues[6] == "TRUE"){
            cp->setGun(true);
        }
        else if(cValues[6] == "FALSE"){
            cp->setGun(false); 
        }
        
        return cp;
    }

