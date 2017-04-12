/**********************************************
** Description: Kitchen class specification file
** The kitchen will have a locked cabinet that
** contains a holy cross, which is needed to
** open the door to the secret basement.  The correct
** combination must be entered for the player to
** to open the shelf.  There is one incorrect
** combination that will transport the player to
** the basement.  Inside the shelf is a note
** and the holy cross.  There is also a window that
** can be broken for access to the outside.  There
** are also normal exits from the kitchen to other
** rooms.
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
Kitchen::~Kitchen() {};

// ********************* exploreRoom *********************
// Choose between unlocking the combination lock to the
// shelf, breaking the window, or exiting the room.
// *******************************************************
void Kitchen::exploreRoom() {
	std::cout << "\nIn the Kitchen there is a shelf with a combination lock," << std::endl;
	std::cout << "a window to the outside, and doors to the living room" << std::endl;
	std::cout << "and the hallway. " << std::endl;
	std::cout << " 1) Exit the room" << std::endl;
	if (this->getShelfLocked() == true) std::cout << " 2) Examine the locked shelf" << std::endl;
	else std::cout << " 2) Examine the shelf" << std::endl;
	// If the window is broken, give the player the option to exit through the window
	if (this->getWindowBroken() == false) std::cout << " 3) Examine the window" << std::endl;
	else std::cout << " 3) Go through broken window..." << std::endl;
	std::cout << "\nEnter a choice 1 - 3: ";
	int choice;
	std::cin  >> choice;
	std::cin.ignore();
	
	// Look at the shelf and solve the combination
	if (choice == 1) {
		this->exitRoom();
	} else if (choice == 2) {
		this->Special();
	// Examine and break the window
	} else if (choice == 3) {
		// If the window isn't already broken, give the player the option to break it.
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
		// Exit through the window to the outside
		} else {
			pOccupy->incrNumMoves();
			Player *p = pOccupy;
			pOccupy = NULL;
			door3->enterRoom(p);
		}
	// Exit the room
	} else {
		this->exploreRoom();
	}
}

// ********************* exitRoom *********************
// Exit the kitchen to either the hallway or the kitchen
// ****************************************************
void Kitchen::exitRoom() {
	std::cout << "\nChoose which door to enter: " << std::endl;
	std::cout << " 1) Hallway" << std::endl;
	std::cout << " 2) Living Room" << std::endl;

	int door;
	std::cout << "\nEnter a number 1 - 2: ";
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

// *********************** Special ***********************
// Try to open the combination lock.  If opened, the player
// can take the Holy Cross.  There is a specific combination
// that will transport the player to the basement.
// *******************************************************
void Kitchen::Special() {
	// If the shelf is locked, give the player the chance
	// to unlock it with the correct code.  If it is unlocked
	// then let the player take the Holy Cross.  If the entered
	// combination is 6 7 13, the player is transported to the basement
	if (this->getShelfLocked() == true) {
		int c1;
		int c2;
		int c3;

		std::cout << "\nThere is a combination lock to the shelf.  You can" << std::endl;
		std::cout << "turn the lock left, right, and then left a certain" << std::endl;
		std::cout << "number to open the lock." << std::endl;
		std::cout << " 1) Left: 10, Right: 16, Left 13" << std::endl;
		std::cout << " 2) Left:  6, Right:  7, Left 13" << std::endl;
		std::cout << " 3) Left:  7, Right: 13, Left 10" << std::endl;
		std::cout << " 4) Left: 13, Right:  6, Left 16" << std::endl;
		
		int lock;
		std::cout << "\nWhich combination will you choose (1 - 4)? ";
		std::cin  >> lock;
		std::cin.ignore();
	
		if (lock == 1) {
			this->setShelfLocked(false);
			
			std::cout << "\nThe combination is correct!  Inside the shelf is a" << std::endl;
			std::cout << "Holy Cross with a note attached.  The note reads: " << std::endl;
			std::cout << "     \"He who holds the Holiest of Crosses shall gain" << std::endl;
			std::cout << "      access to the hidden Void..." << std::endl;
			std::cout << "\nWill you take the Holy Cross (1 = yes, 0 = no)? ";
			int takeCross;
			std::cin  >> takeCross;
			std::cin.ignore();

			if (takeCross == 1) {
				if (pOccupy->isFull() == false) this->setCrossTaken(true);
				pOccupy->addItem("Holy Cross");
			}

			this->exploreRoom();
		} else if (lock == 2) {
			std::cout << "\nYou will be moved to the basement!" << std::endl;

			pOccupy->incrNumMoves();
			Player *p = pOccupy;
		 	pOccupy = NULL;
			door4->enterRoom(p);
		} else if (lock == 3 || lock == 4) {
			std::cout << "\nYou did not get the correct combination!" << std::endl;

			this->exploreRoom();
		} else {
			this->exploreRoom();
		}
	// If shelf has been unlocked, display the note, and let the player
	// take the cross if it hasn't been taken
	} else {
		std::cout << "\nInside the shelf is a note which reads: " << std::endl;
		std::cout << "     \"He who holds the Holiest of Crosses shall gain" << std::endl;
		std::cout << "      access to the hidden Void..." << std::endl;

		if (this->getCrossTaken() == false) {
			std::cout << "\nWill you take the Holy Cross (1 = yes, 0 = no)? ";
			int takeCross;
			std::cin  >> takeCross;
			std::cin.ignore();

			if (takeCross == 1) {
				if (pOccupy->isFull() == false) this->setCrossTaken(true);
				pOccupy->addItem("Holy Cross");
			}
			
			this->setShelfLocked(false);
		}

		this->exploreRoom();
	}
}

// Getters/Setters
void Kitchen::setWindowBroken(bool w)
{	windowBroken = w; }
bool Kitchen::getWindowBroken()
{	return windowBroken; }
void Kitchen::setShelfLocked(bool s)
{	shelfLocked = s; }
bool Kitchen::getShelfLocked()
{	return shelfLocked; }
void Kitchen::setCrossTaken(bool c)
{	crossTaken = c; }
bool Kitchen::getCrossTaken()
{	return crossTaken; }