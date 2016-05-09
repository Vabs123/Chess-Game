
#include "rook.h"
rook::rook(bool is_white) : restricted_piece(is_white){}
rook::~rook(){}
int rook::value() const
{
    return 5;
}

bool rook::can_move_to(square& location) const
{
    bool valid_move = false;
    if(board::get_board()->is_clear_vertical(*(this->location()), location))
    {
        valid_move = true;
    }
    else if(board::get_board()->is_clear_horizontal(*(this->location()), location))
    {
        valid_move = true;
    }

    return valid_move;
}

void rook::display() const
{
    cout << m_color + "R";
}
