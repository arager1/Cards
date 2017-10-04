#ifndef POKERPLAYER_H
#define POKERPLAYER_H

#include "Player.h"
#include <vector>

const int numRanks = 13 + 2;
const int numSuits = 4;

enum PokerHand {HighCard, Pair, TwoPair, ThreeOfAKind, Straight, Flush, FullHouse, FourOfAKind, StraightFlush};

static const std::string handString[] = { "High Card", "Pair", "Two Pair", "Three of a Kind", "Straight", "Flush", "Full House", "Four of a Kind", "Straight Flush" };

class Pokerplayer : public Player {
public:
	// Initialize Pokerplayer
	Pokerplayer(std::string n, int buyIn);

	// Overload Player's addCard() to call expose()
	void addCard(Card c);

	// Pokerplayer information
	void printHand();
	void printHandMin();
	PokerHand getHand() const;

	// Decrement money by n
	void bet(int n);

	// Clear hand and poker logic variables
	void clearHand();

	// Operator Overloads
	bool operator>(const Pokerplayer &rhs) const;
	bool operator<(const Pokerplayer &rhs) const;
	bool operator==(const Pokerplayer &rhs) const;

	// Best hand up to five cards
	std::vector<Card> bestHand;
	
private:
	int rankbin[numRanks] = {0};
	int suitbin[numSuits] {0};

	std::string handMsg;
	PokerHand pokerhand;

	// Expose new card to poker logic (Fix ugly)
	void expose(Card c);

	int money;
};

#endif