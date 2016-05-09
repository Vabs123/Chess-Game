
#include "queen.h"

queen::queen(bool is_white) : piece(is_white){}
queen::~queen(){}
int queen::value() const{
    return 9;
}

bool queen::can_move_to(square& location) const{
    bool valid_move = false;

    if(board::get_board()->is_clear_vertical(*(this->location()), location))
    {
        valid_move = true;
    }
    else if(board::get_board()->is_clear_horizontal(*(this->location()), location))
    {
        valid_move = true;
    }
    else if(board::get_board()->is_clear_diagonal(*(this->location()), location))
    {
        valid_move = true;
    }
    return valid_move;
}
void queen::display() const
{
    cout << m_color + "Q";
}

