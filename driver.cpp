#include "game.h"
#include "player.h"
#include "card.h"
#include "deck.h"
#include "hand.h"

/****************************************************** 
** Program: driver.cpp
** Author: Raz Poradosu
** Date: 06/11/2022
** Description: a program that allows one player to play a game of Go Fish against the computer.
** Input: boolean depicting if user wants to play in debug mode, ranks of cards the user wants to ask for, input whether the player wants to play again
** Output: A full game of Go Fish according to the rules. 
******************************************************/

using namespace std;

int main() {

bool play_again = true;
char input;
while (play_again == true) {
    Deck d;
    Game g;
    bool debug_mode;
    cout << "Would you like to play in debug mode? (1/0) "; // option for playing in debug mode 
    cin >> debug_mode;
    g.deal_7_cards(); // dealing initial 7 cards at start of game
    if (debug_mode == 1) { // displaying the game according to mode
        g.display_game_cheat_mode();
    }
    else {
        g.display_game();
    }
    while (g.game_status() == true) { // as long as the total books laid is less than 13
        g.human_request(g.game_status(), debug_mode); // player's turn
        g.computer_request(g.game_status(), debug_mode); // computer's turn
    }
    g.game_winner();
    cout << "Would you like to play again? (y/n) ";
    cin >> input;

    if (input = 'y') {
        play_again = true;
    }
    else if (input = 'n') {
        play_again = false;
    }

}
}



