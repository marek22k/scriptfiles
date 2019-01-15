/*
    bfinterpreter v1.0
    The author of this program is Marek K.
*/

#include <iostream>
#include <fstream>
#include "interpreter.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Interpreter::interpreter i = Interpreter::interpreter();
    string res;
    string line;
    ifstream f(argv[1]);
    while(getline(f, line))
    {
        res += line;
    }
    f.close();
    i.icode(res);

    if(i.qinput())
    {
        string input;
        cout << "Input: ";
        cin >> input;
        i.input(input);
    }
    string output = i.interpret();
    cout << output;
    return 0;
}
