OBJS	= card.o deck.o hand.o player.o game.o driver.o
SOURCE	= card.cpp deck.cpp hand.cpp player.cpp game.cpp driver.cpp
HEADER	= card.h deck.h hand.h player.h game.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

card.o: card.cpp
	$(CC) $(FLAGS) card.cpp 

deck.o: deck.cpp
	$(CC) $(FLAGS) deck.cpp 

hand.o: hand.cpp
	$(CC) $(FLAGS) hand.cpp 

player.o: player.cpp
	$(CC) $(FLAGS) player.cpp 

game.o: game.cpp
	$(CC) $(FLAGS) game.cpp 

driver.o: driver.cpp
	$(CC) $(FLAGS) driver.cpp 


clean:
	rm -f $(OBJS) $(OUT)