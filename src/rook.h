#ifndef ROOK_H
#define ROOK_H

#include <iostream>
#include "restricted_piece.h"
#include "square.h"

using namespace std;

class rook : public restricted_piece
{
 public:
    rook(bool is_white);
    ~rook();
    int value() const;
    bool can_move_to(square& location) const;
    void display() const;
};
#endif
