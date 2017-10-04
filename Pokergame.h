#include "Pokerplayer.h"
#include <vector>
#include <string>

class Pokergame {
public:
	// Initialize game with players
	Pokergame();
	~Pokergame();
	void addPlayer(std::string name, int buyIn);

	// Deal num unique cards to each player
	void deal(int num);

	// Add num cards to community cards
	void dealUp(int num);

	// Discard num cards from deck
	void burn(int num);

	// Pokergame information
	void print();
	void printMin();

private:
	bool validName(std::string name);
	std::vector<Pokerplayer> players;
	Deck *deck;
};