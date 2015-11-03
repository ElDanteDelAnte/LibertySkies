/*
 * testWeapon.h
 *
 *  Created on: Sep 22, 2015
 *      Author: eldante
 */

#ifndef TESTWEAPON_H_
#define TESTWEAPON_H_

#include "weaponAbstract.h"
#include <cstring>
#include <string>
#include <stdio.h>

class TestWeapon: public Abstract_Weapon
  {
  public:
    TestWeapon() : Abstract_Weapon()
      {
        this->type1 = PISTOL;
        this->type2 = BALLISTIC;
      }

    void rewardExp()
      {
        weilder->gainExp_pistols(expEarned);
        weilder->gainExp_ballistics(expEarned);
        expEarned = 0;
      }

    void attack(Character* target)
      {
        target->damage_hp(10);
        std::cout << weilder->getName() << " attacks " << target->getName() << " for 10 damage.";
      }
  };

void Character::damage_hp(int damHP)
  {
    this->hp -= damHP;
  }

#endif /* TESTWEAPON_H_ */
