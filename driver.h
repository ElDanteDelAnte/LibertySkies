/*
 * driver.h
 *
 *  Created on: Feb 11, 2016
 *      Author: eldante
 */
/*
 Versions:
 2/11/16
 rudimentary menu options as enums
 askPlayer prototype
 */
#ifndef DRIVER_H_
#define DRIVER_H_

//Main Menu
enum opts_mainMenu
  {
  RESUMEGAME, LOADGAME, SAVEGAME, NEWGAME, QUIT
  };

//Ship Menu
void shipMenu();

enum opts_shipMenu
  {
  EXITSHIP, FLY, MANAGESHIP, MANAGEPARTY, PLANETINFO, MAINMENU
  };

//On-Planet Menu
void landMenu();

enum opts_landMenu
  {
  EXPLORE, LOCATIONS, PARTY, ENTERSHIP
  };

//Flying Ship Menu  EXPERIMENTAL
void flyMenu();

enum opts_flyMenu
  {
  WAYPOINT, SHIPREADOUT, MANPILOT, LAND
  };

//Manage Pary Menu  EXPERIMENTAL
void managePartyMenu();

enum opts_managePartyMenu
  {
  INSPECTMEMBER, EQUIPMENT, INVENTORY, EXITPARTY
  };

//Manage Ship Menu  EXPERIMENTAL
void manageShipMenu();

enum opts_manageShipMenu
  {
  SHIPCONDITION, UPGRADES, EXITSHIPMAN
  };

/* I/O FUNCTIONS */

void promptPlayer(std::vector<std::string> opts);

int askPlayer(std::vector<std::string> opts, bool* unlocked);

int askPlayer(std::vector<std::string> opts);

void giveInputError();

#endif /* DRIVER_H_ */
