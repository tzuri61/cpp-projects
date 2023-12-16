#include "battleship.h"

Battleship::Battleship(const string &player1Name, const string &player2Name)
    : m_players(array<Player, 2>{Player(player1Name),Player(player2Name)})
{
}

int Battleship::getRandom(int lower, int upper)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(lower, upper);
    return dist(rd);
}


void Battleship::play()
{


    m_boards[0] = GameBoard();
    m_boards[1] = GameBoard();
    int row, col;
    int turnOfPlayer = rand() % 2;
    int enemy = (turnOfPlayer +1) % 2;

    while(true){


        cout << m_players[turnOfPlayer].getName() << "'s turn." << endl;

        cout << "Your cheat sheet a.k.a. enemy board: " << endl;

        m_boards[turnOfPlayer].printEnemyBoard();

        cout << "Your own board: " << endl;

        m_boards[turnOfPlayer].printBoard();

        cout << "Enter coordinates: " << endl;
        cout << "row=";
        std::cin >> row;
        cout << "column=";
        std::cin >> col;
        bool hit = m_boards[enemy].hit(row, col);

        m_boards[turnOfPlayer].mark(row, col, hit);
        m_boards[turnOfPlayer].printEnemyBoard();

        if(hit)
        {
            if(m_boards[enemy].allShipsSunk())
            {
                m_players[enemy].addGameLost();
                m_players[turnOfPlayer].addGameWon();
                cout << m_players[turnOfPlayer].getName() << " won!" << endl;
                break;
            }
        }
        else
        {
            turnOfPlayer = enemy;
            enemy = (turnOfPlayer +1) % 2;
        }
    }

    cout << turnOfPlayer << "s Statistik:" << endl
         << "Verlorene Spiele: " << m_players[turnOfPlayer].getGamesLost() << endl
         << "Gewonnene Spiele: " << m_players[turnOfPlayer].getGamesWon() << endl;

    cout << enemy << "s Statistik:" << endl
         << "Verlorene Spiele: " << m_players[enemy].getGamesLost() << endl
         << "Gewonnene Spiele: " << m_players[enemy].getGamesWon() << endl;

}
