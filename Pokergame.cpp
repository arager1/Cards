#include "Pokergame.h"


Pokergame::Pokergame() {
	deck = new Deck();
	deck->load52();
	deck->shuffle();
}

Pokergame::~Pokergame() {
	delete deck;
}

void Pokergame::addPlayer(std::string name, int buyIn) {
	if (validName(name)) players.push_back(Pokerplayer(name, buyIn));
}

static bool playerCompare(Pokerplayer &p1, Pokerplayer &p2) { return p1 > p2; }

void Pokergame::deal(int num) {
	if (num * players.size() > deck->size()) return;
	for (int i = 0; i < num; i++) {
		for (auto it = players.begin(); it != players.end(); it++) it->draw(deck);
	}
	std::sort (players.begin(), players.end(), playerCompare);
}

void Pokergame::dealAll(int num){
	if (num > deck->size()) return;
	for (int i = 0; i < num; i++) {
		// Card c = deck->deal();
		// community.push_back(c);
		// for (auto it = players.begin(); it != players.end(); it++) it->addCard(c);
	}
	std::sort (players.begin(), players.end(), playerCompare);
}

void Pokergame::print() { for (auto it : players) it.printHand(); }

void Pokergame::printMin() { for (auto it : players) it.printHandMin(); }

bool Pokergame::validName(std::string name) {
	if (name == "" or name.size() > 16) return false;
	for (auto it : players) if (name == it.getName()) return false;
	return true;
}