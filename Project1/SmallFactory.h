/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SmallFactory.h
 * Author: D'errah
 *
 * Created on February 15, 2019, 6:40 PM
 */

#ifndef SMALLFACTORY_H
#define SMALLFACTORY_H

#include "CharacterFactory.h"
#include "SmallChar.h"


class SmallFactory : public CharacterFactory{
public:
    virtual Character* Create(string input) const;
};

#endif /* SMALLFACTORY_H */

