/*
    interpreter.cpp
    The author of this file is Marek K.
*/
#include "interpreter.hpp"
#include <string>

using namespace std;
using namespace Interpreter;

string interpreter::icode(string code)
{
    this -> code = code;
    return this -> code;
}

string interpreter::input(string in)
{
    this -> in = in;
    return this -> in;
}

void interpreter::action(char code)
{
    switch(code)
        {
            case '+':
                {
                    //cout << "wird add" << endl;
                    INCREMENTED();
                    break;
                }
            case '-':
                {
                    DECREMENTED();
                    break;
                }
            case '<':
                {
                    LEFT();
                    break;
                }
            case '>':
                {
                    RIGHT();
                    break;
                }
            case '.':
                {
                    char x = cell[cur];
                    res += x;
                    break;
                }
            case ',':
                {
                    cell[cur] = in[inpos];
                    inpos++;
                    break;
                }
            /*default:
                {
                    //cout << "Kommentar: " << code << endl;
                    break;
                }*/
        }
}

int interpreter::bfloop(int i, string code)
{
    int sp = i+1;
    int pp = 0;
    int o = 0;
    while(code[sp+pp] != ']' || o != 0)
    {
        //if(code[sp+pp] == ']' && o == 0) break;
        if(code[sp+pp] == ']' && o != 0) o--;
        if(code[sp+pp] == '[') o++;
        pp++;
    }
    string lcode = code.substr(sp, pp);  // loop code
    //cout << "schleifen code ist " << lcode << endl;
    while(cell[cur] != 0)
    {
        for(unsigned int j = 0; j < pp; j++)
        {
            char x = code[sp+j];
            if(x == '[')
            {
                j += bfloop(j, lcode);
            }
            else
            {
                action(code[sp+j]);
            }
        }
    }
    //cout << "i 1: " << i << endl;
    return pp + 1;
    //cout << "i 2: " << i << endl;
    //cout << "schleifen ende" << endl;
}

string interpreter::interpret()
{
    if(code == "") return "0x0001";
    for(unsigned int i = 0; i < code.length(); i++)
    {
        char x = code[i];
        if(x == '[')
        {
            i += bfloop(i, code);
        }
        else
        {
            //cout << "codeteil(a)" << code[i] << endl;
            //cout << "i: " << i << endl;
            //cout << "cc: " << to_string(cell[cur]) << endl;
            action(code[i]);
        }
    }
    //cout << to_string(cell[0]) << endl;
    //cout << to_string(cell[1]) << endl;
    return res;
}

bool interpreter::qinput()
{
    if(code.find(",") != string::npos) return true;
    return false;
}

void interpreter::LEFT()
{
    cur--;
}

void interpreter::RIGHT()
{
    cur++;
}

void interpreter::INCREMENTED()
{
    cell[cur]++;
}

void interpreter::DECREMENTED()
{
    cell[cur]--;
}
