/**********************************************
** Name: Josh Williams
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
#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <cstddef>

#include "Space.hpp"
#include "Basement.hpp"
#include "Hallway.hpp"
#include "LivingRoom.hpp"
#include "Outside.hpp"
#include "SecretBasement.hpp"
#include "Player.hpp"

class Kitchen : public Space{
protected:
	bool windowBroken;	// Indicates if the window is broken
	bool shelfLocked;	// Indicates if the shelf is locked
	bool crossTaken;

public:
	Kitchen() {
		setWindowBroken(false);	// The window should not be broken at first
		setShelfLocked(true);	// The shelf should be locked at first
		setCrossTaken(false);
		setRoomName("Kitchen");
	}
	virtual ~Kitchen();
	void Special();
	virtual void exploreRoom();
	// Exit kitchen (make pOccupy NULL)
	virtual void exitRoom();
	// Getters/Setters
	void setWindowBroken(bool w);
	bool getWindowBroken();
	void setShelfLocked(bool s);
	bool getShelfLocked();
	void setCrossTaken(bool c);
	bool getCrossTaken();
};

#endif