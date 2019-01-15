// The author of this program is Marek Küthe
// Website: mk16.de
// E-Mail: m.k@mk16.de

#include <iostream>

using namespace std;

int main()
{
	cout << "Hello User! Enter a number:" << endl;
	int num;
	cin >> num;
	
	if(num < 0)
	{
		cout << "The number is crazy!" << endl;
	}
	else if(num%2 == 0)
	{
		cout << "The number is good!" << endl;
	}
	else
	{
		cout << "The number is bad!" << endl;
	}
	
	return 0;
}