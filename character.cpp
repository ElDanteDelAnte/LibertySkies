#include "weaponAbstract.h"
#include "character.h"
#include <cstring>
#include <string>

#define DERIVEDSTATFACTOR 5

/**
 Versions:

 6/30/15

 Add gain_EXP() functions with level-up for each skill.
 Add get() functions for EXP and Lv for each skill.
 Add get() functions for the max_[base stats].
 Add function to calculate max_[base stats].

 Still to do: Constructor function, get() functions for current hp, stam, spirit

 Skills added:

 plasma      (hp)
 ballistics  (hp)
 blades      (hp)
 blunts      (hp)
 rifles      (hp)
 pistols     (hp)
 unarmed     (hp)

 lightArmor  (stam)
 heavyArmor  (stam)

 stealth     (stam)
 engineering (stam)
 speech      (spirit)
 medicine    (spirit)
 tech        (spirit)

 athletics   (stam)
 perception  (spirit)

 mining      (stam)

 holy        (spirit)
 dark        (spirit)
 psi         (spirit)

 9/21/15
 Add equip_weapon function

 11/16/15
 Add getHP function.
 */

void Character::gainExp_plasma(int exp)
  {
    this->charExp.plasma += exp * this->charRace.expRate_plasma;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.plasma + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.plasma >= toNextLevel)
          {
            this->charExp.plasma -= toNextLevel;
            this->charSkills.plasma++;
          }
      }
    while (this->charExp.plasma >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_ballistics(int exp)
  {
    this->charExp.ballistics += exp * this->charRace.expRate_ballistics;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.ballistics + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.ballistics >= toNextLevel)
          {
            this->charExp.ballistics -= toNextLevel;
            this->charSkills.ballistics++;
          }
      }
    while (this->charExp.ballistics >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_blades(int exp)
  {
    this->charExp.blades += exp * this->charRace.expRate_blades;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.blades + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.blades >= toNextLevel)
          {
            this->charExp.blades -= toNextLevel;
            this->charSkills.blades++;
          }
      }
    while (this->charExp.blades >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_blunts(int exp)
  {
    this->charExp.blunts += exp * this->charRace.expRate_blunts;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.blunts + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.blunts >= toNextLevel)
          {
            this->charExp.ballistics -= toNextLevel;
            this->charSkills.blunts++;
          }
      }
    while (this->charExp.blunts >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_rifles(int exp)
  {
    this->charExp.rifles += exp * this->charRace.expRate_rifles;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.rifles + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.rifles >= toNextLevel)
          {
            this->charExp.rifles -= toNextLevel;
            this->charSkills.rifles++;
          }
      }
    while (this->charExp.rifles >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_pistols(int exp)
  {
    this->charExp.pistols += exp * this->charRace.expRate_pistols;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.pistols + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.pistols >= toNextLevel)
          {
            this->charExp.pistols -= toNextLevel;
            this->charSkills.pistols++;
          }
      }
    while (this->charExp.pistols >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_unarmed(int exp)
  {
    this->charExp.unarmed += exp * this->charRace.expRate_unarmed;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.unarmed + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.unarmed >= toNextLevel)
          {
            this->charExp.unarmed -= toNextLevel;
            this->charSkills.unarmed++;
          }
      }
    while (this->charExp.unarmed >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_lightArmor(int exp)
  {
    this->charExp.lightArmor += exp * this->charRace.expRate_lightArmor;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.lightArmor + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.lightArmor >= toNextLevel)
          {
            this->charExp.lightArmor -= toNextLevel;
            this->charSkills.lightArmor++;
          }
      }
    while (this->charExp.lightArmor >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_heavyArmor(int exp)
  {
    this->charExp.heavyArmor += exp * this->charRace.expRate_heavyArmor;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.heavyArmor + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.heavyArmor >= toNextLevel)
          {
            this->charExp.heavyArmor -= toNextLevel;
            this->charSkills.heavyArmor++;
          }
      }
    while (this->charExp.heavyArmor >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_stealth(int exp)
  {
    this->charExp.stealth += exp * this->charRace.expRate_stealth;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.stealth + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.stealth >= toNextLevel)
          {
            this->charExp.stealth -= toNextLevel;
            this->charSkills.stealth++;
          }
      }
    while (this->charExp.stealth >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_engineering(int exp)
  {
    this->charExp.engineering += exp * this->charRace.expRate_engineering;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.engineering + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.engineering >= toNextLevel)
          {
            this->charExp.engineering -= toNextLevel;
            this->charSkills.engineering++;
          }
      }
    while (this->charExp.engineering >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_speech(int exp)
  {
    this->charExp.speech += exp * this->charRace.expRate_speech;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.speech + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.speech >= toNextLevel)
          {
            this->charExp.speech -= toNextLevel;
            this->charSkills.speech++;
          }
      }
    while (this->charExp.speech >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_medicine(int exp)
  {
    this->charExp.medicine += exp * this->charRace.expRate_medicine;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.medicine + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.medicine >= toNextLevel)
          {
            this->charExp.medicine -= toNextLevel;
            this->charSkills.medicine++;
          }
      }
    while (this->charExp.medicine >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_tech(int exp)
  {
    this->charExp.tech += exp * this->charRace.expRate_tech;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.tech + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.tech >= toNextLevel)
          {
            this->charExp.tech -= toNextLevel;
            this->charSkills.tech++;
          }
      }
    while (this->charExp.tech >= toNextLevel);

    this->calcBaseStats();

  }

