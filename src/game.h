#ifndef GAME_H
#define GAME_H

#include <set>
#include <iostream>
#include "board.h"
#include "piece.h"
#include "player.h"

using namespace std;

class game
{
 public:
    ~game();
    static void initialize();
    static player* get_next_player();
    static player* opponent_of(player& player);

 private:

    game();
    static player* player1;
    static player* player2;
    static player* next_player;
    static set<piece*> white_pieces;
    static set<piece*> black_pieces;

};

#endif
