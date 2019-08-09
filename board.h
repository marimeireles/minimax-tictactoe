#pragma once

#include <string>

#include "player.h"

using namespace std;

class Board {
private:
    Player _player1, _player2;
    int **_ticTacToeBoard;

public:
    Board(Player player1, Player player2);
    void printStatus(Player* player1, Player* player2);
    void initializeTicTacToeBoard();
    void makeAMove(string);
    void printBoard(Player* player1, Player* player2);
    bool play(Player player, int* coord);
    void setCoordsTicTacToeBoard(int* coord, int playerNumber);
    bool checkVictoryConditions();
};
