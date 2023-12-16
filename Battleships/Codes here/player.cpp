#include "player.h"

Player::Player(const string& playerName)
    : m_gamesWon(0), m_gamesLost(0), m_playerName(playerName)
{
}

int Player::getGamesWon() const
{
    return m_gamesWon;
}

int Player::getGamesLost() const
{
    return m_gamesLost;
}

int Player::getGamesPlayed() const
{
    return (m_gamesLost + m_gamesWon);
}

void Player::addGameWon()
{
    m_gamesWon++;
}

void Player::addGameLost()
{
    m_gamesLost++;
}

string Player::getName()
{
    return m_playerName;
}

