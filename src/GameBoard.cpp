#include "GameBoard.hpp"
#include <iostream>
#include <algorithm>
#include <string>

// initializer. MovesDone counts how many moves has been done
// to figure if it is tie. Also initialize board to contain
// spaces
GameBoard::GameBoard(): m_movesDone{0}
{
    for(int i=0; i < 3; i++)
    {
        for(int j=0; j < 3; j++)
        {
            m_board[i][j] = ' ';
        }
    }
}

// check if move  is legal by checking that input is not
// less than 0 or higher than 2 and that the move is not
// already made
bool GameBoard::checkIfLegal(int x, int y)
{
    if(x < 0 && x > 2 && y < 0 && y > 2)
    {
        return false;
    }
    if(m_board[x][y] == ' ')
    {
        return true;
    } else
    {
        return false;
    }
}

// prints the gameboard
void GameBoard::printBoard()
{
    std::cout << std::endl;
    std::cout << "  0 1 2" <<std::endl;
    for(int i = 0; i < 3; i++)
    {
        std::cout << i <<'|';
        for(int j = 0; j < 3; j++)
        {
            std::cout << m_board[i][j] << "|";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// get value of position. X O or space
char GameBoard::getValue(int x, int y)
{
    return m_board[x][y];
}

// set value to position and whose move it is
void GameBoard::setValue(int x, int y, bool player)
{
    if(player)
    {
        m_board[x][y] = 'X';
    } else
    {
        m_board[x][y] = 'O';
    }
    m_movesDone++;
}

// backs down one move. Only for Bot
void GameBoard::setToInit(int x, int y)
{
    m_board[x][y] = ' ';
    m_movesDone--;
}


// returns 0 if bot, 1 if player, 2 if tied, 3 if not done
int GameBoard::CheckWin(bool player)
{
    char symbol = 'O';
    if(player)
    {
        symbol = 'X';
    }
    // check rows and columns
    for(int i = 0; i < 3; i++)
    {
        if(m_board[i][0] == symbol && m_board[i][1] == symbol && m_board[i][2] == symbol)
        {
            if(symbol == 'X')
                return 1;
            else
                return 0;
        }
        if(m_board[0][i] == symbol && m_board[1][i] == symbol && m_board[2][i] == symbol)
        {
            if(symbol == 'X')
                return 1;
            else
                return 0;
        }
    }
    // diagonal check
    if(m_board[0][0] == symbol && m_board[1][1] == symbol && m_board[2][2] == symbol)
    {
        if(symbol == 'X')
            return 1;
        else
            return 0;
    }
    if(m_board[0][2] == symbol && m_board[1][1] == symbol && m_board[2][0] == symbol)
    {
        if(symbol == 'X')
            return 1;
        else
            return 0;
    }
    // tied
    if(m_movesDone == 9)
    {
        return 2;
    }
    // no winner
    return 3;
}