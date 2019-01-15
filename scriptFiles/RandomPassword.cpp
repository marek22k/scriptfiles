#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string RandomChar(int num, string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") {
    string str(1, symbols.at(num%symbols.length()));
    return str;
}

int main()
{
    srand(time(0));
    string res = "";
    res += "The password is ";
    for(int i = 0; i < 7; i++) {
        res += RandomChar(rand());
    }
    cout << res << endl;
    return 0;
}
