#pragma once

#include <string>

using namespace std;

class Player
{
public:
    ~Player();
    // Player(string name, int turn, int victories, int defeats);
    Player();

    string getName();
    int getPlayerNumber();
    int getVictories();
    int getDefeats();
    void setName();
    void setItsYourTurn();
    void setItsNotYourTurn();
    void setPlayerNumber(int);
    void addVictory();
    void addDefeat();

private:
    string _name;
    int _turn, _victories, _defeats, _playerNumber;
};

void setBothPlayersNumbers(Player* player1, Player* player2);