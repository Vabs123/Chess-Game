
#include "pawn.h"
#include "queen.h"
#include "board.h"

pawn::pawn(bool is_white) : restricted_piece(is_white), m_delegate(NULL){}
pawn::~pawn(){
    if(m_delegate)
        delete m_delegate;
}

void pawn::set_location(square* location){
    piece::set_location(location);
}

int pawn::value() const{
    return 1;
}
bool pawn::move_to(player& by_player, square& to)
{
    bool valid = false;
    if(m_delegate)
    {
        valid = m_delegate->move_to(by_player, to);
        if(valid)
        {
            location()->set_occupier(NULL);
            set_location(&to);
            location()->set_occupier(this);
        }
    }
    else
    {
        valid = restricted_piece::move_to(by_player, to);
        if(valid)
        {
            if(board::get_board()->is_end_row(*location()))
            {
                m_delegate = new queen(is_white());
                m_delegate->set_location(location());
            }
        }
    }

    return valid;
}

bool pawn::can_move_to(square& location) const
{
    bool valid_move = false;
    int translation_X = location.get_X() - this->location()->get_X();
    int translation_Y = location.get_Y() - this->location()->get_Y();

    if(m_delegate)
    {
        valid_move = m_delegate->can_move_to(location);
    }
    else
    {
        if(!is_white())
        {
            translation_X *= -1;
            translation_Y *= -1;
        }
        if(!location.occupied() && translation_Y == 1 && translation_X == 0)
        {
            valid_move = true;
        }

        else if(!has_moved() && translation_Y == 2 && translation_X == 0 &&
                board::get_board()->is_clear_vertical(*(this->location()), location))
        {
            valid_move = true;
        }
        else if(location.occupied() && translation_Y == 1 &&
                (translation_X == 1 || translation_X == -1))
        {
            valid_move = true;
        }
    }

    return valid_move;
}

void pawn::display() const
{
    if(m_delegate)
    {
        m_delegate->display();
    }
    else
    {
        cout << m_color + "P";
    }
}

