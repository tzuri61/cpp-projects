#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "dinosaur.h"
#include <vector>
using std::vector;

class herbivore : public dinosaur
{
private:
    int hide_chance;
    bool ishidden;
public:

    herbivore(string creature, int maxweight, int growthrate, char kindofrace, int hide_chance, int breedchance, bool ishidden)
        :dinosaur ("herbivore", creature, maxweight, growthrate, kindofrace, breedchance)
    {
        this->hide_chance = hide_chance;
        this->ishidden = ishidden;
    }

    bool hide(int hide_chance);


    bool getishidden();

    int gethidechance();

};

#endif // HERBIVORE_H
