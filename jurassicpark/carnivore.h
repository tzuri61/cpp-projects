#ifndef CARNIVORE_H
#define CARNIVORE_H

#include "dinosaur.h"
#include <vector>
using std::vector;

class carnivore : public dinosaur
{
public:
    carnivore(string creature, int maxweight, int growthrate, char kindofrace, int breedchance, int hunt_counter)
        :dinosaur("carnivore", creature, maxweight, growthrate, kindofrace, breedchance)
    {
        this->hunt_counter = hunt_counter;
    }

    int GetHuntCounter();

    bool hunt(int herbi_currentweight, int carni_currentweight, int hunt_counter);

private:

    int hunt_counter;
};

#endif // CARNIVORE_H
