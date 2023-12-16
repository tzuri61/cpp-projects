#include <iostream>
#include <array>
#include <random>
#include "header.h"
using namespace std;

bool PlayerActive = true;


int unreaveled_counter = 0;
int revealed_counter = 0;
int number_of_fields = 0;
bool boom = false;
int const mine_number = 15;





int main()
{
    bool mine_see_mode = true;
    int mine_see = 0;

    cout << "Herzlich Willkommen zu Minesweeper" << endl;
    cout << "\n" << endl;

    bool WantPlay = true;
    while(WantPlay == true)
    {

        cout << "Wollen Sie die Minen ausgegeben bekommen?(1 für Ja, 0 für Nein)" << endl;
                    cin >> mine_see;


        if(mine_see == 1)
        {
            mine_see_mode = true;
        }
        else
        {
            mine_see_mode = false;
        }


        void initialize();;
        set_mine(mine_number);
        neighbour_mines();
        bool LOSE = false;
        do
        {

            cout << "Anzahl der Mienen: " << mine_number << endl;
            cout << "verdeckte Felder: " << numbersofunrevealedfields() << endl;
            display(mine_see_mode);
            bool a = isthereamine();
            if(a == false)
            {
                cout << "\nDu hast verloren" << endl;
                LOSE = true;
            }

            checkNeighbours();
            hey_neighbour();
            if(mine_number == numbersofunrevealedfields())
            {
                cout << "----------------------------------------" << endl;
                cout << "HERZLICHEN GLÜCKWUNSCH DU HAST GEWONNEN"  << endl;
                        cout << "----------------------------------------" << endl;
                LOSE = true;
            }
        }
        while(LOSE == false);

        return 0;


    }



}
