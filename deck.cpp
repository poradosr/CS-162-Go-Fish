#include "deck.h"

using namespace std;

/******************************************************************
 * Function: Deck()
 * Description: Default contructor. Constructs a deck of 52 cards with each card corresponding to a differenrt suit and rank combination
 * Parameters: None
 * Pre-Conditions: rank and suit are accessible
 * Post-Conditions: Each rank and suit of a card correspond to an integer and not a string
******************************************************************/
Deck::Deck() {
    //Deck constructor 
    this->cards_remaining = 52;
    int deck_num = 0;
    for (int i=0; i < 4; ++i) {
        for(int j=0; j < 13; ++j) {
            deck[deck_num].set_rank(j);
            deck[deck_num].set_suit(i);
            deck_num++;
        }
    }

} 

/******************************************************************
 * Function: ~Deck()
 * Description: Default destructor
 * Parameters: None
 * Pre-Conditions: Deck has been constructed
 * Post-Conditions: None
******************************************************************/
Deck::~Deck() {  

}

/******************************************************************
 * Function: set_deck()
 * Description: creates a deck of 52 cards with each card corresponding to a differenrt suit and rank combination
 * Parameters: None
 * Pre-Conditions: deck has been initialized and rank/suit are accessible 
 * Post-Conditions: None
******************************************************************/
void Deck::set_deck() {
    int deck_num = 0;
    for (int i=0; i < 4; ++i) {
        for(int j=0; j < 13; ++j) {
            deck[deck_num].set_rank(j);
            deck[deck_num].set_suit(i);
            deck_num++;
        }
    }

} 

/******************************************************************
 * Function: get_deck(int) const
 * Description: retreives the card located in a certain index of the deck
 * Parameters: int card_number
 * Pre-Conditions: deck has been initialized and populated
 * Post-Conditions: None
******************************************************************/
Card Deck::get_deck(int card_number) const {
    return deck[card_number];
}

/******************************************************************
 * Function: set_cards_remaining()
 * Description: sets the number of cards remaining to the number of elements in the deck
 * Parameters: None
 * Pre-Conditions: deck has been initialized and populated
 * Post-Conditions: None
******************************************************************/
void Deck::set_cards_remaining() {
    cards_remaining = sizeof(deck);
}

/******************************************************************
 * Function: get_cards_remaining() 
 * Description: retreives the number of cards remaining in the deck
 * Parameters: None
 * Pre-Conditions: deck has been initialized and populated
 * Post-Conditions: None
******************************************************************/
int Deck::get_cards_remaining() {
    return cards_remaining;
}

/******************************************************************
 * Function: shuffle_deck() 
 * Description: shuffles the elements of the deck
 * Parameters: None
 * Pre-Conditions: deck has been initialized and populated
 * Post-Conditions: must be called at start of program
******************************************************************/
void Deck::shuffle_deck() {
    srand(time(NULL)); // initialize seed randomly

    for (int i = 0; i < 100; ++i) {
        int card1 = (rand() % (52));
        int card2 = (rand() % (52));
        Card temp = deck[card1];
        deck[card1] = deck[card2];
        deck[card2] = temp;
    }
}

/******************************************************************
 * Function: remove_a_card() 
 * Description: removes a card from the deck
 * Parameters: None
 * Pre-Conditions: cards_remaining has been initialized
 * Post-Conditions: remaining cards left in deck updates and removed card is returned
******************************************************************/
 Card& Deck::remove_a_card() {
    this->cards_remaining--;
    return this->deck[this->cards_remaining];
}

/******************************************************************
 * Function: print_deck() 
 * Description: prints out the elements of the deck
 * Parameters: None
 * Pre-Conditions: rank and suit have been initialized and their values converted to strings
 * Post-Conditions: rank's and suit's values are accessible
******************************************************************/
void Deck::print_deck() {
    for (int i = 0; i < this->cards_remaining; i++) {
        cout << this->deck[i].map_rank() << " of " << this->deck[i].map_suit() << endl;
    }
}