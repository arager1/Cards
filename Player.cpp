#include "Player.h"
#include <iostream>
#include <algorithm>



Player::Player(std::string n) : name(n) {}

void Player::draw(Deck *d){
	if (d->size() > 0) addCard(d->deal());
}

void Player::addCard(Card c){
	hand.push_back(c);
}

void Player::clearHand(){
	hand.clear();
}

int Player::handSize(){
	return hand.size();
}

std::string Player::getName(){
	return name;
}

void Player::printHand(){
	std::cout << "\n\t" << name << "'s Hand" << "\n\t===============" << std::endl;
	for (auto it = hand.begin(); it != hand.end(); it++){
		std::cout << "\t" << it->cardString() << std::endl;
	}
	std::cout << "\t===============\n" << std::endl;
}
