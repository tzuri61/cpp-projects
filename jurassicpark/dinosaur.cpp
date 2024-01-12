#include "dinosaur.h"
#include <iostream>
#include <random>
using std::endl;
using std::cout;

dinosaur::dinosaur(string race, string creature, int maxweight, int growthrate, char kindofrace, int breedchance)
    : race(race), maxweight(maxweight),growthrate(growthrate), creature(creature), kindofrace(kindofrace), breedchance(breedchance)
    {
        if(kindofrace == 'h')
        {
            currentweight = maxweight * 0.05;
        }
        else
            currentweight = maxweight * 0.20;
    }

std::random_device rd;

    int dinosaur::getRandom(int lower, int upper)
    {
        std::uniform_int_distribution<int> dist(lower, upper);
        return dist(rd);
    }


bool dinosaur::age(int current_weight, int maxweight, int growthrate)
{
    int deathchance;

        if(current_weight == maxweight)
        {
        deathchance = dinosaur::getRandom(0,100);
            if(growthrate <= deathchance){


                return true;
            }
            else
            {
                return false;
            }
        }
        else if(current_weight < maxweight)
        {
            switch(growthrate)
            {
            case 20:
                currentweight *= 1.2;
                break;
            case 40:
                currentweight *= 1.4;
                break;
            case 30:
                currentweight *= 1.3;
                break;
            }

            if(currentweight > maxweight)
            {
                currentweight = maxweight;
            }

            return false;
        }
        return false;

}

int dinosaur::GetMaxweight()
{
    return maxweight;
}

int dinosaur::Getgrowthrate()
{
    return growthrate;
}

int dinosaur::Getbreedchance()
{
    return breedchance;
}

string dinosaur::getcreature()
{
    return creature;
}

int dinosaur::Getcurrentweight()
{
    return currentweight;
}

char dinosaur::Getkindofrace()
{
    return kindofrace;
}


bool dinosaur::breed(int breedchance, string creature_current, string creature_next)
{
    int breednumber;
    if(creature_current == creature_next)
    {
        breednumber = dinosaur::getRandom(0,100);
        if(breedchance >= breednumber)
        {

            return true;
        }
        else
            return false;
    }
    else
        return false;
}

void dinosaur::print()
{
    cout << "currentweight: " << currentweight << endl;
    cout << "maxweight: " << maxweight << endl;
    cout << "growthrate: " << growthrate << endl;
}
