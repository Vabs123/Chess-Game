#include "bishop.h"

bishop::bishop(bool is_white) : piece(is_white){}
bishop::~bishop(){}
int bishop::value() const{
    return 3;
}
bool bishop::can_move_to(square& location) const
{
    bool valid_move = false;

	if(board::get_board()->is_clear_diagonal(*(this->location()), location))
    {
        valid_move = true;
    }
	return valid_move;
}

void bishop::display() const
{
    cout << m_color + "B";
}
