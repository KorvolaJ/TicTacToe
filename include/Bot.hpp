// Bot that uses MinMax Search to win

#include <string>
#include "GameBoard.hpp"

// helper struct
struct BotMove
{
    BotMove() {};
    BotMove(int score): score(score){};
    int x;
    int y;
    int score;
};

class Bot
{
public:
    void makeAction(GameBoard& board);

private:
    BotMove getBestmove(GameBoard& board, bool player);
};