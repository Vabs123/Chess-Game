
//Restricted Pieces

#include "player.h"
#include "restricted_piece.h"

restricted_piece::restricted_piece(bool is_white) : piece(is_white){
	m_moved = false;
}

restricted_piece::~restricted_piece(){
}

bool restricted_piece::move_to(player& by_player, square& to){
	bool valid_move = piece::move_to(by_player ,to );

	if(valid_move && !m_moved){
		m_moved = true;
	}

	return valid_move;
}

bool restricted_piece::has_moved() const{
	return m_moved;
}
