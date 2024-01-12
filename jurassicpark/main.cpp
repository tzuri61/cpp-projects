#include "carnivore.h"
#include "herbivore.h"
#include "dinosaur.h"
#include <iostream>
#include <experimental/random>

using namespace std;
int daycounter = 0;

void passingtime(vector<carnivore>&v_carni, vector<herbivore>&v_herbi)
{


    int car_size = (int)v_carni.size();
    int her_size = (int)v_herbi.size();


    daycounter++;

    cout << "Tag " << daycounter << "\n" << endl;


    for(int i = 0; i < (int)v_carni.size(); i++)
    {
        if(v_carni[i].age(v_carni[i].Getcurrentweight(),v_carni[i].GetMaxweight(), v_carni[i].Getgrowthrate()) == true)
        {
            v_carni.erase(v_carni.begin()+i);
        }
    }
    cout << "Anzahl der Karnivoren, die an Altersschwaeche starben: " << car_size - (int)v_carni.size() << endl;



    for(int i = 0; i < (int)v_herbi.size(); i++)
    {
        if(v_herbi[i].age(v_herbi[i].Getcurrentweight(),v_herbi[i].GetMaxweight(), v_herbi[i].Getgrowthrate()) == true)
        {
            v_herbi.erase(v_herbi.begin()+i);

        }
    }
    cout << "Anzahl der Herbivoren, die an Altersschwaeche starben: " << her_size - (int)v_herbi.size() << endl;

    int carninew = 0;


    for(int i = 0; i < car_size; i++)//Carni Geburt
    {
        for(int j = i+1; j < car_size; j++)
        {
            if(v_carni[i].breed(v_carni[i].Getbreedchance(),v_carni[i].getcreature(),v_carni[j].getcreature()) == true && (v_herbi.size() + v_carni.size()) < 100)
            {
                v_carni.push_back(carnivore(v_carni[i].getcreature(),v_carni[i].GetMaxweight(),v_carni[i].Getgrowthrate(),v_carni[i].Getkindofrace(), v_carni[i].Getbreedchance(), v_carni[i].GetHuntCounter()));
                carninew++;
                break;
            }
        }

    }
    cout << "Anzahl der neugeborenen Karnivoren: " << carninew << endl;


    int hernew = 0;
    int herbibicounter = 0;


    for(int i = 0; i < her_size; i++)//Herbi Geburt
    {
        for(int j = i+1; j < her_size; j++)
        {

            if(v_herbi[i].breed(v_herbi[i].Getbreedchance(),v_herbi[i].getcreature(),v_herbi[j].getcreature()) == true)
            {
                if(v_herbi[i].getcreature() == "Brachiosaurus" && (v_herbi.size() + v_carni.size()) < 100)
                {
                    v_herbi.push_back(herbivore(v_herbi[i].getcreature(),v_herbi[i].GetMaxweight(),v_herbi[i].Getgrowthrate(),v_herbi[i].Getkindofrace(),v_herbi[i].gethidechance(), v_herbi[i].Getbreedchance(),v_herbi[i].getishidden()));
                    hernew++;
                    break;
                }
                else
                {
                    herbibicounter = 0;
                    while(v_herbi[i].getcreature() == "Parasaurolophus" && (v_herbi.size() + v_carni.size()) < 100 && herbibicounter < 3)
                    {
                    herbibicounter++;
                    hernew++;
                    v_herbi.push_back(herbivore(v_herbi[i].getcreature(),v_herbi[i].GetMaxweight(),v_herbi[i].Getgrowthrate(),v_herbi[i].Getkindofrace(),v_herbi[i].gethidechance(), v_herbi[i].Getbreedchance(),v_herbi[i].getishidden()));
                    }
                    break;
                }
            }
        }

    }
    cout << "Anzahl der neugeborenen Herbivoren: " << hernew << endl;

    int tomato = 0;
    for(int i = 0; i < (int)v_herbi.size(); i++)//verstecken
    {
        if(v_herbi[i].hide(v_herbi[i].gethidechance()) == true)
        {
            tomato++;
        }
    }
    cout << "Anzahl an Herbivoren, die sich verstecken konnten: " << tomato << endl;


    int potato = 0;
    for(int i = 0; i < (int)v_carni.size(); i++)//fressen
    {
        int v_herbi_size = (int) v_herbi.size();
        int random_hunt = std::experimental::randint(0, v_herbi_size);
        if(v_carni[i].hunt(v_herbi[random_hunt].Getcurrentweight(),v_carni[i].Getcurrentweight(),v_carni[i].GetHuntCounter()) == true && v_herbi[random_hunt].getishidden() == false)
        {
            v_herbi.erase(v_herbi.begin()+random_hunt);
            potato++;
        }
    }
    cout << "Anzahl an Herbivoren, die von Karnivoren gefressen wurden: " << potato << endl;

    int HungRich = 0;

    for(int i = 0; i < (int)v_carni.size(); i++){
        if(v_carni[i].GetHuntCounter() >= 2)
        {
            HungRich++;
            v_carni.erase(v_carni.begin()+i);
        }
    }
    cout << "Anzahl an Karnivoren, die verhungert sind: " << HungRich << endl;


    cout << "\n\n\nSTATS: " << endl;
    cout << "Anzahl an Hebivoren: " << v_herbi.size() << endl;
    cout << "Anzahl an Karnivoren: " << v_carni.size() << endl;



}

