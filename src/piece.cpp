//piece.cpp

#include "player.h"
#include "restricted_piece.h"
#include <string>
#include "piece.h"
#include "player.h"

piece::piece(bool is_white): m_is_white(is_white), m_square(NULL){
    if(is_white)
        m_color = "W";
    else
        m_color = "B";
}

piece::~piece(){
}

void piece::set_location(square* location){
    m_square = location ;
}

bool piece::is_white() const
{
    return m_is_white;
}

bool piece::is_on_square() const
{
    return m_square;
}

string piece::color() const
{
    return m_color;//Restricted Pieces
}

bool piece::move_to(player& by_player ,square& to_square)
{
    bool valid_move = false;
    piece* to_capture = NULL;
    square* from_square = m_square;

    if(m_is_white == by_player.is_white())
    {
        if(can_move_to(to_square))
        {
            if(to_square.occupied())
            {
                to_capture = to_square.occupied_by();
                if(to_capture->is_white() != by_player.is_white())
                {
                    valid_move = true;
                }
            }
            else
            {
                valid_move = true;
            }

            if(valid_move)
            {
                if(to_capture)
                {
                    to_capture->set_location(NULL);
                }

                m_square->set_occupier(NULL);
                m_square = &to_square;
                m_square->set_occupier(this);

                if(by_player.in_check())
                {
                    valid_move = false;
                    m_square = from_square;
                    m_square->set_occupier(this);
                    to_square.set_occupier(to_capture);
                    if(to_capture)
                    {
                        to_capture->set_location(&to_square);
                    }
                }
                else
                {
                    if(to_capture)
                    {
                        by_player.capture(to_capture);
                    }
                }
            }
        }
    }
    return valid_move;
}

square* piece::location() const
{
    return m_square;
}

