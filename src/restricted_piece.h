
// header hai
#include<iostream>
#ifndef RESTRICTED_H
#define RESTRICTED_H

#include "piece.h"

class player;
using namespace std;

class restricted_piece: public piece
{
    bool m_moved;

public:
    restricted_piece(bool is_white);
    virtual ~restricted_piece();

    virtual bool move_to(player& by_player ,square& to);
    bool has_moved() const ;
};

#endif // RESTRICTED_H
