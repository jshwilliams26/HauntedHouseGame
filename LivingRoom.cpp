/**********************************************
** Name: Josh Williams
** Description: Living Room class specification file
** In the living room, the player can exit the
** room, examine the bookshelf, and examine
** the window and break it.  The bookshelf will
** have books with hints at how to play the game.
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
LivingRoom::~LivingRoom() {};

// ******************* exploreRoom ********************
// Explore the Living Room.  There are options to exit the
// room, examine the bookshelf, and examine/break the
// window.
// ****************************************************
void LivingRoom::exploreRoom() {
	std::cout << "\nIn the living room there is a bookshelf, a window" << std::endl;
	std::cout << "to the outside, and doors to the kitchen and the" << std::endl;
	std::cout << "hallway.  What do you want to do? " << std::endl;
	std::cout << " 1) Exit the room" << std::endl;
	// If the window is broken, give the player the option to exit through the window
	if (this->getWindowBroken() == false) std::cout << " 2) Examine the window" << std::endl;
	else std::cout << " 2) Go through broken window..." << std::endl;
	std::cout << " 3) Examine the bookshelf" << std::endl;
	
	std::cout << "\nChoose 1 - 3: ";
	int choice;
	std::cin  >> choice;
	std::cin.ignore();
	
	// Exit the room
	if (choice == 1) {
		this->exitRoom();
	// Break the window, or go through the broken window
	} else if (choice == 2) {
		if (this->getWindowBroken() == false) {
			std::cout << "\nYou can see the outside through the window." << std::endl;
			std::cout << "The window is high up from the ground outside," << std::endl;
			std::cout << "and you will not be able to return inside this way." << std::endl;
			std::cout << "Break the window (1 = yes, 0 = no)? ";
			int breakW;
			std::cin >> breakW;
			std::cin.ignore();
			
			if (breakW == 1) {
				this->setWindowBroken(true);
				std::cout << "\nThe window has been broken!" << std::endl;
			}
			
			this->exploreRoom();
		} else {
			pOccupy->incrNumMoves();
			Player *p = pOccupy;
			pOccupy = NULL;
			door3->enterRoom(p);
		}
	// Examine the bookshelf
	} else if (choice == 3) {
		this->Special();
	// The wrong choice leads back to the menu
	} else {
		this->exploreRoom();
	}
}

// ********************* Special **********************
// Explore the bookshelf in the living room.  The books
// will have clues to secrets in the haunted house.
// There is a hidden book that, if accidentally selected,
// will transport the player to the basement.
// ****************************************************
void LivingRoom::Special() {
	// Display which books to read
	std::cout << "\nThere are several books on the bookshelf that stand out: " << std::endl;
	std::cout << " 1) Magickal Cookbook" << std::endl;
	std::cout << " 2) Devils and Demons" << std::endl;
	std::cout << " 3) The Black Grimoire" << std::endl;
	std::cout << " 4) The Incantation" << std::endl;
	std::cout << "\nWhich book will you read? ";
	int book;
	std::cin  >> book;
	std::cin.ignore();
	
	// This book gives hints to solving the kitchen shelf lock
	if (book == 1) {
		std::cout << "\nYou read a passage from \"Magickal Cookbook\":" << std::endl;
		std::cout << "    \"To obtain the Holy Cross follow these steps:" << std::endl;
		std::cout << "       1) Wave your wand to the left 10 times" << std::endl;
		std::cout << "       2) Wave your wand to the right 16 times" << std::endl;
		std::cout << "       3) Wave your wand to the left 13 times\"" << std::endl;
		
		this->exploreRoom();
	// Warn the player not to spend too much time in the house
	} else if (book == 2) {
		std::cout << "\nYou read a passage from \"Devils and Demons\":" << std::endl;
		std::cout << "    \"The House on the Hill has many devils and demons." << std::endl;
		std::cout << "     Those who linger too long in the house may be devoured..." << std::endl;
		
		this->exploreRoom();
	// Tell the player how to win the game
	} else if (book == 3) {
		std::cout << "\nYou read a passage from \"The Black Grimoire\":" << std::endl;
		std::cout << "    \"He who digs the cursed skull from the deepest lair will be" << std::endl;
		std::cout << "     pursued by the morning star, but if he escapes and returns" << std::endl;
		std::cout << "     the skull to the altar, he will be victorious!\"" << std::endl;
		
		this->exploreRoom();
	// How to access the secret basement
	} else if (book == 4) {
		std::cout << "\nYou read a passage from \"The Incantation\":" << std::endl;
		std::cout << "    \"He who wishes to enter the secret Void must bear the cross" << std::endl;
		std::cout << "     and light and chant the sacred phrase to open the door to the" << std::endl;
		std::cout << "     nether region...\"" << std::endl;
		
		this->exploreRoom();
	// This is the hidden book that, if the player chooses something else besides 1 - 4,
	// the floor will drop out and the player will fall to the basement.
	} else {
		std::cout << "\nYou read a passage from \"Journeys into the Abyss\":" << std::endl;
		std::cout << "    \"He who opens the books blasphemous and profane" << std::endl;
		std::cout << "     shall descend into the pit...\"" << std::endl << std::endl;
		
		std::cout << "\nThe floor opens up beneath you and you fall below!" << std::endl;
		
		pOccupy->incrNumMoves();
		Player *p = pOccupy;
		pOccupy = NULL;		
		door4->enterRoom(p);
	}
}

// ********************* exitRoom *********************
// Exit the living room to either the hallway or the
// kitchen
// ****************************************************
void LivingRoom::exitRoom() {
	std::cout << "\nChoose which door to enter: " << std::endl;
	std::cout << " 1) Hallway" << std::endl;
	std::cout << " 2) Kitchen" << std::endl;

	int door;
	std::cout << "\nEnter 1 or 2: ";
	std::cin  >> door;
	std::cin.ignore();
	
	if (door > 0 && door < 3) {
		pOccupy->incrNumMoves();
		Player *p = pOccupy;
		pOccupy = NULL;

		if (door == 1) door1->enterRoom(p);
		else if (door == 2) door2->enterRoom(p);
	} else this->exitRoom();
}

// Getters/setters
void LivingRoom::setWindowBroken(bool w)
{	windowBroken = w; }
bool LivingRoom::getWindowBroken()
{	return windowBroken; }