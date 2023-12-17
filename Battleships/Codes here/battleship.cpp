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

        do
        {
            cout << "Enter coordinates: " << endl;
            cout << "row=";
            std::cin >> row;
            cout << "column=";
            std::cin >> col;
            if(row > 9 || col > 9 || row < 0 || col < 0)
            {
                cout << "\nno...try again..." << endl;
            }
        }
        while(row > 9 || col > 9 || row < 0 || col < 0);
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
            turnOfPlayer = enemy;
            enemy = (turnOfPlayer +1) % 2;
        }
        else
        {
            turnOfPlayer = enemy;
            enemy = (turnOfPlayer +1) % 2;
        }
    }

    cout << m_players[turnOfPlayer].getName() << "s statistics:" << endl
         << "defeats: " << m_players[turnOfPlayer].getGamesLost() << endl
         << "wins: " << m_players[turnOfPlayer].getGamesWon() << endl;

    cout << m_players[enemy].getName() << "s statistics:" << endl
         << "defeats: " << m_players[enemy].getGamesLost() << endl
         << "wins: " << m_players[enemy].getGamesWon() << endl;

}
