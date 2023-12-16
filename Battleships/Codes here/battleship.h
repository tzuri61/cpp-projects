/**
 * \file
 * \date 08.12.2019
 * \author Michael Roth
 * This is the header file for the \ref Battleship class, which is the main
 * class for the game.
 * This class holds two \ref Player objects as well as their corresponding \ref
 * GameBoard objects.
 */

#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "gameboard.h"
#include "player.h"
#include <random>

#include <string>
using std::string;

#include <array>
using std::array;

/**
 * @brief The Battleship class
 *
 * This is the main class of the game. An object is constructed by supplying two
 * player names. One game round is then started by simply calling the \ref play
 * function.
 *
 * The Players and their boards are stored in Arrays to make the implementation
 * of the game logic easier.
 *
 * **Note:** If you find that confusing, you are welcome the change the Arrays
 * into something else, or have two attributes per player.
 */
 class Battleship
{
  public:
  /**
   * @brief Battleship constructor
   * @param[in] player1Name Name of the first player
   * @param[in] player2Name Name of the second player
   */
  Battleship(const string& player1Name, const string& player2Name);

  /**
   * @brief Play one game of Battleships!
   *
   * This function shall do the following:
   *
   *     - Initialize both players' game boards:
   *     - The ships shall be placed at randomized locations
   *     - The 'cheat sheets' shall be empty
   *     - This can easily be achieved by creating new \ref GameBoard objects
   * and storing them in \ref m_boards, overwriting the old boards which may be
   * there already
   *
   * Then, do the following in a loop:
   *   1. Determine the active Player either by random coin toss or first player
   * always gets to start
   *   2. Print both the game board and the 'cheat sheet' for the active player
   *   3. Ask the active player a location she wants to shoot at
   *   4. Call the \ref GameBoard::hit function for that location on the
   * **inactive** Player's board
   *   5. Inform the active player if she hit something and make the correct
   * mark on the cheat sheet
   *   6. Switch the players, e.g. active player becomes inactive and inactive
   * Player becomes active
   *   7. Repeat Steps 1 to 6 until one player has lost
   *   8. Exit the function
   *
   */
  void play();

  private:

  int getRandom(int lower, int upper);

  /**
   * @brief Array containing the two \ref Player objects
   */
  array<Player, 2> m_players;

  /**
   * @brief Array containing the two \ref GameBoard objects, one for each player
   */
  array<GameBoard, 2> m_boards;
};

#endif // BATTLESHIP_H
