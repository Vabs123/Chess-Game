

#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include "piece.h"
#include "square.h"

using namespace std;

class bishop : public piece
{
 public:
    bishop(bool is_white);
    ~bishop();
    int value() const;
    bool can_move_to(square& location) const;
    void display() const;
};

#endif
