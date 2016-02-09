#ifndef ONFOOTBATTLESYSTEM_H
#define ONFOOTBATTLESYSTEM_H

//#include <vector>
//#include "character.h"
using namespace std;
//Can this only be stated once?

/* List of Party Members */
extern vector<Character> global_partyMembers;

/* List of Enemies */
extern vector<Character> global_enemyTroop;

/* Combined list of combatants */
extern vector<Character> global_onFootBattlers;

typedef enum
  {
  CONTINUE, PARTYWIN, PARTYLOSE
  } battleProgression;

/* The overall on-foot battle system function. */
void onFootBattleSystemMain(vector<Character> encounteredEnemies);

/* Determines the order the combatants take their turns in a given round. */
void onFootBattle_decideOrder();

/* Prototype temporarilly here for testing purposes.*/
vector<Character> onFootBattle_sortTurnOrder(vector<Character> unsorted);


#endif
