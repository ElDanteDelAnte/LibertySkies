/*
 * weaponAbstract.h
 *
 *  Created on: Sep 21, 2015
 *      Author: eldante
 */
/*
Versions:
  9/21/15:
  Weapons can have up to three types, third type being TWOHANDED
*/
#ifndef WEAPONABSTRACT_H_
#define WEAPONABSTRACT_H_

#include "character.h"

typedef enum
  {
    NOTYPE, UNARMED, PISTOL, RIFLE, BALLISTIC, PLASMA, BLADE, BLUNT, TWOHANDED
  } WeaponType;

class Abstract_Weapon
  {
  protected:
    int expEarned;
    Character* weilder;
    WeaponType type1;
    WeaponType type2;
    WeaponType type3;

  public:
    Abstract_Weapon()
      {
        expEarned = 0;
        weilder = NULL;
        type1 = NOTYPE;
        type2 = NOTYPE;
        type3 = NOTYPE;
      }

    virtual ~Abstract_Weapon();

    void becomeEquipped(Character* weild) {this->weilder = weild;}

    virtual void attack(Character* target) = 0;

    virtual void rewardExp() = 0;


  };





#endif /* WEAPONABSTRACT_H_ */
