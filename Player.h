#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"

class Player {
public:
	// Initialize Player
	Player(std::string n);

	// Add or remove Cards
	void draw(Deck *d);
	virtual void addCard(Card c);
	virtual void clearHand();

	// Player information
	std::string getName();
	int handSize();
	virtual void printHand();

	std::vector<Card> hand;
	
protected:
	std::string name;
};

#endif