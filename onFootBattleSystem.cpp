#include "onFootBattleSystem.h"
#include <iostream>
#include <vector>
using namespace std;

/**
 * The process of fighting enemies on-planet.
 */
/*
 Versions:

 9/07/15:

 Enemies added before allies.
 Sequence is an int, no randomness factor yet.
 sortTurnOrder is N*Log(N) (?) efficient and home-made
 nothing yet done in the case of ties
 */

/* Decide order based on base speed-like stat with a randomness factor*/

vector<Character> onFootBattle_sortTurnOrder(vector<Character> unsorted)
  {
    vector<Character> sorted(unsorted.size());  //fully sorted vector

    //put the first Character into sorted
    //so that it is not empty at beginning
    sorted[0] = unsorted[unsorted.size() - 1];
    unsorted.pop_back();
    int numberSorted = 1;

    /* Sort each Character from unsorted into its appropriate place in sorted */

    //IMPORTANT: the vector is sorted in turn order, with descending sequence values,
    //and those with higher max_stam going before those with lower max_stam for those of equal sequence
    for (auto &myCharacter : unsorted)
      {
        //if the character to be sorted has a higher sequence variable than the sorted Character
        //being inspected
        int sortedIndex = 0;

        //Find the point where myCharacter is no longer bigger than the one being inspected
        while ((myCharacter.getSequence() < sorted[sortedIndex].getSequence())
            && (sortedIndex < numberSorted))
          {
            sortedIndex++;
          }

        //Use max_stam as a trump
        while ((myCharacter.getSequence() == sorted[sortedIndex].getSequence())
            && (myCharacter.getMaxStam() <= sorted[sortedIndex].getMaxStam())
            && (sortedIndex < numberSorted))
          {
            sortedIndex++;
          }

        sorted.insert(sorted.begin() + sortedIndex, myCharacter);
        numberSorted++;
      }

    return sorted;
  }

/*
 void onFootBattle_decideOrder()
 {
 // Combine both sides of the battle while generating order
 int unsortedIndex = 0;
 int totalSize = global_enemyTroop.size() + global_partyMembers.size();
 vector<Character> orderThisRound(totalSize);

 //Characters should have a function to determine a value representing their order;
 //add in each combatant to combined vector while running their function
 for (auto &enemyBattler : global_enemyTroop)
 {
 //run the Enemy's generating function and add it to the unsorted vector
 enemyBattler.calcInitiative();
 orderThisRound[unsortedIndex++] = enemyBattler;
 }
 for (auto &alliedBattler : global_partyMembers)
 {
 //run the Party's generating function and add it to the unsorted vector
 alliedBattler.calcInitiative();
 orderThisRound[unsortedIndex++] = alliedBattler;
 }

 //sort the combined vector based on this computed order value
 global_onFootBattlers = onFootBattle_sortTurnOrder(orderThisRound);
 }


 void onFootBattleSystemMain(vector<Character> encounteredEnemies)
 {

 // Make List of Enemies the global list
 global_enemyTroop = encounteredEnemies;

 battleProgression onFootBattleProgression = CONTINUE;

 // loop battle sequence until one side reaches 0 hp for all members
 while (onFootBattleProgression == CONTINUE)
 {
 //decide order
 onFootBattle_decideOrder();

 //exchange attacks

 //gain EXP--or is this done in the Character's attack() function?
 //check for all 0 hp

 }
 // Check who is victorious.

 // give loot

 // Return to exploring.

 }
 */
