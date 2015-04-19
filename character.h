#ifndef CHARACTER_H
#define CHARACTER_H

#include "declarations.h"

/**
 * Base of any creature in the game.
 */
/*
 Versions:

 3/7/15:
 First designed

 Early stats.

 4/?/15
 Race is a struct.
 Skill XP is seprate from level.
 Skills and XP in their own structs.
 */

typedef struct
  {
    int plasma;
    int ballistics;
    int blades;
    int blunts;     //420 blaze it
    int rifles;
    int pistols;
    int unarmed;

    int lightArmor;
    int heavyArmor;

    int stealth;
    int engineering;
    int speech;
    int medicine;
    int tech;

    int holy;
    int dark;
    int psi;
  } skills;

class Character
  {
  private:
    //Skills  [Do we measure in XP?]

    //[Answer: We have two separate variables
    //for each skill. One for XP and one for
    //actual level. Level is updated each time
    //XP is earned.]

    //Note: Racial bonus is added ONLY
    //when calculating effects, NOT when
    //calculating skill level.

    skills charSkills;
    skills charXp;

    //Base Atrributes
    Race race;

    char* name;
    int hp;
    int max_hp;
    int stam;
    int max_stam;
    int sprit;
    int maxs_spirt;

    //inventory
    //equipped weapon
    //equipped armor
    //talisman/augment/accessory
    //any other items?

  public:
  };

#endif
