/*
 * testWeapon.h
 *
 *  Created on: Sep 22, 2015
 *      Author: eldante
 */


/**
 * 3/7/16
 * Depreciated.
 */


#ifndef TESTWEAPON_H_
#define TESTWEAPON_H_

//#include "weaponAbstract.h"
#include <cstring>
#include <string>
#include <stdio.h>
#include <iostream>
#include "declarations.h"

class TestWeapon: public Abstract_Weapon
  {
  public:
    TestWeapon() :
        Abstract_Weapon()
      {
        /*
        this->type1 = PISTOL;
        this->type2 = BALLISTIC;
        */
      }

    void rewardExp()
      {
        /*
        weilder->gainExp_pistols(expEarned);
        weilder->gainExp_ballistics(expEarned);
        expEarned = 0;
        */
      }

    void attack(Character* target)
      {
        /*
        target->damage_hp(10);
        std::cout << weilder->getName() << " attacks " << target->getName()
            << " for 10 damage." << std::endl;
        */
      }

    std::string getCharName()
      {
        //return weilder->getName();
        return "dummy";
      }

  };

void Character::damage_hp(int damHP)
  {
    //this->hp -= damHP;
  }

Character::Character()
  {
    this->name = "testCharacter";
    this->charRace.racename = HUMAN;
    this->hp = 0;
    this->max_hp = 0;
    this->stam = 0;
    this->max_stam = 0;
    this->spirit = 0;
    this->max_spirit = 0;
    this->sequence = 0;

    this->weapon = NULL;

    //std::cout << "Constructing Character, default" << endl;
  }

Character::Character(std::string charName, int orderIndex)
  {
    this->name = charName;
    this->sequence = orderIndex;

    this->hp = 20;
    this->max_hp = 20;
    this->stam = 0;
    this->max_stam = 0;
    this->spirit = 0;
    this->max_spirit = 0;

    //std::cout << "Constructing Character, 2 parameters" << endl;

    this->weapon = NULL;
  }

int Character::getSequence()
  {
    return this->sequence;

    //std::cout << "calling getSequence()" << endl;
  }

#endif /* TESTWEAPON_H_ */
