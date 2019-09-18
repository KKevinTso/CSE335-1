/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BigChar.h
 * Author: D'errah
 *
 * Created on February 22, 2019, 3:18 PM
 */

#ifndef BIGCHAR_H
#define BIGCHAR_H

#include "Character.h"


class BigChar: public Character{
private:
    string _specialSkill;
    
public:  
    void setSpecialSkill(string s){_specialSkill = s;} 
    virtual void print() const;
};

#endif /* BIGCHAR_H */

