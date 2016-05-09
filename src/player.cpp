
//player.cpp
#include <iostream>
#include "player.h"
#include "board.h"
#include "game.h"

#define X_MIN 'a'
#define X_MAX 'h'
#define Y_MIN '1'
#define Y_MAX '8'

player::player(string name, bool is_white, king& my_king, set<piece*>& my_pieces) :
m_name(name), m_is_white(is_white), m_my_pieces(my_pieces), m_my_king(my_king){
}

player::~player(){
}

bool player::in_check()
{
    bool check = false;
    for (set<piece*>::iterator itr = game::opponent_of(*this)->my_pieces()->begin();
         itr != game::opponent_of(*this)->my_pieces()->end(); ++itr)
    {
        if (((piece*)*itr)->location() &&
            ((piece*)*itr)->can_move_to(*(my_king()->location())))
        {
            // I am in check
            check = true;
        }
    }

    return check;
}

void player::capture(piece* apiece)
{
    apiece->set_location(NULL);
    m_captured_pieces.insert(apiece);
}

string player::get_name() const
{
    return m_name;
}

bool player::is_white() const
{
    return m_is_white;
}

int player::score() const
{
    int score = 0;
    for (set<piece*>::iterator itr = m_captured_pieces.begin(); itr != m_captured_pieces.end(); ++itr)
    {
        score += ((piece*)*itr)->value();
    }

    return score;
}

set<piece*>* player::my_pieces() const
{
    return &m_my_pieces;
}

king* player::my_king() const
{
    return &m_my_king;
}

bool player::make_move()
{
    string bad_input;
    string from_square =  "  ";
    string to_square = "  ";
    int from_X;
    int from_Y;
    int to_X;
    int to_Y;

    if(in_check())
    {
        cout << m_name << " is in check!" << endl;
    }
    cout << m_name << " Player Enter Move ( From-Point  To-Point ): ";
    cin >> from_square >> to_square;

    while(from_square.length() != 2 ||
          to_square.length() != 2 ||
          tolower(from_square.at(0)) < X_MIN ||
          tolower(from_square.at(0)) > X_MAX ||
          tolower(to_square.at(0)) < X_MIN ||
          tolower(to_square.at(0)) > X_MAX ||
          tolower(from_square.at(1)) < Y_MIN ||
          tolower(from_square.at(1)) > Y_MAX ||
          tolower(to_square.at(1)) < Y_MIN ||
          tolower(to_square.at(1)) > Y_MAX ||
          !(board::get_board()->square_at(tolower(from_square.at(0)) - X_MIN,
                                      tolower(from_square.at(1)) - Y_MIN)->occupied())
          )
    {
        cerr << "Invalid Move. Try Again." << endl;
        cin.clear();
        getline(cin, bad_input); //Use nahi hai
        cout << m_name << " player enter move (e.g. a2 a4): ";
        cin >> from_square >> to_square;
    }
    from_X = tolower(from_square.at(0)) - X_MIN;
    from_Y = tolower(from_square.at(1)) - Y_MIN;
    to_X = tolower(to_square.at(0)) - X_MIN;
    to_Y = tolower(to_square.at(1)) - Y_MIN;
    return board::get_board()->square_at(from_X, from_Y)->occupied_by()->move_to(*this,
                                                                  *(board::get_board()->square_at(to_X, to_Y)));

}


