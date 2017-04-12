/**********************************************
** Description: Secret Basement class specification file
** The secret basement will have a number of
** spots on the ground to dig, one of them has
** the cursed skull.  The others lead to different
** parts of the house.  If the player does not
** have the shovel, they cannot do anything
** in the secret basement.
**********************************************/
#ifndef SECRETBASEMENT_HPP
#define SECRETBASEMENT_HPP

#include <cstddef>

#include "Space.hpp"
#include "Basement.hpp"
#include "Hallway.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
#include "Outside.hpp"
#include "Player.hpp"

class SecretBasement : public Space{
protected:
	bool skullFound;	

public:
	SecretBasement() {
		setSkullFound(false);
		setRoomName("Secret Basement");
	}
	virtual ~SecretBasement();
	virtual void exploreRoom();
	void Special();
	// Exit secret basement (make pOccupy NULL)
	virtual void exitRoom();
	// Getters/Setters
	void setSkullFound(bool s);
	bool getSkullFound();
};

#endif