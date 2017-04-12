/**********************************************
** Name: Josh Williams
** Description: Space class specification file
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
#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <cstddef>
#include <cstdlib>

#include "Player.hpp"

class Space{
protected:
	// Pointers to 4 doors
	Space *door1;
	Space *door2;
	Space *door3;
	Space *door4;
	std::string roomName;	// The name of the room
	Player * pOccupy;	// Points to a player occupying a room
						// Should be NULL if there isn't a player
						// in the room

public:
	// Constructor
	Space() {
		door1 = NULL;
		door2 = NULL;
		door3 = NULL;
		door4 = NULL;
		pOccupy = NULL;
	}
	// Destructor
	virtual ~Space();
	// Set the doors to point to a space
	void setDoor1(Space *s);
	void setDoor2(Space *s);
	void setDoor3(Space *s);
	void setDoor4(Space *s);
	
	// Enter room (make pOccupy point to a player object)
	virtual void enterRoom(Player *p);
	// Explore the room/space
	virtual void exploreRoom();
	// Exit room (make pOccupy NULL)
	virtual void exitRoom();
	
	// Pure virtual function, this is for features unique
	// to a derived Room class
	virtual void Special() = 0;

	// Getters/setters
	virtual void setRoomName(std::string rn);
	virtual std::string getRoomName();
};

#endif