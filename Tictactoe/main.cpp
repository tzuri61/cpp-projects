#include <iostream>
#include "gameboard.h"

int main(){
    int playerturn = 1;

    gameboard b;

    do
    {
        playerturn = (playerturn + 1) % 2;
        b.boardprint(playerturn);
        b.boardmark(playerturn);
        if(b.checkfields() == true)
        {
            break;
        }
    }
    while(!b.result());

    if(b.result())
    {
        cout << "player " << playerturn + 1 << "won" << endl;
    }
    else{
        cout << "draw" << endl;
    }

}
