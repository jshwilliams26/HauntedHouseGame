/**********************************************
** Name: Josh Williams
** Description: Hallway class implementation file
** Once the player enters the Hallway from the
** outside, the door to the outside will be locked
** until the player has the cursed skull.  There
** is also a desk with a flashlight in it.  There
** is also a crack near the floor that can be
** kicked, and if opened up, can lead to the basement.
**********************************************/
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Space.hpp"
#include "Basement.hpp"
#include "Hallway.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
#include "Outside.hpp"
#include "SecretBasement.hpp"
#include "Player.hpp"

// Destructor
Hallway::~Hallway() {};

// ******************* exploreRoom ********************
// Explore the Hallway.  There are options to exit the
// room, look in the desk drawer, and examine the crack
// in the floor.
// ****************************************************
void Hallway::exploreRoom() {
	std::cout << "\nIn the hallway there are doors to the outside, the kitchen," << std::endl;
	std::cout << "and the living room.  There is also a desk with a drawer.  Near" << std::endl;
	std::cout << "the desk there is a crack in the floor.  What do you want to do?" << std::endl;
	std::cout << " 1) Exit the room" << std::endl;
	std::cout << " 2) Open the desk drawer" << std::endl;
	// Examine the crack, and indicate if the crack is opened or not
	if (this->getFloorCrackOpened() == false) std::cout << " 3) Examine the crack" << std::endl;
	else std::cout << " 3) Drop below where the crack opened..." << std::endl;
	
	std::cout << "\nEnter a number 1 - 3: ";
	int choice;
	std::cin  >> choice;
	std::cin.ignore();
	
	// Exit the room
	if (choice == 1) this->exitRoom();
	// Look in the drawer, take a flashlight or not
	else if (choice == 2) {
		// If the flashlight hasn't been taken, give the user the option to take it
		if (this->getFlashlightTaken() == false) {
			std::cout << "\nThere is a flashlight with a note attached. The note reads: " << std::endl;
			std::cout << "   \"The one who lights the way will find eternal darkness...\"" << std::endl;
			std::cout << "\nDo you wish to take the flashlight (1 = Y, 0 = N): ";
			int take;
			std::cin  >> take;
			std::cin.ignore();
			if (take == 1) {
				if (pOccupy->isFull() == false) this->setFlashlightTaken(true);
				pOccupy->addItem("Flashlight");
			}
		// If the flashlight has been taken, display the note
		} else {
			std::cout << "\nThere is a note that reads: " << std::endl;
			std::cout << "   \"The one who lights the way will find eternal darkness...\"" << std::endl;			
		}

		this->exploreRoom();
	// Kick a crack in the floor, or go through the opened cracked
	} else if (choice == 3) {
		if (this->getFloorCrackOpened() == false) {
			std::cout << "\nDo you wish to kick the crack in the floor (1 = Y, 0 = N)? ";
			int ans;
			std::cin  >> ans;
			std::cin.ignore();
			if (ans == 1) this->Special();
			else this->exploreRoom();
		// The opened crack leads to the basement
		} else {
			pOccupy->incrNumMoves();
			Player *p = pOccupy;
			pOccupy = NULL;
			door4->enterRoom(p);
		}
	// The wrong choice leads back to the menu
	} else {
		this->exploreRoom();
	}
}

// ********************* exitRoom *********************
// Exit the hallway.  If the player doesn't have the
// Cursed Skull, the player can't exit through the
// main door.
// ****************************************************
void Hallway::exitRoom() {
	// Determine if the player has the Cursed Skull
	std::string skull = "Cursed Skull";
	bool skullFound = pOccupy->searchItemBag(skull);
	
	std::cout << "\nChoose which door to enter: " << std::endl;
	std::cout << " 1) Kitchen" << std::endl;
	std::cout << " 2) Living Room" << std::endl;
	std::cout << " 3) Outside" << std::endl;
	int door;
	std::cout << "\nEnter a number 1 - 3: ";
	std::cin  >> door;
	std::cin.ignore();
	
	if (door == 1) {
		pOccupy->incrNumMoves();
		Player *p = pOccupy;
		pOccupy = NULL;
		door1->enterRoom(p);
	} else if (door == 2) {
		pOccupy->incrNumMoves();
		Player *p = pOccupy;
		pOccupy = NULL;
		door2->enterRoom(p);
	} else if (door == 3) {
		// Let the player through if the skull is in the bag
		if (skullFound == true) {
			std::cout << "\nThe Cursed Skull unlocked the front entrance!" << std::endl;

			pOccupy->incrNumMoves();
			Player *p = pOccupy;
			pOccupy = NULL;	
			door3->enterRoom(p);
		// Forbid the player from entering if skull is not in the bag
		} else {
			std::cout << "\nYou do not have the Cursed Skull! You cannot exit!!!" << std::endl;
			this->exitRoom();
		}
	} else {
		this->exitRoom();
	}
	
}

// ********************* Special **********************
// Kick the crack in the floor.  The kick strength is
// randomly selected.  If it is strong enough, the
// crack breaks open.
// ****************************************************
void Hallway::Special() {
	int kick = rand() % 10 + 1;

	if (kick < 3) {
		std::cout << "\nThat was pathetic..." << std::endl << std::endl;
	} else if (kick >= 3 && kick <= 9) {
		std::cout << "\nYou can do better than that..." << std::endl << std::endl;
	} else {
		std::cout << "\nThe crack opened up, you peer below and see nothing but darkness..." << std::endl;
		setFloorCrackOpened(true);
	}
	
	this->exploreRoom();
}

// Getters/Setters
void Hallway::setFloorCrackOpened(bool w)
{	floorCrackOpened = w; }
bool Hallway::getFloorCrackOpened()
{	return floorCrackOpened; }
void Hallway::setFlashlightTaken(bool f)
{	flashlightTaken = f; }
bool Hallway::getFlashlightTaken()
{	return flashlightTaken; }