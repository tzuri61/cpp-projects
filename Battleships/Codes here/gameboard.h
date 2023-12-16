/**
 * \file
 * \date 08.12.2019
 * \author Michael Roth
 * This is the header file for the \ref GameBoard class which represents the
 * game board(s) for a single player.
 */

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "ship.h"
#include <random>

#include <array>
using std::array;

/**
 * @brief The GameBoard class
 *
 * This class contains everything that a single player needs in order to play.
 * First of all, this class contains an array of one's own ships. Furthermore it
 * contains a map of locations where Player A has tried to hit ships from Player
 * B.
 *
 * The primary functions of this board are \ref hit which represents
 * a shot from the enemy. The \ref hit function handles the shot and returns
 * true if any ship was actually hit by that shot. The other important function
 * is \ref mark which is used to mark positions where the player tried to hit
 * enemy ships.
 *
 * Every Player needs one instance of this in order to:
 *
 *   - Have a registry where her own ships are located
 *   - Have an idea where she has already tried to hit her enemy's ships
 *
 * Note that while the enemy board is represented as a two dimensional array of
 * `char` values, the own registry exists simply as `vector` of \ref Ship
 * objects.
 *
 * Also, this class has the neccessary functions functions to print both of
 * those boards.
 *
 * Note that Battleships is played on a 10 x 10 board, with valid rows and
 * columns ranging from 0 to 9.
 */
class GameBoard
{
  public:
  /**
   * @brief GameBoard constructor
   *
   * This shall initialize the enemy board (attribute \ref m_enemyBoard) with
   * dot characters '.'. The player's ships can either be placed here also, or
   * later by calling \ref randomPlaceShips.
   *
   *
   */
  GameBoard();

  /**
   * @brief Prints the player's board.
   *
   * This function prints the player's board to the console screen. You are
   * relatively free to be creative here, but make sure that all ships are
   * displayed properly.
   *
   * Some suggestions are:
   *
   *   - A location containing water is represented by printing '.'
   *   - A location containing an intact (e.g. undamaged) ship part is
   * represented by its ship number (e.g. the ships index in the array)
   *   - A location containing a damaged ship part of an **unsunken ship** is
   * represented by an 'X'
   *   - A location containing a part of a sunken ship is represented by an 'S'
   *
   * You can, as mentioned before, use other characters, but those four types of
   * locations should be distinguishable from another.
   */
  void printBoard();

  /**
   * @brief Prints the 'cheat sheet', containing markings where this player has
   * hit or missed.
   *
   * When trying to hit the other player's ships, it does not make sense to
   * shoot the same location more than once. In order to 'memorize' those
   * locations, the two-dimensional array is used. In there, the characters have
   * the following meanings:
   *
   *   - '.' represents a location which has not yet beens shot
   *   - 'X' represents a hit ship at that locations
   *   - 'O' represents a shot into open water
   *
   * As with \ref printBoard you are free to change the characters if you fancy
   * something else.
   */
  void printEnemyBoard();

  /**
   * @brief The enemy player's shot on our board
   * @param[in] row The row where we are being shot
   * @param[in] col The column where we are being shot
   * @return True if the shot hit any of our ships, false otherwise.
   *
   * This function is called when the enemy is trying to hit any of our ships.
   * Generally a shot is directed at a specific location denoted by `row` and
   * `col`.
   *
   * If there is a ship part at that location, that part shall be damaged by
   * that shot.
   *
   * \see Part::setDamaged
   * \see printBoard
   */
  bool hit(int row, int col);

  /**
   * @brief Mark locations on the enemy board where we already shot at
   * @param[in] row The row where we shot
   * @param[in] col The column where we shot
   * @param[in] wasHit True if the shot was a hit (e.g. we hit a ship)
   *
   * This function shall make a mark on the 'cheat sheet'. The mark shall be
   * different depending on if we hit something there.
   *
   * \see hit
   * \see printEnemyBoard
   */
  void mark(int row, int col, bool wasHit);

  /**
   * @brief Randomly place ships.
   *
   * This function randomly places ships on the board, e.g. it populates the
   * \ref m_ships vector.
   *
   * The following ships shall be placed:
   *   - 1 'Dreadnought' with 5 parts
   *   - 2 'Cruisers' with 4 parts
   *   - 3 'Destroyers' with 3 parts
   *   - 4 'Submarines' with 2 parts
   *
   * The ships shall be placed so that:
   *   - No ships intersect each other
   *   - No ship has parts outside the playing area
   *   - When this is called for both players, the resulting placements shall be
   * different
   *
   */
  void randomPlaceShips();

  /**
   * @brief Test if all ships are sunk
   * @return True if all ships on this board are sunk
   *
   * This function is used to determine if the player has lost the game. As a
   * reminder: The player has lost the game when she has no floating ship left.
   */
  bool allShipsSunk();

  private:

  int getRandom(int lower, int upper);

  Direction intToDirection(int dir);

  void subRandomPlaceShips(int lengthOfShip, int amountOfShip, int shipCounter);

  bool checkField(int row, int col, int lengthOfShip, Direction direction);
  /**
   * @brief The player's ships
   *
   * This is the collection of the player's ships. Since there are always 10 ships
   * on the board, we can use a simple `std::array`.
   */
  array<Ship, 10> m_ships;

  /**
   * @brief The 'cheat sheet'
   *
   * This is a two-dimensional Array of `char` values. What this means is that
   * we use an `std::array<char, 10>` to represent a row. Then, a collection of
   * 10 of such rows finally is a grid, our two-dimensional structure.
   *
   * So the datatype for this is `array< array<char, 10>, 10 >`.
   *
   */
  array<array<char, 10>, 10> m_enemyBoard;
};

#endif // GAMEBOARD_H
