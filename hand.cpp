#include "hand.h"
#include "card.h"

using namespace std;

/******************************************************************
 * Function: Hand()
 * Description: Class default constructor. Creates a hand object
 * Parameters: None
 * Pre-Conditions: hand object has been initialized
 * Post-Conditions: Must have destructor
******************************************************************/
Hand::Hand() {
    this->cards = NULL;
    this->n_cards = 0;
} 
/******************************************************************
 * Function: ~Hand()
 * Description: Class destructor. deletes memory that was allocated by constructor
 * Parameters: None
 * Pre-Conditions: hand object has been initialized
 * Post-Conditions: No memory leaks
******************************************************************/
Hand::~Hand() {   
    delete [] this->cards;
    this->cards = NULL;
}

/******************************************************************
 * Function: operator=(const Hand&)
 * Description: Operator assignment overload. Deep copies a hand object
 * Parameters: const Hand& h
 * Pre-Conditions: hand object has been initialized and populated
 * Post-Conditions: a second identical hand object is created.
******************************************************************/
Hand& Hand::operator=(const Hand& h) {
    // member-wise copy
    this->n_cards = h.n_cards;

    // free the memory first
    if (this->cards != NULL) { 
        delete [] this->cards;
    }

    // deep copy
    this->cards = new Card [this->n_cards];
    for (int i = 0; i < this-> n_cards; ++i) {
        this->cards[i] = h.cards[i];
    }

    return *this;

}

/******************************************************************
 * Function: Hand(const Hand&)
 * Description: copy constructor
 * Parameters: const Hand& h
 * Pre-Conditions: hand object has been initialized and populated
 * Post-Conditions: a second identical hand object is created without deleting the memory
******************************************************************/
Hand::Hand(const Hand& h) {
    // member-wise copy
    this->n_cards = h.n_cards;

    // deep copy
    this->cards = new Card [this->n_cards];
    for (int i = 0; i < this-> n_cards; ++i) {
        this->cards[i] = h.cards[i];
    }
}
/******************************************************************
 * Function: get_cards()
 * Description: retreives the array of cards in a hand object
 * Parameters: None
 * Pre-Conditions: dynamic memory has been allocated to an array of cards in a players hand and it has been initialized
 * Post-Conditions: None
******************************************************************/
Card* Hand::get_cards() {
    return cards;
}

/******************************************************************
 * Function: set_cards()
 * Description: >????????
 * Parameters: None
 * Pre-Conditions: ????????
 * Post-Conditions: None
******************************************************************/
void Hand::set_cards(Deck& deck) {
    for (int i=0; i < 7; ++i) {
        deck.get_deck(i) = cards[i]; // sets top 7 cards to players hand
        // must delete these cards from deck. Call remove function??
    }
}

/******************************************************************
 * Function: get_n_cards()
 * Description: retreives the number of cards in a hand object
 * Parameters: None
 * Pre-Conditions: number of cards have been set
 * Post-Conditions: None
******************************************************************/
int Hand::get_n_cards() {
    return n_cards;
}

/******************************************************************
 * Function: set_n_cards()
 * Description: sets the number of cards in hand to the size of the hand array
 * Parameters: None
 * Pre-Conditions: hand was initialized
 * Post-Conditions: None
******************************************************************/
void Hand::set_n_cards() {
    n_cards = sizeof(cards);
}
/******************************************************************
 * Function: add_card_to_hand(Card&)
 * Description: adds a card object to a hand object
 * Parameters: Card& c
 * Pre-Conditions: hand must be able to dynamically change in size
 * Post-Conditions: the added card must be removed from wherever is was located prior 
******************************************************************/
void Hand::add_card_to_hand(Card& c) {
    Card* temp_arr = new Card [this->n_cards + 1]; // allocate an array of cards with size + 1

    // copy the old array objects to new array
    for (int i = 0; i < this->n_cards; ++i) {
        temp_arr[i] = this->cards[i];
    }
    
    temp_arr[this->n_cards] = c; // add the new card object c into cards array

    // delete old array
    if (this->cards != NULL) {
        delete [] this->cards;
    }

    this->cards = temp_arr; // set cards to temp_arr
    this->n_cards++; // increment the n_cards
}

/******************************************************************
 * Function: remove_card_from_hand(Card&)
 * Description: removes a card object from a hand object
 * Parameters: Card& c
 * Pre-Conditions: hand must be able ro dynamically change in size
 * Post-Conditions: the removed card must be immediatelly placed somewhere 
******************************************************************/
void Hand::remove_card_from_hand(Card& c) { //assuming I know the card exists in hand
    Card* temp_arr = new Card [this->n_cards - 1]; // allocate an array of cards with size - 1
    
    int j = 0;
    for (int i = 0 ; i < this->n_cards; ++i) {
        if ((cards[i].get_rank() != c.get_rank()) || (cards[i].get_suit() != c.get_suit())) { 
            temp_arr[j] = this->cards[i]; // add cards back to array
            j++;
        }
    }

     // delete old array
    if (this->cards != NULL) {
        delete [] this->cards;
    }

    this->cards = temp_arr;
    this->n_cards--;
}

/******************************************************************
 * Function: has_rank(int)
 * Description: checks if a hand has a card with inputted rank
 * Parameters: int rank
 * Pre-Conditions: hand has been populated and can be accessed
 * Post-Conditions: the inputted rank gets assigned to a suit to produce one card
******************************************************************/
int Hand::has_rank(int rank) {
  for(int i = 0; i < this->n_cards; i++) {
    if(cards[i].get_rank() == rank) {
      return cards[i].get_suit();
    }
  }
  return -1;
}

/******************************************************************
 * Function: book_exists(int)
 * Description: checks if a book exists (4 cards of the same rank) in a hand object
 * Parameters: int card_rank
 * Pre-Conditions: hand has been populated and can be accessed
 * Post-Conditions: books should be removed by another function
******************************************************************/
bool Hand::book_exists(int card_rank) {
    int count  = 0; 
    for (int i = 0; i < this->n_cards; ++i) { // iterating through array of cards
        if (this->cards[i].get_rank() == card_rank) { // if rank exists
            count++;
        }
    } 
    if (count == 4) { // if there is a book (4 cards)
        return true;
    }
    else {
        return false;
    }
} 

/******************************************************************
 * Function: random_card_cheat()
 * Description: returns a randomly picked card in the Player's Hand used for the computer to pick its own card to request
 * Parameters: None
 * Pre-Conditions: num_cards must accurately represent the logical size of the cards array
 * Post-Conditions: all cards stay the same
******************************************************************/
Card Hand::random_card_cheat() {
    //return a random card from player's hand
    srand(time(NULL)); // Initialize seed
    int random_index = rand() % get_n_cards(); // computer randomly picks index from player's cards
    Card random_card = get_cards()[random_index]; // get the rank located at that index
    return random_card;
}

/******************************************************************
 * Function: in_hand(int)
 * Description: returns a true if the rank passed is located in the hand
 * Parameters: int wanted_rank
 * Pre-Conditions: a eanted rank has been inputted from the player
 * Post-Conditions: another function must be used subsequently
******************************************************************/
bool Hand::in_hand(int wanted_rank) {
    for (int i = 0; i < n_cards; ++i) {
        if (get_cards()[i].get_rank() == wanted_rank) {
            return true;
        }
    }
    return false;
}