/**********************************************
** Name: Josh Williams
** Description: Outside class implementation file
** This will define an Outside class.  The
** player will have the option to explore a
** shack, a garden, to enter through the main
** door, and to enter through the ground level
** window.  The player can enter the basement 
** through the window, but cannot return to the
** outside that way, because the window is too
** high from the ground inside the basement.
** The player can find a shovel in the garden.
**********************************************/
#include <cstddef>
#include <cstdlib>
#include <iostream>

#include "Space.hpp"
#include "Basement.hpp"
#include "Hallway.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
#include "Outside.hpp"
#include "SecretBasement.hpp"
#include "Player.hpp"

// Destructor
Outside::~Outside() {};

// ******************* exploreRoom ********************
// Explore the Outside.  There is a garden, altar, and
// a shack to explore, and a main door and a window to
// enter.  
// ****************************************************
void Outside::exploreRoom() {
	std::cout << "\nOutside there is a garden, a shack, the main door" << std::endl;
	std::cout << "to the house, an altar by the tree, and a window on" << std::endl;
	std::cout << "the ground level." << std::endl;
	std::cout << " 1) Enter the house" << std::endl;
	std::cout << " 2) Examine the garden" << std::endl;
	std::cout << " 3) Examine the altar" << std::endl;
	std::cout << " 4) Look in the shack" << std::endl;
	std::cout << " 5) Examine the ground level window" << std::endl;
	std::cout << "\nChoose an action 1 - 5: ";
	int choice;
	std::cin  >> choice;
	std::cin.ignore();

	// Enter the house through the main entrance
	if (choice == 1) {
		pOccupy->incrNumMoves();
		Player *p = pOccupy;
		pOccupy = NULL;
		door1->enterRoom(p);
	// Look in the garden, and take a shovel or not
	} else if (choice == 2) {
		if (this->getShovelTaken() == false) {
			int take;
			std::cout << "\nIn the garden is a shovel. Take it (1 = yes, 0 = no)? ";
			std::cin  >> take;
			std::cin.ignore();

			if (take == 1) {
				if (pOccupy->isFull() == false) this->setShovelTaken(true);
				pOccupy->addItem("Shovel");
			}
		} else {
			std::cout << "\nThere is nothing to take in the garden." << std::endl;
		}
		this->exploreRoom();
	// Look at the altar, this is where the cursed skull will need to be placed to win the game
	} else if (choice == 3) {
		std::cout << "\nThere is a stone altar by the tree, and it appears that" << std::endl;
		std::cout << "something can be seated on top of it." << std::endl;
		
		if (pOccupy->searchItemBag("Cursed Skull") == true) {
			int place;
			std::cout << "\nPlace the Cursed Skull on the altar (1 = yes, 0 = no)?" << std::endl;
			std::cin  >> place;
			std::cin.ignore();
			
			if (place == 1) {
				std::cout << "\nThe Cursed Skull has been returned to the altar!" << std::endl;
				std::cout << "You are victorious!!!!!!!" << std::endl << std::endl;
				
				pOccupy = NULL;
			} else {
				this->exploreRoom();
			}
		// Go back to the menu if the skull is not in the bag
		} else {
			this->exploreRoom();
		}
	// Look in the shack, and there is a notebook and a broken slot machine
	} else if (choice == 4) {
		std::cout << "\nIn the shack is a notebook which reads:" << std::endl;
		std::cout << "     \"Those who enter the house cannot linger for too long" << std::endl;
		std::cout << "      or else they may be devoured by a spirit. Some books" << std::endl;
		std::cout << "      in the house give hints, but those books which are hidden" << std::endl;
		std::cout << "      take those who read them to the world below.  Beware of" << std::endl;
		std::cout << "      entering the abyss without a light to guide your way..." << std::endl;

		int slot;
		std::cout << "\nThere is also a slot machine in the shack." << std::endl;
		std::cout << "Play the slot machine (1 = yes, 0 = no)? ";
		std::cin  >> slot;
		std::cin.ignore();
		
		if (slot == 1) this->Special();
		else this->exploreRoom();
	// Explore the window
	} else if (choice == 5) {
		std::cout << "\nThe window near the ground is cracked open" << std::endl;
		std::cout << "Go inside (1 = yes, 0 = no)? ";
		int goin;
		std::cin  >> goin;
		std::cin.ignore();

		if (goin == 1) {
			pOccupy->incrNumMoves();
			Player *p = pOccupy;
			pOccupy = NULL;
			door2->enterRoom(p);
		} else {
			this->exploreRoom();
		}
	// The wrong choice leads back to the menu
	} else {
		this->exploreRoom();
	}
}

// ******************* Special ********************
// Play the slot machine.  Two of the combos will
// transport the player to a different space.
// ************************************************
void Outside::Special() {
	int s1 = rand() % 9 + 1;
	int s2 = rand() % 9 + 1;
	int s3 = rand() % 9 + 1;
	
	// Artificially test 6 6 6
	/*s1 = 6;
	s2 = 6;
	s3 = 6;*/
	
	// Artificially test 1 4 8
	/*s1 = 1;
	s2 = 4;
	s3 = 8;*/

	std::cout << "\nYou rolled the following: " << std::endl;
	std::cout << "  " << s1 << "  " << s2 << "  " << s3 << std::endl;

	// For the roll 6 6 6, move to the kitchen
	if (s1 == 6 && s2 == 6 && s3 == 6) {
		pOccupy->incrNumMoves();
		Player *p = pOccupy;
		pOccupy = NULL;	
		door3->enterRoom(p);
	// For the roll 1 4 8, move to the living room
	} else if (s1 == 1 && s2 == 4 && s3 == 8) {
		pOccupy->incrNumMoves();
		Player *p = pOccupy;
		pOccupy = NULL;		
		door4->enterRoom(p);
	// Otherwise the slot machine does nothing
	} else {
		std::cout << "\nNothing happened." << std::endl;

		this->exploreRoom();
	}
}

// Getters/setters
void Outside::setShovelTaken(bool s)
{	shovelTaken = s; }
bool Outside::getShovelTaken()
{	return shovelTaken; }