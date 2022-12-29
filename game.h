#ifndef game_h
#define game_h
#include <iostream>
#include <string>
#include <cstdlib>
#include "card.h"
#include "hand.h"
#include "player.h"
#include "deck.h"

class Game {
    private:
    Deck d;
    Player players[2];
    
    public:
    Game(); // default constructor 
    ~Game(); // destructor

    // getters
    //Deck get_deck();
    //Player get_players();

    // setters
    //void set_deck();
    //void set_players();

    void draw_card();
    void deal_7_cards();
    bool game_status();
    void display_game();
    void display_game_cheat_mode();
    void computer_request(bool, bool); 
    bool comp_has_match(int, bool);
    void human_request(bool, bool);
    bool human_has_match(int);
    int go_fish_player();
    int go_fish_computer();
    void game_winner(); 
    int validate_input();
};

#endif