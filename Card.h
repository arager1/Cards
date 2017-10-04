#ifndef CARD_H
#define CARD_H

#include <string>

enum Rank { Two=2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};
enum Suit { Spades, Hearts, Clubs, Diamonds};

static const std::string rankString[] = { "Joker", "Joker", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
static const std::string suitString[] = { "Spades", "Hearts", "Clubs", "Diamonds" };

static const std::string rankStringMin[] = { "0", "0", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" };
static const std::string suitStringMin[] = { "S", "H", "C", "D" };

class Card {
public:
	// Initialize Card
	Card(Rank r, Suit s);
	
	// Card information
	Rank getRank() const;
	Suit getSuit() const;
	std::string cardString() const;
	std::string cardStringMin() const;

	// Operator overloads
	bool operator>(const Card &rhs) const;
	bool operator<(const Card &rhs) const;
	bool operator==(const Card &rhs) const;
	Card &operator=(const Card &rhs);

private:
	Rank rank;
	Suit suit;
};

#endif