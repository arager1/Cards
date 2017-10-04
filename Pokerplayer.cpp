#include "Pokerplayer.h"
#include <iostream> 
#include <stdlib.h>
#include <fstream>

Pokerplayer::Pokerplayer(std::string n, int buyIn) : Player(n), money(buyIn) { clearHand(); }

void Pokerplayer::addCard(Card c){
	hand.push_back(c);
	expose(c);
}

void Pokerplayer::printHand(){
	std::string line = "";
	auto best_it = bestHand.begin();
	line.append("\n\t" + name + "'s Hand\t\t\tPoker Hand\n\t===============\t\t\t===============");
	std::cout << line << std::endl;
	for (auto it = hand.begin(); it != hand.end(); it++){
		line = "\t" + it->cardString();
		if (best_it != bestHand.end()) {
			line.append("    \t\t" + (*best_it).cardString());
			best_it++;
		}
		else line.append("    \t\t===============");
		std::cout << line << std::endl;
	}
	line = "\t===============    \t\t===============\n\n\t" + handMsg + "\n";
	std::cout << line << std::endl;
}

void Pokerplayer::printHandMin(){
	for (auto it = hand.begin(); it != hand.end(); it++){
		std::cout << it->cardStringMin() << " ";
	}
	std::cout << "\n" << handMsg << std::endl;
}

void Pokerplayer::clearHand(){
	hand.clear();
	bestHand.clear();
	pokerhand = HighCard;
	handMsg = name + " has an empty hand";
	for (int i = 0; i < numRanks; i++) rankbin[i] = 0;
	for (int i = 0; i < numSuits; i++) suitbin[i] = 0;
}

PokerHand Pokerplayer::getHand() const { return pokerhand; }

void Pokerplayer::bet(int n) { if (n <= money) money -= n; }

bool Pokerplayer::operator>(const Pokerplayer &rhs) const{
	if (pokerhand == rhs.getHand()) {
		auto rhs_it = rhs.bestHand.begin();
		for (auto it = bestHand.begin(); it != bestHand.end(); it++){
			if (it->getRank() != rhs_it->getRank()) {
				return it->getRank() > rhs_it->getRank();
			}
			rhs_it++;
		}
		return false;
	}
	else {
		return pokerhand > rhs.getHand();
	}
}

bool Pokerplayer::operator<(const Pokerplayer &rhs) const{
	if (pokerhand == rhs.getHand()) {
		auto rhs_it = rhs.bestHand.begin();
		for (auto it = bestHand.begin(); it != bestHand.end(); it++){
			if (it->getRank() != rhs_it->getRank()) {
				return it->getRank() < rhs_it->getRank();
			}
			rhs_it++;
		}
		return false;
	}
	else {
		return pokerhand < rhs.getHand();
	}
}

bool Pokerplayer::operator==(const Pokerplayer &rhs) const{
	auto rhs_it = rhs.bestHand.begin();
	for (auto it = bestHand.begin(); it != bestHand.end(); it++){
		if (it->getRank() != rhs_it->getRank()) return false;
		rhs_it++;
	}
	return true;
}

