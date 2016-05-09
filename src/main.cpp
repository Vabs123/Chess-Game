#include <iostream>
#include "game.h"
#include "board.h"

int main (int argc, char * const argv[])
{
    player* current_player = NULL;
    game::initialize();
    board::get_board()->display(cout);
    while(true)
    {
        current_player = game::get_next_player();
        while(!current_player->make_move())
        {
            cerr << "Invalid move... Try again." << endl;
        }
        board::get_board()->display(cout);
    }
    return 0;
}
