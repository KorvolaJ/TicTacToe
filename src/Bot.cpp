#include "Bot.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// chooses and makes action
void Bot::makeAction(GameBoard& board)
{
    BotMove bestMove = getBestmove(board, false);
    board.setValue(bestMove.x, bestMove.y, false);
}

// recursive minimax algorithm
BotMove Bot::getBestmove(GameBoard& board, bool player)
{
    // check if terminal state and return value based on it
    // 10 if bot wins, -10 if bot loses and 0 if tied
    int win = board.CheckWin(player);
    if(win == 0)
    {
        return BotMove(10);
    }
    else if(win == 1)
    {
        return BotMove(-10);
    }
    else if(win == 2)
    {
        return BotMove(0);
    }

    // all the possible moves in this state
    std::vector<BotMove> moves;

    // loop through every action
    for(int x = 0; x < 3; x++)
    {
        for(int y = 0; y < 3; y++)
        {
            // if the move is possible
            if(board.getValue(x,y) == ' ')
            {
                // simulate by actually making the move
                BotMove move;
                move.x = x;
                move.y = y;
                board.setValue(x,y, player);

                // simulate next move 
                if(player)
                {
                    // bots perspective
                    move.score = getBestmove(board, false).score;
                } else
                {   
                    // player's perpective
                    move.score = getBestmove(board, true).score;
                }
                // store move
                moves.push_back(move);
                // delete simulated move
                board.setToInit(x,y);
            }
        }
    }

    // This part finds the best possible move from moves vector
    int bestMove = 0;
    // it depends whether this is player's or bot's round
    if(player)
    {
        // player wants to minimize bot's score, so it chooses
        // the move that gives the lowest score
        int bestScore = 99999;
        for(int i = 0; i < moves.size(); i++)
        {
            if(moves[i].score < bestScore)
            {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    } else
    {
        // bot wants to maximize the score so it chooses the
        // move that gives the highest score
        int bestScore = -99999;
        for(int i = 0; i < moves.size(); i++)
        {
            if(moves[i].score > bestScore)
            {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    // return the best move
    return moves[bestMove];
}


