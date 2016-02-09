/**
 * 7/23/15:
 * Just the order so far
 * Does not yet account for ties.
 *
 * 11/16/15:
 * Initializes weapon as per constructor requirements.
 *
 * 2/8/12
 * now #includes declarations.h instead of character.h
 * still #includes onFootBattleSystem.h" directly (intentional so far)
 */

#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "checkit.h"
//#include "character.h"
#include "declarations.h"
#include "onFootBattleSystem.h"

//dummy constructor
Character::Character()
  {
    this->name = "testCharacter";
    this->charRace.racename = HUMAN;
    this->hp = 0;
    this->max_hp = 0;
    this->stam = 0;
    this->max_stam = 0;
    this->spirit = 0;
    this->max_spirit = 0;
    this->sequence = 0;

    this->weapon = NULL;

    //std::cout << "Constructing Character, default" << endl;
  }

Character::Character(std::string charName, int orderIndex)
  {
    this->name = charName;
    this->sequence = orderIndex;

    this->hp = 0;
    this->max_hp = 0;
    this->stam = 0;
    this->max_stam = 0;
    this->spirit = 0;
    this->max_spirit = 0;

    this->weapon = NULL;

    //std::cout << "Constructing Character, 2 parameters" << endl;
  }

Character::Character(std::string charName, int baseSequence, int maxStam)
  {
    this->name = charName;
    this->sequence = baseSequence;

    this->hp = 0;
    this->max_hp = 0;
    this->stam = 0;
    this->max_stam = maxStam;
    this->spirit = 0;
    this->max_spirit = 0;

    this->weapon = NULL;

    //std::cout << "Constructing Character, 3 parameters" << endl;
  }

int Character::getSequence()
  {
    return this->sequence;

    //std::cout << "calling getSequence()" << endl;
  }

void Character::calcInitiative()
  {
    /*To be determined*/
  }

void testDecideOrderWOTies()
  {
    //desired result order in testOrder
    std::string testNameAlly3 = "Jenny";
    std::string testNameEnemy3 = "Snake";
    std::string testNameAlly2 = "Sally";
    std::string testNameEnemy2 = "Spider";
    std::string testNameAlly1 = "George";
    std::string testNameEnemy1 = "Bat";

    std::cout << "Created test Character name strings" << endl;

    std::vector<Character> testOrder(6);

    std::cout << "Created testOrder vector" << endl;

    testOrder[0] = Character("Jenny", 9);
    testOrder[1] = Character("George", 3);
    testOrder[2] = Character("Bat", 1);
    testOrder[3] = Character("Sally", 6);
    testOrder[4] = Character("Spider", 5);
    testOrder[5] = Character("Snake", 7);

    std::cout
        << "Created test Characters and assigned their scrambled spots in testOrder"
        << endl;
    std::cout << "Calling sortTurnOrder" << endl;

    testOrder = onFootBattle_sortTurnOrder(testOrder);

    std::cout << "sortTurnOrder ran" << endl;
    std::cout << "Checking results via names" << endl;

    checkit_int(strcmp(testOrder[0].getName().c_str(), testNameAlly3.c_str()),
        0);
    checkit_int(strcmp(testOrder[1].getName().c_str(), testNameEnemy3.c_str()),
        0);
    checkit_int(strcmp(testOrder[2].getName().c_str(), testNameAlly2.c_str()),
        0);
    checkit_int(strcmp(testOrder[3].getName().c_str(), testNameEnemy2.c_str()),
        0);
    checkit_int(strcmp(testOrder[4].getName().c_str(), testNameAlly1.c_str()),
        0);
    checkit_int(strcmp(testOrder[5].getName().c_str(), testNameEnemy1.c_str()),
        0);

    std::cout << "testOrder[0]: " << testOrder[0].getName() << ", sequence: "
        << testOrder[0].getSequence() << endl;
    std::cout << "testOrder[1]: " << testOrder[1].getName() << ", sequence: "
        << testOrder[1].getSequence() << endl;
    std::cout << "testOrder[2]: " << testOrder[2].getName() << ", sequence: "
        << testOrder[2].getSequence() << endl;
    std::cout << "testOrder[3]: " << testOrder[3].getName() << ", sequence: "
        << testOrder[3].getSequence() << endl;
    std::cout << "testOrder[4]: " << testOrder[4].getName() << ", sequence: "
        << testOrder[4].getSequence() << endl;
    std::cout << "testOrder[5]: " << testOrder[5].getName() << ", sequence: "
        << testOrder[5].getSequence() << endl;

  }

