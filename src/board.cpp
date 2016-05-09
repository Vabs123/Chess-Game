#include<cmath>
#include<cstdlib>
#include "board.h"
#include "piece.h"

board::board()
{
    for(int i = 0; i < m_DIMENSION ; i++ )
    {
        for(int j = 0; j< m_DIMENSION;j++)
        {
            m_squares[i][j] = new square(i,j);
        }
    }
}

board::~board()
{
    for(int i = 0; i < m_DIMENSION ; i++ )
    {
        for(int j = 0; j< m_DIMENSION;j++)
        {
            delete[] m_squares[i][j];
        }
        delete[] m_squares[i];
    }
    delete[] m_squares;
}

board* board::get_board()
{
    if(!m_the_board)
        m_the_board = new board();
    return m_the_board;
}

square* board::square_at(int x,int y) const
{
    return m_squares[x][y];
}

bool board::is_clear_vertical(square& from, square& to) const
{
    square* start = NULL;
    square* end = NULL;
    bool valid = true;

    if(from.get_Y() <= to.get_Y())
    {
        start = &from ;
        end = &to;
    }
    else
    {
        start = &to;
        end = &from;
    }
    if(start->get_X() != end->get_X())
    {
        valid = false;
    }
    else
    {
        for(int i = start->get_Y()+1 ; i< end->get_Y() ; i++)
        {
            if(square_at(start->get_X(), i)->occupied())
            {
                valid = false;
            }
        }
    }
    return valid;
}

bool board::is_clear_horizontal(square& from, square& to) const
{
    square* start = NULL;
    square* end = NULL;
    bool valid = true;

    if(from.get_X() <= to.get_X())
    {
        start = &from;
        end = &to;
    }
    else
    {
        start = &to;
        end = &from;
    }
    if(start->get_Y() != end->get_Y())
    {
        valid = false;
    }
    else
    {
        for(int i = start->get_X() + 1; i < end->get_X(); i++)
        {
            if(square_at(i, start->get_Y())->occupied())
            {
                valid = false;
            }
        }
    }

    return valid;
}

bool board::is_clear_diagonal(square& from, square& to) const
{
    bool valid = true;
    int translation_X = to.get_X() - from.get_X();
    int translation_Y = to.get_Y() - from.get_Y();
    int x_dir = 1;
    int y_dir = 1;

    if(translation_X < 0)
    {
        x_dir = -1;
    }

    if(translation_Y < 0)
    {
        y_dir = -1;
    }
    if(abs(translation_X) != abs(translation_Y))
    {
        valid = false;
    }
    else
    {
        for(int i = 1; i < abs(translation_X); i++)
        {
            if(square_at(from.get_X() + (i * x_dir), from.get_Y() + (i * y_dir))->occupied())
            {
                valid = false;
            }
        }
    }

    return valid;
}

bool board::is_end_row(square& location) const
{
    return (location.get_Y() == 0 || location.get_Y() == (m_DIMENSION - 1));
}

void board::display(ostream& out_stream) const
{   system("cls");

    out_stream << endl << endl <<"                             ~~~~ TWO PLAYER CHESS ~~~~" << endl << endl;
    out_stream << endl << "                     A    B    C    D    E    F    G    H" << endl;
    out_stream << "                   =========================================" << endl<<endl;
    for (int y = m_DIMENSION - 1; y >= 0; y--)
    {
        out_stream << "               " <<y + 1 << "  ";
        for (int x = 0; x < m_DIMENSION; x++)
        {
            out_stream << " | ";
            if(m_squares[x][y]->occupied())
                m_squares[x][y]->occupied_by()->display();
            else
                out_stream << "  ";
        }
        out_stream << " |   " << y + 1 << endl <<endl <<"                   -----------------------------------------" << endl<<endl;
    }
    out_stream << "                      A    B    C    D    E    F    G    H" << endl << endl;
}

board* board::m_the_board = NULL;

