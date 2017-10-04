#include "../Pokerplayer.h"
#include <iostream>
#include <assert.h>

void printSuccess(std::string s);

void highKicker(Pokerplayer &p);		// Two pair with pairs lower than kicker
void straightPair(Pokerplayer &p);		// Straight where one card is paired
void twoThrees(Pokerplayer &p);			// Full house where there are two three-of-a-kinds
void threeTwos(Pokerplayer &p);			// Two pair with an extra pair and a high kicker
void sixStraight(Pokerplayer &p); 		// Six card straight
void aceLowStraight(Pokerplayer &p);	// Ace-low straight

int main(){

	Pokerplayer p = Pokerplayer("Alec", 1000);

	highKicker(p);
	straightPair(p);
	twoThrees(p);
	threeTwos(p);
	sixStraight(p);
	aceLowStraight(p);
	
}

void printSuccess(std::string s){
	std::cout << "\t" << s << " :   \tSuccess!" << std::endl;
}

void highKicker(Pokerplayer &p){
	p.addCard(Card(King, Spades));
	p.addCard(Card(Two, Spades));
	p.addCard(Card(Two, Diamonds));
	p.addCard(Card(Four, Clubs));
	p.addCard(Card(Queen, Hearts));
	p.addCard(Card(Seven, Spades));
	p.addCard(Card(Queen, Clubs));
	assert(p.getHand() == TwoPair);
	assert(p.bestHand[0] == Card(Queen, Hearts));
	assert(p.bestHand[1] == Card(Queen, Clubs));
	assert(p.bestHand[2] == Card(Two, Spades));
	assert(p.bestHand[3] == Card(Two, Diamonds));
	assert(p.bestHand[4] == Card(King, Spades));
	p.clearHand();
	printSuccess("High Kicker");
}

void straightPair(Pokerplayer &p){
	p.addCard(Card(King, Spades));
	p.addCard(Card(Ten, Spades));
	p.addCard(Card(Two, Diamonds));
	p.addCard(Card(Jack, Clubs));
	p.addCard(Card(Queen, Hearts));
	p.addCard(Card(Nine, Spades));
	p.addCard(Card(King, Clubs));
	assert(p.getHand() == Straight);
	assert(p.bestHand[0] == Card(King, Spades));
	assert(p.bestHand[1] == Card(Queen, Hearts));
	assert(p.bestHand[2] == Card(Jack, Clubs));
	assert(p.bestHand[3] == Card(Ten, Spades));
	assert(p.bestHand[4] == Card(Nine, Spades));
	p.clearHand();
	printSuccess("Straight and Pair");
}

void twoThrees(Pokerplayer &p){
	p.addCard(Card(King, Spades));
	p.addCard(Card(Nine, Clubs));
	p.addCard(Card(King, Diamonds));
	p.addCard(Card(Jack, Clubs));
	p.addCard(Card(Nine, Hearts));
	p.addCard(Card(Nine, Spades));
	p.addCard(Card(King, Clubs));
	assert(p.getHand() == FullHouse);
	assert(p.bestHand[0] == Card(King, Spades));
	assert(p.bestHand[1] == Card(King, Clubs));
	assert(p.bestHand[2] == Card(King, Diamonds));
	assert(p.bestHand[3] == Card(Nine, Spades));
	assert(p.bestHand[4] == Card(Nine, Hearts));
	p.clearHand();
	printSuccess("Two Three Kinds");
}

void threeTwos(Pokerplayer &p){
	p.addCard(Card(King, Spades));
	p.addCard(Card(King, Hearts));
	p.addCard(Card(Queen, Clubs));
	p.addCard(Card(Jack, Spades));
	p.addCard(Card(Jack, Clubs));
	p.addCard(Card(Six, Hearts));
	p.addCard(Card(Six, Diamonds));
	assert(p.getHand() == TwoPair);
	assert(p.bestHand[0] == Card(King, Spades));
	assert(p.bestHand[1] == Card(King, Hearts));
	assert(p.bestHand[2] == Card(Jack, Spades));
	assert(p.bestHand[3] == Card(Jack, Clubs));
	assert(p.bestHand[4] == Card(Queen, Clubs));
	p.clearHand();
	printSuccess("Three pairs");
}

void sixStraight(Pokerplayer &p){
	p.addCard(Card(King, Spades));
	p.addCard(Card(Queen, Clubs));
	p.addCard(Card(Jack, Diamonds));
	p.addCard(Card(Ten, Clubs));
	p.addCard(Card(Nine, Hearts));
	p.addCard(Card(Eight, Spades));
	p.addCard(Card(Two, Clubs));
	assert(p.getHand() == Straight);
	assert(p.bestHand[0] == Card(King, Spades));
	assert(p.bestHand[1] == Card(Queen, Clubs));
	assert(p.bestHand[2] == Card(Jack, Diamonds));
	assert(p.bestHand[3] == Card(Ten, Clubs));
	assert(p.bestHand[4] == Card(Nine, Hearts));
	p.clearHand();
	printSuccess("Six Straight");
}

void aceLowStraight(Pokerplayer &p){
	p.addCard(Card(Five, Spades));
	p.addCard(Card(Ten, Clubs));
	p.addCard(Card(Three, Diamonds));
	p.addCard(Card(Four, Clubs));
	p.addCard(Card(King, Hearts));
	p.addCard(Card(Two, Spades));
	p.addCard(Card(Ace, Clubs));
	assert(p.getHand() == Straight);
	assert(p.bestHand[0] == Card(Five, Spades));
	assert(p.bestHand[1] == Card(Four, Clubs));
	assert(p.bestHand[2] == Card(Three, Diamonds));
	assert(p.bestHand[3] == Card(Two, Spades));
	assert(p.bestHand[4] == Card(Ace, Clubs));
	p.clearHand();
	printSuccess("Ace-Low straight");
}
