#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include "square.h"
#include "piece.h"

using namespace std;

class knight : public piece
{
 public:
    knight(bool is_white);
    ~knight();
    int value() const;
    bool can_move_to(square& location) const;
    void display() const;
};

#endif
