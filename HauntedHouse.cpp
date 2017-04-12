/**********************************************
** Description: Haunted House implementation file
** This class defines a haunted house, and it
** instantiates different space objects and links
** them together.  There is a function to begin
** the game and construct the house (link the
** spaces/rooms together).
**********************************************/
#include <cstddef>
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

// Set the door pointers for each space object so that
// the rooms can be connected
void HauntedHouse::constructHouse() {
	// Basement door pointers
	b->setDoor1(o);
	b->setDoor2(k);
	b->setDoor3(l);
	b->setDoor4(s);
	
	// Hallway door pointers
	h->setDoor1(k);
	h->setDoor2(l);
	h->setDoor3(o);
	h->setDoor4(b);
	
	// Kitchen door pointers
	k->setDoor1(h);
	k->setDoor2(l);
	k->setDoor3(o);
	k->setDoor4(b);
	
	// Living room door pointers
	l->setDoor1(h);
	l->setDoor2(k);
	l->setDoor3(o);
	l->setDoor4(b);

	// Outside door pointers
	o->setDoor1(h);
	o->setDoor2(b);
	o->setDoor3(k);
	o->setDoor4(l);
	
	// Secret basement door pointers
	s->setDoor1(b);
	s->setDoor2(k);
	s->setDoor3(h);
	s->setDoor4(l);
}

// Start the game, the user will begin from the outside
void HauntedHouse::beginGame() {
	std::string nm;
	std::cout << "\nWhat will be the player's name? ";
	std::getline(std::cin, nm);
	p = new Player(nm);
	
	// The game will start at the outside.
	o->enterRoom(p);
}