# simple makefile
# define target dependencies and files
pokemonapp: pokemonapp.o deck.o card.o cardDatabase.o
	g++ -o pokemonapp pokemonapp.o deck.o card.o cardDatabase.o
# define how each object file is to be built
pokemonapp.o: pokemonapp.cpp deck.h
	g++ -c pokemonapp.cpp -Wall -Wextra -Wpedantic -std=c++11
deck.o: deck.cpp deck.h
	g++ -c deck.cpp -Wall -Wextra -Wpedantic -std=c++11
card.o: card.cpp card.h
	g++ -c card.cpp -Wall -Wextra -Wpedantic -std=c++11
cardDatabase.o: cardDatabase.cpp cardDatabase.h
	g++ -c cardDatabase.cpp -Wall -Wextra -Wpedantic -std=c++11
# clean up
clean:
	rm -f pokemonapp *.o