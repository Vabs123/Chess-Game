//square header
#ifndef SQUARE_H
#define SQUARE_H

class piece;
using namespace std;

class square
{
    int m_x , m_y;
    piece* m_piece;
public:
    square(int x ,int y);
    square();
    ~square();
    void set_occupier(piece* piece);
    int get_X() const;
    int get_Y() const;
    bool occupied() const ;
    piece* occupied_by() const;
};
#endif // SQUARE_H

