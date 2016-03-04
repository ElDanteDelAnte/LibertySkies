/*
 * driver.cpp
 *
 *  Created on: Feb 8, 2016
 *      Author: eldante
 */
/*
 Versions:

 2/8/16
 loops act function which opens menus

 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "declarations.h"
#include "driver.h"

using namespace std;

/**
 * Master game driver.
 * Displays the Main Menu.
 *
 * Options:
 *   resume game
 *   load game
 *   save game
 *   new game
 *   quit game
 *
 * @return Exit Runtime.
 */
int main()
  {
    bool gameRunning = true;

    /* MAIN MENU */
    //build option vector
    vector<string> mainMenu;
    mainMenu.push_back("RESUMEGAME");
    mainMenu.push_back("LOADGAME");
    mainMenu.push_back("SAVEGAME");
    mainMenu.push_back("NEWGAME");
    mainMenu.push_back("QUITGAME");

    //display options
    promptPlayer(mainMenu);

    //until exit game
    while (gameRunning)
      {
        //retrieve new input
        int choice = askPlayer(mainMenu);


        switch (choice)
          {
          //continue playing
          case RESUMEGAME:
            //shipMenu()
            break;

          //load game file
          case LOADGAME:
            //loadMenu()
            break;

          //save game file
          case SAVEGAME:
            //saveGame()
            break;

          //start new game
          case NEWGAME:
            //startNewGame()
            break;

          //quit game
          case QUIT:
            gameRunning = false;
            break;

          //error
          default:
            giveInputError();
          }
      }

    return 0;  //end of runtime
  }

/**
 * Menu displayed when inside the ship.
 *
 * Options:
 *   exit ship
 *   fly ship
 *   manage ship
 *   manage party
 *   planet info
 *   return to Main Menu
 */
void shipMenu()
  {
    bool gameActive = true;

    //build option vector
    vector<string> shipMenu;
    shipMenu.push_back("EXITSHIP");
    shipMenu.push_back("FLY");
    shipMenu.push_back("MANAGESHIP");
    shipMenu.push_back("MANAGEPARTY");
    shipMenu.push_back("PLANETINFO");
    shipMenu.push_back("MAINMENU");

    //display options
    promptPlayer(shipMenu);

    //while the game is "unpaused"
    while (gameActive)
      {
        //retrieve new input
        int choice = askPlayer(shipMenu);

        switch (choice)
          {
          //exit to planet
          case EXITSHIP:
            landMenu();
            break;

          //fly to a new location
          case FLY:
            //flyShipMenu()
            break;

          //manage the ship
          case MANAGESHIP:
            //manageShipMenu()
            break;

          //manage the party
          case MANAGEPARTY:
            //managePartyMenu()
            break;

          //information about the planet
          case PLANETINFO:
            //displayPlanetInfo()  //POSSIBLE approach
            break;

          //return to Main Menu
          case MAINMENU:
            gameActive = false;
            break;

          //error
          default:
            giveInputError();
          }
      }
  }

/**
 * Menu for having landed on planet.
 *
 * Options:
 *   explore
 *   discovered locations
 *   manage party
 *   return to ship
 */
void landMenu()
  {
    bool onPlanet = true;

    //build option vector
    vector<string> landMenu;

    //display options
    promptPlayer(landMenu);

    //retrieve and process input
    while (onPlanet)
      {
        int choice = askPlayer(landMenu);

        switch (choice)
          {
          //explore the planet
          case EXPLORE:
            //currPlanet.exploreMenu();
            break;

          //discovered locations
          case LOCATIONS:
            //currPlanet.locationsMenu();
            break;

          //manage party
          case PARTY:
            //managePartyMenu();  //same as from on ship
            break;

          //return to ship
          case ENTERSHIP:
            onPlanet = false;
            break;

          //error
          default:
            giveInputError();
          }
      }
  }

/**
 * Fly to a new destination.
 * THIS DESIGN IS TEMPORARY.
 *
 * Options (currently):
 *   fly to discovered location
 *   readout of ship systems
 *   fly manually
 *   return to planet
 */
void flyMenu()
  {
    bool flyingShip = true;

    //build option vector
    vector<string> flyMenu;

    //display options
    promptPlayer(flyMenu);

    //retrieve and process input
    while (flyingShip)
      {
        int choice = askPlayer(flyMenu);

        switch (choice)
          {
          //fly to discovered location
          case WAYPOINT:
            //flyToWayPoint();
            break;
          //readout of ship systems
          case SHIPREADOUT:
            //shipReadout();
            break;
          //fly manually
          case MANPILOT:
            //manPilot();    //EXTREMELY EXPERIMENTAL
            break;
          //land on planet
          case LAND:
            //if (currPlanet != NULL)
            //  flyingShip = false;
            //else
            //  give an error
          //error
          default:
            giveInputError();
          }
      }
  }

/* I/O FUNCTIONS*/

/**
 * Presents options to the player.
 *
 * @param opts List of options.
 */
void promptPlayer(vector<string> opts)
  {
    for (auto& myOpt : opts)
      {
        cout << myOpt << endl;
      }
  }

/**
 * Obtains player's selected option, provided option is unlocked.
 *
 * @param opts List of possible options.
 * @param validOpts Indicates which choices are currently unlocked.
 * @return Index of option selected, -1 if locked, or -2 if invalid.
 */
int askPlayer(vector<string> opts, bool* validOpts)
  {
    cout << ">";

    //retrieve user input
    string response;
    cin >> response;

    //match input to option
    for (int i = 0; i < opts.size(); i++)
      {
        string currOpt = opts.at(i);

        //return place of matching option
        if (response.compare(currOpt) == 0)
          {
            if (validOpts[i]) return i;    //option is unlocked

            return -1;                     //option is locked
          }
      }

    return -2;                             //input is invalid
  }

/**
 * Obtains player's selected option, assuming all options are unlocked.
 *
 * @param opts List of possible options.
 * @return Index of option selected, -2 if invalid.
 */

int askPlayer(vector<string> opts)
  {
    bool allTrue[25];

    for (int i = 0; i < 25; i++)
      allTrue[i] = true;

    return askPlayer(opts, allTrue);
  }


/**
 * Displays an input error message.
 */
void giveInputError()
  {
    cout << "Invalid input" << endl;
  }
