/**********************************************
** Name: Josh Williams
** Description: Living Room class specification file
** In the living room, the player can exit the
** room, examine the bookshelf, and examine
** the window and break it.  The bookshelf will
** have books with hints at how to play the game.
**********************************************/
#ifndef LIVINGROOM_HPP
#define LIVINGROOM_HPP

#include <cstddef>

#include "Space.hpp"
#include "Basement.hpp"
#include "Hallway.hpp"
#include "Kitchen.hpp"
#include "Outside.hpp"
#include "SecretBasement.hpp"
#include "Player.hpp"

class LivingRoom : public Space{
protected:
	bool windowBroken;	// Indicate if the window has been broken

public:
	LivingRoom() {
		setWindowBroken(false);	// The window should not be broken at first
		setRoomName("Living Room");
	}
	virtual ~LivingRoom();
	void Special();
	virtual void exploreRoom();
	virtual void exitRoom();
	// Getters/Setters
	void setWindowBroken(bool w);
	bool getWindowBroken();
};

#endif