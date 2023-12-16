#include <iostream>

using namespace std;

int main()
{
	int max = 0, min = 10000000, sum = 0, ui = 1;

	cout << "Geben Sie eine beliebige Anzahl positiver Ganzzahlen ein: " << endl;

	while(ui > 0)
	{
		cout << " > ";
		cin >> ui;		
		
		if(max < ui)
		{
			max = ui;
		}
		if(min > ui && ui > 0)
		{
			min = ui;
		}
		if(ui > 0)
		{
			sum += ui;
		}
		if(ui <= 0 && sum == 0)
		{
			return 0;
		}
	}

	
	cout << "Die kleinste Zahl ist: " << min << endl
		<< "Die groesste Zahl ist: " << max << endl
		<< "Die Summe aller Zahlen ist: " << sum << endl;
	
}
