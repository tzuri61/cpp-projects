#include "ship.h"

Ship::Ship()
{
}

Ship::Ship(int row, int col, int lengthOfShip, Direction direction)
{
    switch(direction){
    case Direction::north:
        if((row - lengthOfShip) < 0)
        {
            cout << "Du kannst dein Schiff nicht ausserhalb des Spielfeldes platzieren." << endl;
        }

        for(int i = 0; i < lengthOfShip; i++)
        {
            Part part = Part(row--, col);
            m_parts.push_back(part);
        }

        break;

    case Direction::east:
        if((col + lengthOfShip) > 9)
        {
            cout << "Du kannst dein Schiff nicht ausserhalb des Spielfeldes platzieren." << endl;
        }

        for(int i = 0; i < lengthOfShip; i++)
        {
            Part part = Part(row, col++);
            m_parts.push_back(part);
        }

        break;

    case Direction::south:
        if((row + lengthOfShip) > 9)
        {
            cout << "Du kannst dein Schiff nicht ausserhalb des Spielfeldes platzieren." << endl;
        }

        for(int i = 0; i < lengthOfShip; i++)
        {
            Part part = Part(row++, col);
            m_parts.push_back(part);
        }

        break;

    case Direction::west:
        if((col - lengthOfShip) < 0)
        {
            cout << "Du kannst dein Schiff nicht ausserhalb des Spielfeldes platzieren." << endl;
        }

        for(int i = 0; i < lengthOfShip; i++)
        {
            Part part = Part(row, col--);
            m_parts.push_back(part);
        }

        break;
    }
}

bool Ship::hasPartIn(int row, int col)
{
    for(int i = 0; i < (int)m_parts.size(); i++)
    {
        if((m_parts[i].getRow() == row) && (m_parts[i].getCol() == col))
        {
            return true;
        }
    }
    return false;
}

Part& Ship::getPartIn(int row, int col)
{
    for(int i = 0; i < (int)m_parts.size(); i++)
    {
        if((m_parts[i].getRow() == row) && (m_parts[i].getCol() == col))
        {
            return m_parts[i];
        }
    }
    throw std::invalid_argument("no part found");
}

bool Ship::isDamaged()
{
    for(int i = 0; i < (int)m_parts.size(); i++)
    {
        if(m_parts[i].isDamaged())
        {
            return true;
        }
    }
    return false;
}

bool Ship::isSunk()
{
    for(int i = 0; i < (int)m_parts.size(); i++)
    {
        if(!m_parts[i].isDamaged())
        {
            return false;
        }
    }
    return true;
}
