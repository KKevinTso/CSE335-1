/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BigFactory.h
 * Author: D'errah
 *
 * Created on February 15, 2019, 6:50 PM
 */

#ifndef BIGFACTORY_H
#define BIGFACTORY_H

#include "CharacterFactory.h"
#include "BigChar.h"


class BigFactory : public CharacterFactory{
public:
    virtual Character* Create(string input) const;
};


#endif /* BIGFACTORY_H */

