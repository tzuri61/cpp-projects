#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <iostream>
#include <array>
using namespace std;

class gameboard
{
    private:
    array<array<char,3>,3>board;//baord xD


    public:

    gameboard();//initialiseren

    void boardmark(int playerturn);//markiert mit x oder o

    void boardprint(int playerturn);//printet board

    bool result();//gewonnen?

    bool checkfields();//freie felder?

};

#endif // GAMEBOARD_H