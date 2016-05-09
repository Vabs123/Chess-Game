//square check karna hai
#include "piece.h"
#include "square.h"

square::square(int x,int y):m_x(x),m_y(y),m_piece(NULL){
}

square::~square(){
}

void square::set_occupier(piece* piece){
    m_piece = piece;
}

int square::get_X() const{
    return m_x;
}

int square::get_Y() const{
    return m_y;
}

bool square::occupied() const{
    if(m_piece != NULL){
    	return true;
	}
	else 
	return false;
}

piece* square::occupied_by() const{
    return m_piece ;
}
