#include "Deck.h"
#include "iostream"
#include <random>
#include <algorithm>
#include <ctime>

Deck::Deck() {
	std::srand(time(NULL));
}

void Deck::addCard(Rank r, Suit s){
	Card c(r, s);
	deck.push_back(c);
	next = deck.begin();
}

void Deck::load52() {
	loadEuchre();
	addCard(Eight, Spades);
	addCard(Seven, Spades);
	addCard(Six, Spades);
	addCard(Five, Spades);
	addCard(Four, Spades);
	addCard(Three, Spades);
	addCard(Two, Spades);
	addCard(Eight, Hearts);
	addCard(Seven, Hearts);
	addCard(Six, Hearts);
	addCard(Five, Hearts);
	addCard(Four, Hearts);
	addCard(Three, Hearts);
	addCard(Two, Hearts);
	addCard(Eight, Clubs);
	addCard(Seven, Clubs);
	addCard(Six, Clubs);
	addCard(Five, Clubs);
	addCard(Four, Clubs);
	addCard(Three, Clubs);
	addCard(Two, Clubs);
	addCard(Eight, Diamonds);
	addCard(Seven, Diamonds);
	addCard(Six, Diamonds);
	addCard(Five, Diamonds);
	addCard(Four, Diamonds);
	addCard(Three, Diamonds);
	addCard(Two, Diamonds);
}

void Deck::loadEuchre(){
	addCard(Ace, Spades);
	addCard(King, Spades);
	addCard(Queen, Spades);
	addCard(Jack, Spades);
	addCard(Ten, Spades);
	addCard(Nine, Spades);
	addCard(Ace, Hearts);
	addCard(King, Hearts);
	addCard(Queen, Hearts);
	addCard(Jack, Hearts);
	addCard(Ten, Hearts);
	addCard(Nine, Hearts);
	addCard(Ace, Clubs);
	addCard(King, Clubs);
	addCard(Queen, Clubs);
	addCard(Jack, Clubs);
	addCard(Ten, Clubs);
	addCard(Nine, Clubs);
	addCard(Ace, Diamonds);
	addCard(King, Diamonds);
	addCard(Queen, Diamonds);
	addCard(Jack, Diamonds);
	addCard(Ten, Diamonds);
	addCard(Nine, Diamonds);
}

int randomFunc (int i) { return std::rand()%i; }

void Deck::shuffle() {
	random_shuffle(next, deck.end(), randomFunc);
	next = deck.begin();
}

Card Deck::deal() {
	if (next == deck.end()) reset();
	Card c = *next;
	next++;
	return c;
}

void Deck::dealUp() {
	if (next == deck.end()) reset();
	community.push_back(*next);
	next++;
}

void Deck::burn() {
	if (next == deck.end()) reset();
	discard.push_back(*next);
	next++;
}

void Deck::reset() {
	next = deck.begin();
	community.clear();
	discard.clear();
}

void Deck::clear() { 
	deck.clear();
	community.clear();
	discard.clear();
}

int Deck::size(){ return deck.end() - next; }

void Deck::print(){
	std::cout << "\n\tTop of Deck\n\t===============" << std::endl;
	for (auto &it : deck){
		std::cout << "\t" << it.cardString() << std::endl;
	}
	std::cout << "\n\t===============\n\tBottom of Deck\n" << std::endl;
}
