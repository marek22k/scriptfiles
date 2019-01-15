// Author: Marek K.

/*

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Dieses Programm ist Freie Software: Sie koennen es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veroeffentlichten Version, weiter verteilen und/oder modifizieren.

    Dieses Programm wird in der Hoffnung bereitgestellt, dass es nuetzlich sein wird, jedoch
    OHNE JEDE GEWAEHR,; sogar ohne die implizite
    Gewaehr der MARKTFAEHIGKEIT oder EIGNUNG FUER EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License fuer weitere Einzelheiten.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
	
*/

#include <iostream>
#include <string>
#include <sstream>
#include <locale>

using namespace std;

string uppercase(string str)
{
    string res;
    locale temp;
    for(int i =0; i < str.length(); i++)
        res += toupper(str[i], temp);

    return res;
}

template <class T>
string toString(T nostr)
{
    stringstream ss;
    ss << nostr;
    return ss.str();
}

string encrypt(string param_keyword, string param_str)
{
    string s[5][5];
    string keyword;
    string str;
    string e;

    for(int i = 0; i < param_keyword.length(); i++)
    {
        char x = param_keyword[i];
        if(keyword.find(x) == string::npos && x != 'J') keyword += x;
        if(x == 'J') keyword += "I";
    }
    keyword = uppercase(keyword);
    // cout << keyword << endl;

    int n1 = 0;
    char n2 = 'A';
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(n1 != keyword.length())
            {
                s[i][j] += keyword[n1];
                n1++;
            }
            else
            {
                if(keyword.find(n2) == string::npos && n2 != 'J')
                {
                    s[i][j] += n2;
                    n2++;
                }
                else
                {
                    n2++;
                    j--;
                }
            }
        }
    }

     for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    param_str = uppercase(param_str);
    for(int i = 0; i < param_str.length(); i++)
    {
        if(param_str[i] >= 'A' && param_str[i] <= 'Z')
        {
            if(param_str[i] == param_str[i-1]) str += "X";
            str += param_str[i];
        }
    }

    //if(str.length()%2!=0) return encrypt(param_keyword, param_str + "X");
    //cout << str << endl;

    string arr1[5];
    string arr2[5];
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            arr1[i] += s[i][j];
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            arr2[i] += s[j][i];
        }
    }

    for(int i = 0; i < str.length(); i += 2)
    {
        char a = str[i];
        char b = str[i+1];

        bool make = false;

        for(int j = 0; j < 5; j++)
        {
            bool b1 = false, b2 = false;
            int p1, p2;
            if((p1=arr1[j].find(a)) != string::npos) b1 = true;
            if((p2=arr1[j].find(b)) != string::npos) b2 = true;
            if(b1 == true && b2 == true)
            {
                if(p1 == 4) e += arr1[j][0];
                else e += arr1[j][p1+1];

                if(p2 == 4) e += arr1[j][0];
                else e += arr1[j][p2+1];

                make = true;
            }
        }

        for(int j = 0; j < 5; j++)
        {
            bool b1 = false, b2 = false;
            int p1, p2;
            if((p1=arr2[j].find(a)) != string::npos) b1 = true;
            if((p2=arr2[j].find(b)) != string::npos) b2 = true;
            if(b1 == true && b2 == true)
            {
                if(p1 == 4) e += arr2[j][0];
                else e += arr2[j][p1+1];

                if(p2 == 4) e += arr2[j][0];
                else e += arr2[j][p2+1];

                make = true;
            }
        }

        if(! make)
        {
            int pos1i = -1, pos1j = -1, pos2i = -1, pos2j = -1;
            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    if(s[i][j] == toString(a))
                    {
                        pos1i = i;
                        pos1j = j;
                    }
                    if(s[i][j] == toString(b))
                    {
                        pos2i = i;
                        pos2j = j;
                    }
                }
            }
            e += s[pos1i][pos2j];
            e += s[pos2i][pos1j];

            make = true;
        }
        //e += " ";
    }

    return e;
}

string decrypt(string param_keyword, string param_str)
{
    string s[5][5];
    string keyword;
    string str = param_str;
    string e;

    //if(str.length()%2==0) return "Error";

    for(int i = 0; i < param_keyword.length(); i++)
    {
        char x = param_keyword[i];
        if(keyword.find(x) == string::npos && x != 'J') keyword += x;
        if(x == 'J') keyword += "I";
    }
    keyword = uppercase(keyword);
    // cout << keyword << endl;

    int n1 = 0;
    char n2 = 'A';
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(n1 != keyword.length())
            {
                s[i][j] += keyword[n1];
                n1++;
            }
            else
            {
                if(keyword.find(n2) == string::npos && n2 != 'J')
                {
                    s[i][j] += n2;
                    n2++;
                }
                else
                {
                    n2++;
                    j--;
                }
            }
        }
    }

    string arr1[5];
    string arr2[5];
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            arr1[i] += s[i][j];
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            arr2[i] += s[j][i];
        }
    }

    for(int i = 0; i < str.length(); i += 2)
    {
        char a = str[i];
        char b = str[i+1];

        bool make = false;

        for(int j = 0; j < 5; j++)
        {
            bool b1 = false, b2 = false;
            int p1, p2;
            if((p1=arr1[j].find(a)) != string::npos) b1 = true;
            if((p2=arr1[j].find(b)) != string::npos) b2 = true;
            if(b1 == true && b2 == true)
            {
                if(p1 == 0) e += arr1[j][4];
                else e += arr1[j][p1-1];

                if(p2 == 0) e += arr1[j][4];
                else e += arr1[j][p2-1];

                make = true;
            }
        }

        for(int j = 0; j < 5; j++)
        {
            bool b1 = false, b2 = false;
            int p1, p2;
            if((p1=arr2[j].find(a)) != string::npos) b1 = true;
            if((p2=arr2[j].find(b)) != string::npos) b2 = true;
            if(b1 == true && b2 == true)
            {
                if(p1 == 0) e += arr2[j][4];
                else e += arr2[j][p1-1];

                if(p2 == 0) e += arr2[j][4];
                else e += arr2[j][p2-1];

                make = true;
            }
        }

        if(! make)
        {
            int pos1i = -1, pos1j = -1, pos2i = -1, pos2j = -1;
            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    if(s[i][j] == toString(a))
                    {
                        pos1i = i;
                        pos1j = j;
                    }
                    if(s[i][j] == toString(b))
                    {
                        pos2i = i;
                        pos2j = j;
                    }
                }
            }
            e += s[pos1i][pos2j];
            e += s[pos2i][pos1j];

            make = true;
        }
    }

    return e;
}

int main()
{
    //cout << encrypt("playfair", "HalloWorldX") << endl;
    cout << "The developer of the program is Marek K.; The program uses Playfair cipher." << endl;
    cout << "Enter \"encrypt\" or \"decrypt\": ";
    string ans;
    cin >> ans;
    if(ans == "encrypt")
    {
        cout << "Keyword: ";
        string keyword;
        cin >> keyword;
        cout << "Text: ";
        string text;
        cin >> text;
        cout << "Result: " << encrypt(keyword, text) << endl;
    }
    else if(ans == "decrypt")
    {
        cout << "Keyword: ";
        string keyword;
        cin >> keyword;
        cout << "Text: ";
        string text;
        cin >> text;
        cout << "Result: " << decrypt(keyword, text) << endl;
    }
    else
        cout << "Error: Invalid input" << endl;
    return 0;
}
