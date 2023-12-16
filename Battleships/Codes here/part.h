/**
 * \file
 * \date 08.12.2019
 * \author Michael Roth
 * This is the header file for the \ref Part class.
 * The \ref Part class is used to represent on piece (or part)
 * of a \ref Ship for the \ref Battleship game
 */

#ifndef PART_H
#define PART_H

/**
 * @brief The Part class represents a part of a \ref Ship in the context of the
 * \ref Battleship game.
 *
 * One object of Part is located at a specific * position denoted by row and
 * column. Multiple Part objects make up one object of \ref Ship, as a matter of
 * fact there is a composition association between those two.
 *
 * A ship's part has a status which indicates wether it is damaged or not.
 * A part of a ship does neither 'know' to which ship it belongs neither if that
 * ship is already sunk or not.
 *
 */
class Part
{
  public:
  /**
   * @brief Part constructor
   * @param[in] row The grid row on which this part is to be placed
   * @param[in] col The grid column on which this part is to be placed
   *
   * This is supposed to be the only Part constructor. The values for \ref m_row
   * and \ref m_col shall be assigned from `row` and `col` respectively.
   * The status \ref m_status shall be initialized with 0. indicating 'no
   * damage'.
   */
  Part(int row, int col);

  /**
   * @brief Returns wether or not this part is damaged
   * @return True if damaged, False if undamaged
   *
   * Note that there is no extra status for a sunken \ref Ship.
   * By definition, a ship is sunk when all parts were hit, e.g. are damaged.
   */
  bool isDamaged() const;

  /**
   * @brief Sets the status of this part to a value representing 'damaged'.
   *
   * The attribute \ref m_status is supposed to be 0 if there is no damage,
   * and 1 if this part was damaged.
   * This method shall thereby set \ref m_status to 1.
   */
  void setDamaged();

  /**
   * @brief Returns the row with which this part was constructed
   * @return The row with which this part was constructed
   */
  int getRow() const;

  /**
   * @brief Returns the column with which this part was constructed
   * @return The column with which this part was constructed
   */
  int getCol() const;

  private:
  /**
   * @brief The row where this part is located on the grid.
   */
  int m_row;

  /**
   * @brief The column where this part is located on the grid.
   */
  int m_col;

  /**
   * @brief Status of the part as integer value
   *
   * 0 means 'No Damage'
   * 1 means 'Damaged'
   */
  int m_status;
};

#endif // PART_H
