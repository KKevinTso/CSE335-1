/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.h
 * Author: D'errah
 *
 * Created on February 15, 2019, 2:23 PM
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;


class Character{
private:
    string _name;
    string _size;
    double _weight;
    int _speed;
    double _hairLength;
    string _race;
    
public:  
    void setName(string s){_name = s;}
    string getName(){return _name;}
    void setSize(string s){_size = s;}
    void setWeight(double d){_weight = d;}
    void setSpeed(int n){_speed = n;}
    int getSpeed(){return _speed;}
    void setHairLength(double d){_hairLength = d;}
    double getHairLength(){return _hairLength;}
    void setRace(string s){_race = s;}
    string getRace(){return _race;}
    
    virtual void print()const;
};


#endif /* CHARACTER_H */

