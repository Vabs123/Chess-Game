//board.h
#ifndef BOARD_H
#define BOARD_H

#include <ostream>
#include "square.h"

using namespace std;

class board
{
    board();
    static board* m_the_board;
    static const int m_DIMENSION = 8;
    square* m_squares[m_DIMENSION][m_DIMENSION];

public:
    ~board();
    static board* get_board();
    square* square_at(int x,int y) const;
    bool is_clear_vertical(square& from, square& to) const;
    bool is_clear_horizontal(square& from ,square& to) const;
    bool is_clear_diagonal(square& from,square& to) const;
    bool is_end_row(square& location) const;
    void display(ostream& outstream) const;
};

#endif // BOARD_H
