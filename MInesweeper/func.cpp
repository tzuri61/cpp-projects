#include <iostream>
#include <array>
#include <random>
#include "header.h"
#include "random.h"

using namespace std;
std::random_device rd;
int cor_x = 0;
int cor_y = 0;
int const cols = 12;
int const rows = 12;
array<array<Tile, cols>, rows>board;


int getRandom(int lower, int upper)
{
    std::uniform_int_distribution<int> dist(lower, upper);
    return dist(rd);
}

void initialize()
{


    for(int i = 0 ; i < cols ;i++){
        for(int j = 0; j < rows; j++){
            board[i][j].allocmode = hidden;
            board[i][j].sumofmines = 0;
        }
    } //Alle Felder sind hidden

}

void set_mine(int mine_random)
{
    int mine_counter = 0;

    while(mine_random != mine_counter)//Minen werden zufällig gesetzt solange mine_random = mine_counter ist
    {
        int const varone = getRandom(0,11);
        int const vartwo = getRandom(0,11);
        board[varone][vartwo].allocmode = mine;
        mine_counter++;

    }

}

void neighbour_mines()
{

    for(int i = 0; i <= 11; i++){
        for(int j = 0; j <= 11; j++){

            for(int x = -1; x <= 1; x++){
                for(int y = -1; y <= 1; y++)
                {
                    if(board[i+x][j+y].allocmode == mine)
                    {
                        board[i][j].sumofmines += 1;
                    }
                }
            }
        }
    }

}

bool revealedEmptyNeighbour(int ro, int cu){

    if(board[ro][cu].sumofmines == 0 && board[ro][cu].allocmode != mine)
    {
        return true;
    }
    return false;

}

void display(bool mode)
{

    cout << "\n";
    cout << "X" << endl;
    for(int i = 0; i < rows; i++)
    {


        if(i <= 9)
        {   cout << i << " |";

        }
        else{
            cout << i << "|";
        }
        cout << "  ";
        for(int j = 0; j < cols; j++)
        {

            if(board[i][j].allocmode == hidden)
            {
                cout << " * ";
            }
            else if(board[i][j].allocmode == mine)
            {
                if(mode == true){
                    cout << " X ";
                }
                else{
                    cout << " * ";
                }
            }
            else if(board[i][j].allocmode == revealed)
            {

                if(board[i][j].sumofmines != 0)
                    cout << " " <<  board[i][j].sumofmines << " ";
                else
                    cout << " . ";
            }
        }
        cout << "\n";

    }
    cout << "    -------------------------------------" << endl;
    cout << " ";
    cout << "";
    cout << "     0  1  2  3  4  5  6  7  8  9 10 11 Y" << endl;
}


bool isthereamine()
{

    do{
        cout << "Nennen sie zuerst die Koordinate X und dann die Koordinate Y (mit Leerzeichen)" << endl;
        cin >> cor_x >> cor_y;
        if(cor_x>11||cor_x<0||cor_y>11||cor_y<0){
            cout << "nope geht nicht." << endl << endl;
        }
    }
    while(cor_x>11||cor_x<0||cor_y>11||cor_y<0);

    if(board[cor_x][cor_y].allocmode != mine)
    {
        board[cor_x][cor_y].allocmode = revealed;
        return true;
    }
    else
        return false;


}


bool checkNeighbours()
{
    for (int ro = 0; ro <= 11; ro++)
    {
        for (int cu = 0; cu <= 11; cu++)
        {
            if(board[ro-1][cu].allocmode == revealed || board[ro+1][cu].allocmode==revealed || board[ro][cu+1].allocmode==revealed || board[ro][cu-1].allocmode==revealed || board[ro-1][cu+1].allocmode==revealed || board[ro-1][cu-1].allocmode==revealed || board[ro+1][cu+1].allocmode==revealed || board[ro+1][cu-1].allocmode==revealed)
            {
                bool an = revealedEmptyNeighbour(ro, cu);
                if(an  == true)
                {

                    if(board[ro][cu].allocmode == hidden)
                    {
                        board[ro][cu].allocmode = revealed;
                    }

                }
            }
        }
    }
    return false;
}


void hey_neighbour(){
    for (int row = 0; row < 12; ++row) {
        for (int col = 0; col < 12; ++col) {
            if(board[row][col].allocmode ==revealed && board[row][col].sumofmines ==0){
                if(row-1>=0&&col-1>=0){
                    board[row-1][col-1].allocmode =revealed;
                }

                if(col-1>=0){
                    board[row][col-1].allocmode =revealed;
                }

                if(row+1<12&&col-1>=0){
                    board[row+1][col-1].allocmode =revealed;
                }

                if(row-1>=0){
                    board[row-1][col].allocmode =revealed;
                }

                if(row+1<12){
                    board[row+1][col].allocmode =revealed;
                }

                if(row-1>=0&&col+1<12){
                    board[row-1][col+1].allocmode =revealed;
                }

                if(col+1<12){
                    board[row][col+1].allocmode =revealed;
                }

                if(row+1<12&&col+1<12){
                    board[row+1][col+1].allocmode =revealed;
                }
            }
        }
    }
}


int numbersofunrevealedfields()
{
    int revealed_counter = 0;

    for(int i = 0; i < rows; i++)
        for (int l = 0; l < cols; l++) {
            if(board[i][l].allocmode == revealed)
            {
                revealed_counter++;
            }
        }

    return 144 - revealed_counter;
}
