/**********************************************
** Description: Player class implementation file
** This class will define a player with a name,
** an item bag, and an alive or dead status.
** There are functions to add and remove items
** from the bag, as well as to display the
** contents of the bag and search the bag for
** an item.
**********************************************/
#include "Player.hpp"
#include <iostream>

// Constructor
Player::Player(std::string n) {
	setName(n);
	setAlive(true);
	setNumMoves(0);
}

// *************** addItem ******************
// Adds an item to itemBag if there are less
// than 5 items in the bag.
// ******************************************
void Player::addItem(std::string i) {
	if (itemBag.size() < 3) {
		itemBag.push_back(i);
		std::cout << "\nItem \"" << i << "\" added to you bag!" << std::endl;
	} else {
		std::cout << "\nThe item bag is full!" << std::endl;
		this->removeItem();
	}
}

// ************* removeItem *****************
// Displays the items in the bag and gives
// the user the choice of which item to
// remove.
// ******************************************
void Player::removeItem() {
	std::cout << "Remove an item from your bag (1 = yes, 0 = no)? ";
	int rem;
	std::cin  >> rem;
	std::cin.ignore();

	if (rem == 1) {
		// Show the contents of the item bag
		this->displayItemBag();
		// Since the items are listed 1 - 5, enter the number
		// for the item to be removed
		int item;
		std::cout << "\nIndicate the number of the item to remove: ";
		std::cin  >> item;
		// Validate that the input is 1 - 5
		while (item < 1 || item > 3) {
			std::cout << "Please enter a number 1 - 3! ";
			std::cin >> item;
		}
		item--;	// Decrement by 1 to use the number as an index to the vector

		if (item >= 0 && item < 3) itemBag.erase(itemBag.begin()+item);
	}
}

// ************** isFull ******************
// Indicate if the item bag is full or not
// ****************************************
bool Player::isFull() {
	if (itemBag.size() >= 3) return true; // Shouldn't ever be greater than 3, but just in case...
	else return false;
}


// ************ displayItemBag **************
// Displays the contents of the bag.
// ******************************************
void Player::displayItemBag() {
	std::cout << "\nHere are the items in your bag:" << std::endl;
	for (int i = 0; i < itemBag.size(); i++) {
		std::cout << " " << i+1 << ") " << itemBag[i] << std::endl;
	}
	std::cout << std::endl;
}

// ************* searchItemBag **************
// Search the bag for an item.
// ******************************************
bool Player::searchItemBag(std::string item) {
	bool found = false;
	
	for (int i = 0; i < itemBag.size(); i++) {
		if (itemBag[i] == item) found = true;
	}
	
	return found;
}

// Getters/Setters
void Player::setName(std::string n)
{	name = n; }
std::string Player::getName()
{	return name; }
void Player::setAlive(bool a)
{	alive = a; }
bool Player::getAlive()
{	return alive; }
void Player::setNumMoves(int n)
{	numMoves = n; }
int Player::getNumMoves()
{	return numMoves; }
void Player::incrNumMoves()	// Increments the number of moves by 1
{	numMoves++; }