#include <iostream>
#include "random.h"
#include <random>

using namespace std;

random_device rd;

int getRandom(int lower, int upper)
{
	uniform_int_distribution<int> dist(lower, upper);
	return dist(rd);
	}

int main()
{
	int i = getRandom(1,10) ;
  
	cout << i << endl;


	int number = 0;
	cout << "Hallo, bitte nenne eine Zahl zwischen 1 und 10. Du hast 5 Versuche es richtig zu raten." << endl;	

	for(int tries = 1; tries <= 5; tries++)
	{
		cout << tries << ". Versuch: ";	
		cin >> number;		

		if(i == number)
  		{
			cout << "Herzlichen Glückwunsch!!! Du hast richtig geraten!";
			return 0;
  		}
		else
		{
			if(tries == 5) break;
			cout << "Schade, Sie lagen falsch. Versuchen Sie es nochmal. " << endl;
		}
	}
	
	cout << "Schade, Sie haben es nicht geschafft, vielleicht klappt es beim naechsten Mal. " << endl;
	return 0;
}

