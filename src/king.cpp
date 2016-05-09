#include<cmath>
#include "king.h"
king::king(bool is_white) : restricted_piece(is_white){}

king::~king(){}

int king::value() const{
    return 0;
}

bool king::can_move_to(square& location) const
{
    bool valid_move = false;
    int translation_X = location.get_X() - this->location()->get_X();
    int translation_Y = location.get_Y() - this->location()->get_Y();
	if(abs(translation_Y) == 1 && translation_X == 0)
    {
        valid_move = true;
    }
	else if(abs(translation_X) == 1 && translation_Y == 0)
    {
        valid_move = true;
    }
	else if(abs(translation_X) == 1 && abs(translation_Y) == 1)
    {
        valid_move = true;
    }

    return valid_move;
}
void king::display() const{
    cout << m_color + "K";
}
