#include <iostream>
#include <string>
#include "card.h"

using namespace std;

/******************************************************************
 * Function: Card()
 * Description: Default Card constructor that sets both private variables to 0
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: The private variables are initialized
******************************************************************/
Card::Card() {
    this->rank = 0;
    this->suit = 0;
} 

/******************************************************************
 * Function: Card(int, int)
 * Description: Parametized constructor. Creates a card with a certain rank and suit
 * Parameters: int r, int s
 * Pre-Conditions: Parameters are integers renk (0-12) and suit (0-3)
 * Post-Conditions: The constructed card has a corresponding value for rank and suit
******************************************************************/
Card::Card(int r, int s) {
    this->rank = r;
    this->suit = s;
}

/******************************************************************
 * Function: ~Card()
 * Description: Default destructor
 * Parameters: None
 * Pre-Conditions: Card has been constructed
 * Post-Conditions: None
******************************************************************/
Card::~Card() {
    
}

/******************************************************************
 * Function: set_rank(int card_number)
 * Description: sets this Card's rank
 * Parameters: int card_number
 * Pre-Conditions: None
 * Post-Conditions: rank is re-assigned to card_number's value
******************************************************************/
void Card::set_rank(int card_number) {
    rank = card_number;
}

/******************************************************************
 * Function: get_rank() const
 * Description: gets this Card's rank
 * Parameters: None
 * Pre-Conditions: rank has been initialized
 * Post-Conditions: rank's value is accessible
******************************************************************/
int Card::get_rank() const {
    return rank;
}

/******************************************************************
 * Function: setsuit(int card_symbol)
 * Description: sets this Card's suit
 * Parameters: int card_symbol
 * Pre-Conditions: None
 * Post-Conditions: suit is re-assigned to card_symbol's value
******************************************************************/
void Card::set_suit(int card_symbol) {
    suit = card_symbol;
}

/******************************************************************
 * Function: get_suit() const
 * Description: gets this Card's suit
 * Parameters: None
 * Pre-Conditions: suit has been initialized
 * Post-Conditions: suit's value is accessible
******************************************************************/
int Card::get_suit() {
    return suit;
}

/******************************************************************
 * Function: map_suit() 
 * Description: converts the integer of the suit to the corresponding string
 * Parameters: None
 * Pre-Conditions: suit has been initialized
 * Post-Conditions: suit's value is accessible
******************************************************************/
string Card::map_suit() { //convert the int suit to corresponding string 
    string card_symbol_array[4] = {"Diamond", "Spade", "Clubs", "Heart"};
    return card_symbol_array[this->suit];
} 

/******************************************************************
 * Function: map_rank() 
 * Description: converts the integer of the rank to the corresponding string
 * Parameters: None
 * Pre-Conditions: rank has been initialized
 * Post-Conditions: rank's value is accessible
******************************************************************/
string Card::map_rank() { //convert the int rank to corresponding string 
    string card_number_array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    return card_number_array[this->rank];
} 

/******************************************************************
 * Function: print_card() 
 * Description: prints out the suit and rank of a card 
 * Parameters: None
 * Pre-Conditions: rank and suit have been initialized and their values converted to strings
 * Post-Conditions: rank's and suit's values are accessible
******************************************************************/
void Card::print_card() { 
    cout << map_suit() << " ";
    cout << map_rank();
} 