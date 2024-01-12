#include "herbivore.h"
#include <iostream>
using std::cout;

bool herbivore::hide(int hide_chance)
{
    int randnum;

    randnum = dinosaur::getRandom(0,100);
    if(randnum <= hide_chance)
    {
        ishidden = true;
        return true;
    }
    else
    {
        ishidden = false;
        return false;
    }
}

bool herbivore::getishidden()
{
    return ishidden;
}

int herbivore::gethidechance()
{
    return hide_chance;
}
