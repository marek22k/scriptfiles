#include <iostream>
#include <cstdlib>
#include <sstream>
#include "DOZEN.h"
#include "English.h"
// #include "German.h"

using namespace std;
using namespace DOZEN;

string oul(int x = 100)
{
    string res = "";
    for(int i = 0; i < x; i++) res+="-";
    return res;
}

int main()
{
    int n1, n2;

    cout << endl << B1 << oul() << endl << MSG1;
    cin >> n1;

    cout << MSG2;
    cin >> n2;

    double d, g, b;
    if(n1 == 1)
    {
        d = n2;
        g = DozenToGros(n2);
        b = dozenToBit(n2);
    }
    else if(n1 == 2)
    {
        d = grosToDozen(n2);
        g = n2;
        b = grosToBit(n2);
    }
    else if(n1 == 3)
    {
        d = bitToDozen(n2);
        g = bitToGros(n2);
        b = n2;
    }
    else
    {
        cerr << ERR1 << "\n";
        ERR1then(ERR1Parameter);
    }
    cout << B1 << oul() << endl << endl << B2 << oul() << endl << MSG3 << endl;
    cout << B2 << oul() << endl << endl << B3 << oul() << endl;

    stringstream a, e, c;
    a << d; e << g; c << b;
    string o = "         |                     " + c.str() + NL + wordBIT + NL + wordARE + NL + a.str() + NL + wordDOZEN;
    string t = "         |                     " + c.str() + NL + wordBIT + NL + wordARE + NL + e.str() + NL + wordGROS;

    int backspace1 = 108-o.length(), backspace2 = 108-t.length();
    cout << o;
    for(int i = 0; i < backspace1; i++) cout << NL;
    cout << "|" << endl << t;
    for(int i = 0; i < backspace2; i++) cout << NL;
    cout << "|" << endl << B3 << oul() << endl;
}
