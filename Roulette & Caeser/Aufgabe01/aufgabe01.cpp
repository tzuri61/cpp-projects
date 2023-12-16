#include <iostream>
#include <random>
#include "random.h"
#include <array>

using namespace std;
std::random_device rd;
int getRandom(int lower, int upper)
{
	std::uniform_int_distribution<int> dist(lower, upper);
	return dist(rd);
}
int main()
{
	double v = 10000; //Vermögen
	double e = 0; //seinen Einsatz als positive Zahl
	int z = 0; //Zahl, auf die er wettet
	char modi;
	int wiederholung = 0;
	
	//const int rz = getRandom(0,36);//die Zahl, die im Roulette Rad gefallen ist
	
	cout << "-----------------------------------" << endl;
	cout << "Herzlich Willkommen zu hDa-Roulette" << endl;
	cout << "-----------------------------------" << endl;

	do
	{
		
		cout << "\nWählen Sie einen Spielmodi:" << endl;
		cout << "f) Farbe" << endl;
		cout << "s) Spalten" << endl;
		cout << "z) Zahlen" << endl;
		cout << "Auswahl: " << endl;
		cin >> modi;

		switch(modi){
		case 'f':{
			const int rzz = getRandom(0,36);
			cout << "\n\nSie haben den Spielmodus Farbe gewählt.";
			
			do
			{
				cout << "\nWie viel Geld möchten Sie einsetzen?\nihr aktuelles Vermögen:" << v << "€" << endl;
				cout << "Ihr Einsatz: " << endl;
				cin >> e;

				if(e > v) //Vermeiden, dass Spieler mehr einsetzen kann als möglich (siehe while(true))
				{	
					cout << "ehmm Ich glaube so viel Geld haben Sie nicht...Versuchen Sie es nochmal..." << endl;
				}

				else if (e < 0)
				{
					cout << "Sie können keine Minusbeträge angeben...Versuchen Sie es nochmal..." << endl;
				}		
			}
			while(e < 0 or e > v); //Um aus der Schleife rauszukommen muss e > 0 und e < v sein

				cout << rzz << endl;
			do 
			{
				cout << "Wählen Sie zwischen zwei Farben aus. Für Schwarz tippen Sie die 1 und für Rot die 2." << endl;
				cout << "Ihre Auswahl: ";
				cin >> z;

					if(z != 1 and z != 2)
					{
						cout << "\nDas ist nicht möglich..." << endl;
					}		
			}
			while(z != 1 and z != 2);

			int result = 0;
			result = rzz % 2;
				
			if(rzz == 0)
			{
				v -= e;
				
				cout << "Schade, Sie haben verloren und verlieren ihren Einsatz. Sie haben lediglich nur noch ein Vermögen von " << v << "€." << endl;
				
				break;
			}		

			if(result == 1 and z == 1 or result == 0 and z == 2)
			{
				
				v += e;

				cout << "-----------------------------------------" << endl;
				cout << "HERZLICHEN GLÜCKWUNSCH SIE HABEN GEWONNEN" << endl;
				cout << "-----------------------------------------" << endl;
				cout << "\nIhr Gewinn betraegt: " << e << "€.";
				cout << "Sie haben nun ein Vermögen von: " << v << "€" << endl;
				
				break;
			}
			else
			{
				v -= e;
				
				cout << "Schade, Sie haben verloren und verlieren ihren Einsatz. Sie haben lediglich nur noch ein Vermögen von " << v << "€." << endl;
				
				break;
			}
			
		}
		case 's':{

		const int rzz = getRandom(1,36);
		int spalte = 0;
		array<array<int, 3>, 12> zahlentabelle;
		cout << "\n\nSie haben den Spielmodus Spalten gewählt.";

			do
			{
				cout << "\nWie viel Geld möchten Sie einsetzen?\nihr aktuelles Vermögen:" << v << "€" << endl;
				cout << "Ihr Einsatz: ";
				cin >> e;

				if(e > v) //Vermeiden, dass Spieler mehr einsetzen kann als möglich (siehe while(true))
				{	
					cout << "ehmm Ich glaube so viel Geld haben Sie nicht...Versuchen Sie es nochmal..." << endl;
				}
				else if (e < 0)
				{
					cout << "Sie können keine Minusbeträge angeben...Versuchen Sie es nochmal..." << endl;
				}		
			}
			while(e < 0 or e > v); //Um aus der Schleife rauszukommen muss v > e > 0 sein

			do
			{
				cout <<"\n\ndie richtige Zahl: " << rzz << endl; //zum testen
				cout << "Wählen Sie eine Spalte aus (1, 2 oder 3)." << endl;
				cin >> spalte;
				int d = 0;				

				for(int i = 0; i < 12; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						zahlentabelle[i][j] = d++;
					}				
				}	

				if(spalte > 3 or spalte < 1)
				{
					cout << "Diese Spalte gibt es nicht..." << endl;
				}
			}
			while(spalte > 3 or spalte < 1);
				
				bool result = false;

				for(int i = 0; i < zahlentabelle.size(); i++)
				{
					if(zahlentabelle[i][spalte] == rzz)
					{
						v += (e * 2);

						cout << "-----------------------------------------" << endl;
						cout << "HERZLICHEN GLÜCKWUNSCH SIE HABEN GEWONNEN" << endl;
						cout << "-----------------------------------------" << endl;
						cout << "\nIhr Gewinn betraegt: " << e * 2 << "€.";
						cout << "Sie haben nun ein Vermögen von: " << v << "€" << endl;
						
						result = true;

						break;
					}					
				}
				
				if(result == false)
				{
					v -= e;							
				
					cout << " Schade, Sie haben verloren und verlieren ihren Einsatz. Sie haben lediglich nur noch ein Vermögen von " << v << "€." << endl;

					break;
				}
				break;
		}
		case 'z':{
		const int rzz = getRandom(0,36);
		cout << "\n\nSie haben den Spielmodus Zahlen gewählt.";
		
			do
			{	
				cout << "\nWie viel Geld möchten Sie einsetzen?\nihr aktuelles Vermögen:" << v << "€" << endl;
				cout << "Ihr Einsatz: " << endl;
				cin >> e;
			
				if(e > v) //Vermeiden, dass Spieler mehr einsetzen kann als möglich (siehe while(true))
				{
					cout << "ehmm Ich glaube so viel Geld haben Sie nicht...Versuchen Sie es nochmal..." << endl;
				}
				else if (e < 0)
				{	
					cout << "Sie können keine Minusbeträge angeben...Versuchen Sie es nochmal..." << endl;
				}
			}
			while(e < 0 or e > v);//Um aus der Schleife rauszukommen muss e > 0 und e < v sein
			
				cout << "\nNun gut, Sie setzen " << e << "€ ein. Auf Welche Zahl wollen Sie setzen? \nNennen Sie eine Zahl zwischen 0 und 36" << endl;
				cout << "Die im Roulette gefallene Zahl: " << rzz; //für Testzwecke
			do
			{
				cout << "\nihre gewählte Zahl: ";
				cin >> z; //verhindern, dass Zahlen unter 0 und über 36 ausgewählt werden können

				if(z > 36 or z < 0)
				{
					cout << "Das geht nicht...Versuchen Sie es nochmal..." << endl;
				}	
			}
			while(z > 36 or z < 0); //z > 0 und z <= 36 muss false sein aus der Schleife rauszukommen

				if(rzz == z)
				{
					v += (e * 35);
					
					cout << "-----------------------------------------" << endl;
					cout << "HERZLICHEN GLÜCKWUNSCH SIE HABEN GEWONNEN" << endl;
					cout << "-----------------------------------------" << endl;
					cout << "\nIhr Gewinn betraegt: " << e * 35<< "€.";
					cout << "Sie haben nun ein Vermögen von: " << v << endl;
				}
				else
				{
					v -= e;

					cout << "Schade, Sie haben verloren und verlieren ihren Einsatz. Sie haben lediglich nur noch ein Vermögen von " << v << "€." << endl;
				}
			}
		}
	
		cout << "Wollen Sie weiter spielen? Geben Sie für ja eine 1 ein und für nein eine 0." << endl;
		cin >> wiederholung;

		if(wiederholung == 0)
		{
			return 0;
		}

		if(wiederholung < 0 or wiederholung > 1)
		{
			wiederholung = 0;

			cout << "Das geht nicht. Geben Sie eine gueltige Zahl ein." << endl;
		}
	}
	while(wiederholung);
}
