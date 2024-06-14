CC = g++
CFLAGS = -std=c++17 -Wall
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

all: main

catan: main
	./$^

main: main.o vertex.o edge.o tile.o board.o player.o person.o gameLogic.o deck.o KnightCard.o monopolyCard.o roadBuildingCard.o victoryPointCard.o yearOfPlentyCard.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.cpp vertex.hpp edge.hpp tile.hpp board.hpp player.hpp person.hpp gameLogic.hpp deck.hpp KnightCard.hpp monopolyCard.hpp roadBuildingCard.hpp victoryPointCard.hpp yearOfPlentyCard.hpp
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

# developmentCard.o: developmentCard.cpp developmentCard.hpp
# 	$(CC) $(CFLAGS) -c $<

deck.o: deck.cpp deck.hpp developmentCard.hpp
	$(CC) $(CFLAGS) -c $<

KnightCard.o: KnightCard.cpp KnightCard.hpp developmentCard.hpp
	$(CC) $(CFLAGS) -c $<

monopolyCard.o: monopolyCard.cpp monopolyCard.hpp developmentCard.hpp
	$(CC) $(CFLAGS) -c $<

roadBuildingCard.o: roadBuildingCard.cpp roadBuildingCard.hpp developmentCard.hpp
	$(CC) $(CFLAGS) -c $<

victoryPointCard.o: victoryPointCard.cpp victoryPointCard.hpp developmentCard.hpp
	$(CC) $(CFLAGS) -c $<

yearOfPlentyCard.o: yearOfPlentyCard.cpp yearOfPlentyCard.hpp developmentCard.hpp
	$(CC) $(CFLAGS) -c $<

# valgrind: main
# 	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }

# valgrind: main
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt ./main

valgrind: main
	valgrind --leak-check=full --show-leak-kinds=all ./main

clean:
	rm -f *.o main
