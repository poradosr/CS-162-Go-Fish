#ifndef deck_h
#define deck_h
#include <iostream>
#include <string>
#include <cstdlib>
#include "card.h"

using namespace std;

class Deck {
private: 
    Card deck[52]; // a deck full of cards
    int cards_remaining; // number of cards remaining in deck

public:
    Deck(); // default constructor 
    ~Deck(); // destructor

    // getters
    Card get_deck(int card_number) const;
    int get_cards_remaining();

    // setters
    void set_deck();
    void set_cards_remaining();

    void shuffle_deck();
    Card& remove_a_card();
    void print_deck();

};

#endif