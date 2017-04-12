/**********************************************
** Name: Josh Williams
** Description: Basement class specification file
** The player will die from entering the basement
** without a light.  There is a hole in the basement
** that the player can jump down and return to the
** outside.  There is a door without a handle that
** requires a chant to be made to open the door.
** The incorrect chant will transport the player
** to a different room.  The correct chant will
** open the door if the player has the Holy Cross,
** otherwise the door cannot be opened.
**********************************************/
#ifndef BASEMENT_HPP
#define BASEMENT_HPP

#include <cstddef>

#include "Space.hpp"
#include "Hallway.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
#include "Outside.hpp"
#include "SecretBasement.hpp"
#include "Player.hpp"

class Basement : public Space{
protected:
	bool doorOpened;	// If the door to the secret room has been opened or not

public:
	Basement() {
		setRoomName("Basement");
		setDoorOpened(false);	// The door should not be opened at first
	}
	virtual ~Basement();
	void Special();
	virtual void exploreRoom();
	// Exit basement (make pOccupy NULL)
	virtual void exitRoom();
	void setDoorOpened(bool d);
	bool getDoorOpened();
};

#endif