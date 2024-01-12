#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <string>

using std::string;

class dinosaur
{   
public:
    // beschreibt einen Dinosaurier
    dinosaur(string race, string creature, int maxweight, int growthrate, char kindofrace, int breedchance);

    bool age(int currentweight, int maxweight, int growthrate);
    bool breed(int breedchance, string creature_current, string creature_next);




    int GetMaxweight();//return Maxweight

    int Getgrowthrate();//return Growthrate

    int Getbreedchance();//return breedchance

    string getcreature();//return creature

    int Getcurrentweight();//return curr. weight

    char Getkindofrace();//return kindofrace

    void print();//printet xD

    int getRandom(int lower, int upper);



private:
    int currentweight;
    string race;
    int maxweight;
    int growthrate;
    string creature;
    char kindofrace;
    int breedchance;


};

#endif // DINOSAUR_H
