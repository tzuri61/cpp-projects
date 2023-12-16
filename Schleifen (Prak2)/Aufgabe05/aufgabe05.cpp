#include <iostream>

using namespace std;

int main()
{
	string s;
	
	while(s == "k" or "r" or "d" or "q")
	{
		cout << " Herzlich Willkommen zum Flaechenberechner!" << endl;
		cout << "\n Von welcher geometrischen Figur soll die Flaeche berechnet werden?" << endl;
		cout << "\n k) Kreis" << endl;
		cout << " r) Rechteck" << endl;
		cout << " d) Dreieck" << endl;
		cout << "\n q) Beenden" << endl;	

		cin >> s;
	
		if(s == "k")
		{
			cout << "Wird noch implementiert..." << endl;
			break;
		}
		else if(s == "r")
		{
			cout << "Wird noch implementiert..." << endl;
			break;
		}
		else if(s == "d")
		{
			cout << "Wird noch implementiert.." << endl;
			break;
		}
		else if(s == "q")
		{
			return 0;
		}
	}
}	

