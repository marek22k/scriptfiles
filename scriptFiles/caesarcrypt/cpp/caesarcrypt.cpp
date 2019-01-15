#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
string toString(T conv)
{
    stringstream ss;
    ss << conv;
    return ss.str();
}

void encrypt()
{
    char text[26], TEXT[26];
    int key, last = 0;
    string txt, res;

    cout << "Key: ";
    cin >> key;
    cout << "Text: ";
    cin >> txt;

    for(int i = 0; i < 26; i++)
        text[i] = 'a' + i;

    for(int i = 0; i < 26; i++)
    {
        char t = 'a' + i + key;
        if(t > 122)
        {
            last = i;
            break;
        }
        else
            TEXT[i] = t;
    }

    for(int i = last; i < 26;i++)
        TEXT[i] = 'a' + i-last;

    for(int i = 0; i < txt.length(); i++)
    {
        string a = txt.substr(i, 1);
        for(int j = 0; j < 26; j++)
            if(a == toString(text[j]))
                res += toString(TEXT[j]);
        //cout << "Round " << i << ": " << res << endl;
    }

    cout << "Key: " << key << "; Result: " << res << endl;
}

void decrypt(int key, string txt)
{
    char text[26], TEXT[26];
    int last = 0;
    string res;

    for(int i = 0; i < 26; i++)
        text[i] = 'a' + i;

    for(int i = 0; i < 26; i++)
    {
        char t = 'a' + i + key;
        if(t > 122)
        {
            last = i;
            break;
        }
        else
            TEXT[i] = t;
    }

    for(int i = last; i < 26;i++)
        TEXT[i] = 'a' + i-last;

    for(int i = 0; i < txt.length(); i++)
    {
        string a = txt.substr(i, 1);
        for(int j = 0; j < 26; j++)
            if(a == toString(TEXT[j]))
                res += toString(text[j]);
        //cout << "Round " << i << ": " << res << endl;
    }

    if(toString(key).length() == 1)
        cout << "Key: 0" << key << "; Result: " << res << endl;
    else
        cout << "Key: " << key << "; Result: " << res << endl;
}

int main()
{
    cout << "The developer of the program is Marek K.; The program uses Caesar cipher." << endl;
    cout << "Enter \"encrypt\" or \"decrypt\": ";
    string ans;
    cin >> ans;
    if(ans == "encrypt")
        encrypt();
    else if(ans == "decrypt")
    {
        string txt;
        cout << "Text: ";
        cin >> txt;
        for(int i = 0; i < 26; i++)
            decrypt(i, txt);
    }
    else
        cout << "Error: Invalid input" << endl;
    return 0;
}
