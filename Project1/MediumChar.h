/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MediumChar.h
 * Author: D'errah
 *
 * Created on February 22, 2019, 3:18 PM
 */

#ifndef MEDIUMCHAR_H
#define MEDIUMCHAR_H

#include "Character.h"


class MediumChar: public Character{   
private:
    string _meleeWeapon;
    
public:
    void setMeleeWeapon(string s){_meleeWeapon = s;}
    virtual void print() const;
};

#endif /* MEDIUMCHAR_H */

