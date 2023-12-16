/**
 * \file
 * \date 08.12.2019
 * \author Michael Roth
 * This is the header file for the \ref Player class.
 * This class is used for storing player Names and some sort of highscore table.
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using std::string;

/**
 * @brief The Player class represents a single player for the \ref Battleship
 * game.
 *
 * Objects of this class store
 *   - The player's name
 *   - How many games where won
 *   - How many games where lost
 */
class Player
{
  public:
  /**
   * @brief Player constructor.
   * @param[in] playerName The player's name.
   *
   * The attribute \ref m_playerName shall be initialized with the
   * `playerName` parameter.
   *
   * The attributes \ref m_gamesWon and \ref m_gamesLost
   * shall be initialized with 0.
   */
  Player(const string& playerName);

  /**
   * @brief Get games won.
   * @return The number of games which were won by this player.
   */
  int getGamesWon() const;

  /**
   * @brief Get games lost.
   * @return The number of games which were lost by this player.
   */
  int getGamesLost() const;

  /**
   * @brief Get games played.
   * @return The total number of games this player has played.
   *
   * \see getGamesWon
   * \see getGamesLost
   */
  int getGamesPlayed() const;

  /**
   * @brief Add another won game.
   *
   * This shall increase the number of won games by 1.
   */
  void addGameWon();

  /**
   * @brief Add another lost game.
   *
   * This shall increase  the number of lost games by 1
   */
  void addGameLost();

  /**
   * @brief Get the player's name
   * @return The player's name
   */
  string getName();

  private:
  /**
   * @brief Number of games won.
   */
  int m_gamesWon;

  /**
   * @brief Number of games lost.
   */
  int m_gamesLost;

  /**
   * @brief The player's name.
   */
  string m_playerName;
};

#endif // PLAYER_H
