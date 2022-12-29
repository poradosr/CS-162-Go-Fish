#include "player.h"
#include "hand.h"

using namespace std;

/******************************************************************
 * Function: Player()
 * Description: class default constructor. Creates a player object
 * Parameters: None
 * Pre-Conditions: player object has been initialized
 * Post-Conditions: Must have destructor
******************************************************************/
Player::Player() { 
    this->books = NULL;
    this->n_books = 0;
} 

/******************************************************************
 * Function: Player(int)
 * Description: class parametized constructor. Creates a player object and accepts parameter to initialize its nember variable n_books to size  
 * Parameters: int size
 * Pre-Conditions: player object has been initialized
 * Post-Conditions: Must have destructor
******************************************************************/
Player::Player (int size) {
    this->n_books = size;
    this->books = new int [size];
}

/******************************************************************
 * Function: ~Player()
 * Description: class destructor. deletes memory that was allocated by constructor
 * Parameters: None
 * Pre-Conditions: player object has been initialized
 * Post-Conditions: No memory leaks
******************************************************************/
Player::~Player() { // destructor
    if (this->books != NULL) {
        delete [] this->books;
        this->books = NULL;
    }
}

/******************************************************************
 * Function: Player(const Player&)
 * Description: copy constructor
 * Parameters: const Player& p
 * Pre-Conditions: player object has been initialized and populated
 * Post-Conditions: a second identical player object is created without deleting the memory
******************************************************************/
Player::Player(const Player& p) { // copy constructor
    // member-wise copy
    this->hand = p.hand;
    this->n_books = p.n_books;

    // deep copy
    this->books = new int [this->n_books];
    for (int i = 0; i < this->n_books; ++i) {
        this->books[i] = p.books[i];
    }
} 

/******************************************************************
 * Function: operator=(const Player&)
 * Description: Operator assignment overload. Deep copies a player object
 * Parameters: const Player& p
 * Pre-Conditions: player object has been initialized and populated
 * Post-Conditions: a second identical player object is created.
******************************************************************/
Player& Player::operator=(const Player & p) {
    // member-wise copy
    this->hand = p.hand;
    this->n_books = p.n_books;

    // free the memory first
    if (this->books != NULL) { 
        delete [] this->books;
    }

    // deep copy
    this->books = new int [this->n_books];
    for (int i = 0; i < this-> n_books ; ++i) {
        this->books[i] = p.books[i];
    }

    return *this;

}

/******************************************************************
 * Function: get_hand()
 * Description: retreives the hand object from the player class
 * Parameters: None
 * Pre-Conditions: books array has been initialed
 * Post-Conditions: None
******************************************************************/
Hand Player::get_hand() {
    return hand;
}

/******************************************************************
 * Function: get_n_books()
 * Description: retreives the number of books in the book array
 * Parameters: None
 * Pre-Conditions: books array has been initialed
 * Post-Conditions: None
******************************************************************/
int Player::get_n_books() {
    return n_books;
}

/******************************************************************
 * Function: get_books()
 * Description: retreives the books array
 * Parameters: None
 * Pre-Conditions: books array has been initialed
 * Post-Conditions: None
******************************************************************/
int* Player::get_books() {
    return books;
}

/******************************************************************
 * Function: set_hand(const Hand&)
 * Description: a hand object to a player
 * Parameters: const Hand& h
 * Pre-Conditions: hand has been initialized and populated
 * Post-Conditions: None
******************************************************************/
void Player::set_hand(const Hand& h) {
    this->hand = h;
}

/******************************************************************
 * Function: set_n_books()
 * Description: sets the number of books to the size of the book array
 * Parameters: None
 * Pre-Conditions: books array has been initialed
 * Post-Conditions: None
******************************************************************/
void Player::set_n_books() {
    n_books = sizeof(books);
}

/******************************************************************
 * Function: set_books()
 * Description: sets the books an array
 * Parameters: None
 * Pre-Conditions: books array has been initialed
 * Post-Conditions: Logic to set books correctly must be implemented
******************************************************************/
void Player::set_books(int change_book_to, int index) {
    books[index] = change_book_to;
}

/******************************************************************
 * Function: remove_book(int)
 * Description: removes a book from a hand object
 * Parameters: int rank_chosen
 * Pre-Conditions: hand has been initialized and populated
 * Post-Conditions: the number of books is updated
******************************************************************/
void Player::remove_book(int rank_chosen) {
    //remove a card of rank_chosen until there are no more left
    int suit;
    while ((suit = hand.has_rank(rank_chosen)) != -1) {
        Card c(rank_chosen, suit);
        hand.remove_card_from_hand(c); // removes a card object from a hand
    }
    allocate_memory_books(rank_chosen);

}

/******************************************************************
 * Function: allocate_memory_books(int)
 * Description: makes extra memory space for adding book
 * Parameters: int rank_chosen
 * Pre-Conditions: books must be able to dynamically change in size
 * Post-Conditions: the cards are removed from the corresponding hand object
******************************************************************/
void Player::allocate_memory_books(int rank_chosen) {
    int* temp_arr = new int[this->n_books + 1]; // allocate an array of books with size + 1

    // copy the old array objects to new array
    for (int i = 0; i < this->n_books; ++i) {
        temp_arr[i] = this->books[i];
    }
    
    temp_arr[this->n_books] = rank_chosen; // add the new book b into books array

    // delete old array
    if (this->books!= NULL) {
        delete [] this->books;
    }

    this->books = temp_arr; // set books to temp_arr
    this->n_books++; // increment the number of books
}


/******************************************************************
 * Function: place_a_card(Card&)
 * Description: places a card in a hand
 * Parameters: Card& c
 * Pre-Conditions: deck has been shuffled
 * Post-Conditions: hand dynamically grows to add memory for card object 
******************************************************************/
void Player::place_a_card(Card& c) {
    this->hand.add_card_to_hand(c);
}

/******************************************************************
 * Function: has_rank(int)
 * Description: calls the has_rank function located in hand
 * Parameters: int rank
 * Pre-Conditions: has_rank in the hand class is a properly working function
 * Post-Conditions: Can be called from Player class (encapsulation)
******************************************************************/
int Player::has_rank(int rank) {
  return hand.has_rank(rank);
}

/******************************************************************
 * Function: add_card_to_hand(Card&)
 * Description: calls the add_card_to_hand function located in hand
 * Parameters: Card& c
 * Pre-Conditions: add_card_to_hand in the hand class is a properly working function
 * Post-Conditions: Can be called from Player class (encapsulation)
******************************************************************/
void Player::add_card_to_hand(Card& c) {
    hand.add_card_to_hand(c);
}

/******************************************************************
 * Function: remove_card_from_hand(Card&)
 * Description: calls the remove_card_from_hand function located in hand
 * Parameters: Card& c
 * Pre-Conditions: remove_card_from_hand in the hand class is a properly working function
 * Post-Conditions: Can be called from Player class (encapsulation)
******************************************************************/
void Player::remove_card_from_hand(Card& c) { //assuming I know the card exists in hand
    hand.remove_card_from_hand(c);
}

/******************************************************************
 * Function: randon_card_cheat()
 * Description: calls the randon_card_cheat function located in hand
 * Parameters: None
 * Pre-Conditions: randon_card_cheat in the hand class is a properly working function
 * Post-Conditions: Can be called from Player class (encapsulation)
******************************************************************/
Card Player::random_card_cheat() {
    hand.random_card_cheat();
}
