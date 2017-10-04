#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
	// Initialize Deck
	Deck();
	void addCard(Rank r, Suit s);
	void load52();
	void loadEuchre();

	// Main Deck functions
	void shuffle();
	Card deal();
	void dealAll();

	// Clean-up functions
	void reset();
	void clear();

	// Deck information
	int size();
	void print();

private:
	std::vector<Card> deck;
	std::vector<Card>::iterator next;
	std::vector<Card> community;
};

#endif