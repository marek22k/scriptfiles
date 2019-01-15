#include <iostream>  /* std::cout, std::cin, std::endl */

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int n;

    cout << "Please enter a number: ";
    cin >> n;
    cout << endl << "Floyd's triangle:" << endl;

    int j;

    for(int i = 1, num = 1; i <= n; i++)
    {
        for(j = 0; j < i; j++, num++)
            cout << num << " ";

        cout << endl;
    }
    return 0;
}
