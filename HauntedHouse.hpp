/**********************************************
** Description: Haunted House specification file
** This class defines a haunted house, and it
** instantiates different space objects and links
** them together.  There is a function to begin
** the game and construct the house (link the
** spaces/rooms together).
**********************************************/
#ifndef HAUNTEDHOUSE_HPP
#define HAUNTEDHOUSE_HPP

#include <cstddef>

#include "Space.hpp"
#include "Basement.hpp"
#include "Hallway.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
#include "Outside.hpp"
#include "SecretBasement.hpp"
#include "Player.hpp"

class HauntedHouse{
protected:
	Space *b;	// basement
	Space *h;	// hallway
	Space *k;	// kitchen
	Space *l;	// living room
	Space *o;	// outside
	Space *s;	// secret basement
	Player *p;

public:
	// Dynamically allocate an object of each room in the house
	HauntedHouse() {
		b = new Basement();
		h = new Hallway();
		k = new Kitchen();
		l = new LivingRoom();
		o = new Outside();
		s = new SecretBasement();
		
		this->constructHouse();
	}

	// Delete the room objects when the game is over
	virtual ~HauntedHouse() {
		delete b;
		delete h;
		delete k;
		delete l;
		delete o;
		delete s;
		delete p;
	}

	// Set all of the pointers for each space/room
	void constructHouse();
	// Begin the game
	void beginGame();
};

#endif