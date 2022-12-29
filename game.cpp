#include "game.h"

using namespace std;
    
/******************************************************************
 * Function: Game()
 * Description: Class default constructor. Creates a game object
 * Parameters: None
 * Pre-Conditions: game object has been initialized
 * Post-Conditions: must have a destructor
******************************************************************/
Game::Game() { // default constructor
} 
    
/******************************************************************
 * Function: ~Game()
 * Description: Class destructor. deletes memory that was allocated by constructor
 * Parameters: None
 * Pre-Conditions: game object has been initialized
 * Post-Conditions: No memory leaks
******************************************************************/
Game:: ~Game() { // destructor
} 


//Deck Game::get_deck() {
// return Deck
//}
    
//Player Game::get_players() {
    //return Player;
//}

// void Game::set_deck() {

// }

// void Game::set_players() {

// }

/******************************************************************
 * Function: draw_card()
 * Description: deals a cards from the shuffled deck to a hand of player/computer
 * Parameters: None
 * Pre-Conditions: players and their hands have been initialized
 * Post-Conditions: the deck has 38 cards
******************************************************************/
void Game::draw_card() {
    Card c1 = this->d.remove_a_card(); // remove card from deck
    this->players[0].get_hand().add_card_to_hand(c1); // add this card to first element of player 1

    Card c2 = this->d.remove_a_card(); // remove card from deck
    this->players[1].get_hand().add_card_to_hand(c2); // add this card to first element of player 2
}

/******************************************************************
 * Function: deal_7_cards()
 * Description: deals 7 cards from the shuffled deck to both the player and the computer
 * Parameters: None
 * Pre-Conditions: players and their hands have been initialized
 * Post-Conditions: the deck has 38 cards
******************************************************************/
void Game::deal_7_cards() {
    d.shuffle_deck();
    for (int i = 0; i < 7; ++i) {
        Card c1 = this->d.remove_a_card(); // remove card from deck
        this->players[0].place_a_card(c1); // add this card to player 1

        Card c2 = this->d.remove_a_card(); // remove card from deck
        this->players[1].place_a_card(c2); // add this card to player 2
    }
}

/******************************************************************
 * Function: game_status()
 * Description: Checks whether the game is over by counting the total books put down by both players
 * Parameters: None
 * Pre-Conditions: players and their hands/books have been initialized and counted properly
 * Post-Conditions: continues the game until 13 books have been laid down
******************************************************************/
bool Game::game_status() {
    if (players[0].get_n_books() + players[1].get_n_books() < 13) {
        return true;
    } 
    return false;
}

/******************************************************************
 * Function: display_game()
 * Description: Displays thebooks of both and computer and player and the hand of the player
 * Parameters: None
 * Pre-Conditions: debug mode boolean has been initialized and is false
 * Post-Conditions: Player cannot see computer's hand
******************************************************************/
void Game::display_game() { 
    cout << endl << endl;
    cout << "-----------------------------------------------------------" << endl;

    cout << "Player's Books: "; // display book aquired by player
    cout << "[" << players[0].get_n_books() << "]";

    cout << endl << endl << "Player's Hand: " << endl; // display player's cards
    int num_cards_player0 = players[0].get_hand().get_n_cards();
    for (int i = 0; i < num_cards_player0; i++){
        cout << "[";
        players[0].get_hand().get_cards()[i].print_card();
        cout << "]" << endl;
    }
    
    cout << endl << endl << "Computer's Books: "; // display book aquired by computer
    cout << "[" << players[1].get_n_books() << "]";

    cout << endl << "-----------------------------------------------------------" << endl;
}

