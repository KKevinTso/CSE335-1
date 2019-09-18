/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MediumFactory.h
 * Author: D'errah
 *
 * Created on February 15, 2019, 6:40 PM
 */

#ifndef MEDIUMFACTORY_H
#define MEDIUMFACTORY_H

#include "CharacterFactory.h"
#include "MediumChar.h"


class MediumFactory : public CharacterFactory{
public:
    virtual Character* Create(string input) const;
};

#endif /* MEDIUMFACTORY_H */

