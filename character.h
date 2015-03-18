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
*/
class Character
  {
    private:
      //Skills  [Do we measure in XP?]
      int plasma;
      int ballistics;
      int blade;
      int blunts;     //420 blaze it
      int rifle;
      int pistol;
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
      
      Race race;
      
      char* name;
      int hp;
      int max_hp;
      int stam;
      int max_stam;
      int sprit;
      int maxs_spirt;
      
      //inventory
      //equiped weapon
      //equiped armor
      //talisman/augment/accessory
      //any other items?
  };

#endif
