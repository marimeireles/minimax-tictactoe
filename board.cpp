#include <string>
#include <iostream>
#include <set>

#include "board.h"

Board::Board(Player player1, Player player2)
    : _player1(player1)
    , _player2(player2)
{
}

void Board::printStatus(Player* player1, Player* player2)
{
    cout << endl << "Player 1: " << player1->getName() << " - Victories: " << player1->getVictories() << " Defeats: " << player1->getDefeats() << endl;
    cout << "Player 2: " << player2->getName() << " - Victories: " << player2->getVictories() << " Defeats: " << player2->getDefeats() << endl << endl;
}

void Board::initializeTicTacToeBoard()
{
    _ticTacToeBoard = (int**)calloc(3, sizeof(int*));
    for (int i = 0; i < 3; ++i)
    {
        _ticTacToeBoard[i] = (int*)calloc(1, sizeof(int));
    }
}

void Board::printBoard(Player* player1, Player* player2)
{
    cout << "      0           1           2" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << endl;
        cout << i;
        for (int j = 0; j < 3; ++j)
        {
            if (_ticTacToeBoard[i][j] == 0)
                cout << "      ";
            else if (_ticTacToeBoard[i][j] == player1->getPlayerNumber())
                cout << "     X";
            else if (_ticTacToeBoard[i][j] == player2->getPlayerNumber())
                cout << "     O";
            if (j != 2)
                cout << "     |";
        }
        if (i != 2)
            cout << endl << endl << " ----------------------------------" << endl;
    }
    cout << endl << endl;
}

void Board::setCoordsTicTacToeBoard(int* coord, int playerNumber)
{
    cout << "Type the coordinate that you want to mark: ";
    cin >> coord[0] >> coord[1];
    cout << endl;
    if (cin.fail()) {
        cout << "Please type a valid coordinate. An example of coordinates is 0 0." << endl;
        cin.clear();
        cin.ignore();
        setCoordsTicTacToeBoard(coord, playerNumber);
    }
    else if(_ticTacToeBoard[coord[0]][coord[1]] != 0)
    {
        cout << "This position was already marked. Choose another one!" << endl;
        setCoordsTicTacToeBoard(coord, playerNumber);
    }
    else if (((coord[0] < 0) || (coord[1] < 0)) || ((coord[0] >= 3) || (coord[1] >= 3)))
    {
        cout << "Please type a valid coordinate." << endl << endl;
        setCoordsTicTacToeBoard(coord, playerNumber);
    }
    else
    {
        _ticTacToeBoard[coord[0]][coord[1]] = playerNumber;
        return;
    }
}

bool Board::checkVictoryConditions()
{
    //horizontal win logic
    set<int> memmoryHorizontal[3];

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
                memmoryHorizontal[i].insert(_ticTacToeBoard[i][j]);
        }
        if (((memmoryHorizontal[i].size() == 1) && (memmoryHorizontal[i].find(0) == memmoryHorizontal[i].end())))
        {
            return true;
        }
    }

    //vertical win logic
    set<int> memmoryVertical[3];

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
                memmoryVertical[i].insert(_ticTacToeBoard[j][i]);
        }
        if (((memmoryVertical[i].size() == 1) && (memmoryVertical[i].find(0) == memmoryVertical[i].end())))
        {
            return true;
        }
    }

    //diagonal win logic
    if (_ticTacToeBoard[0][0] == _ticTacToeBoard[1][1] && _ticTacToeBoard[1][1] == _ticTacToeBoard[2][2] && _ticTacToeBoard[0][0] != 0)
    {
        return true;
    }
    else if (_ticTacToeBoard[0][2] == _ticTacToeBoard[1][1] && _ticTacToeBoard[1][1] == _ticTacToeBoard[2][0] && _ticTacToeBoard[0][2] !=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Board::play(Player player, int* coord)
{
    setCoordsTicTacToeBoard(coord, player.getPlayerNumber());
    return checkVictoryConditions();
}
