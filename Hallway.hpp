/**********************************************
** Description: Hallway class specification file
** Once the player enters the Hallway from the
** outside, the door to the outside will be locked
** until the player has the cursed skull.  There
** is also a desk with a flashlight in it.  There
** is also a crack near the floor that can be
** kicked, and if opened up, can lead to the basement.
**********************************************/
#ifndef HALLWAY_HPP
#define HALLWAY_HPP

#include <cstddef>

#include "Space.hpp"
#include "Basement.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
#include "Outside.hpp"
#include "SecretBasement.hpp"
#include "Player.hpp"

class Hallway : public Space{
protected:
	bool floorCrackOpened;	// Determines if the crack in the wall has been opened.
	bool flashlightTaken;	// was flashlight taken

public:
	Hallway() {
		setRoomName("Hallway");
		setFlashlightTaken(false);
		setFloorCrackOpened(false);	// Determines if crack in wall has been opened
	}
	virtual ~Hallway();
	void Special();
	virtual void exploreRoom();
	// Exit hallway (make pOccupy NULL)
	virtual void exitRoom();
	// Getters/Setters
	void setFloorCrackOpened(bool w);
	bool getFloorCrackOpened();
	void setFlashlightTaken(bool f);
	bool getFlashlightTaken();
};

#endif