#include <iostream>

#include "player.h"

using namespace std;

// Player::Player(string name, int turn, int victories, int defeats, int playerNumber)
// {
//     _name = name;
//     _victories = victories;
//     _defeats = defeats;
//     _playerNumber = playerNumber;
// }

Player::Player()
{
    _name = "";
    _turn = 0;
    _victories = 0;
    _defeats = 0;
    _playerNumber = -1;
}

void Player::setName()
{
    cin >> _name;
}

void Player::setPlayerNumber(int number)
{
    _playerNumber = number;
}

void Player::setItsYourTurn()
{
    _turn = 1;
    cout << "It's " << _name << "'s turn now!" << endl;
}

void Player::setItsNotYourTurn()
{
    _turn = 0;
}

string Player::getName()
{
    return _name;
}

int Player::getPlayerNumber()
{
    return _playerNumber;
}

int Player::getVictories()
{
    return _victories;
}

int Player::getDefeats()
{
    return _defeats;
}

void Player::addVictory()
{
    _victories = +1;
}

void Player::addDefeat()
{
    _defeats = +1;
}

Player::~Player()
{
}

void setBothPlayersNumbers(Player* player1, Player* player2)
{
    cout << "Player 1 - Enter your number that's your unique identifier: ";
    int number;
    cin >> number;
    if (cin.fail()) {
        cout << "Please enter a number." << endl;
        cin.clear();
        cin.ignore();
        setBothPlayersNumbers(player1, player2);
    }
    else if (number == 0)
    {
        cout << "You can choose any number but 0 amigo." << endl;
        setBothPlayersNumbers(player1, player2);
    }
    player1->setPlayerNumber(number);

    cout << "Player 2 - Enter your number that's your unique identifier: ";
    cin >> number;
    if (cin.fail()) {
        cout << "Please enter a number." << endl;
        cin.clear();
        cin.ignore();
        setBothPlayersNumbers(player1, player2);
    }
    else if (number == 0)
    {
        cout << "You can choose any number but 0 amigo." << endl;
        setBothPlayersNumbers(player1, player2);
    }
    player2->setPlayerNumber(number);

    if (player1->getPlayerNumber() == player2->getPlayerNumber())
    {
        cout << "Please choose different numbers. Your numbers are unique identifiers." << endl;
        setBothPlayersNumbers(player1, player2);
        return;
    }

}