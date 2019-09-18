/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SmallChar.h
 * Author: D'errah
 *
 * Created on February 22, 2019, 3:18 PM
 */

#ifndef SMALLCHAR_H
#define SMALLCHAR_H

#include "Character.h"


class SmallChar: public Character{
private:
    bool _gun;
    
public:
    void setGun(bool b){_gun = b;}
    virtual void print() const;
};

#endif /* SMALLCHAR_H */

