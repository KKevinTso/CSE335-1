/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CharacterFactory.h
 * Author: D'errah
 *
 * Created on February 15, 2019, 6:46 PM
 */

#ifndef CHARACTERFACTORY_H
#define CHARACTERFACTORY_H

#include "Character.h"


class CharacterFactory {
public:
    virtual Character* Create(string input)const = 0;
};

#endif /* CHARACTERFACTORY_H */

