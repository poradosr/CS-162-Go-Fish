#ifndef card_h
#define card_h
#include <iostream>
#include <string>

using namespace std;

class Card {
private:
    int rank;  // range 0-12.
    int suit;  // range 0-3.
public:
    Card(); // default-constructor
    Card(int, int);
    ~Card(); // destructor

    // getters
    int get_rank() const;
    int get_suit();
    
    // setters
    void set_rank(int card_number);
    void set_suit(int card_symbol);

    string map_suit();
    string map_rank();
    void print_card();
};

#endif
