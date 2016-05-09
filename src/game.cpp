
#include "game.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include "king.h"
#include "square.h"
#include "player.h"

game::game()
{
}

game::~game()
{
    for (set<piece*>::iterator itr = white_pieces.begin();
         itr != white_pieces.end(); ++itr)
    {
        delete *itr;
    }
    white_pieces.clear();
    for (set<piece*>::iterator itr = black_pieces.begin();
         itr != black_pieces.end(); ++itr)
    {
        delete *itr;
    }
    black_pieces.clear();

    delete &player1;
    delete &player2;
}

void game::initialize()
{
    piece* apiece;
    king* aking;
    square* asquare;

    white_pieces = *(new set<piece*>);
    black_pieces = *(new set<piece*>);

    // Queen
    //      White
    apiece = new queen(true);
    asquare = board::get_board()->square_at(3, 0);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    white_pieces.insert(apiece);
    //      Black
    apiece = new queen(false);
    asquare = board::get_board()->square_at(3, 7);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    black_pieces.insert(apiece);

    //Bishop
    //      White-true
    //      Black - false
    apiece = new bishop(true);
    asquare = board::get_board()->square_at(2, 0);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    white_pieces.insert(apiece);
    apiece = new bishop(false);
    asquare = board::get_board()->square_at(2, 7);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    black_pieces.insert(apiece);
    apiece = new bishop(true);
    asquare = board::get_board()->square_at(5, 0);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    white_pieces.insert(apiece);
    apiece = new bishop(false);
    asquare = board::get_board()->square_at(5, 7);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    black_pieces.insert(apiece);

    //Knight
    apiece = new knight(true);
    asquare = board::get_board()->square_at(1, 0);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    white_pieces.insert(apiece);
    apiece = new knight(false);
    asquare = board::get_board()->square_at(1, 7);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    black_pieces.insert(apiece);
    apiece = new knight(true);
    asquare = board::get_board()->square_at(6, 0);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    white_pieces.insert(apiece);
    apiece = new knight(false);
    asquare = board::get_board()->square_at(6, 7);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    black_pieces.insert(apiece);

    //Rook
    apiece = new rook(true);
    asquare = board::get_board()->square_at(0, 0);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    white_pieces.insert(apiece);
    apiece = new rook(false);
    asquare = board::get_board()->square_at(0, 7);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    black_pieces.insert(apiece);
    apiece = new rook(true);
    asquare = board::get_board()->square_at(7, 0);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    white_pieces.insert(apiece);
    apiece = new rook(false);
    asquare = board::get_board()->square_at(7, 7);
    asquare->set_occupier(apiece);
    apiece->set_location(asquare);
    black_pieces.insert(apiece);

    for (int i = 0; i < 8; i++)
    {
        //White
        apiece = new pawn(true);
        asquare = board::get_board()->square_at(i, 1);
        asquare->set_occupier(apiece);
        apiece->set_location(asquare);
        white_pieces.insert(apiece);
        //Black
        apiece = new pawn(false);
        asquare = board::get_board()->square_at(i, 6);
        asquare->set_occupier(apiece);
        apiece->set_location(asquare);
        black_pieces.insert(apiece);
    }

    // create the white king
    aking = new king(true);
    asquare = board::get_board()->square_at(4, 0);
    asquare->set_occupier(aking);
    aking->set_location(asquare);
    white_pieces.insert(aking);

    // create White player and hand them their pieces
    player1 = new player("White", true, *aking, white_pieces);

    // create the black king
    aking = new king(false);
    asquare = board::get_board()->square_at(4, 7);
    asquare->set_occupier(aking);
    aking->set_location(asquare);
    black_pieces.insert(aking);

    // create Black player and hand them their pieces
    player2 = new player("Black", false, *aking, black_pieces);

    next_player = player2;
}

player* game::get_next_player()
{
    next_player = opponent_of(*next_player);
    return next_player;
}

player* game::opponent_of(player& player_)
{
    player* opponent;

    if(player_.get_name() == player1->get_name())
    {
        opponent = player2;
    }
    else
    {
        opponent = player1;
    }
    return opponent;
}

player* game::player1 = NULL;
player* game::player2 = NULL;
player* game::next_player = NULL;
set<piece*> game::white_pieces;
set<piece*> game::black_pieces;
