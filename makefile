
CXX=g++ 
CXXFLAGS=-std=c++11 -Wall
OBJECTS = Card.cpp Deck.cpp Player.cpp Pokerplayer.cpp Pokergame.cpp
MAIN = main.cpp
TEST = test/test_player.cpp
EXE = poker

all: 
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(MAIN) -o $(EXE)

testplayer:
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(TEST) -o $(EXE)

clean:
	rm -f poker

run: $(EXE)
	./$(EXE)

.PHONY: all run
