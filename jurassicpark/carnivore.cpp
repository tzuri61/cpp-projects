#include "carnivore.h"

bool carnivore::hunt(int herbi_currentweight, int carni_currentweight, int hcounter)
{


    if(carni_currentweight < herbi_currentweight)
    {
        hunt_counter = hcounter + 1;
        return false;
    }
    else
    {
        hunt_counter = 0;
        return true;
    }
}

int carnivore::GetHuntCounter()
{
    return hunt_counter;
}