/* Battle Stats */

void Character::gainExp_athletics(int exp)
  {
    this->charExp.athletics += exp * this->charRace.expRate_athletics;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.athletics + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.athletics >= toNextLevel)
          {
            this->charExp.athletics -= toNextLevel;
            this->charSkills.athletics++;
          }
      }
    while (this->charExp.athletics >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_perception(int exp)
  {
    this->charExp.perception += exp * this->charRace.expRate_perception;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.perception + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.perception >= toNextLevel)
          {
            this->charExp.perception -= toNextLevel;
            this->charSkills.perception++;
          }
      }
    while (this->charExp.perception >= toNextLevel);

    this->calcBaseStats();

  }

/* Other Stats */

void Character::gainExp_mining(int exp)
  {
    this->charExp.mining += exp * this->charRace.expRate_mining;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.mining + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.mining >= toNextLevel)
          {
            this->charExp.mining -= toNextLevel;
            this->charSkills.mining++;
          }
      }
    while (this->charExp.mining >= toNextLevel);

    this->calcBaseStats();

  }

/* Magic stats */

void Character::gainExp_holy(int exp)
  {
    this->charExp.holy += exp * this->charRace.expRate_holy;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.holy + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.holy >= toNextLevel)
          {
            this->charExp.holy -= toNextLevel;
            this->charSkills.holy++;
          }
      }
    while (this->charExp.holy >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_dark(int exp)
  {
    this->charExp.dark += exp * this->charRace.expRate_dark;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.dark + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.dark >= toNextLevel)
          {
            this->charExp.dark -= toNextLevel;
            this->charSkills.dark++;
          }
      }
    while (this->charExp.plasma >= toNextLevel);

    this->calcBaseStats();

  }

void Character::gainExp_psi(int exp)
  {
    this->charExp.psi += exp * this->charRace.expRate_psi;
    int toNextLevel;

    /* Level up multiple times, if enough EXP */
    do
      {
        int nextLevel = this->charSkills.psi + 1;
        toNextLevel = nextLevel * (nextLevel + 1) * (nextLevel + 2);

        /* Check if enough to level up */
        if (this->charExp.psi >= toNextLevel)
          {
            this->charExp.psi -= toNextLevel;
            this->charSkills.psi++;
          }
      }
    while (this->charExp.psi >= toNextLevel);

    this->calcBaseStats();

  }

/* getExp() Functions */
int Character::getExp_plasma()
  {
    return this->charExp.plasma;
  }

int Character::getExp_ballistics()
  {
    return this->charExp.ballistics;
  }

int Character::getExp_blades()
  {
    return this->charExp.blades;
  }

int Character::getExp_blunts()
  {
    return this->charExp.blunts;
  }

int Character::getExp_rifles()
  {
    return this->charExp.rifles;
  }

int Character::getExp_pistols()
  {
    return this->charExp.pistols;
  }

int Character::getExp_unarmed()
  {
    return this->charExp.unarmed;
  }

int Character::getExp_lightArmor()
  {
    return this->charExp.lightArmor;
  }

int Character::getExp_heavyArmor()
  {
    return this->charExp.heavyArmor;
  }

int Character::getExp_stealth()
  {
    return this->charExp.stealth;
  }

int Character::getExp_engineering()
  {
    return this->charExp.engineering;
  }

int Character::getExp_speech()
  {
    return this->charExp.speech;
  }

int Character::getExp_medicine()
  {
    return this->charExp.medicine;
  }

int Character::getExp_tech()
  {
    return this->charExp.tech;
  }

int Character::getExp_athletics()
  {
    return this->charExp.athletics;
  }

int Character::getExp_perception()
  {
    return this->charExp.perception;
  }

int Character::getExp_mining()
  {
    return this->charExp.mining;
  }

