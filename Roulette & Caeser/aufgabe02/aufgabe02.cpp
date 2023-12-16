#include <iostream>
using namespace std;

int main()
{

	string s = "";	

	int positions_right = 0;
	char letter;
	int zahl = 0;

	cout << endl << "Um wie viele Positionen nach rechts sollen die Zeichen verschoben werden: ";
	cin >> positions_right;

	cout << "Bitte geben Sie eine Zeichenkette an, die codiert werden soll: ";
	cin >> s;

	positions_right %= 26;
	
	for(int i = 0; i < s.length(); i++)
	{
		//i guckt die position von dem einen Buchstaben an
        	letter = tolower(s[i]);
		zahl = (int)letter;

		// Zeichen um n Positionen verschieben
		zahl += positions_right;

		if(zahl < 97)
		{			
			zahl += 26;
		}
		if(zahl > 122)
		{
			zahl -= 26;
		}	
        	
		letter = (char)zahl;

        	cout << letter;
	}

	return 0;
}