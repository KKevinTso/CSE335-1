/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: D'errah
 *
 * Created on February 15, 2019, 1:56 PM
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

#include "Character.h"
#include "CharacterFactory.h"
#include "SmallFactory.h"
#include "MediumFactory.h"
#include "BigFactory.h"

using namespace std;


class Game{
private:
    string _fileName;
    
public:
    Game(string s){_fileName = s;}
  
    vector<Character*> createSisters();
    void getCharacters();
    void getCharactersByRace();
    void getCharactersBySpeed();
    void getCharactersByHair();
};

#endif /* GAME_H */

