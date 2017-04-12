/******************************************
** Description: Player class test file.
** This will test the Player class's ability
** to add and remove items from the player's
** item bag, as well as to increment the number
** of moves and make the player not alive.
******************************************/
#include "Player.hpp"
#include <iostream>

int main() {
	Player p("Joe");
	
	// Add Items.  A-C should be able to be added without a problem
	// The program should indicate that the bag is full when it tries
	// to add D and E.
	std::cout << "Adding item A" << std::endl;
	p.addItem("A");
	p.displayItemBag();
	std::cout << "Adding item B" << std::endl;
	p.addItem("B");
	p.displayItemBag();
	std::cout << "Adding item C" << std::endl;
	p.addItem("C");
	p.displayItemBag();
	std::cout << "Adding item D" << std::endl;
	p.addItem("D");
	p.displayItemBag();
	std::cout << "Adding item E" << std::endl;
	p.addItem("E");
	p.displayItemBag();
	
	// Indicate if the item bag is full
	p.removeItem();
	p.displayItemBag();
	std::cout << "Testing if the item bag is full..." << std::endl;
	if (p.isFull() == true) std::cout << "The item bag is full!" << std::endl;
	else std::cout << "The item bag is not full!" << std::endl;
	p.displayItemBag();

	// Remove an item and show that it was removed
	p.removeItem();
	p.displayItemBag();

	// Show the number of moves, then increment 3 times, then show the number of moves again
	std::cout << p.getName() << " currently has " << p.getNumMoves() << " moves." << std::endl;

	for (int x = 0; x < 3; x++) {
		std::cout << "Incrementing moves by 1..." << std::endl;
		p.incrNumMoves();
	}

	std::cout << p.getName() << " currently has " << p.getNumMoves() << " moves." << std::endl << std::endl;

	// Show that the player is alive, do something to kill the player, then show that the player is dead
	if (p.getAlive() == true) std::cout << p.getName() << " is currently alive." << std::endl;
	else std::cout << p.getName() << " is dead." << std::endl;

	std::cout << p.getName() << " is attacked!" << std::endl;
	p.setAlive(false);

	if (p.getAlive() == true) std::cout << p.getName() << " is currently alive." << std::endl;
	else std::cout << p.getName() << " is dead." << std::endl;
	
	return 0;
}