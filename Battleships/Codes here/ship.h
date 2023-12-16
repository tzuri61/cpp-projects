/**
 * \file
 * \date 08.12.2019
 * \author Michael Roth
 * This is the header file for the \ref Ship class.
 * A Ship is, in this context, a composite collection of \ref Part objects,
 * where the part objects make up the ship.
 */

#ifndef SHIP_H
#define SHIP_H
#include <vector>
#include <iostream>
#include "part.h"
#include <stdexcept>

using std::vector;
using std::cout;
using std::endl;

/**
 * @brief The Direction enum, indicating in which direction a ship is pointed
 */
enum class Direction
{
  north,
  east,
  south,
  west
};

/**
 * @brief The Ship class, a collection of \ref Part objects.
 *
 * This class represents a ship for the \ref Battleship game. A ship is made up
 * of at parts, e.g. \ref Part objects which are stored using a vector.
 *
 * Ships of multiple sizes are represented by having different amount of parts:
 *
 *   - The 'Dreadnought' has 5 parts
 *   - A 'Cruiser' has 4 parts
 *   - A 'Destroyer' has 3 parts
 *   - A 'Submarine' has 2 parts
 *
 */
class Ship
{
  public:

  /**
   * @brief Ship Standard constructor
   *
   * Should do nothing. This is just needed in order for the std::array in \ref
   * GameBoard to work.
   */
  Ship();

  /**
   * @brief Ship constructor
   * @param[in] row The row where the aft part of the ship shall be placed
   * @param[in] col The column where the aft part of the ship shall be placed
   * @param[in] lengthOfShip Which length the ship shall have (usually 2 to 5)
   * @param[in] direction Which direction the ship should point to with:
   *   - 0 meaning up
   *   - 1 meaning right
   *   - 2 meaning down
   *   - 3 meaning left
   * @throws std::invalid_argument if either the direction of the ship is an
   * invalid value **or** if parts of the ship would be placed outside of the
   * 10x10 grid.
   *
   * This constructs a ship with the given parameters. The aft section of the
   * ship is always placed at the given row and column. From there on,
   * (lengthOfShip - 1) number of parts are placed in the given direction.
   *
   * If, for example, a ship shall be constructed at `row = 3` and `col = 2`,
   * a length of 3 and `direction = 1` this means the following part objects are
   * created:
   *   - Part at 3 / 2
   *   - Part at 3 / 3
   *   - Part at 3 / 4
   *
   */
  Ship(int row, int col, int lengthOfShip, Direction direction);

  /**
   * @brief Evaluates if this ship extends to the given row and col
   * @param[in] row Row which is to be checked
   * @param[in] col Column which is to be checked
   * @return True if ship extends to the field row/col, false otherwise.
   *
   * This function is used to determine wether or not a ship is present in the
   * given row and col. This is easily answered by iterating over the ship's
   * parts and checking if any of those are located on this position.
   *
   * \see getPartIn
   */
  bool hasPartIn(int row, int col);

  /**
   * @brief Returns the ship's part which is in the given row and col
   * @param[in] row Row of the Part
   * @param[in] col Column of the Part
   * @return Reference to the ship part at the given location.
   * @throws std::invalid_argument if there is no such part at the given
   * position.
   *
   * It is advised to only use this function if you are sure that the given
   * position really contains a part of this ship, e.g. calling \ref hasPartIn
   * first.
   *
   * \see hasPartIn
   */
  Part& getPartIn(int row, int col);

  /**
   * @brief Returns wether or not the ship is damaged.
   * @return True if the ship is damaged.
   *
   * A ship is considered to be damaged if there is at least one of it's parts
   * damaged. If **all** of the parts are damaged, the ship is considered to be
   * sunk, but this also counts as damaged.
   *
   * \see isSunk
   */
  bool isDamaged();

  /**
   * @brief Returns wether or not the ship is sunk.
   * @return True if the ship is sunk.
   *
   * A ship is considered to be sunk if **all** of it's parts are damaged.
   *
   * \see isDamaged
   */
  bool isSunk();

  private:
  /**
   * @brief The ship's parts
   *
   * This vector stores the \ref Part objects which make up the ship.
   */
  vector<Part> m_parts;
};

#endif // SHIP_H