int Character::getExp_holy()
  {
    return this->charExp.holy;
  }

int Character::getExp_dark()
  {
    return this->charExp.dark;
  }

int Character::getExp_psi()
  {
    return this->charExp.psi;
  }

/* getLv() Functions */
int Character::getLv_plasma()
  {
    return this->charSkills.plasma;
  }

int Character::getLv_ballistics()
  {
    return this->charSkills.ballistics;
  }

int Character::getLv_blades()
  {
    return this->charSkills.blades;
  }

int Character::getLv_blunts()
  {
    return this->charSkills.blunts;
  }

int Character::getLv_rifles()
  {
    return this->charSkills.rifles;
  }

int Character::getLv_pistols()
  {
    return this->charSkills.pistols;
  }

int Character::getLv_unarmed()
  {
    return this->charSkills.unarmed;
  }

int Character::getLv_lightArmor()
  {
    return this->charSkills.lightArmor;
  }

int Character::getLv_heavyArmor()
  {
    return this->charSkills.heavyArmor;
  }

int Character::getLv_stealth()
  {
    return this->charSkills.stealth;
  }

int Character::getLv_engineering()
  {
    return this->charSkills.engineering;
  }

int Character::getLv_speech()
  {
    return this->charSkills.speech;
  }

int Character::getLv_medicine()
  {
    return this->charSkills.medicine;
  }

int Character::getLv_tech()
  {
    return this->charSkills.tech;
  }

int Character::getLv_athletics()
  {
    return this->charSkills.athletics;
  }

int Character::getLv_perception()
  {
    return this->charSkills.perception;
  }

int Character::getLv_mining()
  {
    return this->charSkills.mining;
  }

int Character::getLv_holy()
  {
    return this->charSkills.holy;
  }

int Character::getLv_dark()
  {
    return this->charSkills.dark;
  }

int Character::getLv_psi()
  {
    return this->charSkills.psi;
  }

/* Non-skill get() funcs */

void Character::calcBaseStats()
  {
    int hpTotal = 0;
    int stamTotal = 0;
    int spiritTotal = 0;

    //Sum up levels of each category of skill.

    hpTotal += this->charSkills.plasma;
    hpTotal += this->charSkills.ballistics;
    hpTotal += this->charSkills.blades;
    hpTotal += this->charSkills.blunts;
    hpTotal += this->charSkills.rifles;
    hpTotal += this->charSkills.pistols;
    hpTotal += this->charSkills.unarmed;

    stamTotal += this->charSkills.lightArmor;
    stamTotal += this->charSkills.heavyArmor;
    stamTotal += this->charSkills.athletics;
    stamTotal += this->charSkills.mining;
    stamTotal += this->charSkills.stealth;
    stamTotal += this->charSkills.engineering;

    spiritTotal += this->charSkills.perception;
    spiritTotal += this->charSkills.speech;
    spiritTotal += this->charSkills.medicine;
    spiritTotal += this->charSkills.tech;
    spiritTotal += this->charSkills.holy;
    spiritTotal += this->charSkills.dark;
    spiritTotal += this->charSkills.psi;

    //Set max of each stat to total * 5
    this->max_hp = hpTotal * DERIVEDSTATFACTOR;
    this->max_stam = stamTotal * DERIVEDSTATFACTOR;
    this->max_spirit = spiritTotal * DERIVEDSTATFACTOR;
  }

std::string Character::getName()
  {
    return this->name;
  }

raceName Character::getRaceName()
  {
    return this->charRace.racename;
  }

int Character::getHP()
  {
    return this->hp;
  }

int Character::getMaxHP()
  {
    return this->max_hp;
  }

//int Character::getStam()

int Character::getMaxStam()
  {
    return this->max_stam;
  }

//int Character::getSpirit()

int Character::getMaxSpirit()
  {
    return this->max_spirit;
  }

/* ITEM-RELATED FUNCTIONS */
void Character::equipWeapon(Abstract_Weapon* weap)
  {
    this->weapon = weap;
    weap->becomeEquipped(this);
  }

Abstract_Weapon* Character::getWeapon()
  {
    return this->weapon;
  }
/*
Abstract_Weapon* Character::unequipWeapon()
  {
    Abstract_Weapon& weap = this->weapon;
    this->weapon = TestWeapon(); //To be defined in the test driver, eventually to become "unarmed"
    return weap;
  }
  */

/* COMBAT-RELATED FUNCTIONS */

//TODO: get() functions for current hp, stam, and spirit
//TODO: Character constructor function (Will need to initialize skill lv.s to 1, EXP to 0)