void Pokerplayer::expose(Card c){

	std::sort (hand.begin(), hand.end(), std::greater<Card>());
	bestHand.clear();
	handMsg = name + " has a ";

	rankbin[c.getRank() - 2]++;
	suitbin[c.getSuit()]++;

	bool hasStraight = false;
	bool hasFlush = false;
	bool hasStraightFlush = false;
	int numPairs = 0;
	int numThree = 0;
	int numFour = 0;
	int straightCount = 0;

	Rank straightHighRank;
	Suit flushSuit;

	// Expose ranks and suits to hand and set variables to record hand possibilities
	for (int i = 0; i < numRanks; i++){

		if (rankbin[i] == 4) numFour++;
		else if (rankbin[i] == 3) numThree++;
		else if (rankbin[i] == 2) numPairs++;

		if (rankbin[i] > 0) straightCount++;
		else straightCount = 0;

		if (straightCount >= 5) {
			hasStraight = true;
			straightHighRank = Rank(i + 2);
		}

	}

	// Check special case: Ace-low straight
	if (rankbin[0] and rankbin[1] and rankbin[2] and rankbin[3] and rankbin[12] and hasStraight == false) {
		hasStraight = true;
		straightHighRank = Five;
	}

	// Check flush
	for (int i = 0; i < numSuits; i++){
		if (suitbin[i] >= 5){
			hasFlush = true;
			flushSuit = Suit(i);
		}
	}

	// Check straight flush
	if (hasStraight and hasFlush){
		Rank target = straightHighRank;
		bool rankInFlush[5] = {false, false, false, false, false};
		int count = 0;
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (it->getRank() == target){
				if (it->getSuit() == flushSuit and bestHand.size() < 5){
					rankInFlush[count] = true;
					count++;
					bestHand.push_back(*it);
				}
				target = Rank(target - 1);
			}
		}
		hasStraightFlush = true;
		for (int i = 0; i < 5; i++){
			if (rankInFlush[i] == false) {
				hasStraightFlush = false;
				bestHand.clear();
			}
		}
	}

	// Straight flush
	if (hasStraightFlush) {
		pokerhand = StraightFlush;
		if (bestHand.front().getRank() == Ace) handMsg.append("Royal Flush");
		else handMsg.append(rankString[bestHand.front().getRank()] + " high " + handString[StraightFlush]);
	}

	// Four of a Kind
	else if (numFour > 0) {
		pokerhand = FourOfAKind;
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (rankbin[it->getRank() - 2] == 4) bestHand.push_back(*it);
		}
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (rankbin[it->getRank() - 2] != 4 and bestHand.size() < 5) bestHand.push_back(*it);
		}
		handMsg.append(handString[FourOfAKind] + ", four " + rankString[bestHand.front().getRank()] + "s and a " + rankString[bestHand.back().getRank()] + " kicker");
	}

	// Full House
	else if (numThree > 1 or (numThree > 0 and numPairs > 0)) {
		pokerhand = FullHouse;
		Rank threeRank;
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (rankbin[it->getRank() - 2] == 3 and bestHand.size() < 3) {
				bestHand.push_back(*it);
				threeRank = it->getRank();
			}
		}
		for (auto it = hand.begin(); it != hand.end(); it++) {
			if (it->getRank() != threeRank and rankbin[it->getRank() - 2] >= 2 and bestHand.size() < 5) bestHand.push_back(*it);
		}
		handMsg.append(handString[FullHouse] + ", " + rankString[bestHand.front().getRank()] + "s over " + rankString[bestHand.back().getRank()] + "s");
	}

	// Flush
	else if (hasFlush) {
		pokerhand = Flush;
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (it->getSuit() == flushSuit) bestHand.push_back(*it);
		}
		handMsg.append(rankString[bestHand.front().getRank()] + " high " + handString[Flush]);
	}

	// Straight
	else if (hasStraight) {
		pokerhand = Straight;
		Rank target = straightHighRank;
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (it->getRank() == target and bestHand.size() < 5) {
				bestHand.push_back(*it);
				if (target == Two and hand[0].getRank() == Ace) {
					bestHand.push_back(hand[0]);
				}
				else target = Rank(target - 1);
			}
		}
		handMsg.append(rankString[bestHand.front().getRank()]  + " high " + handString[Straight]);
	}

	// Three of a Kind
	else if (numThree > 0) {
		pokerhand = ThreeOfAKind;
		Rank threeRank;
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (rankbin[it->getRank() - 2] == 3) {
				bestHand.push_back(*it);
				threeRank = it->getRank();
			}
		}
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (it->getRank() != threeRank and bestHand.size() < 5) bestHand.push_back(*it);
		}
		handMsg.append(handString[ThreeOfAKind] + ", three " + rankString[bestHand.front().getRank()] + "s and a " + rankString[bestHand.end()[-2].getRank()] + " " + rankString[bestHand.back().getRank()] + " kicker");
	}

	// Two Pair
	else if (numPairs > 1) {
		pokerhand = TwoPair;
		Rank firstRank, secondRank;
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (rankbin[it->getRank() - 2] == 2 and bestHand.size() < 2) {
				bestHand.push_back(*it);
				firstRank = it->getRank();
			}
		}
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (it->getRank() != firstRank and rankbin[it->getRank() - 2] == 2 and bestHand.size() < 4) {
				bestHand.push_back(*it);
				secondRank = it->getRank();
			}
		}
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (it->getRank() != firstRank and it->getRank() != secondRank and bestHand.size() < 5) bestHand.push_back(*it); 
		}
		handMsg.append(handString[TwoPair] + ", " + rankString[bestHand.front().getRank()] + "s over " + rankString[bestHand.end()[-2].getRank()] + "s and a " + rankString[bestHand.back().getRank()] + " kicker");
	}

	// Pair
	else if (numPairs == 1) {
		pokerhand = Pair;
		Rank pairRank;
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (rankbin[it->getRank() - 2] == 2 and bestHand.size() < 2) {
				bestHand.push_back(*it);
				pairRank = it->getRank();
			}
		}
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (it->getRank() != pairRank and bestHand.size() < 5) bestHand.push_back(*it);
		}
		handMsg.append(handString[Pair] + " of " + rankString[bestHand.front().getRank()] + "s");
	}

	// High Card
	else {
		pokerhand = HighCard;
		for (auto it = hand.begin(); it != hand.end(); it++){
			if (bestHand.size() < 5) bestHand.push_back(*it);
		}
		handMsg.append(rankString[bestHand.front().getRank()] + " " + handString[HighCard]);
	}
}

