
#ifndef KING_H
#define KING_H

#include <iostream>
#include "restricted_piece.h"

using namespace std;

class king : public restricted_piece
{
 public:
    king(bool is_white);
    ~king();
    int value() const;
    bool can_move_to(square& location) const;
    void display() const;
};

#endif
