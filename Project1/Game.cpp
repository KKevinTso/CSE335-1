#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

#include "Game.h"
using namespace std;


//take a file of sisters and create a Character for each sister, put it in a
//vector, and return that vector of Characters
vector<Character*> Game::createSisters(){
    //take in the file of sisters
    ifstream infile(_fileName);     
    string line;
    vector<Character*> vc;

    //each line is a character, for each line create the appropriate Character
    //archetype; Big, Small, or Medium
    while(getline(infile, line)){
        if(line.find("small") != string::npos){ 
            SmallFactory sf;
            Character* cp = sf.Create(line);
            vc.push_back(cp);
        }
        
        
        else if (line.find("med") != string::npos){
            MediumFactory mf;
            Character* cp = mf.Create(line);
            vc.push_back(cp);
        }
        
        else if (line.find("big") != string::npos){ 
            BigFactory bf; 
            Character* cp = bf.Create(line);
            vc.push_back(cp);
        }
        
        else{
            cout << "there is no size specified" << endl;
        }       
    }

    return vc;
}

    

    
//Print Characters by name
void Game::getCharacters(){
    vector<Character*> vc = createSisters();

    //loop through vector
    for (vector<Character*>::iterator it = vc.begin() + 1; it < vc.end(); it++){
        //create index
        int index = distance(vc.begin(), it);

        //value we are comparing
        Character* key = vc[index];

        //if value we are on is less than one behind it, swap them
        while(key->getName() < vc[index-1]->getName()){
            vc[index] = vc[index-1];
            vc[index-1] = key;

            //start from where swap happened and go again
            if ((index-2) >= 0){
                index -= 1;
            }
        }
    }

    cout << "********************Printing Sisters********************" << endl;
    for(Character* & i : vc){
        i->print();
    }
    cout << "*********************************************************" << endl;
    cout << endl;
}
    
    
    
    
//Print Characters by race
void Game::getCharactersByRace(){
    vector<Character*> vc = createSisters();

    for (vector<Character*>::iterator it = vc.begin() + 1; it < vc.end(); it++){
        int index = distance(vc.begin(), it);

        Character* key = vc[index];

        while(key->getRace() < vc[index-1]->getRace()){
            vc[index] = vc[index-1];
            vc[index-1] = key;

            if ((index-2) >= 0){
                index -= 1;
            }
        }
    }

    cout << "****************Printing Sisters by Race****************" << endl;
    for(Character* & i : vc){
        i->print();
    }
    cout << "*********************************************************" << endl;
    cout << endl;
}

    
    
    
//Print Characters by by speed
void Game::getCharactersBySpeed(){
    vector<Character*> vc = createSisters();

    for (vector<Character*>::iterator it = vc.begin() + 1; it < vc.end(); it++){
        int index = distance(vc.begin(), it);

        Character* key = vc[index];

        while(key->getSpeed() < vc[index-1]->getSpeed()){
            vc[index] = vc[index-1];
            vc[index-1] = key;

            if ((index-2) >= 0){
                index -= 1;
            }
        }
    }

    cout << "****************Printing Sisters by Speed****************" << endl;
    for(Character* & i : vc){
        i->print();
    }
    cout << "*********************************************************" << endl;
    cout << endl;
}
    
    
    
    
//Print Characters by Hair Length
void Game::getCharactersByHair(){
    vector<Character*> vc = createSisters();

    for (vector<Character*>::iterator it = vc.begin() + 1; it < vc.end(); it++){
        int index = distance(vc.begin(), it);

        Character* key = vc[index];

        while(key->getHairLength() < vc[index-1]->getHairLength()){
            vc[index] = vc[index-1];
            vc[index-1] = key;

            if ((index-2) >= 0){
                index -= 1;
            }
        }
    }

    cout << "*************Printing Sisters by Hair Length*************" << endl;
    for(Character* & i : vc){
        i->print();
    }
    cout << "*********************************************************" << endl;
    cout << endl;
}