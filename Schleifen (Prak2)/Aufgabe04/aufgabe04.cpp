#include <iostream>

using namespace std;

int main()
{
	int z = 0;
	cout << "Geben Sie eine Zahl ein: "<< endl;
	
	const char* a = "+";
	const char* b = "-";
	const char* c = 0;

	cin >> z;	

	if(z >= 0)
	{
		c = a;
	}
	else
	{
		c = b;
		z *= -1;
	}
	while(z)
	{
		cout << z % 10 << endl;
		z /= 10;
	}
		cout << c << endl;
}
