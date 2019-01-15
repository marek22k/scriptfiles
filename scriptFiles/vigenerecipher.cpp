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

#include <iostream>  /* cout, cin */
#include <string>  /* string */

#include <cstddef>  /* size_t */
#include <cstdlib>  /* abort, EXIT_SUCCESS */

using namespace std;

string vigenere_encrypt(string, string);
string vigenere_decrypt(string, string);

int main()
{
    string text, key;
    short int option = -1;

    cout << "Encrypt/Deceypt (0/1): ";
    cin >> option;
    if(cin.fail() || option == -1) abort();

    cout << "Text: ";
    cin >> text;
    if(cin.fail()) abort();

    cout << "Key: ";
    cin >> key;
    if(cin.fail()) abort();

    if(option == 0)
        cout << "Encrypt: " << vigenere_encrypt(text, key);
    else if(option == 1)
        cout << "Decrypt: " << vigenere_decrypt(text, key);
    else
        abort();

    return EXIT_SUCCESS;
}

string vigenere_encrypt(string text, string key)
{
    for(size_t i = 0; i < text.length(); i++)
        if((text[i] = static_cast<unsigned>(text[i] - 'a' + key[i%key.length()])) > static_cast<int>('z'))
            text[i] -= 26;

    return text;
}

string vigenere_decrypt(string text, string key)
{
    for(size_t i = 0; i < text.length(); i++)
        if((text[i] = static_cast<unsigned>(text[i] + 'a' - key[i%key.length()])) < static_cast<int>('a'))
            text[i] += 26;

    return text;
}
