#include "battleship.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Please enter first player name:";
    string player1Name;
    cin >> player1Name;

    cout << "Please enter second player name:";
    string player2Name;
    cin >> player2Name;

    Battleship battleship(player1Name, player2Name);

    const int exit = 2;
    int choose = 0;

    while (choose != exit)
    {
        cout << "MENU:" << endl;
        cout << "1 - start battleship" << endl;
        cout << "2 - exit" << endl;
        cout << "choose:";
        cin >> choose;

        if (choose == 1)
        {
            battleship.play();
        }
    }
}
