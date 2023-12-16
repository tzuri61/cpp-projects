#ifndef HEADER_H
#define HEADER_H

enum Allocation{ //enum für den status, was auf das Feld zutrifft
    hidden,
    revealed,
    mine,
    };

struct Tile
{
    int sumofmines;
    Allocation allocmode;
};

void initialize();

void set_mine(int mine_random);

void neighbour_mines();

bool revealedemptyneighbour(int ro, int cu);

void display(bool mode);

bool checkNeighbours();

bool isthereamine();

void hey_neighbour();

int numbersofunrevealedfields();
#endif // HEADER_H
