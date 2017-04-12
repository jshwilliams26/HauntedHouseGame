/**********************************************
** Description: Basement class specification file
** The player will die from entering the basement
** without a light.  There is a hole in the basement
** that the player can jump down and return to the
** outside.  There is a door without a handle that
** requires a chant to be made to open the door.
** The incorrect chant will transport the player
** to a different room.  The correct chant will
** open the door if the player has the Holy Cross,
** otherwise the door cannot be opened.
**********************************************/
#include <cstddef>
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
Basement::~Basement() {};

// ***************** exploreRoom ********************
// Explore the basement, by either jumping down the
// hole or chanting a phrase in front of the door to
// open it.  Incorrect chants will transport the player
// to a different room.
// **************************************************
void Basement::exploreRoom() {
	// Do not let the player explore the basement unless the player has the flashlight
	if (pOccupy->searchItemBag("Flashlight") == true) {
		std::cout << "\nIn the basement is a wooden door with no door handle," << std::endl;
		std::cout << "and a hole in the ground.  What will you do?" << std::endl;
		std::cout << " 1) Examine the hole" << std::endl;
		// Indicate to the player to enter the door if it has been opened
		if (this->getDoorOpened() == false) std::cout << " 2) Examine the door" << std::endl;
		else std::cout << " 2) Enter the doorway..." << std::endl;
		std::cout << "\nChoose 1 or 2: ";
		int choice;
		std::cin  >> choice;
		std::cin.ignore();
		
		// Go down the hole, return to the outside
		if (choice == 1) {
			std::cout << "\nThere is a hole in the ground, will you go down" << std::endl;
			std::cout << "(1 = yes, 0 = no)? ";
			int goDown;
			std::cin  >> goDown;
			std::cin.ignore();
			
			if (goDown == 1) {
				pOccupy->incrNumMoves();
				Player *p = pOccupy;
				pOccupy = NULL;
				door1->enterRoom(p);
			} else {
				this->exploreRoom();
			}
		// Chant in front of the doorway to open it
		} else {
			if (this->getDoorOpened() == false) this->Special();
			else {
				pOccupy->incrNumMoves();
				Player *p = pOccupy;
				pOccupy = NULL;
				door4->enterRoom(p);
			}
		}
		
	// The player will die in the basement if entered without a flashlight
	} else {
		std::cout << "\nYou have been enveloped by darkness..." << std::endl;
		std::cout << "GAME OVER!!!!!!!!!!!!!!!!!!!!" << std::endl << std::endl;

		pOccupy = NULL;
	}
}

// Exit room (make pOccupy NULL)
void Basement::exitRoom() {
	this->exploreRoom();
}

// ******************* Special **********************
// Chant the correct phrase to open the door, otherwise
// the player will be transported to a different room.
// The chant phrase is the name of the room with each
// character moved up one character and the name is reversed.
// **************************************************
void Basement::Special() {
	std::cout << "\nThere is a note on the door, which says: \"Chant the" << std::endl;
	std::cout << "correct phrase, and the door will open.  Other chants" << std::endl;
	std::cout << "may set you back in your path.  Each chant is elevated" << std::endl;
	std::cout << "and inverted.  There are several chants you can make:\"" << std::endl;
	std::cout << "\n 1) \"OFIDUJL\"" << std::endl;
	std::cout << " 2) \"UOFNFTBC UFSDFT\"" << std::endl;
	std::cout << " 3) \"NPPS HOJWJM\"" << std::endl;
	std::cout << "\nWhich chant will you make (1 - 3)? ";
	int chant;
	std::cin  >> chant;
	std::cin.ignore();
	
	// Transport the player to the kitchen
	if (chant == 1) {
		pOccupy->incrNumMoves();
		Player *p = pOccupy;
		pOccupy = NULL;		
		door2->enterRoom(p);
	// Open the door, if the user has the holy cross, otherwise don't open it.
	} else if (chant == 2) {
		if (pOccupy->searchItemBag("Holy Cross") == true) {
			this->setDoorOpened(true);
			std::cout << "\nThe door has been engulfed in flames and has disappeared!" << std::endl;
			std::cout << "Beyond the door lies a stairway that leads deep down..." << std::endl;
			this->exploreRoom();
		} else {
			std::cout << "\nThe door cannot be opened without the Holy Cross!" << std::endl;
			this->exploreRoom();
		}
	// Transport the player to the living room
	} else if (chant == 3) {
		pOccupy->incrNumMoves();
		Player *p = pOccupy;
		pOccupy = NULL;		
		door3->enterRoom(p);
	} else {
		this->Special();
	}
}

// Getters/Setters
void Basement::setDoorOpened(bool d)
{	doorOpened = d; }
bool Basement::getDoorOpened()
{	return doorOpened; }