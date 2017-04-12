/**********************************************
** Name: Josh Williams
** Description: Space class implementation file
** This is an abstract class that is the base
** for different room/space classes that will
** make up the Haunted House.  There are 4
** space pointers for 4 doors, the room will
** have a name, and there will be a pointer to
** a player (it will be NULL if the player
** isn't in the room, and will point to a
** player if the player is in the room). There
** are functions to enter, explore, and exit
** the room.  There is also a pure virtual
** function (Special) that will be individually
** defined for each derived space class and
** will do something unique for that class.
**********************************************/
#include <iostream>
#include <cstddef>
#include <cstdlib>

#include "Space.hpp"
#include "Player.hpp"

// Destructor
Space::~Space() { };

// Set the doors to a particular space/derived space
void Space::setDoor1(Space *s)
{	door1 = s; }
void Space::setDoor2(Space *s)
{	door2 = s; }
void Space::setDoor3(Space *s)
{	door3 = s; }
void Space::setDoor4(Space *s)
{	door4 = s; }

// ******************* enterRoom ********************
// Enter room (make pOccupy point to a player object)
// This function will kill the player if the player
// has made too many moves.
// **************************************************
void Space::enterRoom(Player *p) {
	pOccupy = p;
	
	// Announce that player has entered the room/space
	std::cout << "\n\n" << pOccupy->getName() << " is in the space \"" << this->getRoomName() << "\"." << std::endl;
	std::cout << pOccupy->getName() << " has made " << pOccupy->getNumMoves() << " move(s)." << std::endl;

	// The player will not be alive if the player has made more than 50 moves
	if (pOccupy->getNumMoves() > 50) pOccupy->setAlive(false);

	// The game ends when the player is no longer alive.
	if (pOccupy->getAlive() == false) {
		std::cout << std::endl;
		std::cout << pOccupy->getName() << " has lingered for too long..." << std::endl;
		std::cout << "   ...the devil comes and devours " << pOccupy->getName() << "!!!!" << std::endl << std::endl;
		std::cout << pOccupy->getName() << " has died!" << std::endl << std::endl;
		std::cout << "GAME OVER!!!!!!!!!!!!!!!!!!!!" << std::endl << std::endl;
		
		pOccupy = NULL;
	} else {
		// If the player is alive in the room, explore the room	
		this->exploreRoom();
	}
}

// **************** exploreRoom ******************
// Explore the room
// ***********************************************
void Space::exploreRoom() { }

// **************** exitRoom ******************
// Exit room (make pOccupy NULL)
// ********************************************
void Space::exitRoom() {
	pOccupy = NULL;
}

// Getters/Setters
void Space::setRoomName(std::string rn)
{	roomName = rn; }
std::string Space::getRoomName()
{	return roomName; }