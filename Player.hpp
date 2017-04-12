/**********************************************
** Name: Josh Williams
** Description: Player class specification file
** This class will define a player with a name,
** an item bag, and an alive or dead status.
** There are functions to add and remove items
** from the bag, as well as to display the
** contents of the bag and search the bag for
** an item.
**********************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>

class Player{
protected:
	bool alive;	// If player is alive or dead
	int numMoves;	// number of moves for a player
	std::string name;	// Player name
	std::vector <std::string> itemBag;	// Item bag

public:
	Player(std::string n);	// Constructor
	void addItem(std::string i);	// Add an item to the item bag
	void removeItem();	// Remove an item from the item bag
	void displayItemBag();	// Display the contents of the item bag
	bool searchItemBag(std::string item);	// Search the item bag for an item
	bool isFull();	// Indicates if the item bag is full

	// Getters/Setters
	void setAlive(bool a);
	bool getAlive();
	void setName(std::string n);
	std::string getName();
	void setNumMoves(int n);
	int getNumMoves();
	void incrNumMoves();	// Increments the number of moves by 1
};

#endif