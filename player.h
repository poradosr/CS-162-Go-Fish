#ifndef player_h
#define player_h
#include <iostream>
#include <string>
#include "hand.h"

using namespace std;

class Player {
private:
    Hand hand; // the hand of a single player
    int* books; // Array with ranks for which the player has books
    int n_books; // number of books a single player has

public:
    Player(); // default constructor 
    Player (int size);
    Player(const Player &); // copy constructor
    Player& operator=(const Player&); // assignment operator overload
    ~Player(); // destructor

    // getters
    Hand get_hand();
    int* get_books();
    int get_n_books();

    // setters
    void set_hand(const Hand&);
    void set_books(int, int);
    void set_n_books();
    void remove_book(int);
    void allocate_memory_books(int);
    void place_a_card(Card&); 
    int has_rank(int rank);
    void add_card_to_hand(Card&);
    void remove_card_from_hand(Card&);
    Card random_card_cheat();
};

#endif