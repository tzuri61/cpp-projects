#include "gameboard.h"
#include <array>
using std::cout;
using std::array;
using std::endl;

    gameboard::gameboard() //Initialisieren
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++){

                board[i][j] = '.';

            }
        }
    }

    void gameboard::boardprint(int playerturn) //printet alles
    {
        cout << "Player " << playerturn + 1 << " turn";
        for(int i = 0; i < board.size(); i++)
        {
            cout << i << endl;
            for(int j = 0; j < 3; j++)
            {
                
                switch(board[i][j])
                {
                    case '.':
                    cout << " . ";
                    break;
                    case 'X':
                    cout << " X ";
                    break;
                    case 'O':
                    cout << " O ";
                    break;
                }
                    cout << "\n";
            }
        }
    }

void gameboard::boardmark(int playerturn)
{
    int row, col;
    do{
        cout << "Enter coordinates:" << endl;
        cout << "row: ";
        cin >> row;
        cout <<"col: ";
        cin >> col;
    }while(board[row][col] != '.');

    switch(playerturn)
    {
        case 0:
        board[row][col] = 'X';
        break;
        case 1:
        board[row][col] = 'O';
        break;
    }
 
}

bool gameboard::result()
{
    
    if (board[0][0]== 'X' && board[0][1]=='X' && board[0][2]=='X')
    {
        return true;
    }
    if (board[1][0]=='X' && board[1][1]=='X' && board[1][2]=='X')
    {
        return true;
    }
    if (board[2][0]=='X' && board[2][1]=='X' && board[2][2]=='X')
    {
        return true;
    }
    if (board[0][0]=='X' && board[1][0]=='X' && board[2][0]=='X')
    {
        return true;
    }
    if (board[0][1]=='X' && board[1][1]=='X' && board[2][1]=='X')
    {
        return true;
    }
    if (board[0][2]=='X' && board[1][2]=='X' && board[2][2]=='X')
    {
        return true;
    }
    if (board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X')
    {
        return true;
    }
    if (board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X')
    {
        return true;
    }
    if (board[0][0]== 'O' && board[0][1]=='O' && board[0][2]=='O')
    {
        return true;
    }
    if (board[1][0]=='O' && board[1][1]=='O' && board[1][2]=='O')
    {
        return true;
    }
    if (board[2][0]=='O' && board[2][1]=='O' && board[2][2]=='O')
    {
        return true;
    }
    if (board[0][0]=='O' && board[1][0]=='O' && board[2][0]=='O')
    {
        return true;
    }
    if (board[0][1]=='O' && board[1][1]=='O' && board[2][1]=='O')
    {
        return true;
    }
    if (board[0][2]=='O' && board[1][2]=='O' && board[2][2]=='O')
    {
        return true;
    }
    if (board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O')
    {
        return true;
    }
    if (board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O')
    {
        return true;
    }


    return false;

 
}

bool gameboard::checkfields()
{
    int counter = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            
            if(board[i][j] != '.')
            {
                counter++;
                if(counter == 9)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
