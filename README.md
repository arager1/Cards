# Cards
## Simulation of a deck of cards with poker-playing functionality
###### Usage
1. Open command terminal
2. Run `make`
3. Run `./poker`
###### Example Output
```
			Community Cards
			===============
			Queen of Clubs
			Eight of Diamonds
			Ten of Clubs
			Four of Diamonds
			Nine of Diamonds
			===============

	Nick's Hand			Poker Hand
	===============			===============
	Queen of Diamonds    		Queen of Clubs
	Jack of Clubs    		Jack of Clubs
	===============    		Ten of Clubs
	===============    		Nine of Diamonds
	===============    		Eight of Diamonds
	===============    		===============

	Nick has a Queen high Straight


	Alec's Hand			Poker Hand
	===============			===============
	Queen of Spades    		Queen of Spades
	Three of Spades    		Queen of Clubs
	===============    		Ten of Clubs
	===============    		Nine of Diamonds
	===============    		Eight of Diamonds
	===============    		===============

	Alec has a Pair of Queens


	Danielle's Hand			Poker Hand
	===============			===============
	King of Diamonds    		King of Diamonds
	Five of Spades    		Queen of Clubs
	===============    		Ten of Clubs
	===============    		Nine of Diamonds
	===============    		Eight of Diamonds
	===============    		===============

	Danielle has a King High Card


	Logan's Hand			Poker Hand
	===============			===============
	Three of Diamonds    		Queen of Clubs
	Two of Hearts    		Ten of Clubs
	===============    		Nine of Diamonds
	===============    		Eight of Diamonds
	===============    		Four of Diamonds
	===============    		===============

	Logan has a Queen High Card
```
###### Testing
1. Open command terminal
2. Run `make testplayer`
3. Run `./poker`
###### Example Output
```
	High Kicker :   	Success!
	Straight and Pair :   	Success!
	Two Three Kinds :   	Success!
	Three pairs :   	Success!
	Six Straight :   	Success!
	Ace-Low straight :   	Success!
```