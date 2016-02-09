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

  1/15/16:
  TWOHANDED shal be implemented differently
  All weapons will have an "action" that they can use in addition to attacking
  such as cast a spell or block with a shield.
*/
//#ifndef WEAPONABSTRACT_H_
//#define WEAPONABSTRACT_H_

//#include "character.h"
//#include <string>

typedef enum
  {
    NOTYPE, UNARMED, PISTOL, RIFLE, BALLISTIC, PLASMA, BLADE, BLUNT, //TWOHANDED
  } WeaponType;

class Abstract_Weapon
  {
  protected:
    int expEarned;
    Character* weilder;
    WeaponType type1;
    WeaponType type2;
  //WeaponType type3;

  public:
    Abstract_Weapon()
      {
        expEarned = 0;
        weilder = 0;     //null
        type1 = NOTYPE;
        type2 = NOTYPE;
      //type3 = NOTYPE;
      }

    virtual ~Abstract_Weapon();

    void becomeEquipped(Character* weild) {this->weilder = weild;}

    virtual void attack(Character* target) = 0;

    virtual void rewardExp() = 0;

    //virtual void action() = 0;


  };





//#endif /* WEAPONABSTRACT_H_ */
