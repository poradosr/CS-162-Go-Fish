#ifndef hand_h
#define hand_h
#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"

using namespace std;

class Hand {
private:
    Card* cards; // An array of cards in hand
    int n_cards; // Number of cards in the hand

public:
    Hand(); // default constructor 
    Hand(const Hand&); // copy constructor
    ~Hand(); // destructor
    Hand& operator=(const Hand&); // assignment operator overload

    // getters
    Card* get_cards();
    int get_n_cards();

    // setters
    void set_cards(Deck&);
    void set_n_cards();

    void add_card_to_hand(Card&);
    void remove_card_from_hand(Card&);
    int has_rank(int);
    bool book_exists(int);
    Card random_card_cheat();
    bool in_hand(int);
};

#endif