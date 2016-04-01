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

  2/8/16
  Fixes bug/irregularity with "multiple definition" of virtual destructor.

  3/29/16
  Removes pure virtual functions that were getting in the way of
  Character_Abstract's natural weapon. (This is in the hopes that a Character's
  race can be determined by enums. At least one function in Abstract_Weapon
  should be pure virtual, but hopefully we can add one later that won't cause
  problems.)
  Removes weaponType enum.
  Removes weaponType fields.
*/

//#ifndef WEAPONABSTRACT_H_
//#define WEAPONABSTRACT_H_

//#include "character.h"
//#include <string>



class Abstract_Weapon
  {
  protected:
    int expEarned;
    Abstract_Character* weilder;



  public:
    Abstract_Weapon()
      {
        expEarned = 0;
        weilder = 0;     //null

      }

    virtual ~Abstract_Weapon() { };

    void becomeEquipped(Character* weild) {this->weilder = weild;}

    virtual void attack(Character* target);

    virtual void rewardExp();

    //virtual void action() = 0;


  };

/*
Abstract_Weapon::~Abstract_Weapon()
  {
  }
*/

//#endif /* WEAPONABSTRACT_H_ */
