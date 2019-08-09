#include <regex>
#include <string>
#include <iostream>

#include "player.h"
#include "board.h"

using namespace std;

int selectsGameplay(string userChooseGameplay, string firstOption, string secondOption)
{
    regex r("\\b" + userChooseGameplay + "\\b");
    smatch m;

    if (regex_search(firstOption, m, r))
    {
        cout << "You chose to play with a friend!" << '\n';
        return 1;
    }
    else if (regex_search(secondOption, m, r))
    {
        cout << "You chose to play against the machine!" << '\n';
        return 2;
    }
    else
    {
        cout << "I'm sorry, but I couldn't understand what you meant. Either type the number of the option you want to play or part of the text itself." << endl;
        cin >> userChooseGameplay;
        return selectsGameplay(userChooseGameplay, firstOption, secondOption);
    }
}

int main(int argc, char const *argv[])
{
    cout << "Tic Tac Toe\n" << endl;
    cout << "Would you like to play against a friend or the computer?" << endl;
    string firstOption = "1. Play against a friend";
    string secondOption = "2. Play against the computer";
    cout << firstOption << "   " << secondOption << endl;
    string userChooseGameplay;
    cin >> userChooseGameplay;

    int gamePlay = selectsGameplay(userChooseGameplay, firstOption, secondOption);

    Player player1, player2;

    Board board(player1, player2);

    //set players' information
    cout << endl << "Player 1 - Enter your name: ";
    player1.setName();
    cout << "Player 2 - Enter your name: ";
    player2.setName();

    setBothPlayersNumbers(&player1, &player2);

    game:
        bool win = false;
        switch(gamePlay)
        {
            case 1:
                board.printStatus(&player1, &player2);
                board.initializeTicTacToeBoard();
                board.printBoard(&player1, &player2);

                int coord[2];
                while(!win)
                {
                    player1.setItsYourTurn();
                    if(board.play(player1, coord))
                    {
                        board.printBoard(&player1, &player2);
                        cout << "The game is over. " << player1.getName() << " won this one." << endl;
                        player1.addVictory();
                        player2.addDefeat();
                        board.printStatus(&player1, &player2);
                        break;
                    }
                    board.printBoard(&player1, &player2);
                    player1.setItsNotYourTurn();

                    player2.setItsYourTurn();
                    if(board.play(player2, coord))
                    {
                        board.printBoard(&player1, &player2);
                        cout << "The game is over. " << player2.getName() << " won this one." << endl;
                        player2.addVictory();
                        player1.addDefeat();
                        board.printStatus(&player1, &player2);
                        break;
                    }
                    board.printBoard(&player1, &player2);
                    player2.setItsNotYourTurn();
                }
                cout << "Would you like to play again?" << endl;
                cout << "Press any key and then 'Enter' to keep playing or 'ESC' and then 'Enter' to quit the game." << endl;
                char again;
                cin >> again;
                if (again != 27)
                {
                    goto game;
                }
                else
                {
                    cout << "Byee!" << endl;
                    return 0;
                }
            case 2:
                cout << "Not implemented yet" << endl;
    }
}
