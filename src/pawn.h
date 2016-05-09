#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "square.h"
#include "restricted_piece.h"

using namespace std;

class pawn : public restricted_piece
{
 public:
    pawn(bool is_white);
    ~pawn();
    void set_location(square* location);
    int value() const;
    bool move_to(player& by_player, square& to);
    bool can_move_to(square& location) const;
    void display() const;
 private:
    piece* m_delegate;
};

#endif

