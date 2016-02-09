/*
 Versions:
 (pre 9/21/15 undocumented)

 9/21/15
 adds class Abstract_Weapon

 2/8/16
 makes declarations.h the nucleus of all declarations
 now #includes the mutually-inclusive class headers
 class headers no longer have individual security definers
 IMPORTANT: Only include these headers via declarations.h, never directly
 */

#ifndef DECLARATIONS_H
#define DECLARATIONS_H

class Character;
class Abstract_Weapon;
class Point;

/* DO NOT #include THESE FILES DIRECTLY ANYWHERE ELSE */
/* ONLY USE #include declarations.h */
#include "point.h"
#include "character.h"
#include "weaponAbstract.h"

#endif
