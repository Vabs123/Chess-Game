
//player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <set>
#include "piece.h"
#include "king.h"

using namespace std;

class player
{
	string m_name;
    bool m_is_white;
    set<piece*>& m_my_pieces;
    set<piece*> m_captured_pieces;
    king& m_my_king;

public:
 	player(string name, bool is_white, king& my_king, set<piece*>& my_pieces);
	~player();
	bool make_move();
	bool in_check();
	void capture(piece* apiece);
	string get_name() const;
	bool is_white() const;
	int score() const;
	set<piece*>* my_pieces() const;
	king* my_king() const;
};

#endif

