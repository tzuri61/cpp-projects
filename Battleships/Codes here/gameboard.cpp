#include "gameboard.h"

GameBoard::GameBoard()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            m_enemyBoard[i][j] = '.';
        }
    }
    randomPlaceShips();
}

void GameBoard::printBoard()
{
    int squaresize = 10; // length of one side of the square field

    for(int i = 0; i <= (squaresize + 1); i++)
    {
        if(i != squaresize)
        {
            if(i <= (squaresize - 1))
            {
                if(i >= (squaresize - 1))
                {
                    cout << i <<  " | ";
                }
                else
                {
                    cout << i <<  " | ";
                }
            }
            else
            {
                cout << "    ";
            }


            for(int j = 0; j < squaresize; j++)
            {
                if(i >= squaresize)
                {
                    cout << j << " ";
                }
                else
                {
                    bool found = false;

                    for (int k = 0; k < (int) m_ships.size(); k++) {
                        if (m_ships[k].hasPartIn(i, j)) {
                            if(m_ships[k].isSunk())
                            {
                                cout << "S" << " ";
                            }
                            else if(!m_ships[k].getPartIn(i, j).isDamaged())
                            {
                                if(k < 9)
                                {
                                    cout << k + 1 << " ";
                                }
                                else
                                {
                                    cout << k + 1;
                                }

                            }
                            else
                            {
                                cout << 'X' << " ";
                            }
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << '.' << " ";
                    }
                }
            }
            cout << endl;
        }
        else
        {
            cout << "   ";

            for(int j = 1; j <= squaresize; j++)
            {
                cout << "--";
            }
            cout << endl;
        }
    }
}

void GameBoard::printEnemyBoard()
{
    for(int i = 0; i <= 11; i++)
    {
        if(i != 10)
        {
            if(i < 10)
            {
                if(i < 9)
                {
                    cout << i << " | ";
                }
                else
                {
                    cout << i<< " | ";
                }
            }
            else
            {
                cout << "    ";
            }

            for(int j = 0; j < 10; j++)
            {
                if(i < 10)
                {

                    switch(m_enemyBoard[i][j])
                    {
                    case '.':
                            cout << ". ";
                            break;
                    case 'X':
                            cout << "X ";
                            break;
                    case 'O':
                            cout << "O ";
                            break;
                    default:
                            break;
                    }

                }
                else
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
        else
        {
            cout << "   ";

            for(int j = 0; j <= 10; j++)
            {
                cout << "--";
            }
            cout << endl;
        }

    }

}

bool GameBoard::hit(int row, int col)
{
    for(int i = 0; i < (int)m_ships.size(); i++)
    {
        if(m_ships[i].hasPartIn(row, col))
        {
            m_ships[i].getPartIn(row, col).setDamaged();
            return true;
        }
    }
    return false;
}

void GameBoard::mark(int row, int col, bool wasHit)
{
    if (wasHit)
    {
        m_enemyBoard[row][col] = 'X';
        cout << "\nTreffer!" << endl;
    }
    else
    {
        m_enemyBoard[row][col] = 'O';
        cout << "\nVerfehlt!" << endl;
    }
}

int GameBoard::getRandom(int lower, int upper)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(lower, upper);
    return dist(rd);
}

Direction GameBoard::intToDirection(int dir)
{
    switch(dir)
    {
    case 0:
        return Direction::north;
    case 1:
        return Direction::east;
    case 2:
        return Direction::south;
    case 3:
        return Direction::west;
    }
}

void GameBoard::subRandomPlaceShips(int lengthOfShip, int amountOfShip, int shipCounter)
{
    int row = 0, setRow = 0, col = 0, setCol = 0;
    int direction = 0;
    bool isShipPlaced = true;
    bool isFieldFree = true;

    for(int i = shipCounter; i < (amountOfShip + shipCounter); i++)
    {
        while(true)
        {
            row = getRandom(0, 9);
            col = getRandom(0, 9);
            direction = getRandom(0, 3);
            setRow = row;
            setCol = col;
            isShipPlaced = true;
            isFieldFree = true;

            if(!checkField(row, col, lengthOfShip, intToDirection(direction)))
            {
                continue;
            }

            for(int i = 0; i < lengthOfShip; i++)  //erste schleife geht 5 felder durch
            {
                isFieldFree = true; //zum prüfen

                for(int j = 0; j < (int)m_ships.size(); j++) //zweite schleife prüft ob das feld besetzt ist
                {
                    if(m_ships[j].hasPartIn(row, col)) //die prüfung
                    {
                            isShipPlaced = false;
                            isFieldFree = false;
                            break; // break wenn ein schiff da ist
                    }
                }
                if(isFieldFree)
                {
                    switch(direction) //bewegt das feld um eins in die richtung des schiffes
                    {
                    case 0:
                            row--;
                            break;
                    case 1:
                            col++;
                            break;
                    case 2:
                            row++;
                            break;
                    case 3:
                            col--;
                            break;
                    }
                }
                else
                {
                    break;
                }
            }
            if(isShipPlaced)
            {
                m_ships[i] = Ship(setRow, setCol, lengthOfShip, intToDirection(direction));
                break;
            }
        }
    }
}

void GameBoard::randomPlaceShips()
{
    int dreadnoughtLength  = 5, dreadnought = 1;      //has 5 parts, is placed once
    int cruiserLength      = 4, cruiser     = 2;      //has 4 parts, is placed twice
    int destroyerLength    = 3, destroyer   = 3;      //has 3 parts, is placed thrice
    int submarineLength    = 2, submarine   = 4;      //has 2 parts, is placed four times
    int shipCounter = 0;


    subRandomPlaceShips(dreadnoughtLength, dreadnought, shipCounter);
    shipCounter += dreadnought;

    subRandomPlaceShips(cruiserLength, cruiser, shipCounter);
    shipCounter += cruiser;

    subRandomPlaceShips(destroyerLength, destroyer, shipCounter);
    shipCounter += destroyer;

    subRandomPlaceShips(submarineLength, submarine, shipCounter);
    shipCounter += submarine;

}

bool GameBoard::allShipsSunk()
{
    for(int i = 0; i < (int)m_ships.size(); i++)
    {
        if(!m_ships[i].isSunk())
        {
            return false;
        }
    }
    return true;
}

bool GameBoard::checkField(int row, int col, int lengthOfShip, Direction direction)
{
    switch(direction){
    case Direction::north:
        if((row - lengthOfShip) < 0)
        {
            return false;
        }

        return true;

    case Direction::east:
        if((col + lengthOfShip) > 9)
        {
            return false;
        }

        return true;

    case Direction::south:
        if((row + lengthOfShip) > 9)
        {
            return false;
        }

        return true;

    case Direction::west:
        if((col - lengthOfShip) < 0)
        {
            return false;
        }

        return true;
    }
}


//randomPlaceShips kann auch mit switch case gelöst werden
//statt den for schleifen für die verschiedenen Schiffe
//es bedarf allerdings einiger tests
