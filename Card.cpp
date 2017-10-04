#include "Card.h"

Card::Card(Rank r, Suit s) {
	if (r >= Two and r <= Ace and s >= Spades and s <= Diamonds){
		rank = r;
		suit = s;
	}
}

bool Card::operator>(const Card &rhs) const {
	if (rank == rhs.getRank()) return suit < rhs.getSuit();
	else return rank > rhs.getRank();
}

bool Card::operator<(const Card &rhs) const {
	if (rank == rhs.getRank()) return suit > rhs.getSuit();
	else return rank < rhs.getRank();
}

bool Card::operator==(const Card &rhs) const {
	return (rank == rhs.getRank() and suit == rhs.getSuit());
}

Card &Card::operator=(const Card &rhs){
	rank = rhs.getRank();
	suit = rhs.getSuit();
	return *this;
}

Rank Card::getRank() const {
	return rank;
}
Suit Card::getSuit() const {
	return suit;
}

std::string Card::cardString() const {
	return rankString[rank] + " of " + suitString[suit];
}

std::string Card::cardStringMin() const {
	return rankStringMin[rank] + suitStringMin[suit];
}