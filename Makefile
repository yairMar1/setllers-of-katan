CC = g++
CFLAGS = -std=c++11 -Wall

all: main

run: main
	./$^

main: main.o vertex.o edge.o tile.o board.o player.o person.o gameLogic.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.cpp vertex.hpp edge.hpp tile.hpp board.hpp player.hpp person.hpp gameLogic.hpp
	$(CC) $(CFLAGS) -c $<

vertex.o: vertex.cpp vertex.hpp
	$(CC) $(CFLAGS) -c $<

edge.o: edge.cpp edge.hpp vertex.hpp
	$(CC) $(CFLAGS) -c $<

tile.o: tile.cpp tile.hpp vertex.hpp edge.hpp
	$(CC) $(CFLAGS) -c $<

board.o: board.cpp board.hpp
	$(CC) $(CFLAGS) -c $<

player.o: player.cpp player.hpp
	$(CC) $(CFLAGS) -c $<

person.o: person.cpp person.hpp
	$(CC) $(CFLAGS) -c $<

gameLogic.o: gameLogic.cpp gameLogic.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o main
