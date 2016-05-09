#include "knight.h"
#include<cmath>

knight::knight(bool is_white) : piece(is_white){}
knight::~knight(){}
int knight::value() const{
    return 3;
}

bool knight::can_move_to(square& location) const
{
    bool valid_move = false;
    int translation_X = location.get_X() - this->location()->get_X();
    int translation_Y = location.get_Y() - this->location()->get_Y();
    if(abs(translation_Y) == 1 && abs(translation_X) == 2){
        valid_move = true;
    }
    else if(abs(translation_X) == 1 && abs(translation_Y) == 2){
        valid_move = true;
    }
    return valid_move;
}

void knight::display() const
{
    cout << m_color + "N";
}
