
#ifndef PIECE_H
#define PIECE_H

#include<ostream>
#include "square.h"
#include "board.h"

class player;

using namespace std;

class piece{
private:
    square* m_square;
protected:
    bool m_is_white;
    string m_color;
public:
    piece(bool is_white);
    virtual ~piece();
    virtual bool move_to(player& by_player,square& to_square);
    virtual void set_location(square* location);
    virtual int value() const = 0;
    bool is_white() const ;
    string color() const;
    virtual void display() const = 0;
    virtual bool can_move_to(square& location) const = 0 ;
    bool is_on_square() const;
    square* location() const;
};
#endif // PIECE_H
