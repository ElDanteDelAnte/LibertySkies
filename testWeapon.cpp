/*
 * testWeapon.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: eldante
 */

#include "testWeapon.h"
#include "checkit.h"
#include <stdio.h>

using namespace std;

Abstract_Weapon::~Abstract_Weapon() {}

void testWeaponDamage()
  {
    Character testCharacter1 = Character("Sally", 6);
    Character testCharacter3 = Character("Snake", 4);

    checkit_int(testCharacter1.getHP(), 20);
    checkit_int(testCharacter3.getHP(), 20);

    TestWeapon weap1 = TestWeapon();
    TestWeapon weap3 = TestWeapon();

    testCharacter1.equipWeapon(&weap1);
    testCharacter3.equipWeapon(&weap3);

    testCharacter1.getWeapon()->attack(&testCharacter3);
    checkit_int(testCharacter3.getHP(), 10);
    checkit_int(testCharacter3.getMaxHP(), 20);
    checkit_int(testCharacter1.getHP(), 20);
    checkit_int(testCharacter1.getMaxHP(), 20);

    testCharacter3.getWeapon()->attack(&testCharacter1);
    checkit_int(testCharacter1.getHP(), 10);
    checkit_int(testCharacter1.getMaxHP(), 20);
    checkit_int(testCharacter3.getHP(), 10);
    checkit_int(testCharacter3.getMaxHP(), 20);
  }

int main()
  {
    testWeaponDamage();

    return 0;
  }


