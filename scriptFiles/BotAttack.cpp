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

using namespace std;

int main()
{
    clog << "Log: Start game" << endl;
    int noc;
    cout << "Number of cards: ";
    cin >> noc;
    string i1[noc];
    int i2[noc];
    int i3[noc];
    for(int n = 0; n < noc; n++)
    {
        string *stmp = new string;
        cout << "Please enter the name for card " << (n+1) << ": ";
        cin >> *stmp;
        int *itmp = new int;
        cout << "Please enter the AttackPower for card " << (n+1) << ": ";
        cin >> *itmp;
        int *itmp2 = new int;
        cout << "Please enter the Schild power for card " << (n+1) << ": ";
        cin >> *itmp2;

        i1[n] = *stmp;
        i2[n] = *itmp;
        i3[n] = *itmp2;

        delete stmp;
        delete itmp;
        delete itmp2;
    }

    clog << "Log: Start game while-loop" << endl;
    while(true)
    {
        try
        {
            string card1;
            string card2;
            cout << "Name of Card one: ";
            cin >> card1;
            cout << "Name of Card two: ";
            cin >> card2;

            if(card1 == "abort" && card2 == "abort")
            {
                clog << "Log: The game while-loop is close" << endl;
                throw 1;
            }

            int p1;
            int p2;

            bool b1 = false;
            bool b2 = false;
            bool i;

            for(int n = 0; n < noc; n++)
            {
                if(card1 == i1[n])
                {
                    p1 = i2[n];
                    b1 = true;
                    break;
                }
            }

            for(int n = 0; n < noc; n++)
            {
                if(card2 == i1[n])
                {
                    p2 = i3[n];
                    b2 = true;
                    break;
                }
            }

            i = (b1 && b2);

            if(i != false)
            {
                if(p1 == p2)
                {
                    cout << card1 << " vs. " << card2 << "; Draw" << endl;
                }
                if(p1 > p2)
                {
                    cout << card1 << " vs. " << card2 << "; Won: " << card1 << endl;
                }
                if(p1 < p2)
                {
                    cout << card1 << " vs. " << card2 << "; Won: " << card2 << endl;
                }
            }
            else
            {
                cout << "The entered map name was not found!" << endl;
                cerr << "Error: The Card name is not found!" << endl;
                clog << "Log: A round is skip" << endl;
                throw 0;
            }
        }
        catch(int e)
        {
            if(e == 1)
            {
                break;
            }
            cerr << "Error: An error has occurred; the Error code is " << e << "; for more information, please contact the developer of this program;" << endl;
        }
    }
    clog << "Log: The game is to end" << endl;
    cout << "The developer of this game is Marek K." << endl;
    return 0;
}