void testDecideOrderWithTies()
  {
    //desired result order in testOrder
    std::string testNameAlly3 = "Jenny";
    std::string testNameEnemy3 = "Snake";
    std::string testNameAlly2 = "Sally";
    std::string testNameEnemy2 = "Spider";
    std::string testNameAlly1 = "George";
    std::string testNameEnemy1 = "Bat";

    std::cout << "Created test Character name strings" << endl;

    std::vector<Character> testOrder(6);

    std::cout << "Created testOrder vector" << endl;

    testOrder[0] = Character("Jenny", 9, 55);
    testOrder[1] = Character("Spider", 5, 40);
    testOrder[2] = Character("Bat", 1, 10);
    testOrder[3] = Character("Sally", 9, 30);
    testOrder[4] = Character("George", 5, 10);
    testOrder[5] = Character("Snake", 9, 50);

    std::cout
        << "Created test Characters and assigned their scrambled spots in testOrder"
        << endl;
    std::cout << "Calling sortTurnOrder" << endl;

    testOrder = onFootBattle_sortTurnOrder(testOrder);
    std::cout << "sortTurnOrder ran" << endl;
    std::cout << "Checking results via names" << endl;

    checkit_int(strcmp(testOrder[0].getName().c_str(), testNameAlly3.c_str()),
        0);
    checkit_int(strcmp(testOrder[1].getName().c_str(), testNameEnemy3.c_str()),
        0);
    checkit_int(strcmp(testOrder[2].getName().c_str(), testNameAlly2.c_str()),
        0);
    checkit_int(strcmp(testOrder[3].getName().c_str(), testNameEnemy2.c_str()),
        0);
    checkit_int(strcmp(testOrder[4].getName().c_str(), testNameAlly1.c_str()),
        0);
    checkit_int(strcmp(testOrder[5].getName().c_str(), testNameEnemy1.c_str()),
        0);

    std::cout << "testOrder[0]: " << testOrder[0].getName() << ", sequence: "
        << testOrder[0].getSequence() << ", max_stam: "
        << testOrder[0].getMaxStam() << endl;
    std::cout << "testOrder[1]: " << testOrder[1].getName() << ", sequence: "
        << testOrder[1].getSequence() << ", max_stam: "
        << testOrder[1].getMaxStam() << endl;
    std::cout << "testOrder[2]: " << testOrder[2].getName() << ", sequence: "
        << testOrder[2].getSequence() << ", max_stam: "
        << testOrder[2].getMaxStam() << endl;
    std::cout << "testOrder[3]: " << testOrder[3].getName() << ", sequence: "
        << testOrder[3].getSequence() << ", max_stam: "
        << testOrder[3].getMaxStam() << endl;
    std::cout << "testOrder[4]: " << testOrder[4].getName() << ", sequence: "
        << testOrder[4].getSequence() << ", max_stam: "
        << testOrder[4].getMaxStam() << endl;
    std::cout << "testOrder[5]: " << testOrder[5].getName() << ", sequence: "
        << testOrder[5].getSequence() << ", max_stam: "
        << testOrder[5].getMaxStam() << endl;

  }

int main()
  {
    //std::cout << "Testing ignoring ties" << endl;
    //testDecideOrderWOTies();

    std::cout << "Testing for ties" << endl;
    testDecideOrderWithTies();

    return 0;
  }
