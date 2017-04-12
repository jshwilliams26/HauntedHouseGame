/**********************************************
** Name: Josh Williams
** Description: Secret Basement class implementation file
** The secret basement will have a number of
** spots on the ground to dig, one of them has
** the cursed skull.  The others lead to different
** parts of the house.  If the player does not
** have the shovel, they cannot do anything
** in the secret basement.
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
SecretBasement::~SecretBasement() {};

// ***************** exploreRoom ********************
// If the secret basement is entered without the
// shovel, there is nothing to do but exit.  If the
// player has the shovel and the flashlight, the
// player can then dig a hole.
// **************************************************
void SecretBasement::exploreRoom() {
	std::cout << "\nA single lantern above illuminates the room." << std::endl;
	std::cout << "The floor in this room is covered by dirt." << std::endl;
	std::cout << " 1) Exit the room" << std::endl;
	std::cout << " 2) Dig a hole in the ground" << std::endl;
	
	int choice;
	std::cout << "\nChoose 1 or 2: ";
	std::cin  >> choice;
	std::cin.ignore();
	
	// Exit the room
	if (choice == 1) {
		this->exitRoom();
	// Dig a hole or not if the shovel isn't in the item bag
	} else if (choice == 2) {
		if (pOccupy->searchItemBag("Shovel") == true) {
			this->Special();
		} else {
			std::cout << "\nThe room is empty and there is only dirt on the ground..." << std::endl;
			this->exitRoom();
		}
	} else {
		this->exploreRoom();
	}
}

// Exit room (make pOccupy NULL)
void SecretBasement::exitRoom() {
	std::cout << "\nChoose which door to enter: " << std::endl;
	std::cout << " 1) Basement" << std::endl;
	int door;
	std::cout << "\nEnter 1: ";
	std::cin  >> door;
	std::cin.ignore();

	pOccupy->incrNumMoves();
	Player *p = pOccupy;
	pOccupy = NULL;
	door1->enterRoom(p);
}

// ******************* Special **********************
// Dig a hole in the secret basement.  One has the
// cursed skull, the others lead to other parts of
// the house.  Once the skull is taken, the number of
// player moves will be set to 40 if it is not at least
// 40, this will limit the amount of time the player
// has to escape and place the skull on the altar
// before the player is devoured.
// **************************************************
void SecretBasement::Special() {
	std::cout << "\nA note on the ground says that there is a ghost in the room" << std::endl;
	std::cout << "who covers up your holes after you dig them, so hold onto your" << std::endl;
	std::cout << "shovel.  There are several spots in the room to dig:" << std::endl;
	std::cout << " 1) Right side of door" << std::endl;
	std::cout << " 2) Left side of door" << std::endl;
	std::cout << " 3) Center of room" << std::endl;
	std::cout << " 4) Back of room" << std::endl;
	std::cout << "\nWhere will you dig (pick 1 - 4)? ";
	int dig;
	std::cin  >> dig;
	std::cin.ignore();

	// Go to the kitchen
	if (dig == 1) {
		pOccupy->incrNumMoves();
		Player *p = pOccupy;
		pOccupy = NULL;
		door2->enterRoom(p);
	// Go to the hallway
	} else if (dig == 2) {
		pOccupy->incrNumMoves();
		Player *p = pOccupy;
		pOccupy = NULL;
		door3->enterRoom(p);
	// Go to the living room
	} else if (dig == 3) {
		pOccupy->incrNumMoves();
		Player *p = pOccupy;
		pOccupy = NULL;
		door4->enterRoom(p);
	// The back room hole has the Cursed Skull
	} else if (dig == 4) {
		if (skullFound == false) {
			std::cout << "\nThere was a Cursed Skull buried in the ground." << std::endl;
			std::cout << "Do you wish to take it (1 = yes, 0 = no)? ";
			int take;
			std::cin  >> take;
			std::cin.ignore();

			if (take == 1) {
				// If the item bag is not full, add the skull
				if (pOccupy->isFull() == false) {
					this->setSkullFound(true);
					pOccupy->addItem("Cursed Skull");
					std::cout << "\nYou have found the Cursed Skull! You must escape" << std::endl;
					std::cout << "the House through the main exit or you will perish!" << std::endl;
					std::cout << "You only have 10 moves left!" << std::endl;

					// The player moves will be set to 40 if the moves are less than that
					if (pOccupy->getNumMoves() < 40) {
						pOccupy->setNumMoves(40);
					}
				// If the item bag is not full, remove an item bag first
				// then come back to the skull through the menu...
				} else {
					std::cout << "Your item bag is full!" << std::endl;
					pOccupy->removeItem();
				}
			}
		} else {
			std::cout << "\nThere is nothing in this hole." << std::endl;
		}
		this->exploreRoom();
	} else {
		this->Special();
	}
}

// Getters/Setters
void SecretBasement::setSkullFound(bool s)
{	skullFound = s; }
bool SecretBasement::getSkullFound()
{	return skullFound; }