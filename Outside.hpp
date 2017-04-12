/**********************************************
** Description: Outside class specification file
** This will define an Outside class.  The
** player will have the option to explore a
** shack, a garden, to enter through the main
** door, and to enter through the ground level
** window.  The player can enter the basement 
** through the window, but cannot return to the
** outside that way, because the window is too
** high from the ground inside the basement.
** The player can find a shovel in the garden.
**********************************************/
#ifndef OUTSIDE_HPP
#define OUTSIDE_HPP

#include <cstddef>

#include "Space.hpp"
#include "Basement.hpp"
#include "Hallway.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
#include "SecretBasement.hpp"
#include "Player.hpp"

class Outside : public Space{
protected:
	bool shovelTaken;	// Indicates if the shovel has been taken or not

public:
	Outside() {
		setRoomName("Outside");
		setShovelTaken(false);	// The shovel should not be taken initially
	}
	virtual ~Outside();
	void Special();
	virtual void exploreRoom();
	// Getters/setters
	void setShovelTaken(bool s);
	bool getShovelTaken();
};

#endif