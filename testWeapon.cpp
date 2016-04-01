/*
 * testWeapon.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: eldante
 */

/**
 * 3/7/16
 * Depreciated.
 */

#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include "declarations.h"
#include "testWeapon.h"
#include "checkit.h"

using namespace std;



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

void testWeaponReEequip()
  {
    Character testCharacter1 = Character("Sally", 6);
    Character testCharacter3 = Character("Snake", 4);

    string testName1 = "Sally";
    string testName3 = "Snake";

    TestWeapon weap1 = TestWeapon();
    TestWeapon weap3 = TestWeapon();

    testCharacter1.equipWeapon(&weap1);
    testCharacter3.equipWeapon(&weap3);

    testCharacter1.equipWeapon(&weap3);
    testCharacter3.equipWeapon(&weap1);

    checkit_int(strcmp(weap1.getCharName().c_str(), testName3.c_str()), 0);
    checkit_int(strcmp(weap3.getCharName().c_str(), testName1.c_str()), 0);
  }

int main()
  {
    //testWeaponDamage();

    testWeaponReEequip();

    return 0;
  }

