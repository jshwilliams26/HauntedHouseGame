/****************************************
** Name: Josh Williams
** Description: main program file
** This will welcome the player to the game,
** create a HauntedHouse object, and begin
** the game.
****************************************/
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
#include "HauntedHouse.hpp"

int main() {
	std::system("clear");
	
	// Welcome the game, explain the goal.
	std::cout << "Welcome to the Haunted House Game!" << std::endl;
	std::cout << "The builder of this house was cursed and devoured by" << std::endl;
	std::cout << "the devil.  His cursed skull can be found inside the" << std::endl;
	std::cout << "house. The player's goal will be to find the cursed" << std::endl;
	std::cout << "skull and return it to the altar to break the devil's " << std::endl;
	std::cout << "hold on the house.  The player can only hold 3 items" << std::endl;
	std::cout << "in their bag.  You may only enter a room (move)" << std::endl;
	std::cout << "50 times, those who linger in the devil's house too" << std::endl;
	std::cout << "long will be devoured..." << std::endl;
	
	srand(time(0));
	
	HauntedHouse h;	// Haunted House object
	
	h.beginGame(); 	// begin the game

	return 0;
}