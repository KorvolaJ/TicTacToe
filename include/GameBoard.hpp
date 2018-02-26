// Board

#include <vector>
#include <string>

class GameBoard
{
public:
    GameBoard();
    void printBoard();
    bool checkIfLegal(int x, int y);
    int CheckWin(bool player);
    char getValue(int x, int y);
    void setValue(int x, int y, bool player);
    void setToInit(int x, int y);

private:
    char m_board[3][3];
    int m_movesDone;

};