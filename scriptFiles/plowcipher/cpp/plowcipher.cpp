#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

string zufallsZeichen(string zeichenkette = "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
{
    int laenge = zeichenkette.length();
    int zeichennummer = rand() % laenge;
    string zeichen = zeichenkette.substr(zeichennummer, 1);
    return zeichen;
}

void encrypt(string str, int key)
{
    int laenge = str.length();
    int breite = key;
    int hoehe = laenge / key;

    while(laenge % key != 0)
    {
        str += zufallsZeichen();
        laenge = str.length();
        hoehe = laenge / key;
    }

    string zeichen[hoehe][breite];

    int zn = 0;
    for(int i = 0; i < hoehe; i++)
    {
        for(int j = 0; j < breite; j++)
        {
            zeichen[i][j] = str.substr(zn, 1);
            cout << zeichen[i][j];
            zn++;
        }
        cout << endl;
    }
    cout << endl;

    string res;
    hoehe--;
    breite--;

    for(int i = breite; i >= 0; i--)
    {
        for(int j = hoehe; j >= 0; j--)
        {
            if(i % 2 != 1)
                res += zeichen[j][i];
            else
                res += zeichen[hoehe-j][i];
        }
    }

    cout << "Key: " << key << "; Result: " << res << endl;
}

void decrypt(string str, int key, bool output = true)
{
    int laenge = str.length();
    int breite = key;
    int hoehe = laenge / key;
    string res;

    string zeichen[hoehe][breite];

    int x = 0;
    for(int i = breite - 1; i >= 0; i--)
    {
        for(int j = hoehe - 1; j >= 0; j--)
        {
            if(i % 2 != 1)
                zeichen[j][i] = str.substr(x, 1);
                // += zeichen[j][i];
            else
                zeichen[hoehe-j-1][i] = str.substr(x, 1);
            x++;
        }
    }

    for(int i = 0; i < hoehe; i++)
    {
        for(int j = 0; j < breite; j++)
        {
            res += zeichen[i][j];
            if(output != false) cout << zeichen[i][j];
        }
        if(output != false) cout << endl;
    }
    if(output != false) cout << endl;

    cout << "Key: " << key << "; Result: " << res << endl;
}


int main()
{
    srand( time(0) );
    cout << "The developer of the program is Marek K.; The program uses Plow cipher." << endl;
    cout << "Enter \"encrypt\", \"decrypt\" or \"bfa\" for a Brute-Force-Attack: ";
    string ans;
    cin >> ans;
    if(ans == "encrypt")
    {
        string str;
        int key;
        cout << "Text: ";
        cin >> str;
        cout << "Key: ";
        cin >> key;
        encrypt(str, key);
    }
    else if(ans == "decrypt")
    {
        string str;
        int key;
        cout << "Text: ";
        cin >> str;
        cout << "Key: ";
        cin >> key;
        decrypt(str, key);
    }
    else if(ans == "bfa")
    {
        string str;
            int key1;
            int key2;
            cout << "Text: ";
            cin >> str;
            cout << "From Key ";
            cin >> key1;
            cout << "to Key ";
            cin >> key2;
            for(int i = key1; i <= key2; i++)
            {
                decrypt(str, i, false);
            }
    }
    return 0;
}
