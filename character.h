#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "declarations.h"

class Abstract_Weapon;

/**
 * Base of any creature in the game.
 */
/*
 Versions:

 3/7/15:
 First designed

 Early stats.

 6/30/15:
 Race is a struct.
 Skill XP is seprate from level.
 Skills and XP in their own structs.
 Early definition of Race.
 gain/get funcs are as templates.

 7/23/15:
 Sequence is an int, used to determine order in battle
 Get() function for sequence.

 9/21/15
 Add weapon member

 11/16/15
 Implement hp and getHP() members.
 */

/* Skills */
typedef struct
  {
    int plasma;        //hp
    int ballistics;    //hp
    int blades;        //hp
    int blunts;        //hp, 420 blaze it
    int rifles;        //hp
    int pistols;       //hp
    int unarmed;       //hp

    int lightArmor;    //stam
    int heavyArmor;    //stam

    int stealth;       //stam
    int engineering;   //stam
    int speech;        //spirit
    int medicine;      //spirit
    int tech;          //spirit

    int athletics;     //stam
    int perception;    //stam

    int mining;        //stam

    int holy;          //spirit
    int dark;          //spirit
    int psi;           //spirit
  } skills;

/* Race */
typedef struct
  {
    /*Resistances*/
    double res_plasma;
    double res_pierce;
    double res_slash;
    double res_blunt;
    double res_fire;   //brainstorm
    double res_shock;  //brainstorm
    double res_acid;   //brainstorm
    double res_cold;   //brainstorm
    double res_holy;
    double res_dark;
    double res_psi;

    /*EXP Rate Bonuses*/
    double expRate_plasma;
    double expRate_ballistics;
    double expRate_blades;
    double expRate_blunts;
    double expRate_rifles;
    double expRate_pistols;
    double expRate_unarmed;

    double expRate_lightArmor;
    double expRate_heavyArmor;

    double expRate_stealth;
    double expRate_engineering;
    double expRate_speech;
    double expRate_medicine;
    double expRate_tech;

    double expRate_athletics;
    double expRate_perception;

    double expRate_mining;

    double expRate_holy;
    double expRate_dark;
    double expRate_psi;

    /*Racial Skill bonus levels*/
    skills racialSkillBonus;

    /*Racial Attribute modifiers*/
    raceName racename;

    double mod_hp;
    double mod_stam;
    double mod_spirit;

  } race;



class Character
  {
  private:
    /*Skills  [Do we measure in EXP?]

     [Answer: We have two separate variables
     for each skill. One for EXP and one for
     actual level. Level is updated each time
     XP is earned.]
     [Addendum: EXP is reset to 0 at each level.]

     Note: Racial bonus is added ONLY
     when calculating effects, NOT when
     calculating skill level.
     Additionally, Race can give an EXP
     gain multiplier.*/

    skills charSkills;
    skills charExp;

    //Base Attributes
    race charRace;

    std::string name;
    int hp;
    int max_hp;
    int stam;
    int max_stam;
    int spirit;
    int max_spirit;

    //inventory
    //equipped weapon
    Abstract_Weapon* weapon;
    //equipped armor
    //talisman/augment/accessory
    //any other items?

  public:
    /* Default constructor for testing purposes.
     * Defined in the associated test driver.*/
    Character();

    Character(std::string name, int orderIndex);            //for combat testing
//    Character(std::string name, int baseSequence, int maxStam);  //for combat testing

    /*gainExp() functions*/
    void gainExp_plasma(int exp);
    void gainExp_ballistics(int exp);
    void gainExp_blades(int exp);
    void gainExp_blunts(int exp);
    void gainExp_rifles(int exp);
    void gainExp_pistols(int exp);
    void gainExp_unarmed(int exp);

    void gainExp_lightArmor(int exp);
    void gainExp_heavyArmor(int exp);

    void gainExp_stealth(int exp);
    void gainExp_engineering(int exp);
    void gainExp_speech(int exp);
    void gainExp_medicine(int exp);
    void gainExp_tech(int exp);

    void gainExp_athletics(int exp);
    void gainExp_perception(int exp);

    void gainExp_mining(int exp);

    void gainExp_holy(int exp);
    void gainExp_dark(int exp);
    void gainExp_psi(int exp);

    /* getExp() Functions */
    int getExp_plasma();
    int getExp_ballistics();
    int getExp_blades();
    int getExp_blunts();
    int getExp_rifles();
    int getExp_pistols();
    int getExp_unarmed();

    int getExp_lightArmor();
    int getExp_heavyArmor();

    int getExp_stealth();
    int getExp_engineering();
    int getExp_speech();
    int getExp_medicine();
    int getExp_tech();

    int getExp_athletics();
    int getExp_perception();

    int getExp_mining();

    int getExp_holy();
    int getExp_dark();
    int getExp_psi();

    /* getLv() Functions */
    int getLv_plasma();
    int getLv_ballistics();
    int getLv_blades();
    int getLv_blunts();
    int getLv_rifles();
    int getLv_pistols();
    int getLv_unarmed();

    int getLv_lightArmor();
    int getLv_heavyArmor();

    int getLv_stealth();
    int getLv_engineering();
    int getLv_speech();
    int getLv_medicine();
    int getLv_tech();

    int getLv_athletics();
    int getLv_perception();

    int getLv_mining();

    int getLv_holy();
    int getLv_dark();
    int getLv_psi();

    /* setLv() and set Exp() functions will be done with the constructor implementation*/

    /* Used to "refresh" the character stats to what they should be based on skills */
    void calcBaseStats();

    /* COMBAT-RELATED FUNCTIONS */
    //turn order
    void calcInitiative();
    int sequence;  //to be put in a combat struct
    int getSequence();

    Abstract_Weapon* getWeapon();

    //take damage
    void damage_hp(int damHP);  //raw damage, no resistance flags
    //TODO: Make it possible to specify type of damage

    /* getAtributes() FUCNTIONS*/
    std::string getName();
    raceName getRaceName();
    int getHP();
    int getMaxHP();
    //int getStam();
    int getMaxStam();
    //int getSpirit();
    int getMaxSpirit();

    /* ITEM-RELATED FUNCTIONS */
    void equipWeapon(Abstract_Weapon* weapon);
    Abstract_Weapon* unequipWeapon();  //if encapsulates adding weapon to inventory, make return void
  };

#endif
