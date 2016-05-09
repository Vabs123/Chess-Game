#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include "square.h"
#include "piece.h"

using namespace std;

class queen : public piece
{
 public:
    queen(bool is_white);
    ~queen();
    int value() const;
    bool can_move_to(square& location) const;
    void display() const;
};
#endif

