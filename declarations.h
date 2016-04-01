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

 3/29/16
 replaces character.h with
 characterAbstract.h

 3/31/16
 "Character_Abstract" declaration corrected to "Abstract_Character"
 */

#ifndef DECLARATIONS_H
#define DECLARATIONS_H

class Abstract_Character;
class Abstract_Weapon;
class Point;

/* DO NOT #include THESE FILES DIRECTLY ANYWHERE ELSE */
/* ONLY USE #include declarations.h */
#include "point.h"
#include "characterAbstract.h"
#include "weaponAbstract.h"

#endif
