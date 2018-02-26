#include <iostream>
#include "Bot.hpp"


int main()
{
    GameBoard board;
    Bot minmaxBot;

    int turn = 1;
    board.printBoard();

    while(true)
    {
        if(turn % 2 != 0)
        {
            // boolean for legality of input
            bool legal = false;
            int x, y;
            // ask input till it is legal move
            while(!legal)
            {
                std::cout << "Make your move(row col): " << std::endl;
                std::cin >> x >> y;
                // if it is not int
                // try again
                if(std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                    std::cout << "ERROR not legal, try again" << std::endl;
                    board.printBoard();
                    continue;
                }
                // check if it is legal move
                legal = board.checkIfLegal(x,y);
                if(!legal)
                {
                   std::cout << "ERROR not legal" << std::endl; 
                }
            }
            // make the move
            board.setValue(x,y,true);
        } else
        {
            // Bot
            std::cout << "Bot makes move..." << std::endl;
            minmaxBot.makeAction(board);
        }
        
        board.printBoard();
        int win;
        // check win for bot or player
        if(turn % 2 != 0)
        {
            // parameter is whether it is player
            win = board.CheckWin(true);
        } else{
            win = board.CheckWin(false);
        }
        if(win == 0)
        {
            std::cout << "Bot wins, Sorry" << std::endl;
            return 0;
        }
        else if(win == 1)
        {
            std::cout << "You win!" << std::endl;
            return 0;
        } 
        else if(win == 2)
        {
            std::cout << "Tied!" << std::endl;
            return 0;
        }
        turn++;
    }
    return 0;
}