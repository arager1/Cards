#include "Pokergame.h"
#include <iostream>


int main(){

	Pokergame game;

	game.addPlayer("Alec", 10000);
	game.addPlayer("Nick", 10000);
	game.addPlayer("Danielle", 10000);
	game.addPlayer("Logan", 10000);

	// game.deal(7);
	game.deal(2);
	game.burn(1);
	game.dealUp(3);
	game.burn(1);
	game.dealUp(1);
	game.burn(1);
	game.dealUp(1);


	game.print();

}