int main()
{
        vector<carnivore>v_carni;
        v_carni.push_back(carnivore("Raptor",500,30,'c',12, 0));//string creature, int maxweight, int growthrate, char kindofrace, int breedchance, hunt
        v_carni.push_back(carnivore("Raptor",500,30,'c',12, 0));
        v_carni.push_back(carnivore("Raptor",500,30,'c',12, 0));
        v_carni.push_back(carnivore("Raptor",500,30,'c',12, 0));
        v_carni.push_back(carnivore("TRex",8000,20,'c',8, 0));
        v_carni.push_back(carnivore("TRex",8000,20,'c',8, 0));

        vector<herbivore>v_herbi;
        v_herbi.push_back(herbivore("Parasaurolophus",1500,40,'h',75,85, true));//string creature, int maxweight, int growthrate, char kindofrace, int hide_chance, int breedchance
        v_herbi.push_back(herbivore("Parasaurolophus",1500,40,'h',75,85, true));
        v_herbi.push_back(herbivore("Parasaurolophus",1500,40,'h',75,85, true));
        v_herbi.push_back(herbivore("Parasaurolophus",1500,40,'h',75,85, true));
        v_herbi.push_back(herbivore("Parasaurolophus",1500,40,'h',75,85, true));
        v_herbi.push_back(herbivore("Brachiosaurus",30000,20,'h',50,20, true));
        v_herbi.push_back(herbivore("Brachiosaurus",30000,20,'h',50,20, true));
        v_herbi.push_back(herbivore("Brachiosaurus",30000,20,'h',50,20,true));
        v_herbi.push_back(herbivore("Brachiosaurus",30000,20,'h',50,20,true));


        cout << "Stats(Beginn): " << endl;
        cout << "Anzahl an Hebivoren: " << v_herbi.size() << endl;
        cout << "Anzahl an Karnivoren: " << v_carni.size() << endl;
        cout << "\n\n\n\n" << endl;

        char user_input;

        do{    
        passingtime(v_carni,v_herbi);
        if(v_herbi.size() == 0 or v_carni.size() == 0)
        {
            cout << "Eine Dinosorte ist ausgestorben!" << endl;
            return 0;
        }
        cout << "Willst du einen weiteren Tag simulieren?(y/n)" << endl;
        cin >> user_input;
        }
        while(user_input != 'n');

    return 0;
}

