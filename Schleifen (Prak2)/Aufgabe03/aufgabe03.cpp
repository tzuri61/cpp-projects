#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cout << "Geben Sie eine positive Zahl ein: " << endl;
	cin >> n;


	for(int min = 1; min <= n; min += 2)
	{
		cout << min << " hoch zwei ist: " << min * min << endl;
	}

	return 0;
}