/******************************************************************
 * Function: display_game_cheat_mode ()
 * Description: Displays the hand and books of both and computer and player
 * Parameters: None
 * Pre-Conditions: debug mode boolean has been initialized and is true
 * Post-Conditions: Player can now see computer's hand
******************************************************************/
void Game::display_game_cheat_mode() { 
    cout << endl << endl;
    cout << "-----------------------------------------------------------" << endl;

    cout << "Player's Books: "; // display book aquired by player
    cout << "[" << players[0].get_n_books() << "]";

    cout << endl << endl << "Player's Hand: " << endl; // display player's cards
    int num_cards_player0 = players[0].get_hand().get_n_cards();
    for (int i = 0; i < num_cards_player0; i++){
        cout << "[";
        players[0].get_hand().get_cards()[i].print_card();
        cout << "]" << endl;
    }
    
    cout << endl << "Computer's Books: "; // display book aquired by computer
    cout << "[" << players[1].get_n_books() << "]";
    
    cout << endl << endl << "Computer's Hand: " << endl; // display player's cards
    int num_cards_player1 = players[1].get_hand().get_n_cards();
    for (int i = 0; i < num_cards_player1; i++){
        cout << "[";
        players[1].get_hand().get_cards()[i].print_card();
        cout << "]" << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
}

/******************************************************************
Function: computer_request(bool, bool)
Description: determins a random card for the computer to request and returns the rank of that card
Parameters: bool is_game_over, bool debug_mode
Pre-Conditions: the deck of cards must not be empty
Post-Conditions: rank_chosen is assigned the rank of random pick
******************************************************************/
void Game::computer_request(bool is_game_over, bool debug_mode) {
    bool run_again = true;
    // if turn begins with no cards in computer's hand 
    if (players[1].get_hand().get_n_cards() < 1 && !is_game_over) {
        cout << "Computer's turn to play.";
        players[1].get_hand().add_card_to_hand(d.remove_a_card()); 
        if (debug_mode == 1) {
            display_game_cheat_mode();
        }
        else {
            display_game();
        }

        run_again = false;
    }
    // go fish if the user has no cards left
    if (players[0].get_hand().get_n_cards() < 1) {
        cout << "Computer draws a card from the deck.";
        players[1].get_hand().add_card_to_hand(d.remove_a_card()); //go fish
        run_again = false;
    } 
    while (run_again == true) {
    srand(time(NULL)); // initialize seed randomly
    int random_guess_index = rand() % players[1].get_hand().get_n_cards(); // computer randomly picks index from player's cards
    int rank_chosen = players[1].get_hand().get_cards()[random_guess_index].get_rank() +1; // get the rank located at that index
   
    cout << "Computer asks for a: " << rank_chosen << endl;
    run_again = human_has_match(rank_chosen -1);

    if (debug_mode == 1) {
        display_game_cheat_mode();
    }
    else {
        display_game();
    }
    }   
}
/******************************************************************
 * Function: comp_has_match(int, bool)
 * Description: checks computer's hand for card of rank_chosen
 * Parameters: int rank_chosen, bool debug_mode
 * Pre-Conditions: rank_chosen must be a positive integer
 * Post-Conditions: user is updated
******************************************************************/
bool Game::comp_has_match(int rank_chosen, bool debug_mode) {
    // count and remove cards of rank_chosen from computer's hand
    int count = 0;
    int suit = players[1].has_rank(rank_chosen);
    while (suit != -1) { // as long as the computer has the chosen rank
        Card c(rank_chosen, suit);
        players[1].remove_card_from_hand(c); // remove card from computer
        players[0].add_card_to_hand(c);  // place card in players hand
        count++;
        suit = players[1].has_rank(rank_chosen);
    }
    cout << "Computer gives you " << count << ": " << rank_chosen + 1 << endl; // display message
    
   if (debug_mode == 1) {
        display_game_cheat_mode();
    }
    else {
        display_game();
    }

    if (count == 0) {
        rank_chosen = go_fish_player();
        // check for book
        if (players[0].get_hand().book_exists(rank_chosen)) { // remove book of player from their hand
            cout << "You got a book!" << endl;
            players[0].remove_book(rank_chosen); 
        }
        return false;
    } 
    else {
    // check for book
    if (players[0].get_hand().book_exists(rank_chosen)) { // remove book of player from their hand
        cout << "You got a book!" << endl;
        players[0].remove_book(rank_chosen); 
    }
    return true;
    }
}

/******************************************************************
Function: human_request(bool, bool)
Description: enables player to ask computer for a rank. Deals with error handling if human or computer do not have any cards in their hands.
Parameters: bool is_game_over, bool debug_mode
Pre-Conditions: the deck of cards must not be empty, parameters have been initialized by previous functions or user input
Post-Conditions: assigns the wnted rank to a variable
******************************************************************/
void Game::human_request(bool is_game_over, bool debug_mode) {
    // if turn begins with no cards in computer's hand 
    if (players[1].get_hand().get_n_cards() < 1 && !is_game_over) {
        cout << "Computer has no cards, Player takes a card from the deck" << endl;
        players[0].get_hand().add_card_to_hand(d.remove_a_card()); // Player takes a card form deck
    }

    // go fish if the user has no cards left
    else if (players[0].get_hand().get_n_cards() < 1) {
        cout << "Player draws a card from the deck.";
        players[0].get_hand().add_card_to_hand(d.remove_a_card()); //go fish
    }

    int wanted_rank;
    bool run_again = true;
    while(run_again == true) {
    wanted_rank = validate_input();
    cout << "Computer, the player wants your : " << wanted_rank << endl;
  
    run_again = comp_has_match(wanted_rank-1, debug_mode);
    }
    
    if (debug_mode == 1) {
        display_game_cheat_mode();
    }
    else {
        display_game();
    }
}

/******************************************************************
 * Function: human_has_match(int)
 * Description: checks user's hand for card of rank_chosen
 * Parameters: int rank_chosen
 * Pre-Conditions: rank_chosen must be a positive integer
 * Post-Conditions: user is updated
******************************************************************/
bool Game::human_has_match(int rank_chosen) {
    // count and remove cards of rank_chosen from computer's hand
    int count = 0;
    int suit = players[0].has_rank(rank_chosen);
    while (suit != -1) { // as long as the computer has the chosen rank
        Card c(rank_chosen, suit);
        players[0].remove_card_from_hand(c); // remove card from computer
        players[1].add_card_to_hand(c);  // place card in players hand
        count++;
        suit = players[0].has_rank(rank_chosen);
    }
    cout << "Player gives the computer " << count << ": " << rank_chosen + 1 << endl; // display message

    if (count == 0) {
        rank_chosen = go_fish_computer();
        // check for book
        if (players[1].get_hand().book_exists(rank_chosen)) { // remove computer's book from their hand
            cout << endl << "Computer gets a book!" << endl;
            players[1].remove_book(rank_chosen); 
        }
        return false;
    }
    else {
        // check for book
        if (players[1].get_hand().book_exists(rank_chosen)) { // remove book of player from their hand
            cout << "You got a book!" << endl;
            players[1].remove_book(rank_chosen); 
        }
    return true;
    }
} 

/******************************************************************
 * Function: go_fish_player()
 * Description: if the player asks for a card the computer does not have, the player draws a card from the deck
 * Parameters: None
 * Pre-Conditions: the computer does not have the requested rank
 * Post-Conditions: user is updated, a card is added to the player's hand
******************************************************************/
int Game::go_fish_player() {
    cout << "Go Fish! Player draws a card from the deck.";
    Card card2 = d.remove_a_card();
    players[0].add_card_to_hand(card2); //go fish
    int rank2 = card2.get_rank();
    return rank2;
}

/******************************************************************
 * Function: go_fish_computer()
 * Description: if the computer asks for a card the player does not have, the computer draws a card from the deck
 * Parameters: None
 * Pre-Conditions: the player does not have the requested rank
 * Post-Conditions: user is updated, a card is added to the computer's hand
******************************************************************/
int Game::go_fish_computer() {
    cout << "Go Fish! computer draws a card from the deck.";
    Card card2 = d.remove_a_card();
    players[1].add_card_to_hand(card2); //go fish
    int rank2 = card2.get_rank();
    return rank2;
}

/******************************************************************
 * Function: game_winner()
 * Description: determines the winner of the game based on the number of books that each player has
 * Parameters: None
 * Pre-Conditions: books are updated properly
 * Post-Conditions: None
******************************************************************/
void Game::game_winner() {
    if (players[0].get_n_books() > players[1].get_n_books()) {
        cout << "You win, computer loses! ";
    }
    else if (players[1].get_n_books() > players[0].get_n_books()) {
        cout << "Computer wins, you lose! ";
    }
}

/******************************************************************
 * Function: validate_input()
 * Description: checks if the rank is in the player's hand and prints error message if not
 * Parameters: None
 * Pre-Conditions: the hand object is accessible and in_hand function works
 * Post-Conditions: the user can only guess ranks that they possess
******************************************************************/
int Game::validate_input() {
    int wanted_rank;
    while (true) {
        cout << "What would you like to ask the computer for? ";
        cin >> wanted_rank;
        if (players[0].get_hand().in_hand(wanted_rank -1)) {
            return wanted_rank;
        }
        cout << "Please ask for a rank you possess" << endl;
    }
}
